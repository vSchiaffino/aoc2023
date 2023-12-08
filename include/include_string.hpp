#include <string>
using namespace std;

bool include_string(string all_string, string part_to_include)
{
    for (size_t i = 0; i < all_string.size() - part_to_include.size() + 1; i++)
    {
        if (all_string.substr(i, part_to_include.size()) == part_to_include)
            return true;
    }
    return false;
}