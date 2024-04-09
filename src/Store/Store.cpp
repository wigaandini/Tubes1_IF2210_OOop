#include "Store.hpp"
#include <algorithm>
#include <exception>
#include <iterator>
#include "../Item/Herbivore.hpp"
#include "../Item/Carnivore.hpp"
#include "../Item/Omnivore.hpp"
#include "../Game/Game.hpp"
#include <sstream>
#include <string>

Store::Store()
{
    // this->unlimitedAnimalSell = {"COW", "SHEEP", "HORSE", "RABBIT", "SNAKE", "CHICKEN", "DUCK", "TEAK_TREE", "SANDALWOOD_TREE", "ALOE_TREE", "IRONWOOD_TREE", "APPLE_TREE", "ORANGE_TREE", "BANANA_TREE", "GUAVA_TREE"};
    transform(Game::getAnimalConfig().begin(), Game::getAnimalConfig().end(), back_inserter(this->unlimitedAnimalSell), [](const pair<const string, AnimalConfig> &el)
              { return el.first; });

    transform(Game::getPlantConfig().begin(), Game::getPlantConfig().end(), back_inserter(this->unlimitedPlantSell), [](const pair<const string, PlantConfig> &el)
              { return el.first; });
}

void Store::addItem(Item &item)
{

    if (!this->checkIsLivingBeings(item.getName()))
    {
        this->items[item.getName()].push_back(item);
    }
}

vector<Item> Store::takeItem(const string &name, const int &num)
{

    if ((int)this->items[name].size() < num)
    {
        throw ""; // stock tidak cukup
    }

    vector<Item> items;

    for (int i = 0; i < num; i++)
    {

        if (!this->checkIsLivingBeings(name))
        {

            Item item = this->items[name].front();
            this->items[name].erase(this->items[name].begin());
            items.push_back(item);
        }
        else
        {

            if (name == "COW" || name == "SHEEP" || name == "HORSE" || name == "RABBIT")
            {
                Herbivore animal(name);
                items.push_back(animal);
            }
            else if (name == "SNAKE")
            {
                Carnivore animal(name);
                items.push_back(animal);
            }
            else
            {
                Omnivore animal(name);
                items.push_back(animal);
            }
        }
    }

    return items;
}

vector<string> Store::itemsCanSell() const
{
    vector<string> items;
    for (const auto &pair : this->items)
    {
        if (pair.second.size() > 0)
        {
            items.push_back(pair.first);
        }
    }

    return items;
}

