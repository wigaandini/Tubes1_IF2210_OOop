#ifndef __ITEM_HPP_
#define __ITEM_HPP_

#include <iostream>
#include <string>
#include "../configClass/PlantConfig.hpp"
#include "../configClass/AnimalConfig.hpp"
#include "../configClass/ProductConfig.hpp"
#include "../configClass/RecipeConfig.hpp"

using namespace std;

class Item {
protected:
    static int countIdItem;
    int itemId;
    string name;
    string code;
    int price;

public:
    Item();
    Item(string name, string code, int price);
    virtual ~Item();
    void setItemId(int itemId);
    void setName(string name);
    void setCode(string code);
    void setPrice(int price);
    int getItemId() const;
    string getName() const;
    string getCode() const;
    int getPrice() const;
    bool operator==(const Item&);
    friend ostream& operator<<(ostream&, const Item&);
};

#endif