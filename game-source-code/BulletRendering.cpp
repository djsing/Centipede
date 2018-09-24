#include "BulletRendering.h"

namespace GameEngine
{
	BulletRendering::BulletRendering ( DataPtr data, std::vector<Bullet>& bullets )
		: data_ ( data )
		, bullets_ ( bullets )
	{
	}

	void BulletRendering::Draw()
	{
		for ( unsigned int i = 0; i < bullets_.size(); i++ )
		{
			bullets_.at ( i ).GetObjectSprite().setTexture ( data_->resources.GetTexture ( "Bullet sprite" ) );
			bullets_.at ( i ).GetObjectSprite().setPosition ( bullets_.at ( i ).GetTopLeftXPosition(),
			        bullets_.at ( i ).GetTopLeftYPosition() );
			data_->window.draw ( bullets_.at ( i ).GetObjectSprite() );
		}
	}
} // namespace GameEngine
