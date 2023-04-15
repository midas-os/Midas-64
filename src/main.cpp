/* Includes */
#include <stdio.h>
#include <libdragon.h>

#include "midas/sysinfo.hpp"
#include "midas/common.hpp"
#include "midas/kernel/setup.hpp"
#include "midas/graphics/display.hpp"
#include "midas/math/vector.hpp"

#include "midas/desktop/desktop.hpp"

/* Definitions */
#define RENDER_AUTOMATIC 1

int main(void)
{
    using namespace midas::text;
    using namespace midas::graphics;

    init();

    while(1) {
        int color = graphics_make_color(0, 0, 0, 255);

        /* Get display context */
        display_context_t disp = get_display_ctx();

        /*Fill the screen */
        graphics_fill_screen(disp, color);

        int middle_y = calculate_middle_y("");

        /* Draw the MidAS 64 Logo */
        midas::draw_logo(disp, middle_y - 16);

        /* Version text and start prompt */
        color = graphics_make_color(255, 255, 255, 255);
        graphics_set_color(color, 0x0);
        
        char buffer[32];
        sprintf(buffer, "Version %s", VERSION);

        draw_text_center_x(buffer, middle_y, disp);
        draw_text_center_x("Press A to launch", middle_y + 16, disp);

        /* Render */
        display_show(disp);

        /* Get controller input */
        controller_scan();
        struct controller_data keys = get_keys_pressed();

        if(keys.c[0].A) {
            break;
        }
    }

    sprite_t* icon = midas::graphics::read_from_filesystem("app.sprite");

    midas::application::application my_app("Hello", icon);
    my_app.start = []() {
        midas::text::draw_text_center_x("Hello World!", 100, midas::graphics::get_display_ctx());
    };

    midas::desktop::apps.push_back(&my_app);

    midas::desktop::desktop_update();
}