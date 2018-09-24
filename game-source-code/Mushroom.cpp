#include "DEFINITIONS.h"
#include "Direction.h"
#include "Mushroom.h"

namespace GameEngine
{
	Mushroom::Mushroom ( float xpos, float ypos )
		: Entity ( xpos, ypos )
		, is_bitten_ ( false )
		, is_poisoned_ ( false )
		, lives_remaining_ ( 4 )
	{
		Entity::SetDirection ( Direction::HOVER );
		Entity::SetCenterXPosition ( Entity::GetTopLeftXPosition() + MUSHROOM_SPRITE_SIZE / 2 );
		Entity::SetCenterYPosition ( Entity::GetTopLeftYPosition() + MUSHROOM_SPRITE_SIZE / 2 );
	}

	void Mushroom::SetBitten ( bool isBitten )
	{
		is_bitten_ = isBitten;
	}

	void Mushroom::SetPoisoned ( bool isPoisoned )
	{
		is_poisoned_ = isPoisoned;
	}

	bool Mushroom::IsBitten()
	{
		return is_bitten_;
	}

	bool Mushroom::IsPoisoned()
	{
		return is_poisoned_;
	}

	void Mushroom::DecrementLives()
	{
		lives_remaining_--;
	}

	int Mushroom::GetLivesRemaining()
	{
		return lives_remaining_;
	}
} // namespace GameEngine
