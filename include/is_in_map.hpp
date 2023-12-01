#include <unordered_map>
#include <string>

using namespace std;

bool is_in_map(unordered_map<string, int> map, string key)
{
    for (auto pair : map)
    {
        if (pair.first == key)
            return true;
    }
    return false;
}