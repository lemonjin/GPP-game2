#include "Snow.h"

Snow::Snow() : Entity()
{
	typeNum = rand() % 10 + 1;
	collisionType = entityNS::CIRCLE;
	radius = snowNS::WIDTH / 2.0;
}
Snow::~Snow()
{

}
bool Snow::initialize(Game* gamePtr, Graphics *graphicPtr, int width, int height, int ncols)
{
	//Snow textures
	if (!SnowTexture.initialize(graphicPtr, SNOW_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Snow textures"));
	// hail texture
	if (!HailTexture.initialize(graphicPtr, HAIL_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing hail texture"));
	// snow_fast texture
	if (!FastTexture.initialize(graphicPtr, SNOW_FAST_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing snow_fast texture"));
	// snow_invinicible texture
	if (!InvincibleTexture.initialize(graphicPtr, SNOW_INVINCIBLE_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing snow_invincible texture"));
	// snow_minus texture
	if (!MinusTexture.initialize(graphicPtr, SNOW_MINUS_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing snowman_minus texture"));
	// snow_slow texture
	if (!SlowTexture.initialize(graphicPtr, SNOW_SLOW_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing snowman_minus texture"));
	Hail.initialize(gamePtr->getGraphics(), width, height, ncols, &HailTexture);
	Fast.initialize(gamePtr->getGraphics(), width, height, ncols, &FastTexture);
	Slow.initialize(gamePtr->getGraphics(), width, height, ncols, &SlowTexture);
	Minus.initialize(gamePtr->getGraphics(), width, height, ncols, &MinusTexture);
	Invincible.initialize(gamePtr->getGraphics(), width, height, ncols, &InvincibleTexture);

	return(Entity::initialize(gamePtr, width, height, ncols, &SnowTexture));
}
void Snow::draw()
{
	
	switch (typeNum)
	{
	case 1:
		Hail.setX(this->getX());
		Hail.setY(this->getY());
		Hail.setDegrees(Hail.getDegrees() + snowNS::ROTATION_RATE);// snow rotating
		Hail.draw();
		break;
	case 2:
		Fast.setX(this->getX()); 
		Fast.setY(this->getY());
		Fast.setDegrees(Fast.getDegrees() + snowNS::ROTATION_RATE);// snow rotating
		Fast.draw();
		break;
	case 3:
		Slow.setX(this->getX()); 
		Slow.setY(this->getY());
		Slow.setDegrees(Slow.getDegrees() + snowNS::ROTATION_RATE);// snow rotating
		Slow.draw();
		break;
	case 4:
		Minus.setX(this->getX());
		Minus.setY(this->getY());
		Minus.setDegrees(Minus.getDegrees() + snowNS::ROTATION_RATE);// snow rotating
		Minus.draw();
		break;
	case 5:
		Invincible.setX(this->getX()); 
		Invincible.setY(this->getY());
		Invincible.setDegrees(Invincible.getDegrees() + snowNS::ROTATION_RATE);// snow rotating
		Invincible.draw();
		break;
	default: Image::draw();
		break;
	}
	
}
void Snow::update(float frameTime)
{
	Entity::update(frameTime);
	
	if (this->getVisible())
	{
		spriteData.y += frameTime * velocity.y;
		this->setDegrees(this->getDegrees() + snowNS::ROTATION_RATE);// snow rotating
	}
	
	if (this->getY() > FLOOR)
	{
		this->setVisible(false);
		this->setY(snowNS::DROP_HEIGHT);
	}
}
void Snow::setDroppingSpeed(int speed)
{
	velocity.y = speed;
}
int Snow::getSnowType()
{
	return typeNum;
}