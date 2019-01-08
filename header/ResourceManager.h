#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>

/**
 * @brief Class to manage resources to avoid loading the same file twice.
 * 
 */
class ResourceManager
{
public:
	/**
	 * @brief Get the texture at the specified path. If it is not already loaded, load it with .loadFromFile()
	 * 
	 * @param file The path of the texture to load.
	 * @return sf::Texture* A pointer to the texture.
	 */
	sf::Texture* getTexture(std::string file);

	/**
	 * @brief Get the font at the specified path, or load it if it is not already loaded.
	 * 
	 * @param file The path of the font.
	 * @return sf::Font* A pointer to the font object.
	 */
	sf::Font* getFont(std::string file);

	/**
	 * @brief Template function. Calls rm_init (inherited from GuiComponent) and is intended to load all textures/fonts required by the specified object.
	 * 
	 * @tparam _GC Should be a GUI component or derived class.
	 * @param object The object to initialze.
	 */
	template<typename _GC>
	void initObject(_GC& object)
	{
		object.rm_init(*this);
	}

private:
	/**
	 * @brief Map of all textures, where the key is the filepath.
	 * 
	 */
	std::unordered_map<std::string, sf::Texture> mTextures;

	/**
	 * @brief Map of all fonts, keys = file paths.
	 * 
	 */
	std::unordered_map<std::string, sf::Font> mFonts;
};