#pragma once

#include <libdragon.h>

namespace midas::graphics
{
    display_context_t get_display_ctx() {
        static display_context_t disp = 0;
        while( !(disp = display_lock()) );
        return disp;
    }
}