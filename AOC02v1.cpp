#include <bits/stdc++.h>

#define turbo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ui uint32_t
#define ll long long
#define ull unsigned long long

#define RED "red"
#define GREEN "green"
#define BLUE "blue"

#define RED_QTY 12
#define GREEN_QTY 13
#define BLUE_QTY 14

using namespace std;

bool IsPossible(string color, ui quantity);

int main() {
    turbo
    string s, g;
    ll sumOfAll = 0;

    while (true) {
        bool IMPOSSIBLE = 0;
        cin >> g;

        if (g.find("#") != std::string::npos)
            break;

        ui game; cin >> game;
        sumOfAll += game;

        getline(cin, s);
        s.erase(0, 2);

        size_t pos = 0;
        string delimiter = "; ";
        vector<string> sets;

        while ((pos = s.find(delimiter)) != std::string::npos) {
            sets.push_back(s.substr(0, pos));
            s.erase(0, pos + delimiter.length());
        }
        sets.push_back(s);

        for (auto it : sets) {
            delimiter = ", ";
            pos = 0;
            vector<string> cubes;
            while ((pos = it.find(delimiter)) != std::string::npos) {
                cubes.push_back(it.substr(0, pos));
                it.erase(0, pos + delimiter.length());
            }
            cubes.push_back(it);

            delimiter = " ";
            for (auto cub : cubes) {
                pos = 0;
                ui quantity = 0;
                while ((pos = cub.find(delimiter)) != std::string::npos) {
                    quantity = stoi(cub.substr(0, pos));
                    cub.erase(0, pos + delimiter.length());
                }
                string color = cub;
                if (!IsPossible(color, quantity)) {
                    IMPOSSIBLE = 1;
                    sumOfAll -= game;
                    break;
                }
            }
            if (IMPOSSIBLE)
                break;
        }
    }

    cout << sumOfAll << endl;

}

bool IsPossible(string color, ui quantity) {
    if (color == RED)
        return (quantity <= RED_QTY);
    else if (color == GREEN)
        return (quantity <= GREEN_QTY);
    else if (color == BLUE)
        return (quantity <= BLUE_QTY);
    else
        throw std::invalid_argument("VerifyConstraints color must be either \"red\", \"green\" or \"blue\"!");
    }
