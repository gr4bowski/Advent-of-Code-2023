#include <bits/stdc++.h>

using namespace std;

#define IS_NUMERIC(c) (c >= '0' && c <= '9')
#define PRINT(val) std::cout << std::endl << val << std::endl; 

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

    return std::find(target.begin(), target.end(), value);
}

int RemoveSubstrings(const string substring, string &target)
// removes all occurrences of a given substring in target
// returns count of occurrences of substring in target
{
    string output;

    if (substring.size() == 0 || target.size() == 0)
    {
        sprintf(buffer, "AOClib::RemoveSubstrings neither argument can be an empty string");
        throw std::invalid_argument(buffer);
    }

    vector<string> vec = Split(substring, target);

    for (string it : vec)
        output.append(it);
    
    target = output;

    return vec.size()-1;
}

void PrintVector(const vector<auto> vec)
// prints a vector
{
    for (auto &it : vec)
        cout << it;
    cout << endl;
}

int FindNumberInString(const string str, const int pos)
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

bool IsInBounds(const int pos, const vector<auto> vector)
// checks if pos fits in bounds of a given vector
{
    return pos >= 0 && pos <= (int)vector.size() - 1;
}

bool IsInBounds(const int pos, const string str)
// checks if pos first in bounds of a given string
{
    return pos >= 0 && pos <= (int)str.size() - 1;
}

int FindCharsInRadius(const vector<string> vector2D, const int posX, const int posY, const int radius, const vector<char> chars_to_find)
// looks through vector<string> for given chars in given radius away from point(posX, posY)
// returns the ammount of chars found
// all strings in vector2D should be of the same length
{
    unsigned int count = 0;
    vector<int>  rangeX, rangeY;
    int          floor, celling;

    // check if either input array is empty
    if (vector2D.size() == 0 || vector2D[0].size() == 0)
    {
        sprintf(buffer, "AOClib::FindChar neither vector nor strings inside can be empty");
        throw std::invalid_argument(buffer);
    }
    // check if there are given characters to search for
    if (chars_to_find.size() == 0)
    {
        sprintf(buffer, "AOClib::FindChar chars_to_find vector cannot be empty");
        throw std::invalid_argument(buffer);       
    }
    // check if radius and all positions are greater than 0
    if (posX < 0 || posY < 0 || radius < 0)
    {
        sprintf(buffer, "AOClib::FindChar all positions and radius must be greater than 0");
        throw std::invalid_argument(buffer);  
    }

    floor = (IsInBounds(posX - radius, vector2D)) ? 0 - radius : 0 - posX;
    celling = (IsInBounds(posX + radius, vector2D)) ? radius : vector2D.size() - 1 - posX;

    for (int i = floor; i <= celling; i++)
        rangeX.push_back(i);

    floor = 0; celling = 0;

    floor = (IsInBounds(posY - radius, vector2D[0])) ? 0 - radius : 0 - posY;
    celling = (IsInBounds(posY + radius, vector2D[0])) ? radius : vector2D[0].size() - 1 - posY;

    for (int i = floor; i <= celling; i++)
        rangeY.push_back(i);

    for (int x : rangeX)
        for (int y : rangeY)
            if (std::find(chars_to_find.begin(), chars_to_find.end(), vector2D[posX + x][posY + y]) != chars_to_find.end())
                count++;

    return count;
}

// TO BE TESTED
bool ArePartOfOneNumber(const unsigned int posA, const unsigned int posB, const string str)
// checks if numbers at posA and posB are both part of the same number
// returns false if a non-numeric value is found anywhere between posA & posB 
// returns true if posA == posB or if none non-numeric values are found in between
{
    // check if string str is not empty
    if (str.size() == 0)
    {
        sprintf(buffer, "AOClib::ArePartOfOneNumber input string cannot be empty");
        throw std::invalid_argument(buffer);     
    }
    // check if both positions fit into given string
    if (!IsInBounds(posA, str) || !IsInBounds(posB, str))
    {
        sprintf(buffer, "AOClib::ArePartOfOneNumber both posA and posB must fit into the given string");
        throw std::invalid_argument(buffer);     
    }
    // check if there are numbers at both positions in given string
    if (!IS_NUMERIC(str[posA]) || !IS_NUMERIC(str[posB]))
    {
        sprintf(buffer, "AOClib::ArePartOfOneNumber there must be numeric values at both positions in the given string");
        throw std::invalid_argument(buffer);     
    }

    if (posA == posB)
        return true;
    else if (posA < posB) {
        for (unsigned int i = posA; i <= posB; i++)
            if (!IS_NUMERIC(str[i]))
                return false;
    }
    else if (posA > posB) {
        for (unsigned int i = posB; i <= posA; i++)
            if (!IS_NUMERIC(str[i]))
                return false;
    }

    return true;
}

static int CompareVectors(const vector<auto> vecA, const vector<auto> vecB)
{
    unsigned int count = 0;

    // check if both vectors are non-empty
    if (vecA.size() == 0 || vecB.size() == 0)
    {
        sprintf(buffer, "AOClib::CompareVectors neither vector can be empty");
        throw std::invalid_argument(buffer);
    }
    // check if both vectors contain the variable type
    if (typeid(vecA[0]) != typeid(vecB[0]))
    {
        sprintf(buffer, "AOClib::CompareVectors both vectors must contain same variable types");
        throw std::invalid_argument(buffer);
    }

    for (auto &it : vecA)
        if (std::find(vecB.begin(), vecB.end(), it) != vecB.end())
            count++;

    return count;
}

static inline void ReplaceAll(const string from, const string to, string &str)
// replaces all occurrences of substring <from> with substring <to> 
{
    size_t pos = 0;

    // check if from is a non-empty string
    if (from.size() == 0)
    {
        sprintf(buffer, "AOClib::ReplaceAll string from cannot be empty");
        throw std::invalid_argument(buffer);
    }

    while ((pos = str.find(from, pos)) != std::string::npos) {
        str.replace(pos, from.length(), to);
        pos += to.length();
    }
}

static vector<int> ConvertVectorStringToInt(vector<string> vec)
// converts a vector of numeric strings to a vector of intigers
{
    vector<int> output;

    for (string str : vec)
        output.push_back(stoi(str));
    
    return output;
}