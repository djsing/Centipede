#include "DEFINITIONS.h"
#include "GamePlay.h"
#include "MainMenu.h"

namespace GameEngine
{
MainMenu::MainMenu(DataPtr data) : data_(data)
{
    data_->window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), WINDOW_TITLE, sf::Style::None);
    data_->window.setVerticalSyncEnabled(true);
    data_->window.setPosition(sf::Vector2i(sf::VideoMode().getDesktopMode().width / 3, 0));
    renderer_ = std::make_unique<StateRenderer>(data_);
}

void MainMenu::HandleInput()
{
    sf::Event event;

    while(data_->window.pollEvent(event) && event.type == sf::Event::KeyPressed)
	{
	    if(event.key.code == sf::Keyboard::Escape)
		{
		    data_->window.close();
		}

	    else if(event.key.code == sf::Keyboard::Space)
		{
		    // if player presses space, start game
		    data_->statehandler.AddState(StatePtr(new GamePlay(data_)));
		}
	}
}

void MainMenu::Update(float dt)
{
}

void MainMenu::Draw()
{
    // clear screen to update data
    data_->window.clear();
    renderer_->DisplayMenu();
    // display updated data
    data_->window.display();
}
}  // namespace GameEngine
