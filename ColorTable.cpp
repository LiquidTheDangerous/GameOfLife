#include "ColorTable.h"

sf::Color& ColorTable::at(const int& i, const int& j)
{
	return this->matrix_color[i][j];
}

void ColorTable::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
	const float dx = this->getCellLength();
	const float dy = this->getCellHeigth();
	this->rect.setSize({dx,dy});
	for (int i = 0; i < this->rows_count; ++i) 
	{
		for (int j = 0; j < this->coloums_count; ++j) 
		{
			const sf::Color& cell_color = this->matrix_color[i][j];
			this->rect.setPosition({dx*j + this->point_left_top.x,dy * i + this->point_left_top.y});
			this->rect.setFillColor(this->matrix_color[i][j]);
			window.draw(this->rect,states);
		}
	}
	for (int i = 0; i <= this->coloums_count; ++i) 
	{
		this->line.setStartPoint({i*dx + this->point_left_top.x,this->point_left_top.y});
		this->line.setEndPoint({i*dx + this->point_left_top.x,this->point_left_top.y + this->length_wh.y});
		window.draw(line,states);
	}
	for (int i = 0; i <= this->rows_count; ++i)
	{
		this->line.setStartPoint({ this->point_left_top.x,this->point_left_top.y + i * dy });
		this->line.setEndPoint({ this->point_left_top.x + this->length_wh.x,this->point_left_top.y + i * dy });
		window.draw(line,states);
	};


}

sf::Vector2i ColorTable::GetCoordByPos(const sf::Vector2f& pos)
{
	if (pos.x <= this->point_left_top.x || 
		pos.x >= this->point_left_top.x + this->length_wh.x ||
		pos.y <= this->point_left_top.y ||
		pos.y >= this->point_left_top.y + this->length_wh.y) 
	{
		return {npos,npos};
	}
	return {static_cast<int>(static_cast<int>(pos.x - this->point_left_top.x)/ (this->getCellLength())),static_cast<int>(static_cast<int>(pos.y - this->point_left_top.y) / (this->getCellHeigth()))};
}

float ColorTable::getCellLength() const
{
	return this->length_wh.x / this->coloums_count;
}

float ColorTable::getCellHeigth() const
{
	return this->length_wh.y / this->rows_count;
}
