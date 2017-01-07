// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 6 constants.h v1.0

#ifndef _CONSTANTS_H            // Prevent multiple definitions if this 
#define _CONSTANTS_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include <windows.h>

//-----------------------------------------------
// Useful macros
//-----------------------------------------------
// Safely delete pointer referenced item
#define SAFE_DELETE(ptr)       { if (ptr) { delete (ptr); (ptr)=NULL; } }
// Safely release pointer referenced item
#define SAFE_RELEASE(ptr)      { if(ptr) { (ptr)->Release(); (ptr)=NULL; } }
// Safely delete pointer referenced array
#define SAFE_DELETE_ARRAY(ptr) { if(ptr) { delete [](ptr); (ptr)=NULL; } }
// Safely call onLostDevice
#define SAFE_ON_LOST_DEVICE(ptr)    { if(ptr) { ptr->onLostDevice(); } }
// Safely call onResetDevice
#define SAFE_ON_RESET_DEVICE(ptr)   { if(ptr) { ptr->onResetDevice(); } }
#define TRANSCOLOR  SETCOLOR_ARGB(0,255,0,255)  // transparent color (magenta)

//-----------------------------------------------
//                  Constants
//-----------------------------------------------


// graphic images
const char BACKGROUND_IMAGE[] = "pictures\\background.png";  // background
const char CHARACTER_IMAGE[] = "pictures\\character_white_resting.png";//character player 1
const char CHARACTERWALKING_IMAGE[] = "pictures\\character_white_walking.png";//characterwalking player 1
const char CHARACTER2_IMAGE[] = "pictures\\character_grey_resting.png";//character player 2
const char CHARACTERWALKING2_IMAGE[] = "pictures\\character_grey_walking.png";//characterWalking player 2
const char CLOUD_IMAGE[] = "pictures\\clouds.png";//cloud
const char HAIL_IMAGE[] = "pictures\\Hail.png";//hail
const char SNOW_IMAGE[] = "pictures\\snow.png";//snow
const char FREEZE_IMAGE[] = "pictures\\freeze.png";//freeze

const char FAST_IMAGE[] = "pictures\\fast.png";
const char MINUS_IMAGE[] = "pictures\\minus.png";//minus
const char SLOW_IMAGE[] = "pictures\\slow.png";//slow
const char SNOW_FAST_IMAGE[] = "pictures\\snow_fast.png";//snow_fast
const char SNOW_INVINCIBLE_IMAGE[] = "pictures\\snow_invincible.png";//snow_invincible
const char SNOWMAN_IMAGE[] = "pictures\\snowman.png";//snowman
const char SNOWMAN_HEAD_IMAGE[] = "pictures\\Mr_Snowman_Head_1.png";//snowman_head
const char SNOW_MINUS_IMAGE[] = "pictures\\snow_minus.png";//snow_minus
const char SNOW_SLOW_IMAGE[] = "pictures\\snow_slow.png";//snow_slow

// start_page
const char START_PAGE_IMAGE[] = "pictures\\start_page.png";
const char END_PAGE_IMAGE[] = "pictures\\end_page.png";

// window
const char CLASS_NAME[] = "Hailo";
const char GAME_TITLE[] = "Hailo";
const bool FULLSCREEN = false;             // windowed or fullscreen
const UINT GAME_WIDTH = 1028;               // width of game in pixels
const UINT GAME_HEIGHT = 768;               // height of game in pixels



// game
const double PI = 3.14159265;
const float FRAME_RATE = 200.0f;               // the target frame rate (frames/sec)
const float MIN_FRAME_RATE = 10.0f;             // the minimum frame rate
const float MIN_FRAME_TIME = 1.0f / FRAME_RATE;   // minimum desired time for 1 frame
const float MAX_FRAME_TIME = 1.0f / MIN_FRAME_RATE; // maximum time used in calculations
const float SNOW_SPAWNTIME = 2.0f;
const float SNOW_BALL_WIDTH = 35.0;
const float MAXPOWER = 360;

// key mappings
// In this game simple constants are used for key mappings. If variables were used
// it would be possible to save and restore key mappings from a data file.
const UCHAR ESC_KEY = VK_ESCAPE;   // escape key
const UCHAR ALT_KEY = VK_MENU;     // Alt key
const UCHAR ENTER_KEY = VK_RETURN;   // Enter key

const int FLOOR = 585;
const int SNOW_ROTATION_RATE = 5;
const int SPAWNTIME = 2;
const int BUFFTIME = 1;
const int FREEZETIME = 10;
const float SNOW_MIN_SPEED = 100;
const float SNOW_MAX_SPEED = 150;
const int numOfSnowball = 20;
const int numOfDroppingColumns = 20;
const int Snow_Drop_Height = 30;
const int SPAWNTIME_MIN = 0.4;
const int SPAWNTIME_MAX = 0.8;

//character variable
const float CHARACTER_SPEED = 100.0f;
const float CHARACTER_JUMP_SPEED = 500.0f;

//character  
const int  CHARACTER_START_FRAME = 0;         // starting frame of CHARACTER animation
const int  CHARACTER_END_FRAME = 3;           // last frame of CHARACTER animation
const float CHARACTER_ANIMATION_DELAY = 0.2f; // time between frames of CHARACTER animation
const int  CHARACTER_COLS = 4;                // CHARACTER texture has 1 columns
const int  CHARACTER_WIDTH = 80;              // width of CHARACTER image
const int  CHARACTER_HEIGHT = 112;             // height of CHARACTER image

//characterWalking
const int  CHARACTERWALKING_START_FRAME = 0;         // starting frame of CHARACTERWALKING animation
const int  CHARACTERWALKING_END_FRAME = 9;           // last frame of CHARACTERWALKING animation
const float CHARACTERWALKING_ANIMATION_DELAY = 0.3f; // time between frames of CHARACTERWALKING animation
const int  CHARACTERWALKING_COLS = 10;                // CHARACTERWALKING texture has 1 columns
const int  CHARACTERWALKING_WIDTH = 80;              // width of CHARACTERWALKING image
const int  CHARACTERWALKING_HEIGHT = 112;             // height of CHARACTERWALKING image

//snowman
const int  SNOWMAN_START_FRAME = 0;         // starting frame of SNOWMAN animation
const int  SNOWMAN_END_FRAME = 3;           // last frame of SNOWMAN animation
const float SNOWMAN_ANIMATION_DELAY = 0.3f; // time between frames of SNOWMAN animation
const int  SNOWMAN_COLS = 4;                // SNOWMAN texture has 1 columns
const int  SNOWMAN_WIDTH = 114;              // width of SNOWMAN image
const int  SNOWMAN_HEIGHT = 127;             // height of SNOWMAN image
const int SPEED_ROLLING_OF_DEATH = 200;



// weapon types
enum BUFF { FAST, SLOW, MIUNS, INVINCIBLE};

#endif
