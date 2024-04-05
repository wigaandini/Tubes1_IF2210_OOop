#include "Store.hpp"
#include <algorithm>
#include <exception>
#include "../Item/Herbivore.hpp"
#include "../Item/Carnivore.hpp"
#include "../Item/Omnivore.hpp"

Store::Store()
{
}

void Store::addItem(Item& item)
{
    vector<string> livingBeings = {"COW", "SHEEP", "HORSE", "RABBIT", "SNAKE", "CHICKEN", "DUCK", "TEAK_TREE", "SANDALWOOD_TREE", "ALOE_TREE", "IRONWOOD_TREE", "APPLE_TREE", "ORANGE_TREE", "BANANA_TREE", "GUAVA_TREE"};

    auto it = find(livingBeings.begin(), livingBeings.end(), item.getName());

    if (!this->checkIsLivingBeings(item.getName()))
    {
        this->items[item.getName()].push_back(item);
    }
}

Item &Store::takeItem(const string &name)
{

    if (!this->checkIsLivingBeings(name))
    {
        if (this->items[name].size() == 0){
            throw "";
        }
        Item item = this->items[name].front();
        this->items[name].erase(this->items[name].begin());

        return item;
    } else {
        if (name == "COW" || name == "SHEEP" || name == "HORSE" || name == "RABBIT"){
            Herbivore animal(name);
            return animal;
        } else if (name == "SNAKE"){
            Carnivore animal(name);
            return animal;
        } else {
            Omnivore animal(name);
            return animal;
        }
    }
}

bool Store::checkIsLivingBeings(const string& name){
    vector<string> livingBeings = {"COW", "SHEEP", "HORSE", "RABBIT", "SNAKE", "CHICKEN", "DUCK", "TEAK_TREE", "SANDALWOOD_TREE", "ALOE_TREE", "IRONWOOD_TREE", "APPLE_TREE", "ORANGE_TREE", "BANANA_TREE", "GUAVA_TREE"};

    auto it = find(livingBeings.begin(), livingBeings.end(), name);

    if (it == livingBeings.end()){
        return false;
    } else {
        return true;
    }
}