#include "Farmer.hpp"
#include "../Game/Game.hpp"
#include "../Utils/Utils.hpp"
#include "../Grid/Grid.hpp"
#include <limits>

Farmer::Farmer() : Resident()
{
    type = "Petani";
}

Farmer::Farmer(string username, int weight, int gulden) : Resident(username, weight, gulden)
{
    type = "Petani";
}

Farmer::~Farmer()
{
}

string Farmer::getType()
{
    return type;
}
void Farmer::plant()
{
    // if (this->inventory.isEmpty())
    // {
    //     cout << endl
    //          << "Inventory anda kosong!!" << endl;
    // }
    // else if (!this->inventory.checkInventoryPlant())
    // {
    //     cout << endl
    //          << "Inventory anda tidak ada tanaman!!" << endl;
    // }
    // else if (this->farm.isFull())
    // {
    //     cout << endl
    //          << "Ladang anda penuh!!" << endl;
    // }
    // else
    // {
    //     bool success = false;
    //     while (!success)
    //     {
    //         cout << "Pilih tanaman dari penyimpanan" << endl;
    //         this->inventory.displayStorage(false);

    //         cout << endl
    //              << "Slot (ketik q untuk keluar) : ";
    //         string slot;
    //         cin >> slot;

    //         if (slot == "q")
    //         {
    //             cout << "Tidak jadi melakukan tanam!!" << endl;
    //             return;
    //         }

    //         try
    //         {
    //             if (Game::getPlantConfig().find(this->inventory.see(slot)->getName()) != Game::getPlantConfig().end())
    //             {
    //                 string plantName = this->inventory.see(slot)->getName();
    //                 cout << endl
    //                      << "Kamu memilih " << Utils::toTitleCase(plantName) << "." << endl;
    //                 cout << endl
    //                      << "Pilih petak tanah yang akan ditanami" << endl;
    //                 shared_ptr<Item> itemRef = this->inventory.take(slot);
    //                 shared_ptr<Plant> plantRef = dynamic_pointer_cast<Plant>(itemRef);

    //                 bool done = false;
    //                 while (!done)
    //                 {
    //                     try
    //                     {
    //                         this->farm.displayStorage(false);

    //                         cout << endl
    //                              << "Petak tanah (ketik q untuk kembali) : ";
    //                         string petak;
    //                         cin >> petak;

    //                         if (petak == "q")
    //                         {
    //                             this->inventory.put(slot, itemRef);
    //                             done = true;
    //                             break;
    //                         }

    //                         if (!this->farm.isEmpty(petak))
    //                         {
    //                             cout << endl
    //                                  << "Petak sudah terisi." << endl
    //                                  << "Silahkan masukan petak yang kosong." << endl;
    //                         }
    //                         else
    //                         {
    //                             this->farm.put(petak, plantRef);
    //                             cout << endl
    //                                  << "Cangkul, cangkul, cangkul yang dalam~!" << endl
    //                                  << "Orange tree berhasil ditanam!" << endl;
    //                             done = true;
    //                         }
    //                         success = true;
    //                     }
    //                     catch (const exception &e)
    //                     {
    //                         cout << endl
    //                              << e.what() << endl
    //                              << endl;
    //                     }
    //                 }
    //             }
    //             else
    //             {
    //                 cout << "Apa yang kamu lakukan?!! Kamu mencoba untuk menanam itu?!!" << endl
    //                      << "Silahkan masukan slot yang berisi tanaman." << endl;
    //             }
    //         }
    //         catch (const SlotEmptyException &e)
    //         {
    //             cout << endl
    //                  << "Kamu mengambil harapan kosong dari penyimpanan." << endl
    //                  << "Silahkan masukan slot yang berisi tanaman." << endl
    //                  << endl;
    //         }
    //         catch (const exception &e)
    //         {
    //             cout << endl
    //                  << e.what() << endl
    //                  << endl;
    //         }
    //     }
    // }

    Resident::placeTo<Farm, PlantConfig, Plant>(
        this->farm, Game::getPlantConfig(), [this]()
        { return this->inventory.checkInventoryPlant(); },
        "Ladang");
}

