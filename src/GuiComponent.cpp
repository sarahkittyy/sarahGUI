#include "GuiComponent.h"

GuiComponent::GuiComponent()
{
	
}

GuiComponent::~GuiComponent()
{

}

void GuiComponent::draw(
	sf::RenderTarget& target,
	sf::RenderStates states
	) const
{
	//Derived classes would draw their visual elements here.
	/*IMPORTANT: DERIVED CLASSES SHOULD DRAW ALL THEIR CHILDREN*/
}

void GuiComponent::updateRecursive()
{
	//Update this;
	update();

	//Update all children.
	for(auto &i : mChildren)
	{
		i->updateRecursive();
	}
}

void GuiComponent::update()
{
	//Nothing, derived classes should (but don't have to) inherit & override.
}

void GuiComponent::setParent(GuiComponent* parent)
{
	mParent = parent;
}

GuiComponent* GuiComponent::getParent()
{
	return mParent;
}

void GuiComponent::addChild(GuiComponent* newChild)
{
	//Set the new child's parent to this before pushing it.
	newChild->setParent(this);
	mChildren.push_back(newChild);
}

void GuiComponent::removeChild(std::string name)
{
	//Removes (all) children with a matching name.
	/*
		The ideal world is one in which no two GUI elements have the same name, but yknow--
		*programmers*
	*/
	std::remove_if(mChildren.begin(),
	mChildren.end(),
	[&](GuiComponent*& b)
	{
		return b->getName() == name; 
	});
}

void GuiComponent::removeChildren()
{
	//Yeetus those childrenus.
	mChildren.clear();
}

GuiComponent* GuiComponent::searchChild(std::string name)
{
	//Find the first matching child.
	auto found = std::find_if(
		mChildren.begin(), mChildren.end(),
		[&](GuiComponent*& b)->bool
		{
			return b->getName() == name;
		});
	
	//Return nullptr if the child was not found.
	return (found!=mChildren.end())?(*found):(nullptr);
}

GuiComponent* GuiComponent::searchChildRecursive(std::string name)
{
	//If this is the child, return this.
	if(mName == name)
	{
		return this;
	}
	else if(mChildren.size()) //If this object has children..
	{
		//Iterate through all children.
		for(auto &i : mChildren)
		{
			//Recursively call this function, but from the child.
			auto found = i->searchChildRecursive(name);

			//If the child is found, return it.
			if(found != nullptr)
				return found;
		}
	}
	//No object with the specified name exists anyway.
	return nullptr;
}

void GuiComponent::setName(std::string newName)
{
	mName = newName;
}

std::string GuiComponent::getName()
{
	return mName;
}