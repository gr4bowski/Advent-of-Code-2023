using namespace std;

char buffer[500];

vector<string> Split(const string delimiter, const string source)
// splits source string on a given delimiter 
{
    vector<string> output;
    string         temp = source;
    size_t         pos = 0;


    // check if either input string is empty
    if (source.size() == 0 || delimiter.size() == 0)
        throw std::invalid_argument("AOClib::Split neither argument can be an empty string");


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