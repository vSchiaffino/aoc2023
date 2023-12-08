#include <functional>
#include <iostream>
#include <tuple>
#include <unordered_map>
#include "include/read_lines.hpp"
#include "include/include_string.hpp"
#include "include/split.hpp"
#include "include/matrix.hpp"

using namespace std;

typedef struct
{
    int row;
    int col_from;
    int col_to;
    int number;
} Finded_number;

int main()
{
    vector<string> lines = read_lines(cin);
    int rows = lines.size();
    int cols = lines[0].size();
    Matrix<char> mat(rows, cols);
    int row = 0;
    for (auto line : lines)
    {
        int col = 0;
        for (char c : line)
        {
            mat.set(row, col, c);
            col++;
        }
        row++;
    }
    int n_row = 0;
    vector<Finded_number> finded_numbers;
    for (auto row : mat.grid)
    {
        bool is_reading_number = false;
        int started_reading = -1;
        string str_number = "";
        int n_col = 0;
        for (auto value : row)
        {
            if (isdigit(value))
            {
                if (!is_reading_number)
                {
                    is_reading_number = true;
                    started_reading = n_col;
                }
                str_number += value;
                // std::cout << string(1, value);
            }
            else
            {
                if (is_reading_number)
                {
                    is_reading_number = false;
                    finded_numbers.push_back({
                        row : n_row,
                        col_from : started_reading,
                        col_to : n_col - 1,
                        number : stoi(str_number)
                    });
                    str_number = "";
                }
            }
            n_col++;
        }
        if (is_reading_number)
        {
            finded_numbers.push_back({
                row : n_row,
                col_from : started_reading,
                col_to : n_col - 1,
                number : stoi(str_number)
            });
        }
        n_row++;
    }

    int sum = 0;
    vector<tuple<int, int>> moves = {
        {-1, 0},
        {-1, 1},
        {-1, -1},
        {1, 0},
        {1, 1},
        {1, -1},
        {0, 1},
        {0, -1},
    };

    for (auto finded_number : finded_numbers)
    {
        // cout << "finded_number " << finded_number.number << " ";
        bool is_valid = false;
        for (int col = finded_number.col_from; col <= finded_number.col_to; col++)
        {
            // cout << col << "(";
            for (auto move : moves)
            {
                // cout << "(" << get<0>(move) << "," << get<1>(move) << ") ";
                try
                {
                    char c_after_move = mat.get(finded_number.row + get<0>(move), col + get<1>(move));
                    // cout << "->" << c_after_move << " ";
                    if (!isdigit(c_after_move) && !(c_after_move == '.'))
                    {
                        is_valid = true;
                        break;
                    }
                }
                catch (const std::invalid_argument &e)
                {
                }
            }
            // cout << ") " << endl;
            if (is_valid)
            {
                break;
            }
        }
        if (is_valid)
        {
            // cout << "Valid number " << finded_number.number << endl;
            sum += finded_number.number;
        }
    }

    cout << endl
         << sum << endl;
    return 0;
}