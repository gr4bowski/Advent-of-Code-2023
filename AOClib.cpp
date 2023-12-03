using namespace std;

char buffer[500];

vector<string> split(const string source, const string delimiter)
{
    vector<string> output;
    string         temp = source;
    size_t         pos = 0;

    if (source.size() == 0 || delimiter.size() == 0)
        throw std::invalid_argument("AOClib::split neither argument can be an empty string");

    while ((pos = temp.find(delimiter)) != std::string::npos)
    {
        output.push_back(temp.substr(0, pos));
        temp.erase(0, pos + delimiter.length());
    }
    output.push_back(temp);

    return output;
}

int searchFor(const auto value, const vector<auto> target)
// returns -1 if vector does not conatain given value in target vector
// returns position on which value is found in target vector
{
    if (target.size() != 0 && typeid(value) != typeid(target[0]))
    {
        sprintf(buffer, "AOClib::isInVec cannot look for %s in vector<%s>", typeid(value).name(), typeid(target[0]).name());
        throw std::invalid_argument(buffer);
    }

    for (unsigned int pos; pos < target.size(); pos++)
        if (target[pos] == value)
            return pos;
    return -1;
}