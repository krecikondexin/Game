#include "TibiaGameobject.h"

TGC::Gameobject::Gameobject()
{
	uid = UtilityTools::UniqueIDGenerator::getInstance().next();
	
}

void TGC::Gameobject::update(const double dt)
{

}

sf::Vector2<size_t> TGC::Gameobject::getPosition() const
{
	return position;
}
void TGC::Gameobject::setPosition(sf::Vector2<size_t> newPosition)
{

	position = newPosition;
}

size_t TGC::Gameobject::getID()
{
	return uid;
}

void TGC::Gameobject::setTexture(std::shared_ptr<sf::Texture> texture)
{
	this->texture = texture;
}

void TGC::Gameobject::draw(sf::RenderWindow& renderWindow)
{
	/*
	if (texture)
	{
		return;
	}
	*/
	sf::RectangleShape rect;
	rect.setFillColor(sf::Color::White);
	rect.setPosition(sf::Vector2f(static_cast<double>(position.x) * 32, static_cast<double>(position.y) * 32));
	rect.setSize(sf::Vector2f(32, 32));
	renderWindow.draw(rect);
}
