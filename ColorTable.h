#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Line.h"

template <class T>
using matrix_t = std::vector<std::vector<T>>;
using marix_color_t = matrix_t<sf::Color>;
using vector_color_t = std::vector<sf::Color>;
class ColorTable : public sf::Drawable
{
private:
	mutable Line line;
	mutable sf::RectangleShape rect;

	marix_color_t matrix_color;
	sf::Vector2f point_left_top;
	sf::Vector2f length_wh;
	int rows_count;
	int coloums_count;
public:
	static constexpr auto npos{-1};
	ColorTable(const int& rows_count,
		const int& coloums_count,
		const sf::Vector2f& point_left_top,
		const sf::Vector2f& length_wh,
		const sf::Color& color = sf::Color::White,
		const sf::Color& lines_color = sf::Color::Black) :
		matrix_color(marix_color_t(rows_count, vector_color_t(coloums_count, color))),
		point_left_top(point_left_top),
		rows_count(rows_count),
		coloums_count(coloums_count),
		length_wh(length_wh),
		rect({ this->getCellLength(),this->getCellHeigth() })
	{
		line.setColor(lines_color);
	};

	sf::Color& at(const int& i, const int& j);
	virtual void draw(sf::RenderTarget& window, sf::RenderStates states = sf::RenderStates::Default) const override;
	sf::Vector2i GetCoordByPos(const sf::Vector2f& pos);
	float getCellLength() const;
	float getCellHeigth() const;

};

