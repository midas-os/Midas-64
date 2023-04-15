#pragma once

#include <functional>

namespace midas::application
{
    class application {
    public:
        application() = delete;

        application(const char *name, sprite_t *icon)
            : name(name), icon(icon)
        { }

        ~application() = default;

        /* Variables */
        const char *name;
        sprite_t *icon;

        /* Functions */
        /* void(*name)(paremets) = function as variable */
        /* [](parameters) { ... } = lambda expression */
        void (*start)() = []() { };
        void (*update)() = []() { };
        void (*stop)() = []() { };

        void run() {
            start();

            m_running = true;
            while (m_running) {
                update();
            }

            stop();
        }

    protected:
        bool m_running = false;
    };
}