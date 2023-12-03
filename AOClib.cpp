using namespace std;

char buffer[500];

vector<string> split(const string source, const string delimiter)
{
    vector<string> output;
    string         temp = source;
    size_t         pos = 0;

    if (source.size() == 0 || delimiter.size() == 0)
        throw std::invalid_argument("string.split neither argument can be an empty string");

    while ((pos = temp.find(delimiter)) != std::string::npos) {
        output.push_back(temp.substr(0, pos));
        temp.erase(0, pos + delimiter.length());
    }
    output.push_back(temp);

    return output;
}

bool isInVec(const auto searchFor, const vector<auto> target)
{
    if (target.size() != 0 && typeid(searchFor) != typeid(target[0]))
    {
        sprintf(buffer, "isInVec cannot look for %s in vector<%s>", typeid(searchFor).name(), typeid(target[0]).name());
        throw std::invalid_argument(buffer);
    }

    for (auto it : target)
        if (it == searchFor)
            return 1;
    return 0;
}