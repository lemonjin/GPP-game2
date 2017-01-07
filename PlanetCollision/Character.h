
#ifndef CHARACTER_H
#define CHARACTER_H
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"
#include "textureManager.h"
#include "Snow.h"

namespace characterNS
{
	const int WIDTH = CHARACTER_WIDTH;
	const int HEIGHT = CHARACTER_HEIGHT;
	const int X = 0;
	const int Y = GAME_HEIGHT - HEIGHT - 160.0f;
	const float SPEED = CHARACTER_SPEED;
	const int START_FRAME = CHARACTER_START_FRAME;
	const int END_FRAME = CHARACTER_END_FRAME;
	const float ANIMATION_DELAY = CHARACTER_ANIMATION_DELAY;
	const int   TEXTURE_COLS = CHARACTER_COLS;
	
}

class Character : public Entity
{
private:
	bool jumping;
	float buffTime;
	int score = 0;
	int health = 3;
	TextureManager characterTexture;
	TextureManager characterWalkingTexture;
	Image characterWalking;

public:
	Character();
	virtual void draw();
	virtual bool initialize(Game* gamePtr,Graphics *graphicPtr, int width, int height, int ncols);
	void update(float frameTime);
	void characterMovement(Input *input, UCHAR up, UCHAR down, UCHAR left, UCHAR right);
	bool IsCharacterMoving();
	bool collisionDetectionWithSnow(Snow* snow);
};

#endif