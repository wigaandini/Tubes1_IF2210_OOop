#include "Utils.hpp"
#include <sstream>
#include <algorithm>
#include <limits>
#include <iostream>

vector<string> Utils::splitString(const string &input, const char &delimiter)
{
    vector<string> tokens;
    string token;
    istringstream tokenStream(input);

    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}

string Utils::removeSpaces(const string &input)
{
    string result = input;
    result.erase(remove_if(result.begin(), result.end(), ::isspace), result.end());
    return result;
}

string Utils::readLine(const string &prompt)
{
    string line;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (!prompt.empty())
    {
        cout << prompt;
    }

    getline(cin, line);

    if (!cin)
    {
        cin.clear();
    }
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return line;
}
string Utils::toLower(string s)
{
    string snew;
    for (char c : s)
    {
        snew += tolower(c);
    }
    return snew;
}