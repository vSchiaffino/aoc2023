#include <vector>
#include <functional>
using namespace std;

template <typename T>
class Matrix
{
private:
public:
    vector<vector<T>> grid;
    Matrix(int row_size, int col_size)
    {
        for (int i = 0; i < row_size; i++)
        {
            vector<T> row;
            for (int j = 0; j < col_size; j++)
            {
                row.emplace_back();
            }
            grid.push_back(row);
        }
    }

    T get(int row, int col)
    {
        if (row >= this->grid.size() || col >= this->grid[0].size() || row < 0 || col < 0)
        {
            throw std::invalid_argument("out of bounds");
        }
        return grid.at(row).at(col);
    }

    void set(int row, int col, T val)
    {
        grid[row][col] = val;
    }
};