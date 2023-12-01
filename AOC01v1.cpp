#include <bits/stdc++.h>

#define turbo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ui uint32_t
#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    turbo
    ll sumOfAll = 0;

    while (true){
        vector<int> ints;
        string s; cin >> s;
        int value = 0;

        if (s == "#")
            break;

        for (ui i=0; i < s.size(); i++) {
            char *temp;
            temp = &s[i];
            string strToCheck = temp;
            if (s[i] >= '1' && s[i] <= '9')
                ints.push_back(s[i] - '0');
            else if (strToCheck.find("one") == 0) {
                ints.push_back(1);
            }
            else if (strToCheck.find("two") == 0) {
                ints.push_back(2);
            }
            else if (strToCheck.find("three") == 0) {
                ints.push_back(3);
            }
            else if (strToCheck.find("four") == 0) {
                ints.push_back(4);
            }
            else if (strToCheck.find("five") == 0) {
                ints.push_back(5);
            }
            else if (strToCheck.find("six") == 0) {
                ints.push_back(6);
            }
            else if (strToCheck.find("seven") == 0) {
                ints.push_back(7);
            }
            else if (strToCheck.find("eight") == 0) {
                ints.push_back(8);
            }
            else if (strToCheck.find("nine") == 0) {
                ints.push_back(9);
            }

        }
        
        if (!ints.empty())
            value += ints[0] * 10 + ints.back();
        sumOfAll += value;
        ints.clear();
        value = 0;
    }
    cout << sumOfAll << endl;
}