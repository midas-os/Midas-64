#pragma once
#include <libdragon.h>
#include <cmath>
#include <vector>

#include "cursor.hpp"

#include "../sysinfo.hpp"

#include "../graphics/sprite.hpp"
#include "../graphics/display.hpp"

#include "../math/math.hpp"

#include "../text/text.hpp" 

#include "../application/app.hpp"

/*          Min X, Min Y, Max X, Max Y         */
#define SCREEN_PADDING      vector4(10, 10, 10, 10)

#define APP_SIZE            vector2(64, 64)
#define APP_SPACING         vector2(10, 10)

#define MAX_APPS_PER_COL    2

namespace midas::desktop {
    static std::vector<midas::application::application*> apps;

    void draw_apps(display_context_t disp) {
        int col_idx = 0;
        int row = 0;
        for (auto app : apps) {
            col_idx++;

            if (col_idx > MAX_APPS_PER_COL) {
                col_idx = 0;
                row++;
            }

            /* Make it so apps are drawn windows-style */
            int x = SCREEN_PADDING.x + (col_idx * APP_SIZE.x) + (col_idx * APP_SPACING.x);
            int y = SCREEN_PADDING.y + (row * APP_SIZE.y) + (row * APP_SPACING.y);

            graphics_draw_sprite_trans(disp, x, y, app->icon);
            midas::text::draw_text(app->name, x, y + 42, disp);
        }
    }

    void desktop_update() {
        using namespace midas::text;

        cursor c("cursor.sprite", WIDTH / 2, HEIGHT / 2);

        while(1) {
            float cursor_speed = 0.05f;
            int color = 0x0;

            /* Get display context */
            display_context_t disp = midas::graphics::get_display_ctx();

            /* Draw the background */
            // graphics_draw_sprite_trans(disp, 0, 0, background);
            color = graphics_make_color(184, 48, 96, 255);
            graphics_fill_screen(disp, color);

            /* Draw white text */
            color = graphics_make_color(255, 255, 255, 255);
            graphics_set_color(color, 0x0);

            /* Draw text */
            draw_text_center_x("MidAS Desktop", HEIGHT / 2, disp);

            /* Draw Apps */
            draw_apps(disp);

            /* Cursor */
            graphics_draw_sprite_trans(disp, floor(c.x), floor(c.y), c.get_sprite());

            /* Render */
            display_show(disp);

            /* Get controller input */
            controller_scan();
            struct controller_data keys = get_keys_pressed();

            /* Increment cursor pos */
            c.x += keys.c[0].x * cursor_speed;
            c.y += keys.c[0].y * cursor_speed * -1.0f;

            /* Clamp cursor pos */
            clamp(&c.x, 0 + SCREEN_PADDING.x, WIDTH - SCREEN_PADDING.z);
            clamp(&c.y, 0 + SCREEN_PADDING.y, HEIGHT - SCREEN_PADDING.w);
        }
    }
}