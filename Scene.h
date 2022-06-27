#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "Game.h"
#include "ColorTable.h"

class Scene : public sf::Drawable
{
private:
	Game game;
	ColorTable table;
	sf::Color alive_color;
	sf::Color dead_color;
	std::list<std::shared_ptr<sf::Drawable>> another_obj;

	void fromGameToTable();

public:
	Scene(
		const sf::Vector2f& start_point,
		const sf::Vector2f& size,
		const int& rows_count,
		const int& coloums_count,
		const sf::Color& CellAliveColor = sf::Color::Black,
		const sf::Color& CellDeadColor = sf::Color::White) :
		alive_color(CellAliveColor),
		dead_color(CellDeadColor),
		game(rows_count, coloums_count),
		table(rows_count, coloums_count, start_point, size,CellDeadColor)
	{
	};
	void setDeadAt(const int& i, const int& j);
	void setAlliveAt(const int& i, const int& j);
	sf::Vector2i getCoordsByPoos(const sf::Vector2f& pos);
	virtual void draw(sf::RenderTarget& window, sf::RenderStates states = sf::RenderStates::Default) const override;
	void update();

};

