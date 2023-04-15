#pragma once

namespace midas::application
{
    class Application {
    public:
        Application() = default;
        virtual ~Application() = default;

        virtual void start() = 0;
        virtual void update() = 0;
        virtual void stop() = 0;

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
    }
}