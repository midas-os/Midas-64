#ifndef H_MIDAS_KERNEL
#define H_MIDAS_KERNEL

#include <libdragon.h>
#include <math.h>

#include "../drawing/text_utils.h"
#include "../drawing/sprite_utils.h"
#include "../math/math.h"

/// @brief This function initializes the kernel
void init() {
    display_init( RESOLUTION_MODE, DEPTH_16_BPP, 2, GAMMA_NONE, ANTIALIAS_RESAMPLE );
    dfs_init( DFS_DEFAULT_LOCATION );
    rdp_init();
    controller_init();
    timer_init();
}

/// @brief This function gets the current display context
/// @return Returns the display context
display_context_t get_display_ctx() {
    static display_context_t disp = 0;
    while( !(disp = display_lock()) );
    return disp;
}

/// @brief Draws the MidAS 64 logo
/// @param disp The display context
/// @param y The y position
void draw_logo(display_context_t disp, int y) {
    /* Get colors */
    int c1 = graphics_make_color(219, 186, 0, 255);
    int c2 = graphics_make_color(237, 0, 40, 255);

    /* Create colored text */
    colored_text ct1 = create_colored_text("MidAS ", c1, 0x0);
    colored_text ct2 = create_colored_text("64", c2, 0x0);

    /* Create array */
    colored_text cta[] = {ct1, ct2};

    /* Draw */
    draw_colored_text_array_centered_x(disp, y, cta, 2);
}

float cursor_x = WIDTH / 2;
float cursor_y = HEIGHT / 2;
void kernel_main() {
    float cursor_speed = 0.05f;
    int color = 0x0;

    /* Get display context */
    display_context_t disp = get_display_ctx();

    /* Draw the background */
    show_background(disp, "./backgrounds/desktop-01.sprite");

    /* Draw white text */
    color = graphics_make_color(255, 255, 255, 255);
    graphics_set_color(color, 0x0);

    /* Draw text */
    draw_text_centered_x(disp, 100, "MidAS Desktop");
    draw_text_centered_x(disp, 110, "Work In Progress");

    /* Test Sprite */
    static sprite_t *sprite;
    if(sprite == NULL) {
        sprite = read_sprite_from_file("./cursor.sprite");
    }

    /* Draw sprite */
    graphics_draw_sprite_trans(disp, floor(cursor_x), floor(cursor_y), sprite);

    /* Render */
    display_show(disp);

    /* Get controller input */
    controller_scan();
    struct controller_data keys = get_keys_pressed();

    /* Increment cursor pos */
    cursor_x += keys.c[0].x * cursor_speed;
    cursor_y += keys.c[0].y * cursor_speed * -1.0f;

    /* Clamp cursor pos */
    cursor_x = clamp(cursor_x, 0, 320);
    cursor_y = clamp(cursor_y, 0, 240);
}

#endif