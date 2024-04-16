#include "Utils.hpp"
#include <sstream>
#include <algorithm>
#include <limits>
#include <iostream>
#include <cctype>

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

    if (!prompt.empty())
    {
        cout << prompt;
    }

    getline(cin, line);

    if (!cin)
    {
        cin.clear();
    }

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

string Utils::toTitleCase(const string &input)
{
    string temp;
    string result;
    bool capitalize = true;

    for (char ch : input)
    {
        if (ch == '_')
        {
            temp += ' ';
        }
        else
        {
            temp += ch;
        }
    }

    for (char ch : temp)
    {
        if (isspace(ch))
        {
            capitalize = true;
            result += ch;
        }
        else
        {
            if (capitalize)
            {
                result += toupper(ch);
                capitalize = false;
            }
            else
            {
                result += tolower(ch);
            }
        }
    }

    return result;
}
