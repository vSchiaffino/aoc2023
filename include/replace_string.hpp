#include <string>
using namespace std;

string replace_all_strings(string original, string find, string replace)
{
    string new_string;
    new_string.assign(original);
    for (int i = 0; i < original.size() - find.size(); i++)
    {
        if (original.substr(i, find.size()) == find)
        {
            new_string.erase(i, find.size());
            new_string.insert(i, replace);
        }
    }
    return new_string;
}