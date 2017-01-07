#include "Character.h"

Character::Character() : Entity()
{
	frameDelay = characterNS::ANIMATION_DELAY;
	startFrame = characterNS::START_FRAME;     // first frame of ship animation
	endFrame = characterNS::END_FRAME;
	spriteData.x = characterNS::X;                   // location on screen
	spriteData.y = characterNS::Y;
	collisionType = entityNS::BOX;
	/*edge.bottom = characterNS::HEIGHT;
	edge.right = characterNS::WIDTH;
	edge.top = characterNS::Y;
	edge.left = characterNS::X;*/
	spriteData.width = characterNS::WIDTH;
	spriteData.height = characterNS::HEIGHT;

	spriteData.rect.bottom = characterNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = characterNS::WIDTH;
	spriteData.rect.top = characterNS::Y;
	spriteData.rect.left = characterNS::X;
	velocity.x = 0;                             // velocity X
	velocity.y = 0;                             // velocity Y

	currentFrame = startFrame;

}
bool Character::initialize(Game* gamePtr,Graphics *graphicPtr, int width, int height, int ncols)
{
	//character textures
	if (!characterTexture.initialize(graphicPtr, CHARACTER_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing character textures"));

	//character textures
	if (!characterWalkingTexture.initialize(graphicPtr, CHARACTERWALKING_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing character walking textures"));
	
	characterWalking.initialize(gamePtr->getGraphics(), width, height, ncols, &characterWalkingTexture);
	characterWalking.setFrames(characterNS::START_FRAME, characterNS::END_FRAME);
	characterWalking.setCurrentFrame(characterNS::START_FRAME);
	characterWalking.setFrameDelay(characterNS::ANIMATION_DELAY);
	return(Entity::initialize(gamePtr, width, height, ncols, &characterTexture));
}
void Character::draw()
{
	
	if (IsCharacterMoving())
	{
		characterWalking.setX(spriteData.x);
		characterWalking.setY(spriteData.y);
		characterWalking.draw();
	}
	else
	{
		Image::draw();
	}
}
void Character::update(float frameTime)
{
	Entity::update(frameTime);
	spriteData.x += frameTime * velocity.x;         // move ship along X 
	if (IsCharacterMoving())
	{
		characterWalking.update(frameTime);
		
	}
}

void Character::characterMovement(Input *input, UCHAR up, UCHAR down, UCHAR left, UCHAR right)
{
	if (input->isKeyDown(right))
	{
		velocity.x += 2.0f;
	}
	if (input->isKeyDown(left))
	{
		velocity.x -= 2.0f;
	}

	if (velocity.x > 0)
	{
		velocity.x -= 1.0f;
	}
	else
	{
		velocity.x += 1.0f;
	}
}
bool Character::IsCharacterMoving()
{
	if ((velocity.x > 1.0f && velocity.x > -1.0f) || (velocity.x < 1.0f && velocity.x < -1.0f))
	{
		if ((velocity.x > 1.0f && velocity.x > -1.0f))
		{
			characterWalking.setDegrees(0);
			characterWalking.flipVertical(false);
		}
		if ((velocity.x < 1.0f && velocity.x < -1.0f))
		{
			characterWalking.setDegrees(180);
			characterWalking.flipVertical(true);
		}
		return true;
	}
	else
	{
		return false;
	}
}
bool Character::collisionDetectionWithSnow(Snow* snow)
{
	if ((this->getX() + this->getWidth() - 20) >= (snow->getX()) &&
		(this->getX() + 15) <= (snow->getX() + snow->getWidth()) &&
		(this->getY() + this->getHeight()) >= (snow->getY()) &&
		(this->getY() + 10) <= (snow->getY() + snow->getHeight()))
	{
			return true;
		}
	else
	{
		return false;
	}
}