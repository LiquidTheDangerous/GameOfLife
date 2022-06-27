#pragma once
#include <SFML/Graphics.hpp>


class Line: public sf::Drawable
{
	sf::VertexArray verteces;
public:
	Line(const sf::Vector2f& start_point,
		const sf::Vector2f& end_point,
		const sf::Color& color_start = sf::Color::Black,
		const sf::Color& color_end = sf::Color::Black) :
		verteces(sf::Lines, 2)
	{
		verteces[0].position = start_point;
		verteces[0].color = color_start;
		verteces[1].position = end_point;
		verteces[1].color = color_end;
	};
	Line() :verteces(sf::Lines, 2)
	{
		verteces[0].color = sf::Color::Black;
		verteces[1].color = sf::Color::Black;
	};
	sf::Vector2f getStartPoint() const;
	sf::Vector2f getEndPoint() const;
	void setStartPoint(const sf::Vector2f& start_point);
	void setEndPoint(const sf::Vector2f& end_point);
	void setColor(const sf::Color& color);
	void setStartColor(const sf::Color& color);
	void setEndColor(const sf::Color& color);
	void moveStart(const sf::Vector2f& vect);
	void moveEnd(const sf::Vector2f& vect);
	sf::Color getStartColor() const;
	sf::Color getEndColor();
	virtual void draw(sf::RenderTarget& window, sf::RenderStates states = sf::RenderStates::Default) const override;
};

