#include "Store.hpp"
#include <algorithm>
#include <exception>
#include <iterator>
#include "../Item/Herbivore.hpp"
#include "../Item/Carnivore.hpp"
#include "../Item/Omnivore.hpp"
#include "../Item/Plant.hpp"
#include "../Game/Game.hpp"
#include "../Utils/Utils.hpp"
#include "StoreException.hpp"
#include <limits>
#include <random>

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

    if (!checkQuantity(name, num))
    {
        throw StockNotEnoughException(); // stock tidak cukup
    }

    vector<shared_ptr<Item>> items;

    for (int i = 0; i < num; i++)
    {

        if (!this->checkIsLivingBeings(name))
        {

            shared_ptr<Item> item = this->items[name].back();
            this->items[name].pop_back();
            items.push_back(item);
            if (this->items[name].size() == 0){
                this->items.erase(name);
            }
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
            else if (name == "DUCK" || name == "CHICKEN")
            {
                auto animal = make_shared<Omnivore>(name);

                items.push_back(animal);
            }
            else
            {
                auto plant = make_shared<Plant>(name);

                items.push_back(plant);
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

bool Store::checkQuantity(const string &name, const int &quantity)
{
    if (checkIsLivingBeings(name))
    {
        return true;
    }

    if (quantity > int(this->items.at(name).size()))
    {
        return false;
    }

    return true;
}

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
    int numItemBuy;
    int quantity;
    vector<shared_ptr<Item>> itemBuys;

    while (!isValid)
    {

        bool itemBuyValid = false;

        while (!itemBuyValid)
        {

            cout << "Barang yang ingin dibeli (tulis -1 untuk keluar): ";
            cin >> numItemBuy;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input harus berupa angka. Silahkan coba lagi." << endl;
            }
            else
            {

                if (numItemBuy == -1)
                {

                    cout << "Terima kasih atas kunjungan Anda" << endl;
                    return;
                }

                if (numItemBuy > int(allItemsSell.size()))
                {
                    cout << "Tidak ada barang dengan nomor tersebut !!!" << endl;
                }
                else
                {
                    itemBuyValid = true;
                }
            }
        }
        bool quantityValid = false;

        while (!quantityValid)
        {

            cout << "Kuantitas : ";
            cin >> quantity;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input harus berupa angka. Silahkan coba lagi." << endl;
            }
            else
            {

                if (quantity <= 0)
                {
                    cout << "Kuantitas harus lebih besar sama dengan 0!!" << endl;
                }
                else if (!checkQuantity(allItemsSell.at(numItemBuy - 1), quantity))
                {
                    cout << "Stock tidak cukupp!!!" << endl;
                }
                // else if (!Game::getCurrentPlayer()->getInventory().isInventoryEnough(quantity))
                // {
                //     cout << "Penyimpanan tidak mencukupi!!!" << endl;
                // }
                else
                {
                    quantityValid = true;
                }
            }
        }

        shared_ptr<Item> itemBuyChoose;
        try
        {
            itemBuyChoose = this->takeItem(allItemsSell.at(numItemBuy - 1), 1).at(0);
            itemBuys.push_back(itemBuyChoose);
            cout << endl
                 << "Terdapat opsi dalam pembayaran: " << endl;
            cout << "1. Bayar dengan harga normal" << endl;
            cout << "2. Coin Flip (Jika benar maka barang gratis, Jika salah maka harga menjadi 2x)" << endl
                 << endl;
            bool coinFlipValid = false;
            int answer;

            while (!coinFlipValid)
            {
                cout << "Masukkan pilihan opsi pembayaran: ";
                cin >> answer;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Input harus berupa angka. Silahkan coba lagi." << endl;
                    continue;
                }

                if (answer == 1)
                {
                    Game::getCurrentPlayer()->buy(itemBuyChoose, quantity, 1);
                    coinFlipValid = true;
                }
                else if (answer == 2)
                {
                    cout << endl
                         << "Silahkan pilih head atau tail" << endl;
                    string pilihan;
                    
                    bool coinChooseValid = false;
                    while (!coinChooseValid)
                    {
                        cout << "Masukkan pilihan: ";
                        cin >> pilihan;

                        if (pilihan != "head" && pilihan != "tail")
                        {
                            cout << "Masukan salah silahkah masukan kembali!!!" << endl;
                        }
                        else
                        {
                            coinChooseValid = true;
                            random_device rd;
                            mt19937 gen(rd());
                            uniform_int_distribution<> dist(1, 2);

                            int random_number = dist(gen);
                            string x;
                            if (random_number == 1){
                                x = "head";
                            } else {
                                x = "tail";
                            }

                            cout << endl
                                 << "Koin dilempar" << endl;
                            cout << "ting ting ting" << endl
                                 << "ting ting ting" << endl
                                 << "ting ting ting" << endl;

                            if (x != pilihan)
                            {
                                cout << endl
                                     << "Pilihan anda salah, harga menjadi 2x lipat" << endl;
                                Game::getCurrentPlayer()->buy(itemBuyChoose, quantity, 2);
                            }
                            else
                            {
                                cout << endl
                                     << "Pilihan anda benar, anda beruntung, harga gratis" << endl;
                                Game::getCurrentPlayer()->buy(itemBuyChoose, quantity, 0);
                            }
                        }
                    }
                    coinFlipValid = true;
                }
                else
                {
                    cout << "Masukan salah silahkah masukan kembali!!!" << endl;
                }
            }

            vector<shared_ptr<Item>> items(this->takeItem(allItemsSell.at(numItemBuy - 1), quantity - 1));

            itemBuys.insert(itemBuys.end(), items.begin(), items.end());

            cout << "Selamat Anda berhasil membeli " << quantity << " " << Utils::toTitleCase(itemBuys.at(0)->getName()) << ". Uang Anda tersisa " << Game::getCurrentPlayer()->getGulden() << " gulden.";

            isValid = true;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
            this->addItem(itemBuyChoose);
            itemBuys.clear();
        }
    }

    isValid = false;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (!isValid)
    {

        cout << endl
             << "Pilih slot untuk menyimpan barang yang Anda beli!" << endl
             << endl;
        Game::getCurrentPlayer()->getInventory().displayStorage(true);

        string chooseSlot = Utils::readLine("Petak slot : ");
        chooseSlot = Utils::removeSpaces(chooseSlot);
        vector<string> chooseSlotArray = Utils::splitString(chooseSlot, ',');

        try
        {
            if (int(chooseSlotArray.size()) != quantity)
            {
                throw WrongSlotsSizeException();
            }

            vector<shared_ptr<Item>> itemBuysClone = itemBuys;
            for (unsigned int i = 0; i < chooseSlotArray.size(); i++)
            {
                Game::getCurrentPlayer()->getInventory().put(chooseSlotArray.at(i), itemBuysClone.at(i));
                quantity--;
                itemBuys.erase(itemBuys.begin());
            }

            cout << Utils::toTitleCase(allItemsSell.at(numItemBuy - 1)) << " berhasil disimpan dalam penyimpanan!!" << endl;

            isValid = true;
        }
        catch (const exception &e)
        {

            cout << e.what() << endl;
            cout << "Silahkan ulangi dan berikan masukan yang tepat!!" << endl
                 << endl;
            cout << "Barang tersisa yang belum dimasukkan ke dalam penyimpanan : " << quantity << endl;
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

    bool isValid = false;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (!isValid)
    {
        try
        {

            cout << endl
                 << "Silahkan pilih petak yang ingin Anda jual!" << endl;
            string chooseSlot = Utils::readLine("Petak (Ketik q untuk keluar) : ");

            if (chooseSlot.compare("q") == 0)
            {
                cout << "Terimakasih atas kujungan Anda" << endl;
                return;
            }
            if (chooseSlot.empty())
            {
                throw "Masukan tidak ada silahkan ulangi lagi!!";
            }

            string slots = Utils::removeSpaces(chooseSlot);
            vector<string> chooseSlotArray = Utils::splitString(slots, ',');

            pair<vector<shared_ptr<Item>>, int> items = Game::getCurrentPlayer()->sell(chooseSlotArray);

            this->addItem(items.first);

            cout << "Barang Anda berhasil dijual! Uang Anda bertambah " << items.second << " gulden!" << endl
                 << endl;

            isValid = true;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
            cout << "Silahkan ulangi dan berikan masukan yang tepat!!" << endl
                 << endl;
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

void Store::saveFile(const string &filepath)
{
    ofstream file(filepath, ios::app);

    map<string, int> itemCounts;
    for (const auto &pair : items)
    {
        if(pair.second.size() > 0){
            itemCounts[pair.first] = pair.second.size();
        }
    }

    file << itemCounts.size() << endl;

    for (const auto &pair : itemCounts)
    {
        if (pair.second > 0){
            file << pair.first << " " << pair.second << endl;
        }
        
    }

    file.close();
}