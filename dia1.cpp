#include <iostream>
#include <unordered_map>
#include "include/read_lines.hpp"
#include "include/filter_string.hpp"
#include "include/is_in_map.hpp"

using namespace std;
unordered_map<string, int> str_digit_map = {
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9},
};

int main()
{
    vector<string> lines = read_lines(cin);
    int sum = 0;
    for (auto line : lines)
    {
        int first = -1;
        int last;
        for (size_t i = 0; i < line.size(); i++)
        {
            char c = line.at(i);
            bool is_digit = isdigit(c);
            bool is_three_digit_str = is_in_map(str_digit_map, line.substr(i, 3));
            bool is_four_digit_str = is_in_map(str_digit_map, line.substr(i, 4));
            bool is_five_digit_str = is_in_map(str_digit_map, line.substr(i, 5));
            bool is_digit_str = is_three_digit_str || is_four_digit_str || is_five_digit_str;
            int n;
            if (is_digit || is_digit_str)
            {
                int digits = is_three_digit_str ? 3 : is_four_digit_str ? 4
                                                                        : 5;
                string n_str = is_digit ? string(1, c) : line.substr(i, digits);
                n = is_digit ? stoi(n_str) : str_digit_map[n_str];
                if (first == -1)
                    first = n;
                last = n;
            }
        }
        sum += (first * 10 + last);
    }
    cout << sum << endl;
    return 0;
}