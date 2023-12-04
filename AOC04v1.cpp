#include <bits/stdc++.h>
#include "AOClib.h"

#define turbo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ui uint32_t
#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    turbo
    long sumOfAll = 0;

    while (true) {
        string line;
        vector<string> cards, values, winning_numbers, owned_numbers;

        getline(cin, line);
        
        if (line == "X")
            break;

        // replace all "  " with " "
        ReplaceAll("  ", " ", line);
        
        cards = Split(": ", line);

        cards.erase(cards.begin(), cards.begin() + 1);

        values = Split(" | ", cards[0]);

        winning_numbers = Split(" ", values[0]);

        owned_numbers = Split(" ", values[1]);

        sumOfAll += (int) pow(2, CompareVectors(ConvertVectorStringToInt(winning_numbers), ConvertVectorStringToInt(owned_numbers)) - 1);
    }
    PRINT(sumOfAll);
}