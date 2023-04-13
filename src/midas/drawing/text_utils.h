#ifndef H_TEXT_UTILS
#define H_TEXT_UTILS

#include <libdragon.h>
#include <string.h>

#include "../kernel/sysinfo.h"

/* TODO: Refactor file */

/* Struct for colored text */
typedef struct {
    char* text;
    uint32_t foreground;
    uint32_t background;
} colored_text;

/// @brief This function calculates the y position for centered text
/// @param text The text to calculate
/// @return Returns the centered y position
int calculate_centered_y(char* text) {

    /* Get screen height */
    int screen_height = HEIGHT;

    /* Get the height of the text */
    int text_height = 8;
    for(int i = 0; i < strlen(text); i++) {
        if(text[i] == '\n') {
            text_height += 8;
        }
    }

    return (screen_height - text_height) / 2;
}

/// @brief This function calculates the x position for centered text
/// @param text The text to calculate
/// @return Returns the centered x position
int calculate_centered_x(char* text) {

    /* Get screen width */
    int screen_width = WIDTH;

    /* Get the length of the text */
    int text_length = strlen(text) * 8;

    return (screen_width - text_length) / 2;
}

/// @brief This function creates a colored text struct
/// @param text String for text
/// @param foreground The foreground color in RGBA
/// @param background The background color in RGBA
/// @return Returns the colored text struct
colored_text create_colored_text(char* text, unsigned int foreground, unsigned int background) {
    colored_text ct;
    ct.text = text;
    ct.foreground = foreground;
    ct.background = background;
    return ct;
}

/// @brief This function draws uncolored text centered on the x axis
/// @param disp The display context
/// @param y The y position
/// @param text The text to draw
void draw_text_centered_x(display_context_t disp, int y, char* text) {
    // Get screen width
    int screen_width = WIDTH;
    int text_width = strlen(text) * 8;
    int x = (screen_width - text_width) / 2;
    graphics_draw_text(disp, x, y, text);
}

/// @brief This function draws colored text centered on the x axis
/// @param disp The display context
/// @param y The y position
/// @param ct The colored text struct
void draw_colored_text_centered_x(display_context_t disp, int y, colored_text ct) {
    // Get screen width
    int screen_width = WIDTH;
    int text_width = strlen(ct.text) * 8;
    int x = (screen_width - text_width) / 2;
    graphics_set_color(ct.foreground, ct.background);
    graphics_draw_text(disp, x, y, ct.text);
}

/// @brief This function draws an array of colored text centered on the x axis
/// @param disp The display context
/// @param y The y position
/// @param cta The array of colored text structs
/// @param length The length of the array
void draw_colored_text_array_centered_x(display_context_t disp, int y, colored_text* cta, int length) {
    /* Get the width of the screen */
    int screen_width = WIDTH;

    /* Initialize a variable to keep track of the total width of the text */
    int text_width = 0;

    /* Loop through each element in the array of colored text and add the width of its text to the total text width */
    for (int i = 0; i < length; i++) {
        text_width += strlen(cta[i].text) * 8;
    }

    /* Calculate the x position where the text should start to be centered horizontally */
    int x = (screen_width - text_width) / 2;
    
    /* Loop through each element in the array of colored text and draw it to the display */
    for (int i = 0; i < length; i++) {
        
        /* Set the color of the current colored text element */
        graphics_set_color(cta[i].foreground, cta[i].background);

        /* Draw the text at the current x and y position */
        graphics_draw_text(disp, x, y, cta[i].text);
        x += strlen(cta[i].text) * 8;
    }
}

void draw_text_centered_y(display_context_t disp, int x, char* text) {
    // Get screen height
    int y = calculate_centered_y(text);
    graphics_draw_text(disp, x, y, text);
}

void draw_colored_text_centered_y(display_context_t disp, int x, colored_text ct) {
    // Get screen height
    int y = calculate_centered_y(ct.text);
    graphics_set_color(ct.foreground, ct.background);
    graphics_draw_text(disp, x, y, ct.text);
}

void draw_colored_text_array_centered_y(display_context_t disp, int x, colored_text* cta, int length) {
    /* Get the height of the screen */
    int screen_height = HEIGHT;

    /* Initialize a variable to keep track of the total height of the text */
    int text_height = 0;

    /* Loop through each element in the array of colored text and add the height of its text to the total text height */
    for (int i = 0; i < length; i++) {
        text_height += strlen(cta[i].text) * 8;
    }

    /* Calculate the y position where the text should start to be centered vertically */
    int y = (screen_height - text_height) / 2;
    
    /* Loop through each element in the array of colored text and draw it to the display */
    for (int i = 0; i < length; i++) {
        
        /* Set the color of the current colored text element */
        graphics_set_color(cta[i].foreground, cta[i].background);

        /* Draw the text at the current x and y position */
        graphics_draw_text(disp, x, y, cta[i].text);
        y += strlen(cta[i].text) * 8;
    }
}

void draw_text_centered(display_context_t disp, char* text) {
    int x = calculate_centered_x(text); 
    int y = calculate_centered_y(text);
    graphics_draw_text(disp, x, y, text);
}

void draw_colored_text_centered(display_context_t disp, colored_text ct) {
    int x = calculate_centered_x(ct.text); 
    int y = calculate_centered_y(ct.text);
    graphics_set_color(ct.foreground, ct.background);
    graphics_draw_text(disp, x, y, ct.text);
}

void draw_colored_text_array_centered(display_context_t disp, colored_text* cta, int length) {
    /* Get the width and height of the screen */
    int screen_width = WIDTH;
    int screen_height = HEIGHT;

    /* Initialize a variable to keep track of the total width and height of the text */
    int text_width = 0;
    int text_height = 0;

    /* Loop through each element in the array of colored text and add the width and height of its text to the total text width and height */
    for (int i = 0; i < length; i++) {
        text_width += strlen(cta[i].text) * 8;
        for(int j = 0; j < strlen(cta[i].text); j++) {
            if(cta[i].text[j] == '\n') {
                text_height += 8;
            }
        }
    }

    /* Calculate the x and y position where the text should start to be centered horizontally and vertically */
    int x = (screen_width - text_width) / 2;
    int y = (screen_height - text_height) / 2;
    
    /* Loop through each element in the array of colored text and draw it to the display */
    for (int i = 0; i < length; i++) {
        
        /* Set the color of the current colored text element */
        graphics_set_color(cta[i].foreground, cta[i].background);

        /* Draw the text at the current x and y position */
        graphics_draw_text(disp, x, y, cta[i].text);
        x += strlen(cta[i].text) * 8;
    }
}

#endif /* H_TEXT_UTILS */