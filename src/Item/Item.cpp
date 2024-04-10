#include "Item.hpp"
// class Item
int Item::countIdItem = 1;

Item::Item(){
    this->itemId = -1;
    this->name = "";
    this->code = "";
    this->price = 0;
    // countIdItem ++;
}

Item::Item(string name, string code, int price){
    this->itemId = countIdItem + 1;
    this->name = name;
    this->code = code;
    this->price = price;
    countIdItem ++;
}

Item::~Item(){
    
}

void Item::setItemId(int itemId){
    this->itemId = itemId;
}

void Item::setName(string name){
    this->name = name;
}

void Item::setCode(string code){
    this->code = code;
}

void Item::setPrice (int price){
    this->price = price;
}

const int& Item::getItemId() const{
    return this->itemId;
}

const string& Item::getName() const{
    return this->name;
}

const string& Item::getCode() const{
    return this->code;
}

const int& Item::getPrice() const {
    return this->price;
}

bool Item::operator==(const Item& other){
    return itemId == other.itemId;
}
ostream& operator<<(ostream& os, const Item& item){
    os << item.code;
    return os;
}
