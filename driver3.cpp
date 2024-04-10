
#include <vector>
#include <iostream>

using namespace std;
int main()
{
    vector<int> integer = {0, 1, 2, 3};

    for (auto a = 0; a < integer.size(); ++a)
    {

        if (integer[a] == 2)
        {
            integer.push_back(4);
        }
        if (integer[a] == 4)
        {
            integer.push_back(6);
        }
        cout << integer[a] << endl;
    }
}