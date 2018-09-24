#include "CentipedeRendering.h"
#include "DEFINITIONS.h"

namespace GameEngine
{
	CentipedeRendering::CentipedeRendering ( DataPtr data, CentPtr centipede )
		: data_ ( data )
		, centipede_ ( centipede )
	{
		data_->resources.LoadTexture ( "Segment sprite", SEGMENT_FILEPATH );
		data_->resources.LoadTexture ( "Body Segment sprite", BODY_SEGMENT_FILEPATH );
	}

	void CentipedeRendering::Draw()
	{
		for ( unsigned int i = 0; i < centipede_->GetCentipede().size(); i++ )
		{
			if ( centipede_->GetCentipede().at ( i ).IsFirstSegment() )
			{
				centipede_->GetCentipede().at ( i ).GetObjectSprite().setTexture (
				    data_->resources.GetTexture ( "Segment sprite" ) );
			}
			else
			{
				centipede_->GetCentipede().at ( i ).GetObjectSprite().setTexture (
				    data_->resources.GetTexture ( "Body Segment sprite" ) );
			}

			centipede_->GetCentipede().at ( i ).GetObjectSprite().setPosition (
			    centipede_->GetCentipede().at ( i ).GetTopLeftXPosition(),
			    centipede_->GetCentipede().at ( i ).GetTopLeftYPosition() );
			data_->window.draw ( centipede_->GetCentipede().at ( i ).GetObjectSprite() );
		}
	}
} // namespace GameEngine
