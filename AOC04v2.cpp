#include <bits/stdc++.h>
#include "AOClib.h"

#define turbo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ui uint32_t
#define ll long long
#define ull unsigned long long

#define GAMES_MAX 200

using namespace std;

int main() {
    //turbo
    long sumOfAll = 0;
    unsigned int game = -1;
    vector<int> multiplicator(GAMES_MAX, 1);

    while (true) {
        string line;
        vector<string> cards, values, winning_numbers, owned_numbers;
        unsigned int cards_won = 0;

        getline(cin, line);
        
        if (line == "X")
            break;
        else
            game++;

        ReplaceAll("  ", " ", line);
        
        cards = Split(": ", line);

        cards.erase(cards.begin(), cards.begin() + 1);

        values = Split(" | ", cards[0]);

        winning_numbers = Split(" ", values[0]);

        owned_numbers = Split(" ", values[1]);

        cards_won = CompareVectors(ConvertVectorStringToInt(winning_numbers), ConvertVectorStringToInt(owned_numbers));

        for (unsigned int i = 1; i <= cards_won; i++)
            multiplicator[game + i] += multiplicator[game];
    
        sumOfAll += multiplicator[game];
    }
    PRINT(sumOfAll);
}