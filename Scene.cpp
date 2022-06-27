#include "Scene.h"

void Scene::fromGameToTable()
{
	for (int i = 0; i < this->game.getRowsCount(); ++i) 
	{
		for (int j = 0; j < this->game.getColoumsCount(); ++j) 
		{
			if (this->game.at(i,j) == Game::CellType::Alive)
			{
				this->table.at(i, j) = this->alive_color;
			}
			else
			{
				this->table.at(i, j) = this->dead_color;
			}
		}
	}
}

void Scene::setDeadAt(const int& i, const int& j)
{
	this->table.at(i,j) = this->dead_color;
	this->game.setDeadAt(i, j);
}

void Scene::setAlliveAt(const int& i, const int& j)
{
	this->table.at(i, j) = this->alive_color;
	this->game.setAlliveAt(i,j);
}

sf::Vector2i Scene::getCoordsByPoos(const sf::Vector2f& pos)
{
	return this->table.GetCoordByPos(pos);
}

void Scene::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
	for (auto& i : another_obj)
	{
		window.draw(i.operator*(), states);
	};
	window.draw(table, states);
}

void Scene::update()
{
	this->fromGameToTable();
	this->game.next();
}
