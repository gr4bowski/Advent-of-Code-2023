#include "AOClib.cpp"

vector<string> Split(const string delimiter, const string source);

int SearchFor(const auto value, const vector<auto> target);

int RemoveSubstrings(const string substring, string *target);

void PrintVector(vector<auto> vec);

int FindNumberInString(string str, int pos);

int FindChar(vector<string> vector2D, int posX, int posY, int radius, vector<char> chars_to_find);

#define FindAdjacentChar(vector2D, posX, posY, chars_to_find) FindChar(vector2D, posX, posY, 1, chars_to_find)