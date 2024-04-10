#include "RecipeConfig.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

RecipeConfig::RecipeConfig(){
    this->id = -1;
    this->name = "";
    this->code = "";
    this->price = 0;
}

RecipeConfig::RecipeConfig(int id, string name, string code, int price, map<string, int> materials){
    this->id = id;
    this->name = name;
    this->code = code;
    this->price = price;
    this->materials = materials;
}

RecipeConfig::~RecipeConfig(){

}


ostream& operator<<(ostream& os, map<string,RecipeConfig>& recipe){
    cout << "Resep bangunan yang ada adalah sebagai berikut." << endl;
    for (auto itr = recipe.begin(); itr != recipe.end(); itr++)
    {
        cout << "   " << itr->second.id << ". " << itr->second.name << "(" << itr->second.price << " gulden, ";
        int ctr = 0;
        for (auto material : itr->second.materials)
        {
            cout << material.first << " " << material.second;
            if (ctr < int(itr->second.materials.size()))
            {
                cout << ",";
            }
            ctr++;
        }
        cout << ")" << endl;
    }

    return os;
}
