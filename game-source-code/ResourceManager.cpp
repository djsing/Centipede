#include "ResourceManager.h"

namespace GameEngine
{
void ResourceManager::LoadTexture(std::string name, std::string fileName)
{
    sf::Texture tex;
    if(tex.loadFromFile(fileName))
	{
	    _textures[name] = tex;
	}
    else
	throw TextureFileNotFound{};
}

sf::Texture& ResourceManager::GetTexture(std::string name)
{
    return _textures.at(name);
}
}  // namespace GameEngine