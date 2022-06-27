#pragma once
#include <vector>
#include <iostream>

class Game
{
enum class CellType;
using matrix_cell_t = std::vector<std::vector<CellType>>;
using vector_cell_t = std::vector<CellType>;
private:
	matrix_cell_t matrix;
	matrix_cell_t next_frame;
	static void CopyMatrix( matrix_cell_t& m1,  matrix_cell_t& m2);
public:
	enum class CellType
	{
		Alive,
		Dead
	};
	Game(const matrix_cell_t& matrix,
		const bool& horizontal_closed = false,
		const bool& vertical_closed = false) :
		matrix(matrix)
		
	{
	};
	Game(const int& rows_count, const int& coloums_count) :
		matrix(rows_count, vector_cell_t(coloums_count, CellType::Dead)),
		next_frame(rows_count, vector_cell_t(coloums_count, CellType::Dead))
	{
	};
	void setAlliveAt(const int& i, const int& j);
	void setDeadAt(const int& i, const int& j);
	int getRowsCount();
	int getColoumsCount();
	Game::CellType& at(const int& i, const int& j);
	int getCountOfNbrs(const int& y, const int& x);
	void next();
	friend std::ostream& operator<<(std::ostream& stream, const Game& game);
};

