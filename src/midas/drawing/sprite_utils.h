#ifndef H_SPRITE_UTILS
#define H_SPRITE_UTILS

#include <libdragon.h>
#include <malloc.h>

sprite_t *read_sprite_from_file(const char* filename) {
    int fp = dfs_open(filename);
    sprite_t *sprite = malloc( dfs_size( fp ) );
    dfs_read( sprite, 1, dfs_size( fp ), fp );
    dfs_close( fp );

    return sprite;
}

#endif