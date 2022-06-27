#include "Game.h"



void Game::CopyMatrix(matrix_cell_t& m1, matrix_cell_t& m2)
{
    for (int i = 0; i < m2.size(); ++i) 
    {
        for (int j = 0; j < m2[0].size(); ++j) 
        {
            m1[i][j] = m2[i][j];
        }
    }
}

void Game::setAlliveAt(const int& i, const int& j)
{
    this->matrix[i][j] = CellType::Alive;
    this->next_frame[i][j] = CellType::Alive;
}

void Game::setDeadAt(const int& i, const int& j)
{
    this->matrix[i][j] = CellType::Dead;
    this->next_frame[i][j] = CellType::Dead;
}

int Game::getRowsCount()
{
    return this->matrix.size();
}

int Game::getColoumsCount()
{
    return this->matrix[0].size();
}

Game::CellType& Game::at(const int& i, const int& j)
{
    return this->matrix[i][j];
}

int Game::getCountOfNbrs(const int& y, const int& x)
{
    int res = 0;
    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            if (!(j == 0 && i == 0) && !(j + x < 0 || j + x>=this->matrix[0].size()) && !(i + y < 0 || i + y>=this->matrix.size()) )
            {
                if (this->matrix[i + y][j + x] == CellType::Alive) 
                {
                    //std::cout << i + y<< ' ' << j + x<< std::endl;
                    res++;
                }
            }
        }
    }
    return res;
};
void Game::next()
{
    
    this->CopyMatrix(this->next_frame,this->matrix);
    //std::swap(this->matrix,this->next_frame);
    
    for (int i = 0; i < this->matrix.size(); ++i)
    {
        for (int j = 0; j < this->matrix[0].size(); ++j)
        {
            const int nbrs_count = this->getCountOfNbrs(i, j);
            if (nbrs_count < 2 || nbrs_count > 3)
            {
                if (this->matrix[i][j] != CellType::Dead)
                {
                    this->next_frame[i][j] = CellType::Dead;
                }
            }
            else if (nbrs_count == 3)
            {
                if (this->matrix[i][j] != CellType::Alive)
                {
                    this->next_frame[i][j] = CellType::Alive;
                }
            }

        }
    }
    std::swap(this->matrix,this->next_frame);
    //
    /*this->matrix = this->next_frame;*/
}


std::ostream& operator<<(std::ostream& stream, const Game& game)
{
    for (int i = 0; i < game.matrix.size(); ++i) 
    {
        for (int j = 0; j < game.matrix[0].size(); ++j) 
        {
            if (game.matrix[i][j] == Game::CellType::Alive) 
            {
                stream << '#';
            }
            else if (game.matrix[i][j] == Game::CellType::Dead)
            {
                stream << '_';
            }
            else 
            {
                stream << '*';
            }
        }
        stream << std::endl;
    }
    return stream;
}
