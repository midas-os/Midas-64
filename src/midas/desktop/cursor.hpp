#pragma once

#include <libdragon.h>
#include "../graphics/sprite.hpp"

namespace midas::desktop
{
    class cursor
    {
    public:
        cursor(const std::string& path, const int& x, const int& y)
            : x(x), y(y)
        {
            m_sprite = midas::graphics::read_from_filesystem(path.c_str());
        }

        ~cursor()
        {
            x = 0;
            y = 0;
        }

        sprite_t* get_sprite() { return m_sprite; }

        int x;
        int y;

    private:
        sprite_t* m_sprite;
    };
}
