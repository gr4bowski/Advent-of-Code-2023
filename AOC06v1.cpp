#include <bits/stdc++.h>
#include "AOClib.h"

#define turbo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ui uint32_t
#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    turbo
    vector<int> time, distance;
    long long MulOfAll = 1;

    while (true) {
        vector<string> temp_vstr;
        vector<int> temp_vint;
        string temp_str, line;

        getline(cin, line);
        
        if (line == "X")
            break;

        temp_vstr = Split(": ", line);

        temp_str = temp_vstr[0];
        line = temp_vstr[1];
        
        EraseLeadingSpaces(line);

        while (ReplaceAll("  ", " ", line) > 0);

        temp_vstr = Split(" ", line);

        temp_vint = ConvertVectorStringToInt(temp_vstr);
        
        if (temp_str[0] == 'T') {
            time = temp_vint;
        }
        else if (temp_str[0] == 'D') {
            distance = temp_vint;
        }
        temp_vint.clear();
    }

    // O(n^2)   X D
    for (ui race = 0; race < time.size(); race++)
        for (int i = 0; i < time[race]; i++) {
            if (((time[race] - (i + 1)) * (i + 1)) > distance[race]) {
                MulOfAll *= (time[race] - 2 * i) - 1;
                break;
            }
        }
    
    PRINT(MulOfAll);
}