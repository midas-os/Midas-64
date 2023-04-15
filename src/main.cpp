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

        // /* Version text and start prompt */
        color = graphics_make_color(255, 255, 255, 255);
        graphics_set_color(color, 0x0);
        // draw_text_centered_x(disp, middle_y + 16, "Version 0.0.1");
        // draw_text_centered_x(disp, middle_y + 30, "Press A to launch");
        
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

    midas::desktop::desktop_update();
}