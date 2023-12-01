#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> read_lines(istream &input)
{
    vector<string> lines;

    while (true)
    {
        string line;
        if (!getline(input, line))
            break;
        size_t last_index = line.size() - 1;
        char last_element = line.at(last_index);
        if (last_element == '\n' || last_element == '\r')
            line.erase(last_index);

        lines.push_back(line);
    }

    return lines;
}