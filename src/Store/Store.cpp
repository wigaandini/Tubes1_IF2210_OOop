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

    if (it == livingBeings.end())
    {
        this->items[item.getName()].push_back(item);
    }
}

Item &Store::takeItem(const string &name)
{
    vector<string> livingBeings = {"COW", "SHEEP", "HORSE", "RABBIT", "SNAKE", "CHICKEN", "DUCK", "TEAK_TREE", "SANDALWOOD_TREE", "ALOE_TREE", "IRONWOOD_TREE", "APPLE_TREE", "ORANGE_TREE", "BANANA_TREE", "GUAVA_TREE"};

    auto it = find(livingBeings.begin(), livingBeings.end(), name);

    if (it == livingBeings.end())
    {
        Item item = this->items[name].front();
        this->items[name].erase(this->items[name].begin());

        return item;
    } else {
        if (name == "COW" || name == "SHEEP" || name == "HORSE" || name == "RABBIT"){
            // return Herbivore(animalConfig[name], );
        }
    }
}