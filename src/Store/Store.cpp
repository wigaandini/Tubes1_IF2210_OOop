#include "Store.hpp"
#include <algorithm>
#include <exception>
#include "../Item/Herbivore.hpp"
#include "../Item/Carnivore.hpp"
#include "../Item/Omnivore.hpp"

Store::Store()
{
}

void Store::addItem(shared_ptr<Item> item)
{

    if (!this->checkIsLivingBeings(item->getName()))
    {
        this->items.at(item->getName()).push_back(item);
    }
}



vector<shared_ptr<Item>> Store::takeItem(const string &name, const int &num)
{

    if ((int)this->items[name].size() < num)
    {
        throw ""; // stock tidak cukup
    }

    vector<shared_ptr<Item>> items;

    for (int i = 0; i < num; i++)
    {

        if (!this->checkIsLivingBeings(name))
        {

            auto item = this->items[name].front();
            this->items[name].erase(this->items[name].begin());
            items.push_back(item);
        }
        else
        {

            if (name == "COW" || name == "SHEEP" || name == "HORSE" || name == "RABBIT")
            {
                auto animal = make_shared<Herbivore>(name);
                items.push_back(animal);
            }
            else if (name == "SNAKE")
            {
                auto animal = make_shared<Carnivore>(name);

                items.push_back(animal);
            }
            else
            {
                auto animal = make_shared<Omnivore>(name);

                items.push_back(animal);
            }
        }
    }

    return items;
}

bool Store::checkIsLivingBeings(const string &name)
{
    vector<string> livingBeings = {"COW", "SHEEP", "HORSE", "RABBIT", "SNAKE", "CHICKEN", "DUCK", "TEAK_TREE", "SANDALWOOD_TREE", "ALOE_TREE", "IRONWOOD_TREE", "APPLE_TREE", "ORANGE_TREE", "BANANA_TREE", "GUAVA_TREE"};

    auto it = find(livingBeings.begin(), livingBeings.end(), name);

    if (it == livingBeings.end())
    {
        return false;
    }
    else
    {
        return true;
    }
}

map<string, vector<shared_ptr<Item>>> Store::getItems() const
{
    return this->items;
}

Store::~Store()
{
}