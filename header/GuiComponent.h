#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <algorithm>
#include <vector>

#include "ResourceManager.h"

/**
 * @brief Main abstract GUI class object.
 * Contains all base methods to manage children & the parent object, for a tree-like GUI structure.
 * 
 */
class GuiComponent : public sf::Drawable, public sf::Transformable
{
public:
	/**
	 * @brief Default Constructor
	 * 
	 * @param r The global resource manager.
	 * 
	 */
	GuiComponent(ResourceManager& r);

	/**
	 * @brief Virtual Destructor
	 * 
	 */
	virtual ~GuiComponent();
	
	/**
	 * @brief Calls this->update(), as well as all childrens' updateRecursive(), updating all child objects with one parent call.
	 * 
	 */
	void updateRecursive();

	/**
	 * @brief Update this & only this object, no children.
	 * 
	 * @remarks Usually only called by updateRecursive(), but no harm should be causable by only calling this. Try not to mix calls. 
	 */
	virtual void update();

	/**
	 * @brief Set this object's parent. Usually called from the parent's addChild() method.
	 * 
	 * @param parent The parent object.
	 */
	void setParent(GuiComponent* parent);

	/**
	 * @brief Get this object's parent.
	 * 
	 * @return GuiComponent* A pointer to the parent object.
	 */
	GuiComponent* getParent();

	/**
	 * @brief Get the combined transformation of this object's parent & all parents above.
	 * 
	 * @return sf::Transform The sum transform of all elements up to the top of the tree.
	 */
	sf::Transform getFullTransform();

	/**
	 * @brief Pushes the object into the vector of children. Also calls setParent() on the child object.
	 * 
	 * @param newChild The child to associate.
	 */
	virtual void addChild(GuiComponent* newChild);
	
	/**
	 * @brief Removes a child from the list of children by name.
	 * 
	 * @param name The child's name to remove.
	 */
	virtual void removeChild(std::string name);

	/**
	 * @brief Completely removes all children.
	 * 
	 */
	virtual void removeChildren();

	/**
	 * @brief Searches & retrieves a child by name, locally. Does not search children of children.
	 * 
	 * @param name The name of the child to search for.
	 * @return GuiComponent* Either the child requested, or nullptr if it doesn't exist.
	 */
	virtual GuiComponent* searchChild(std::string name);

	/**
	 * @brief Searches for children recursively through the whole GUI tree.
	 * 
	 * @param name The name of the child to retrieve.
	 * @return GuiComponent* The child to retrieve, or nullptr if the name is not registered.
	 */
	virtual GuiComponent* searchChildRecursive(std::string name);

	/**
	 * @brief Retrieves the name of this object.
	 * 
	 * @return std::string The name of this object.
	 */
	std::string getName();

	/**
	 * @brief Sets the name.
	 * 
	 * @param newName The new name.
	 */
	void setName(std::string newName);

protected:
	/**
	 * @brief This object's parent.
	 * 
	 */
	GuiComponent* mParent;

	/**
	 * @brief The vector of children.
	 * 
	 */
	std::vector<GuiComponent*> mChildren;
	
private:
	/**
	 * @brief Called by Window.draw(), should draw *this & all children.
	 * 
	 */
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	/**
	 * @brief The internal name of this object.
	 * 
	 */
	std::string mName;
};