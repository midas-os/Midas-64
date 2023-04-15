#pragma once

#include <libdragon.h>
#include "graphics/display.hpp"
#include "graphics/sprite.hpp"
#include "text/text.hpp"

namespace midas {
    /// @brief Draws the MidAS 64 logo
    /// @param disp The display context
    /// @param y The y position
    void draw_logo(display_context_t disp, int y) {
        using namespace text;
        using namespace graphics;

        /* Create colored text */
        uint32_t c1 = graphics_make_color(219, 186, 0, 255);
        uint32_t c2 = graphics_make_color(237, 0, 40, 255);

        colored_text ct1 = colored_text("MidAS ", c1, (uint32_t)0x0, disp);
        colored_text ct2 = colored_text("64", c2, (uint32_t)0x0, disp);

        /* Get text locations */
        int l1 = calculate_middle_x(ct1.get_text()) - 16;
        int l2 = calculate_middle_x(ct2.get_text()) + 16;

        /* Draw text */
        ct1.draw(l1, y);
        ct2.draw(l2, y);
    }
}