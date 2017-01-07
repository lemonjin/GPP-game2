
#ifndef SNOW_H
#define SNOW_H
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"
#include "textureManager.h"

namespace snowNS
{
	const int ROTATION_RATE = 5;
	const float MIN_SPEED = SNOW_MIN_SPEED;
	const float MAX_SPEED = SNOW_MAX_SPEED;
	const int DROP_HEIGHT = Snow_Drop_Height;
	const float WIDTH = SNOW_BALL_WIDTH;

}

class Snow : public Entity
{
private:
	BUFF buff;
	TextureManager SnowTexture;
	TextureManager HailTexture;
	TextureManager FastTexture;
	TextureManager SlowTexture;
	TextureManager MinusTexture;
	TextureManager InvincibleTexture;
	Image Hail;
	Image Fast;
	Image Slow;
	Image Minus;
	Image Invincible;
	int typeNum;

public:
	Snow();
	~Snow();
	virtual void draw();
	virtual bool initialize(Game* gamePtr, Graphics *graphicPtr, int width, int height, int ncols);
	void update(float frameTime);
	void setDroppingSpeed(int speed);
	void PositionSet();
	int getSnowType();
};

#endif