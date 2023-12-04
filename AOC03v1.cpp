#include <bits/stdc++.h>
#include "AOClib.h"

#define turbo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ui uint32_t
#define ll long long
#define ull unsigned long long

#define IS_A_SYMBOL(c) \
(c != '.' && (c < '0' || c > '9'))

using namespace std;

long long CalculateEngineParts(vector<string> vvec);

bool HasAdjacentSymbol(vector<string> vvec, int posX, int posY);

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

    cout << CalculateEngineParts(vvec) << endl;
    
}

long long CalculateEngineParts(vector<string> vvec)
{
    long long sumOfAll = 0;
    int       beginsAt = -1;
    bool      isPartNumber = false;

    for (ui line = 0; line < vvec.size(); line++) {
        for (ui i = 0; i < vvec[line].size(); i++) {
            if (vvec[line][i] >= '0' && vvec[line][i] <= '9') {
                if (beginsAt == -1)
                    beginsAt = i;
                if (!isPartNumber)
                    isPartNumber = HasAdjacentSymbol(vvec, line, i);
            } else {
                if (beginsAt != -1 && isPartNumber)
                        sumOfAll += stoi(vvec[line].substr(beginsAt, i - beginsAt + 1));
                    beginsAt = -1;
                    isPartNumber = false;
            }
            if (i == vvec[line].size() - 1) {
                if (beginsAt != -1 && isPartNumber)
                    sumOfAll += stoi(vvec[line].substr(beginsAt, i - beginsAt + 1));
                beginsAt = -1;
                isPartNumber = false;
            }
        }
    }

    return sumOfAll;
}

bool HasAdjacentSymbol(vector<string> vvec, int posX, int posY)
{
    vector<int> checks = {-1, 0, 1};
    
    int x = posX;
    if (posX - 1 != -1)
        x = posX - 1;

    int limX = posX + 1;
    if (posX + 1 != (int)vvec.size())
        limX = posX + 2;

    for (; x < limX; x++) {
        for (int check : checks) {
            if (posY + check != -1 && posY + check < (int)vvec[x].size()) {
                if (IS_A_SYMBOL(vvec[x][posY+check]))
                    return true;
            }
        }
    }

    return false;
}