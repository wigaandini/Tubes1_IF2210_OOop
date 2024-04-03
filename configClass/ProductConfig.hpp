#ifndef _PRODUCTCONFIG_HPP_
#define _PRODUCTCONFIG_HPP_

#include <map>
#include <string>
using namespace std;
enum class ProductType{
        PRODUCT_MATERIAL_PLANT,
        PRODUCT_FRUIT_PLANT
    };

class ProductConfig{
public:
    static map<string, ProductConfig> configs;
    int id;
    string name;
    ProductType type;
    string code;
    string origin;
    int addedWeight;
    int price;

    ProductConfig();
    ProductConfig(int id, string name, ProductType type, string code,string origin,int addedWeight,int price);
    ~ProductConfig();
    static void loadConfigFromFile(string filename);
    static ProductConfig getConfigFromName(const string& name);

};






#endif