// void Farmer::buy(shared_ptr<Item> &item, int quantity)
// {
//     if (item->getPrice() * quantity > this->gulden)
//     {
//         throw ""; // uang  tidak cukup
//     }

//     if (this->inventory.countEmpty() < quantity)
//     {
//         throw ""; // Penyimpanan tidak cukup
//     }

//     this->gulden -= item->getPrice() * quantity;
// }

// vector<shared_ptr<Item>> Farmer::sell(vector<string> &slots)
// {
//     vector<shared_ptr<Item>> items;
//     for (string slot : slots)
//     {

//         if (this->inventory.isEmpty(slot))
//         {
//             throw ""; // empty slot
//         }

//         if (shared_ptr<Building> building = dynamic_pointer_cast<Building>(this->inventory.see(slot))){
//             throw ""; //Tidak bisa jual bangunan
//         }
//     }

//     for (string slot : slots)
//     {

//         const shared_ptr<Item> &item = this->inventory.take(slot);
//         this->gulden += item->getPrice();
//         items.push_back(item);
//     }

//     return items;
// }

void Farmer::harvest()
{
    // if (this->farm.isEmpty())
    // {
    //     cout << endl
    //          << "Ladang anda kosong" << endl;
    // }
    // else if (!this->farm.checkReadyToHarvest())
    // {
    //     cout << endl
    //          << "Ladang anda tidak ada yang siap dipanen" << endl;
    // }
    // else
    // {
    //     this->farm.displayStorage(true);
    //     cout << endl
    //          << "Pilih tanaman siap panen yang kamu miliki" << endl;
    //     map<string, int> plantReady = this->farm.countItemsReadyToHarvest();
    //     int number = 1;
    //     vector<int> total;
    //     vector<string> kode;
    //     vector<int> sizeResult;

    //     for (const auto &entry : plantReady)
    //     {
    //         cout << "    " << number << ". " << Game::getPlantConfig()[entry.first].code << " (" << entry.second << " petak siap panen)" << endl;
    //         number++;
    //         kode.push_back(Game::getPlantConfig()[entry.first].code);
    //         total.push_back(entry.second);
    //         sizeResult.push_back(int(Plant::getHarvestResult()[entry.first].size()));
    //     }

    //     int answer1, answer2;
    //     bool sukses1 = false;
    //     while (!sukses1)
    //     {
    //         cout << endl
    //              << "Nomor tanaman yang ingin dipanen (ketik -1 untuk keluar) : ";
    //         cin >> answer1;

    //         if (answer1 == -1)
    //         {
    //             cout << "Tidak jadi panen!!" << endl;
    //             return;
    //         }

    //         if (answer1 > 0 && answer1 < number)
    //         {
    //             sukses1 = true;
    //         }
    //         else
    //         {
    //             cout << "Masukan salah silahkah masukan kembali!!!" << endl;
    //         }
    //     }
    // if (cin.fail())
    // {
    //     cin.clear();
    //     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //     cout << "Input harus berupa angka. Silahkan coba lagi." << endl;
    // }

    //     bool sukses2 = false;
    //     while (!sukses2)
    //     {
    //         cout << endl
    //              << "Berapa petak yang ingin dipanen : ";
    //         cin >> answer2;

    //         if (answer2 <= total[answer1 - 1])
    //         {
    //             if (answer2 * sizeResult[answer1 - 1] > this->inventory.countEmpty())
    //             {
    //                 cout << endl
    //                      << "Jumlah penyimpanan tidak cukup!" << endl;
    //                 return;
    //             }
    //             else
    //             {
    //                 sukses2 = true;
    //             }
    //         }
    //         else
    //         {
    //             cout << "Jumlah yang bisa dipanen hanya " << total[answer1 - 1] << "!!!" << endl;
    //         }
    //     }

    //     string slot;
    //     vector<string> petak;
    //     cout << "Pilih petak yang ingin dipanen: " << endl;
    //     for (int i = 0; i < answer2; i++)
    //     {
    //         bool sukses3 = false;
    //         while (!sukses3)
    //         {

    //             try
    //             {
    //                 cout << "Petak ke-" << i + 1 << " : ";
    //                 cin >> slot;
    //                 if (this->farm.see(slot)->getCode() != kode[answer1 - 1])
    //                 {
    //                     cout << "Petak tidak sesuai. Silahkan input kembali!" << endl;
    //                 }
    //                 else
    //                 {
    //                     petak.push_back(slot);
    //                     sukses3 = true;
    //                 }
    //             }
    //             catch (const exception &e)
    //             {
    //                 cout << e.what() << endl;
    //             }
    //         }

    //         vector<Product> tempP = this->farm.take(slot)->collect();
    //         unsigned int k = 0;
    //         while (k < tempP.size())
    //         {
    //             this->inventory + make_shared<Product>(tempP[k]);
    //             k++;
    //         }
    //     }
    //     cout << endl
    //          << answer2 << "petak tanaman " << kode[answer1 - 1] << " pada petak ";
    //     for (int l = 0; l < answer2; l++)
    //     {
    //         if (l != answer2 - 1)
    //         {
    //             cout << petak[l] << ", ";
    //         }
    //         else
    //         {
    //             cout << petak[l];
    //         }
    //     }
    //     cout << " telah dipanen" << endl;
    // }

    Resident::harvest<Farm, PlantConfig>(this->farm, Game::getPlantConfig(), Plant::getHarvestResult(), "Ladang");
}

