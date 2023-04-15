#include <iostream>

#pragma once

namespace midas::text {
    class colored_text {
    public:
        colored_text(const std::string& text, const uint32_t& color, const uint32_t& background, display_context_t disp)
            : m_text(text), m_color(color), m_background(background), m_disp(disp)
        { }

        colored_text(const std::string& text)
            : m_text(text), m_color(0x0), m_background(0x0), m_disp(midas::graphics::get_display_ctx())
        { }

        colored_text(const colored_text& other) = delete;
        colored_text() = delete;

        ~colored_text()
        {
            m_text.clear();
            m_color = 0x0;
            m_background = 0x0;
        }

        /* Getters */
        std::string get_text() const { return m_text; }
        uint32_t get_color() const { return m_color; }
        uint32_t get_background() const { return m_background; }
        display_context_t get_display() const { return m_disp; }

        /* Setters */
        void set_text(const std::string& text) { m_text = text; }
        void set_color(const uint32_t& color) { m_color = color; }
        void set_background(const uint32_t& background) { m_background = background; }
        void set_display(display_context_t disp) { m_disp = disp; }

        /* Functions */
        void draw(int x, int y) {
            graphics_set_color(m_color, m_background);
            graphics_draw_text(m_disp, x, y, m_text.c_str());
        }

    private:
        std::string m_text;
        uint32_t m_color;
        uint32_t m_background;
        display_context_t m_disp;
    };

    int calculate_text_width(const std::string& text) {
        return text.length() * 8;
    }

    int calculate_text_height(const std::string& text) {
        /* Get amount of newlines */
        int newlines = 0;

        for (size_t i = 0; i < text.length(); i++) {
            if (text[i] == '\n') {
                newlines++;
            }
        }

        return (newlines + 1) * 8;
    }

    int calculate_middle_x(const std::string& text) {
        return (WIDTH - calculate_text_width(text)) / 2;
    }

    int calculate_middle_y(const std::string& text) {
        return (HEIGHT - calculate_text_height(text)) / 2;
    }

    /* Drawing Functions */
    void draw_text(const std::string& text, int x, int y, display_context_t disp) {
        graphics_draw_text(disp, x, y, text.c_str());
    }

    void draw_text_center_x(const std::string& text, int y, display_context_t disp) {
        int x = calculate_middle_x(text);
        draw_text(text, x, y, disp);
    }

    void draw_text_center_y(const std::string& text, int x, display_context_t disp) {
        int y = calculate_middle_y(text);
        draw_text(text, x, y, disp);
    }

    void draw_text_center(const std::string& text, display_context_t disp) {
        int x = calculate_middle_x(text);
        int y = calculate_middle_y(text);
        draw_text(text, x, y, disp);
    }    
}