#include <iostream>
#include "include/read_lines.hpp"
#include "include/filter_string.hpp"

using namespace std;

int main()
{
    auto filter_only_numbers = [](char c)
    { return bool(isdigit(c)); };
    vector<string> lines = read_lines(cin);
    int sum = 0;
    for (auto line : lines)
    {
        string line_only_numbers = filter_string(line, filter_only_numbers);
        string str_number;
        str_number.push_back(line_only_numbers.at(0));
        str_number.push_back(line_only_numbers.at(line_only_numbers.size() - 1));
        int number = stoi(str_number);
        sum += number;
    }
    cout << sum << endl;
    return 0;
}