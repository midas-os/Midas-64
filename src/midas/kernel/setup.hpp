#pragma once

/// @brief Initializes the kernel.
void init() {
    display_init( RESOLUTION_MODE, DEPTH_16_BPP, 2, GAMMA_NONE, ANTIALIAS_RESAMPLE );
    dfs_init( DFS_DEFAULT_LOCATION );
    rdp_init();
    controller_init();
    timer_init();
}