#include <bits/stdc++.h>

using namespace std;

#define IS_NUMERIC(c) (c >= '0' && c <= '9')

char buffer[500];

vector<string> Split(const string delimiter, const string source)
// splits source string on a given delimiter
// returns a vector of source's substrings
{
    vector<string> output;
    string         temp = source;
    size_t         pos = 0;

    // check if either input string is empty
    if (source.size() == 0 || delimiter.size() == 0)
    {
        sprintf(buffer, "AOClib::Split neither argument can be an empty string");
        throw std::invalid_argument(buffer);
    }

    while ((pos = temp.find(delimiter)) != std::string::npos)
    {
        output.push_back(temp.substr(0, pos));
        temp.erase(0, pos + delimiter.length());
    }
    output.push_back(temp);

    return output;
}

int SearchFor(const auto value, const vector<auto> target)
// searches for a given value in target
// returns -1 if target does not conatain given value
// returns positive int if value is found (position of first encounter)
{
    // check if target vector is empty
    if (target.size() == 0)
    {
        sprintf(buffer, "AOClib::SearchFor cannot look for a value in empty vector");
        throw std::invalid_argument(buffer);
    }
    // check if value is of the same type as arguments stored in target vector
    if (typeid(value) != typeid(target[0]))
    {
        sprintf(buffer, "AOClib::SearchFor cannot look for type->%s in vector<type->%s>",
                typeid(value).name(), typeid(target[0]).name());
        throw std::invalid_argument(buffer);
    }

    for (unsigned int pos; pos < target.size(); pos++)
        if (target[pos] == value)
            return pos;

    return -1;
}

int RemoveSubstrings(const string substring, string *target)
// removes all occurrences of a given substring in target
// returns count of occurrences of substring in target
{
    string output;

    // check if target string is null
    if (target == NULL)
    {
        sprintf(buffer, "AOClib::RemoveSubstrings target cannot be null");
        throw std::invalid_argument(buffer);
    }
    // check if either input string is empty
    if (substring.size() == 0 || target->size() == 0)
    {
        sprintf(buffer, "AOClib::RemoveSubstrings neither argument can be an empty string");
        throw std::invalid_argument(buffer);
    }

    vector<string> vec = Split(substring, *target);

    for (string it : vec)
        output.append(it);
    
    *target = output;

    return vec.size()-1;
}

void PrintVector(vector<auto> vec)
// prints a vector
{
    for (auto &it : vec)
        cout << it;
    cout << endl;
}

int FindNumberInString(string str, int pos)
// returns number found at given position in str
{
    unsigned int begin = -1;
    unsigned int end = -1;

    // check if char at pos exists in str
    if (pos < 0 || pos >= (int)str.size())
    {
        sprintf(buffer, "AOClib::FindNumberInString pos cannot be less then 0 and bigger than str.size()");
        throw std::invalid_argument(buffer);
    }
    // check if char in str at pos (str[pos]) is a numeric value
    if (!IS_NUMERIC(str[pos]))
    {
        sprintf(buffer, "AOClib::FindNumberInString str[pos] must be a numeric value");
        throw std::invalid_argument(buffer);
    }
    
    for (int i = pos; i >= 0; i--)
        if (IS_NUMERIC(str[i]))
            begin = i;
        else break;

    for (unsigned int i = pos; i < str.size(); i++)
        if (IS_NUMERIC(str[i]))
            end = i;
        else break;
    
    return stoi(str.substr(begin, end - begin + 1));
}

bool IsInBounds(int pos, vector<auto> vector)
// checks if pos fits in bounds of a given vector
{
    return pos >= 0 && pos <= (int)vector.size() - 1;
}

bool IsInBounds(int pos, string str)
// checks if pos first in bounds of a given string
{
    return pos >= 0 && pos <= (int)str.size() - 1;
}

int FindChar(vector<string> vector2D, int posX, int posY, int radius, vector<char> chars_to_find)
// seg fault
{
    unsigned int found_count = 0;
    vector<int>  rangeX, rangeY;
    int          floor, celling;

    floor = (IsInBounds(posX - radius, vector2D)) ? 0 - radius : 0;
    celling = (IsInBounds(posX + radius, vector2D)) ? radius : vector2D.size() - 1;

    for (int i = floor; i <= celling; i++)
        rangeX.push_back(i);

    floor = 0; celling = 0;

    floor = (IsInBounds(posY - radius, vector2D[0])) ? 0 - radius : 0;
    celling = (IsInBounds(posY + radius, vector2D[0])) ? radius : vector2D[0].size() - 1;

    for (int i = floor; i < celling; i++)
        rangeY.push_back(i);

    try {
    for (int x : rangeX)
        for (int y : rangeY)
            if (std::find(chars_to_find.begin(), chars_to_find.end(), vector2D[x][y]) != chars_to_find.end())
                found_count++;
    } catch (...) {
        cout << "here" << endl;
    }
    return found_count;
}