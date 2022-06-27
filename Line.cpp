#include "Line.h"

sf::Vector2f Line::getStartPoint() const
{
	return this->verteces[0].position;
}

sf::Vector2f Line::getEndPoint() const
{
	return this->verteces[1].position;
}

void Line::setStartPoint(const sf::Vector2f& start_point)
{
	this->verteces[0].position = start_point;
}

void Line::setEndPoint(const sf::Vector2f& end_point)
{
	this->verteces[1].position = end_point;
}



void Line::setColor(const sf::Color& color)
{
	this->verteces[0].color = color;
	this->verteces[1].color = color;

}

void Line::setStartColor(const sf::Color& color)
{
	this->verteces[0].color = color;
}

void Line::setEndColor(const sf::Color& color)
{
	this->verteces[1].color = color;
}

void Line::moveStart(const sf::Vector2f& vect)
{
	this->verteces[0].position += vect;
}

void Line::moveEnd(const sf::Vector2f& vect)
{
	this->verteces[1].position += vect;
}

sf::Color Line::getStartColor() const
{
	return this->verteces[0].color;
}

sf::Color Line::getEndColor()
{
	return this->verteces[1].color;
}

void Line::draw(sf::RenderTarget& window, sf::RenderStates states) const
{

	window.draw(this->verteces,states);
	//window.draw(reinterpret_cast<sf::Vertex*>(const_cast<Line*>(this)), 2, sf::Lines, states);
}
