#include "DEFINITIONS.h"
#include "Spider.h"
#include "SpiderLogic.h"
#include <cstdlib>
#include <ctime>

namespace GameEngine
{
	SpiderLogic::SpiderLogic ( FieldPtr field )
		: _field ( field )
		, _totalTimePerMovement ( 0 )
		, _speed ( SPIDER_SPEED )
	{
		std::srand ( std::time ( nullptr ) );
	}

	void SpiderLogic::Spawn()
	{
		if ( _field->GetSpiders().empty() )
		{
			auto spider = Spider();
			_field->GetSpiders().push_back ( spider );
			_angle = ( std::rand() % 180 ) * PI / 180;
		}
	}

	void SpiderLogic::Move ( float dt )
	{
		if ( !_field->GetSpiders().empty() )
		{
			for ( unsigned int i = 0; i < _field->GetSpiders().size(); i++ )
			{
				if ( _totalTimePerMovement > SPIDER_MOVEMENT_TIME )
				{
					_angle = ( std::rand() % 360 ) * PI / 180;
					_totalTimePerMovement = 0;
				}

				if ( _field->GetSpiders().at ( i ).GetTopLeftYPosition() <= TURRET_SCREEN_FRACTION * SCREEN_HEIGHT )
				{
					// keep sprite from moving off screen
					_field->GetSpiders().at ( i ).SetTopLeftYPosition ( TURRET_SCREEN_FRACTION * SCREEN_HEIGHT );
					// move
					_field->GetSpiders().at ( i ).SetTopLeftXPosition (
					    _field->GetSpiders().at ( i ).GetTopLeftXPosition() );
					_field->GetSpiders().at ( i ).SetTopLeftYPosition (
					    _field->GetSpiders().at ( i ).GetTopLeftYPosition() + _speed * dt );
					_angle = ( std::rand() % 180 ) * PI / 180;
					_totalTimePerMovement += dt;
					continue;
				}

				if ( _field->GetSpiders().at ( i ).GetTopLeftYPosition() >= SCREEN_HEIGHT - SPIDER_SPRITE_SIZE )
				{
					// keep sprite from moving off screen
					_field->GetSpiders().at ( i ).SetTopLeftYPosition ( SCREEN_HEIGHT - SPIDER_SPRITE_SIZE );
					// move
					_field->GetSpiders().at ( i ).SetTopLeftXPosition (
					    _field->GetSpiders().at ( i ).GetTopLeftXPosition() );
					_field->GetSpiders().at ( i ).SetTopLeftYPosition (
					    _field->GetSpiders().at ( i ).GetTopLeftYPosition() - _speed * dt );
					_angle = ( std::rand() % 360 ) * PI / 180;
					_totalTimePerMovement += dt;
					continue;
				}

				_field->GetSpiders().at ( i ).SetTopLeftXPosition ( _field->GetSpiders().at ( i ).GetTopLeftXPosition() +
				        _speed * dt * cos ( _angle ) );
				_field->GetSpiders().at ( i ).SetTopLeftYPosition ( _field->GetSpiders().at ( i ).GetTopLeftYPosition() +
				        _speed * dt * sin ( _angle ) );
				_totalTimePerMovement += dt;
			}
		}
	}

	void SpiderLogic::CollisionHandle()
	{
		if ( !_field->GetSpiders().empty() )
		{
			for ( unsigned int i = 0; i < _field->GetSpiders().size(); i++ )
			{
				if ( _field->GetSpiders().at ( i ).IsDead() )
				{
					_field->GetSpiders().erase ( _field->GetSpiders().begin() + i );
					i--;
				}
			}
		}
	}
} // namespace GameEngine
