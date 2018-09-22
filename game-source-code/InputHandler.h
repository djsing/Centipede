#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "Direction.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <memory>

namespace GameEngine
{
class InputHandler
{
  public:
    InputHandler(DataPtr data);
    void SetControls(sf::Event event);

  private:
    DataPtr _data;
    bool _isShooting;
    Direction _direction;
    bool _isLeft;
    bool _isRight;
    bool _isUp;
    bool _isDown;
};

typedef std::shared_ptr<InputHandler> InputHandlerPtr;
} // namespace GameEngine

#endif