#include <iostream>
#include <unordered_map>
#include "include/read_lines.hpp"
#include "include/include_string.hpp"
#include "include/split.hpp"

using namespace std;

int main()
{
    unordered_map<string, int> max_q = {
        {"red", 12},
        {"green", 13},
        {"blue", 14},
    };
    vector<string> lines = read_lines(cin);
    int sum = 0;
    for (auto line : lines)
    {
        auto first_split = split(line, ": ");
        auto game_id_split = split(first_split[0], " ");
        auto id = stoi(game_id_split[1]);
        auto sets = split(first_split[1], "; ");
        bool can = true;
        for (string set_string : sets)
        {
            unordered_map<string, int> q_in_this_set = {
                {"red", 0},
                {"green", 0},
                {"blue", 0},
            };
            auto reveals = split(set_string, ", ");
            for (string reveal : reveals)
            {
                auto revealing_part = split(reveal, " ");
                int q = stoi(revealing_part[0]);
                string color = revealing_part[1];
                q_in_this_set[color] += q;
                if (q_in_this_set[color] > max_q[color])
                {
                    can = false;
                    break;
                }
            }
            if (can == false)
                break;
        }
        if (can == true)
        {
            cout << id << endl;
            sum += id;
        }
    }
    cout << endl
         << sum << endl;
    return 0;
}