// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Draw animated spaceships with collision and shield
// Chapter 6 spacewar.cpp v1.0
// This class is the core of the game

#include "spaceWar.h"
using namespace std;

//=============================================================================
// Constructor
//=============================================================================
Spacewar::Spacewar()
{
	
}

//=============================================================================
// Destructor
//=============================================================================
Spacewar::~Spacewar()
{
    releaseAll();           // call onLostDevice() for every graphics item
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void Spacewar::initialize(HWND hwnd)
{
	Game::initialize(hwnd);
	
	// character
	if (!character1.initialize(this ,graphics, characterNS::WIDTH, characterNS::HEIGHT, characterNS::TEXTURE_COLS))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing character1"));
	character1.setFrameDelay(characterNS::ANIMATION_DELAY);
	
	
	
	return;
}

//=============================================================================
// Update all game items
//=============================================================================
void Spacewar::update()
{
	
	character1.update(frameTime);
	character1.characterMovement(input, VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT);		
	if (input->isKeyDown(VK_SPACE))
	{
		if (power >= MAXPOWER)
		{
			power -= 1;
		}
		if (power < MAXPOWER)
		{
			power += 1;
		}
	}
	else
	{
		if (power > 0)
		{
			power -= 1;
		}
	}
}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void Spacewar::ai()
{
}

//=============================================================================
// Handle collisions
//=============================================================================
void Spacewar::collisions()
{
    VECTOR2 collisionVector;
	
		
	
}

//=============================================================================
// Render game items
//=============================================================================
void Spacewar::render()
{
    graphics->spriteBegin();                // begin drawing sprites
	character1.draw();
    graphics->spriteEnd();                  // end drawing sprites
	
		drawing.GetDevice(graphics->get3Ddevice());
		//drawing.CircleFilled(500, 500, 100, 0, full, 32, graphicsNS::BLACK);
		
		drawing.Circle(GAME_WIDTH/2, GAME_HEIGHT/2, 100, 0, power, true, 358, graphicsNS::BLACK);
		//drawing.CircleFilled(GAME_WIDTH / 2, GAME_HEIGHT / 2, 100, 0, full, 32, graphicsNS::BLACK);
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void Spacewar::releaseAll()
{
    
    Game::releaseAll();
    return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void Spacewar::resetAll()
{
    
    Game::resetAll();
    return;
}
int Spacewar::randomNum(int from, int to)
{
	int randnum = rand() % to + from;
	return randnum;
}
float Spacewar::RandomFloat(float a, float b) 
{
	float random = ((float)rand()) / (float)RAND_MAX;
	float diff = b - a;
	float r = random * diff;
	return a + r;
}
