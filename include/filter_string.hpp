#include <string>
#include <functional>
#include <iostream>
using namespace std;

string filter_string(string original, function<bool(char)> filter)
{
    string filtered;
    for (size_t i = 0; i < original.size(); i++)
    {
        char c = original.at(i);
        if (filter(c))
            filtered.push_back(c);
    }
    return filtered;
}