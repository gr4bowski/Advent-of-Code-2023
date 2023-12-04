#include "AOClib.cpp"

vector<string> Split(const string delimiter, const string source);

int SearchFor(const auto value, const vector<auto> target);

int RemoveSubstrings(const string substring, string *target);

void PrintVector(const vector<auto> vec);

int FindNumberInString(const string str, const int pos);

int FindChar(const vector<string> vector2D, const int posX, const int posY, const int radius, const vector<char> chars_to_find);

#define FindAdjacentChar(vector2D, posX, posY, chars_to_find) FindChar(vector2D, posX, posY, 1, chars_to_find)

bool ArePartOfOneNumber(const string str, const unsigned int posA, const unsigned int posB);