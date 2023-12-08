#include <string>
#include <vector>
using namespace std;

vector<string> split(string line, string separator)
{
    vector<string> result;
    size_t pos = 0;
    size_t found;

    while ((found = line.find(separator, pos)) != string::npos)
    {
        result.push_back(line.substr(pos, found - pos));
        pos = found + separator.length();
    }

    result.push_back(line.substr(pos));

    return result;
}