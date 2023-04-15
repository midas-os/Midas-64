#pragma once

#include <libdragon.h>
#include <cstdlib>

namespace midas::graphics {
    sprite_t *read_from_filesystem(const char* filename) {
        int fp = dfs_open(filename);
        sprite_t *sprite = (sprite_t*)malloc(dfs_size(fp));
        dfs_read( sprite, 1, dfs_size( fp ), fp );
        dfs_close( fp );

        return sprite;
    }
}