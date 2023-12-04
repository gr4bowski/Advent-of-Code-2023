#include "AOClib.cpp"

// TO BE DONE: Grouping functions ex. "string operations", "vector operations"

vector<string> Split(const string delimiter, const string source);

int SearchFor(const auto value, const vector<auto> target);

int RemoveSubstrings(const string substring, string &target);

void PrintVector(const vector<auto> vec);

int FindNumberInString(const string str, const int pos);

int FindCharsInRadius(const vector<string> vector2D, const int posX, const int posY, const int radius, const vector<char> chars_to_find);

// for adjacent search range always = 1
#define FindAdjacentChar(vector2D, posX, posY, chars_to_find) \
        FindCharsInRadius(vector2D, posX, posY, 1, chars_to_find)

bool ArePartOfOneNumber(const unsigned int posA, const unsigned int posB, const string str);

static int CompareVectors(const vector<auto> vecA, const vector<auto> vecB);

static inline void ReplaceAll(const string from, const string to, string &str);

static vector<int> ConvertVectorStringToInt(vector<string> vec);