#ifndef CONFIG_H
#define CONFIG_H

#define SCREEN_MAX_W		640
#define SCREEN_MAX_H		480

#define BLOCK_SIZE          20
#define MAX_STATIC_BLOCKS   120
#define MAX_DYNAMIC_BLOCKS  8
#define MAX_BLOCKS          MAX_STATIC_BLOCKS + MAX_DYNAMIC_BLOCKS

#define MAX_VELOCITY        10

#define PLAYER_JUMP_HEIGHT  10
#define PLAYER_MOVE_SPEED   5
#define PLAYER_LIVES        3

#endif // CONFIG_H
