#include "ResourceManager.h"

sf::Texture* ResourceManager::getTexture(std::string file)
{
	//Call find()
	auto found = mTextures.find(file);

	//If it was not found..
	if(found == mTextures.end())
	{
		//Initialize the element in the map...
		mTextures[file] = sf::Texture();

		//Throw if not initialized.
		if (!mTextures[file].loadFromFile(file))
			throw "-- Exception: Could not load file: -- \n" + file;

		//And return a pointer to it.
		return &mTextures[file];
	}
	else //If it was found...
	{
		//Return the found texture.
		return &(found->second);
	}
}

sf::Font* ResourceManager::getFont(std::string file)
{
	//Call find()
	auto found = mFonts.find(file);

	//If it was not found...
	if(found == mFonts.end())
	{
		//Init the element in the map & return a pointer.
		mFonts[file] = sf::Font();
		
		if (!mFonts[file].loadFromFile(file))
			throw "-- Exception: Could not load file: -- \n" + file;

		return &mFonts[file];
	}
	else //If it was found, return it.
	{
		return &(found->second);
	}
}