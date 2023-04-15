#pragma once
#include <libdragon.h>

#include "cursor.hpp"

#include "../graphics/sprite.hpp"
#include "../graphics/display.hpp"

#include "../math/math.hpp"
#include <cmath>

#include "../text/text.hpp" 

/* Laid out as following: Min X, Min Y, Max X, Max Y */
#define SCREEN_PADDING vector4(10, 10, 10, 10)

namespace midas::desktop {
    void desktop_update() {
        cursor c("cursor.sprite", 1000, 1000);

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
            // draw_text_center_x(disp, 100, "MidAS Desktop");
            // draw_text_center_x(disp, 110, "Work In Progress");

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