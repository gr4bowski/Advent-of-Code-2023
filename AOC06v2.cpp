#include <bits/stdc++.h>
#include "AOClib.h"

#define turbo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ui uint32_t
#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    turbo
    unsigned long time = 0, distance = 0;
    long long MulOfAll = 1;

    while (true) {
        vector<string> temp_vstr;
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

        line = temp_str;

        temp_str = "";
        for (auto &it : temp_vstr)
            temp_str.append(it);

        if (line[0] == 'T') {
            time = stoul(temp_str);
        }
        else if (line[0] == 'D') {
            distance = stoul(temp_str);
        }
        
        temp_str = "";
    }

    // O(n^2)   X D
    for (unsigned long i = 0; i < time/2 + 1; i++)
        if (((time - (i + 1)) * (i + 1)) > distance) {
            MulOfAll *= (time - 2 * i) - 1;
            break;
        }
    
    PRINT(MulOfAll);
}