int Farmer::getWealth()
{
    int wealth = gulden;
    for (int i = 0; i < this->inventory.getRow(); i++)
    {
        for (int j = 0; j < this->inventory.getCol(); j++)
        {
            if (this->inventory.see(i, j) != nullptr)
            {
                wealth += this->inventory.see(i, j)->getPrice();
            }
        }
    }
    for (int i = 0; i < this->farm.getRow(); i++)
    {
        for (int j = 0; j < this->farm.getCol(); j++)
        {
            if (this->farm.see(i, j) != nullptr)
            {
                wealth += this->farm.see(i, j)->getPrice();
            }
        }
    }
    return wealth;
}

int Farmer::calculateTax()
{
    int kkp = getWealth() - KTKP_PETANI;
    if (kkp <= 0)
    {
        return 0;
    }
    else
    {
        if (kkp <= 6)
        {
            return 0.05 * kkp;
        }
        else if (kkp <= 25 && kkp > 6)
        {
            return 0.15 * kkp;
        }
        else if (kkp <= 50 && kkp > 25)
        {
            return 0.25 * kkp;
        }
        else if (kkp <= 500 && kkp > 50)
        {
            return 0.30 * kkp;
        }
        else
        {
            return 0.35 * kkp;
        }
    }
}

Farm &Farmer::getFarm()
{
    return this->farm;
}

void Farmer::saveFile(const string &filepath)
{
    ofstream file(filepath, ios::app);

    file << username << " Petani " << weight << " " << gulden << endl;

    Inventory &inventoryItems = Resident::Player::getInventory();
    file << inventoryItems.countInventoryItem() << endl;
    for (int i = 0; i < inventoryItems.getRow(); i++)
    {
        for (int j = 0; j < inventoryItems.getCol(); j++)
        {
            if (inventoryItems.see(i, j) != nullptr)
            {
                file << inventoryItems.see(i, j)->getName() << endl;
            }
        }
    }

    Farm &farmItems = getFarm();
    file << farmItems.countOccupied() << endl;
    for (int j = 0; j < farmItems.getCol(); j++)
    {
        for (int i = 0; i < farmItems.getRow(); i++)
        {
            if (farmItems.see(i, j) != nullptr)
            {
                shared_ptr<Plant> plant = farmItems.see(i, j);
                file << char('A' + j);
                if (i + 1 < 10)
                {
                    file << '0' << i + 1 << " " << plant->getName() << " " << plant->getAge() << endl;
                }
                else
                {
                    file << i + 1 << " " << plant->getName() << " " << plant->getAge() << endl;
                }
            }
        }
    }

    file.close();
}