#ifndef __UTILS_HPP_
#define __UTILS_HPP_

#include <vector>
#include <string>
using namespace std;

class Utils
{
public:
    static vector<string> splitString(const string &, const char &);
    static string removeSpaces(const string &);
    static string readLine(const string &);
    static string toTitleCase(const string &);
    static string toLower(string);
};

#endif