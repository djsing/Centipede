#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML/Graphics/Texture.hpp>
#include <map>

namespace GameEngine
{
/**
 * @class TextureFileNotFound
 * @author Darrion Singh and Sachin Govender
 * @date 07/10/2018
 * @file ResourceManager.h
 * @brief Empty class used to throw an exception when a texture file is not found.
 */
class TextureFileNotFound
{
};
/**
 * @class ResourceManager
 * @author Darrion Singh and Sachin Govender
 * @date 07/10/2018
 * @file ResourceManager.h
 * @brief Handles the loading and retrieving of Texture files.
 */
class ResourceManager
{
   public:
    // load textures
    void LoadTexture(std::string name, std::string fileName);
    sf::Texture& GetTexture(std::string name);

   private:
    std::map<std::string, sf::Texture> _textures;
};
}  // namespace GameEngine

#endif