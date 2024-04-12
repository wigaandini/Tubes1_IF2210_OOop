#include "Store.hpp"
#include <algorithm>
#include <exception>
#include <iterator>
#include "../Item/Herbivore.hpp"
#include "../Item/Carnivore.hpp"
#include "../Item/Omnivore.hpp"
#include "../Game/Game.hpp"
#include "../Utils/Utils.hpp"
#include <limits>
// #include "../Customer/Customer.hpp"

Store::Store()
{
    // this->unlimitedAnimalSell = {"COW", "SHEEP", "HORSE", "RABBIT", "SNAKE", "CHICKEN", "DUCK", "TEAK_TREE", "SANDALWOOD_TREE", "ALOE_TREE", "IRONWOOD_TREE", "APPLE_TREE", "ORANGE_TREE", "BANANA_TREE", "GUAVA_TREE"};
    // transform(Game::getAnimalConfig().begin(), Game::getAnimalConfig().end(), back_inserter(this->unlimitedAnimalSell), [](auto &el)
    //           { return el.second.name; });

    // transform(Game::getPlantConfig().begin(), Game::getPlantConfig().end(), back_inserter(this->unlimitedPlantSell), [](auto &el)
    //           { return el.second.name; });

    // for (const auto& pair : Game::getAnimalConfig()) {
    //     this->unlimitedAnimalSell.push_back(pair.first);
    // }

    // // Mengisi unlimitedPlantSell
    // for (const auto& pair : Game::getPlantConfig()) {
    //     this->unlimitedPlantSell.push_back(pair.first);
    // }
}

void Store::setUnlimitedAnimalSell()
{
    transform(Game::getAnimalConfig().begin(), Game::getAnimalConfig().end(), back_inserter(this->unlimitedAnimalSell), [](auto &el)
              { return el.first; });

    
}
void Store::setUnlimitedPlantSell()
{
    transform(Game::getPlantConfig().begin(), Game::getPlantConfig().end(), back_inserter(this->unlimitedPlantSell), [](auto &el)
              { return el.first; });
}

void Store::addItem(shared_ptr<Item> item)
{

    if (!this->checkIsLivingBeings(item->getName()))
    {
        this->items[item->getName()].push_back(item);
    }
}

void Store::addItem(vector<shared_ptr<Item>> &items)
{

    for (auto &item : items)
    {

        if (!this->checkIsLivingBeings(item->getName()))
        {
            this->items[item->getName()].push_back(item);
        }
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

bool Store::checkIsLivingBeings(const string &name)
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

    cout << "Uang Anda : " << Game::getCurrentPlayer()->getGulden() << endl;
    cout << "Slot penyimpanan tersedia : " << Game::getCurrentPlayer()->getInventory().countEmpty() << endl
         << endl;

    bool isValid = false;

    vector<shared_ptr<Item>> itemBuys;
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

        // shared_ptr<Customer> customer = dynamic_pointer_cast<Customer>(Game::getCurrentPlayer());

        shared_ptr<Item> itemBuyChoose = this->takeItem(allItemsSell.at(numItemBuy - 1), 1).at(0);
        itemBuys.push_back(itemBuyChoose);
        try
        {
            Game::getCurrentPlayer()->buy(itemBuyChoose, quantity);

            vector<shared_ptr<Item>> items(this->takeItem(allItemsSell.at(numItemBuy - 1), quantity - 1));
            itemBuys.insert(itemBuys.end(), itemBuys.begin(), items.end());

            cout << "Selamat Anda berhasil membeli " << quantity << " " << itemBuys.at(0)->getName() << ". Uang Anda tersisa " << Game::getCurrentPlayer()->getGulden() << " gulden.";

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
        cout << Game::getCurrentPlayer()->getInventory() << endl;

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
                Game::getCurrentPlayer()->getInventory().put(chooseSlotArray.at(i), itemBuys.at(i));
            }

            cout << itemBuys.at(0)->getName() << " berhasil disimpan dalam penyimpanan!!" << endl;

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
    if (Game::getCurrentPlayer()->getInventory().isEmpty())
    {
        cout << "Inventory Anda kosong tidak ada barang yang bisa Anda jual" << endl;
        return;
    }
    cout << "Berikut merupakan penyimpanan Anda" << endl;

    Game::getCurrentPlayer()->getInventory().displayStorage(true);

    cout << endl <<  "Silahkan pilih petak yang ingin Anda jual!" << endl;
    bool isValid = false;

    while (!isValid)
    {
        try
        {
            // cout << "Petak (Ketik q untuk keluar) : ";

            string chooseSlot = Utils::readLine("Petak (Ketik q untuk keluar) : ");

            if (chooseSlot.compare("q") == 0)
            {
                cout << "Terimakasih atas kujungan Anda" << endl;
                return;
            }
            if (chooseSlot.empty()){
                throw "Masukan tidak ada silahkan ulangi lagi!!";
            }

            string slots = Utils::removeSpaces(chooseSlot);
            // cout << slots << endl;
            vector<string> chooseSlotArray = Utils::splitString(slots, ',');

            // cout << "slot: " << chooseSlotArray.size() << endl;

            pair<vector<shared_ptr<Item>>, int> items = Game::getCurrentPlayer()->sell(chooseSlotArray);

            // cout << items.first.size() << " " << endl;

            this->addItem(items.first);

            cout << "Barang Anda berhasil dijual! Uang Anda bertambah " << items.second << " gulden!" << endl << endl;

            isValid = true;
        }
        catch (const exception& e)
        {
            cout << e.what() << endl;
        } catch (const char* c) {
            cout << c << endl;
        }
    }

}

ostream &operator<<(ostream &os, const Store &store)
{
    vector<string> itemsSell(store.itemsCanSell());
    os << "Berikut merupakan hal yang dapat Anda beli" << endl;
    int num = 1;
    for (string element : itemsSell)
    {
        os << num++ << ". " << element << " - " << store.items.at(element).at(0)->getPrice() << " (" << store.items.at(element).size() << ")" << endl;
        ;
    }
    // cout << store.unlimitedAnimalSell.size() << endl;
    // cout << Game::getAnimalConfig().begin()->second.name << endl;
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

map<string, vector<shared_ptr<Item>>> Store::getItems() const
{
    return this->items;
}

Store::~Store()
{
}