#include <bits/stdc++.h>

#define turbo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ui uint32_t
#define ll long long
#define ull unsigned long long

#define RED "red"
#define GREEN "green"
#define BLUE "blue"

using namespace std;

int main() {
    turbo
    string s, g;
    ull sumOfAll = 0;

    while (true) {
        cin >> g;

        if (g.find("#") != std::string::npos)
            break;

        ui game; cin >> game;

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

        ui HIGH_RED{0}, HIGH_GREEN{0}, HIGH_BLUE(0);
        for (auto it : sets) { // For all games
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
                if (color == RED)   
                    if (HIGH_RED < quantity)
                        HIGH_RED = quantity;
                if (color == GREEN)   
                    if (HIGH_GREEN < quantity)
                        HIGH_GREEN = quantity;
                if (color == BLUE)   
                    if (HIGH_BLUE < quantity)
                        HIGH_BLUE = quantity;
                }
        }
        ull powerOfMin = HIGH_RED * HIGH_GREEN * HIGH_BLUE;
        sumOfAll += powerOfMin;
    }
    cout << sumOfAll << endl;
}