bool Store::checkIsLivingBeings(const string &name) const
{
    vector<string> livingBeings(this->unlimitedAnimalSell);
    livingBeings.insert(livingBeings.end(), this->unlimitedPlantSell.begin(), this->unlimitedPlantSell.end());

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

// Item Store::seeItem(const string &name)
// {
//     if (!this->checkIsLivingBeings(name))
//     {

//         return this->items[name].front();

//     }
//     else
//     {

//         if (name == "COW" || name == "SHEEP" || name == "HORSE" || name == "RABBIT")
//         {
//             Herbivore animal(name);
//             return animal;
//         }
//         else if (name == "SNAKE")
//         {
//             Carnivore animal(name);
//             return animal;

//         }
//         else
//         {
//             Omnivore animal(name);
//             return animal;
//         }
//     }
// }

void Store::handleCustomerBuy()
{
    vector<string> allItemsSell(this->itemsCanSell());
    allItemsSell.insert(allItemsSell.end(), this->unlimitedAnimalSell.begin(), this->unlimitedAnimalSell.end());
    allItemsSell.insert(allItemsSell.end(), this->unlimitedPlantSell.begin(), this->unlimitedPlantSell.end());

    cout << *this << endl;

    cout << "Uang Anda : " << Game::getCurrentPlayer().getGulden() << endl;
    cout << "Slot penyimpanan tersedia : " << Game::getCurrentPlayer().getInventory()->countEmpty() << endl
         << endl;

    bool isValid = false;

    vector<Item> itemBuys;
    while (!isValid)
    {

        int numItemBuy;
        int quantity;
        cout << "Barang yang ingin dibeli (tulis -1 untuk keluar): ";
        cin >> numItemBuy;

        if (numItemBuy == -1)
        {

            cout << "Terima kasih atas kunjungan Anda" << endl;
            return;
        }
        cout << "Kuantitas : ";
        cin >> quantity;

        Customer *customer = dynamic_cast<Customer *>(&Game::getCurrentPlayer());

        Item &itemBuyChoose = this->takeItem(allItemsSell.at(numItemBuy - 1), 1).at(0);
        itemBuys.push_back(itemBuyChoose);
        try
        {
            customer->buy(itemBuyChoose, quantity);

            vector<Item> items(this->takeItem(allItemsSell.at(numItemBuy - 1), quantity - 1));
            itemBuys.insert(itemBuys.end(), itemBuys.begin(), items.end());

            isValid = true;
        }
        catch (char *)
        {
            cout << "error" << endl;
            this->addItem(itemBuyChoose);
        }
    }

    isValid = false;

    while (!isValid)
    {

        cout << "Pilih slot untuk menyimpan barang yang Anda beli!" << endl
             << endl;
        cout << *Game::getCurrentPlayer().getInventory() << endl;

        string chooseSlot;
        cout << "Petak slot : ";
        cin >> chooseSlot;

        vector<string> chooseSlotArray;

        chooseSlot.erase(remove(chooseSlot.begin(), chooseSlot.end(), ' '), chooseSlot.end());
        string token;
        istringstream tokenStream(chooseSlot);

        while (getline(tokenStream, token, ','))
        {
            chooseSlotArray.push_back(token);
        }
        try
        {

            for (unsigned int i = 0; i < chooseSlotArray.size(); i++)
            {
                Game::getCurrentPlayer().getInventory()->put(chooseSlotArray.at(i), itemBuys.at(i));
            }

            cout << itemBuys.at(0).getName() << " berhasil disimpan dalam penyimpanan!!" << endl;

            isValid = true;
        }
        catch (char *)
        {
            cout << "error";
        }
    }
}

void Store::handleCustomerSell()

{
    if (Game::getCurrentPlayer().getInventory()->isEmpty()){
        cout << "Inventory Anda kosong tidak ada barang yang bisa Anda jual" << endl;
        return ;
    }
    cout << "Berikut merupakan penyimpanan Anda" << endl;

    cout << *Game::getCurrentPlayer().getInventory() << endl;

    cout << "Silahkan pilih petak yang ingin Anda jual!" << endl;

    cout << "Petak : ";

    string chooseSlot;

    cin >> chooseSlot;
    vector<string> chooseSlotArray;

    chooseSlot.erase(remove(chooseSlot.begin(), chooseSlot.end(), ' '), chooseSlot.end());
    string token;
    istringstream tokenStream(chooseSlot);

    while (getline(tokenStream, token, ','))
    {
        chooseSlotArray.push_back(token);
    }

    cout << "Barang Anda berhasil dijual! Uang Anda bertambah 12 gulden!" << endl;
}

ostream &operator<<(ostream &os, const Store &store)
{
    vector<string> itemsSell(store.itemsCanSell());
    os << "Berikut merupakan hal yang dapat Anda beli" << endl;
    int num = 1;
    for (string element : itemsSell)
    {
        os << num++ << ". " << element << " - " << store.items.at(element).at(0).getPrice() << " (" << store.items.at(element).size() << ")" << endl;
        ;
    }

    for (string element : store.unlimitedAnimalSell)
    {
        os << num++ << ". " << element << " - " << Game::getAnimalConfig().at(element).price << endl;
        ;
    }

    for (string element : store.unlimitedPlantSell)
    {
        os << num++ << ". " << element << " - " << Game::getPlantConfig().at(element).price << endl;
        ;
    }

    return os;
}