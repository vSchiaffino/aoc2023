#include <iostream>
#include <unordered_map>
#include "include/read_lines.hpp"
#include "include/include_string.hpp"
#include "include/split.hpp"

using namespace std;

int main()
{
    vector<string> lines = read_lines(cin);
    int sum = 0;
    for (auto line : lines)
    {
        unordered_map<string, int> max_q = {
            {"red", -1},
            {"green", -1},
            {"blue", -1},
        };
        auto first_split = split(line, ": ");
        auto game_id_split = split(first_split[0], " ");
        auto id = stoi(game_id_split[1]);
        auto sets = split(first_split[1], "; ");
        vector<string> colors = {"red", "green", "blue"};
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
            }
            for (string color : colors)
            {
                if (q_in_this_set[color] > max_q[color])
                    max_q[color] = q_in_this_set[color];
            }
        }
        cout << max_q["red"] << " " << max_q["green"] << " " << max_q["blue"] << endl;
        sum += (max_q["red"] * max_q["green"] * max_q["blue"]);
    }
    cout << endl
         << sum << endl;
    return 0;
}