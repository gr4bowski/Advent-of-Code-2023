#include <bits/stdc++.h>
#include "AOClib.h"

#define turbo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ui uint32_t
#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    turbo
    vector<string> vvec;

    while (true) {
        string line;
        getline(cin, line);
        
        if (line == "X")
            break;

        vvec.push_back(line);
    }
    vector<char> vc = {'*'};
    cout << FindChar(vvec, 1, 1, 1, vc) << endl;
}