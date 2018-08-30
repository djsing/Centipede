#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>
#include <SFML/Graphics.hpp>

namespace GameEngine
{
	class TextureFileNotFound{};
	class FontFileNotFound{};

	class ResourceManager
	{
	public:
		ResourceManager(){}
		~ResourceManager(){}
		// load textures
		void LoadTexture(std::string name, std::string fileName);
		sf::Texture &GetTexture(std::string name);
		// load fonts
		void LoadFont(std::string name, std::string fileName);
		sf::Font &GetFont(std::string name);
	private:
		std::map<std::string, sf::Texture> _textures;
		std::map<std::string, sf::Font> _fonts;
	};
}

#endif