/* Includes */
#include <stdio.h>
#include <libdragon.h>

#include "midas/drawing/text_utils.h"
#include "midas/kernel/kernel.h"
#include "midas/kernel/sysinfo.h"

/* Definitions */
#define RENDER_AUTOMATIC 1

int main(void)
{
    init();

    while(1) {
        int color = 0x0;

        /* Get display context */
        display_context_t disp = get_display_ctx();

        /*Fill the screen */
        graphics_fill_screen(disp, color);

        int middle_y = calculate_centered_y("");

        /* Draw the MidAS 64 Logo */
        draw_logo(disp, middle_y);

        /* Version text and start prompt */
        color = graphics_make_color(255, 255, 255, 255);
        graphics_set_color(color, 0x0);
        draw_text_centered_x(disp, middle_y + 16, "Version 0.0.1");
        draw_text_centered_x(disp, middle_y + 30, "Press A to launch");
 
        /* Render */
        display_show(disp);

        /* Get controller input */
        controller_scan();
        struct controller_data keys = get_keys_pressed();

        if(keys.c[0].A) {
            break;
        }
    }

    kernel_start();
    kernel_update();
}