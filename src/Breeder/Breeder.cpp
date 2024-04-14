#include "Breeder.hpp"
#include "../Game/Game.hpp"
#include "../Item/Herbivore.hpp"
#include "../Item/Carnivore.hpp"
#include "../Item/Omnivore.hpp"
#include "../Utils/Utils.hpp"
#include <exception>
#include <fstream>

Breeder::Breeder() : Resident()
{
    type = "Peternak";
}

Breeder::Breeder(string username, float weight, int gulden) : Resident(username, weight, gulden)
{
    type = "Peternak";
}

Breeder::~Breeder()
{
}

string Breeder::getType()
{
    return type;
}

void Breeder::cattle()
{

    if (this->inventory.isEmpty())
    {
        cout << "Inventory Kosong" << endl;
    }
    else if (this->ranch.isFull())
    {
        cout << "Peternakan sudah penuh" << endl;
    }
    else if (!this->inventory.checkInventoryAnimal())
    {
        cout << "Tidak ada hewan yang bisa diternak." << endl;
    }
    else
    {
        bool success = false;
        while (!success)
        {
            cout
                << "Pilih hewan dari penyimpanan" << endl;
            this->inventory.displayStorage(false);
            string answer;
            cout << endl
                 << "Slot (ketik q untuk keluar) : ";
            cin >> answer;
            if (answer == "q")
            {
                cout << "Tidak jadi melakukan ternak!!" << endl;
                return;
            }
            try
            {
                if (Game::getAnimalConfig().find(this->inventory.see(answer)->getName()) != Game::getAnimalConfig().end())
                {
                    string animalName = this->inventory.see(answer)->getName();
                    cout << endl
                         << "Kamu memilih " << Utils::toTitleCase(animalName) << "." << endl;
                    cout << endl
                         << "Pilih petak tanah yang akan ditinggali" << endl;
                    shared_ptr<Item> itemRef = this->inventory.take(answer);
                    shared_ptr<Animal> animalRef = dynamic_pointer_cast<Animal>(itemRef);

                    bool done = false;
                    while (!done)
                    {
                        try
                        {
                            this->ranch.displayStorage(false);

                            cout << endl
                                 << "Petak tanah (ketik q untuk kembali) : ";
                            string petak;
                            cin >> petak;

                            if (petak == "q")
                            {
                                this->inventory.put(answer, itemRef);
                                done = true;
                                break;
                            }

                            if (!this->ranch.isEmpty(petak))
                            {
                                cout << endl
                                     << "Petak sudah terisi." << endl
                                     << "Silahkan masukan petak yang kosong." << endl;
                            }
                            else
                            {
                                // if (auto _ = dynamic_pointer_cast<Carnivore>(animalRef))
                                // {
                                //     this->ranch.put(petak, dynamic_pointer_cast<Carnivore>(animalRef));
                                // }
                                // else if (auto _ = dynamic_pointer_cast<Herbivore>(animalRef))
                                // {
                                //     this->ranch.put(petak, dynamic_pointer_cast<Herbivore>(animalRef));
                                // }
                                // else if (auto _ = dynamic_pointer_cast<Omnivore>(animalRef))
                                // {
                                //     this->ranch.put(petak, dynamic_pointer_cast<Omnivore>(animalRef));
                                // }
                                this->ranch.put(petak, animalRef);

                                cout << "Dengan hati-hati, kamu meletakkan seekor " << Utils::toTitleCase(animalName) << " di kandang." << endl;
                                cout << Utils::toTitleCase(animalName) << " telah menjadi peliharaanmu sekarang!" << endl;
                                done = true;
                            }
                            success = true;
                        }
                        catch (const exception &e)
                        {
                            cout << endl
                                 << e.what() << endl
                                 << endl;
                        }
                    }
                }
                else
                {
                    cout << "Apa yang kamu lakukan?!! Benda yang kamu ambil bukanlah hewan?!!" << endl
                         << "Silahkan masukan slot yang berisi hewan." << endl;
                }
            }
            catch (const SlotEmptyException &e)
            {
                cout << endl
                     << "Kamu mengambil harapan kosong dari penyimpanan." << endl
                     << "Silahkan masukan slot yang berisi hewan." << endl
                     << endl;
            }
            catch (const exception &e)
            {
                cout << endl
                     << e.what() << endl
                     << endl;
            }
        }
    }
}

void Breeder::feedAnimal()
{
    if (this->ranch.isEmpty())
    {
        cout << "Peternakan Kosong" << endl;
    }
    else
    {
        bool isValid = false;
        while (!isValid)
        {
            try
            {

                cout << "Pilih hewan dari kandang yang mau diberi makan" << endl
                     << endl;
                this->ranch.displayStorage(false);

                string answer;
                cout << "Petak Kandang (ketik q untuk keluar) : ";
                cin >> answer;

                if (answer == "q")
                {
                    cout << "Tidak jadi memberi makan!!" << endl;
                    return;
                }

                if (Game::getAnimalConfig().find(this->ranch.see(answer)->getName()) == Game::getAnimalConfig().end())
                {
                    cout << "Maaf yang kamu pilih bukan hewan" << endl;
                }

                cout << "Kamu memilih " << Utils::toTitleCase(this->ranch.see(answer)->getName()) << " untuk diberi makan. " << endl
                     << endl;
                bool adaMakanan = false;
                if (auto _ = dynamic_pointer_cast<Herbivore>(this->ranch.see(answer)))
                {
                    adaMakanan = this->inventory.checkInventoryFruit();
                }
                else if (auto _ = dynamic_pointer_cast<Carnivore>(this->ranch.see(answer)))
                {
                    adaMakanan = this->inventory.checkInventoryMeat();
                }
                else
                {
                    adaMakanan = (this->inventory.checkInventoryFruit()) || (this->inventory.checkInventoryMeat());
                }

                if (!adaMakanan)
                {
                    cout << "Tidak ada makannan dalam penyimpanan yang bisa diberikan kepada hewan tersebut." << endl;
                    continue;
                }

                bool getFoodValid = false;
                while (!getFoodValid)
                {
                    try
                    {

                        cout << "Pilih pangan yang akan diberikan : " << endl;

                        this->inventory.displayStorage(false);

                        string answer1;

                        cout << "Slot (ketik q untuk kembali) : ";
                        cin >> answer1;

                        if (answer1 == "q")
                        {
                            getFoodValid = true;
                            break;
                        }

                        shared_ptr<Item> itemRef = this->inventory.see(answer1);
                        shared_ptr<Product> productRef = dynamic_pointer_cast<Product>(itemRef);

                        this->ranch.see(answer)->eat(productRef);

                        cout << Utils::toTitleCase(this->ranch.see(answer)->getName()) << " sudah diberi makan dan beratnya bertambah " << productRef->getAddedWeight() << " menjadi " << this->ranch.see(answer)->getWeight() << endl
                             << endl;

                        this->inventory.take(answer1);
                        getFoodValid = true;
                        isValid = true;
                    }
                    catch (const exception &e)
                    {
                        cout << e.what() << endl;
                        cout << "Silahkan masukan pilihan kembali dengan benar!!" << endl
                             << endl;
                    }
                }
            }
            catch (const exception &e)
            {
                cout << e.what() << endl;
                cout << "Silahkan masukan pilihan kembali dengan benar!!" << endl
                     << endl;
            }
        }
    }
}

// void Breeder::buy(shared_ptr<Item> &item, int quantity)
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

// vector<shared_ptr<Item>> Breeder::sell(vector<string> &slots)
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

void Breeder::harvest()
{
    if (this->ranch.isEmpty())
    {
        cout << endl
             << "Peternakan anda kosong" << endl;
    }
    else if (!this->ranch.checkAnimalReadyToHarvest())
    {
        cout << endl
             << "Peternakan anda tidak ada yang siap dipanen" << endl;
    }
    else
    {
        this->ranch.displayStorage(true);
        cout << endl
             << "Pilih hewan siap panen yang kamu miliki" << endl;
        map<string, int> plantReady = this->ranch.countAnimal();
        int number = 1;
        vector<int> total;
        vector<string> kode;
        vector<int> sizeResult;

        for (const auto &entry : plantReady)
        {
            cout << "    " << number << ". " << Game::getAnimalConfig()[entry.first].code << " (" << entry.second << " petak siap panen)" << endl;
            number++;
            kode.push_back(Game::getAnimalConfig()[entry.first].code);
            total.push_back(entry.second);
            sizeResult.push_back(int(Animal::getHarvestResult()[entry.first].size()));
        }

        int answer1, answer2;
        bool sukses1 = false;
        while (!sukses1)
        {
            cout << endl
                 << "Nomor hewan yang ingin dipanen (ketik -1 untuk keluar) : ";
            cin >> answer1;

            if (answer1 == -1)
            {
                cout << "Tidak jadi panen!!" << endl;
                return;
            }
            if (answer1 > 0 && answer1 < number)
            {
                sukses1 = true;
            }
            else
            {
                cout << "Masukan salah silahkah masukan kembali!!!" << endl;
            }
        }

        bool sukses2 = false;
        while (!sukses2)
        {
            cout << endl
                 << "Berapa petak yang ingin dipanen : ";
            cin >> answer2;

            if (answer2 <= total[answer1 - 1])
            {
                if (answer2 * sizeResult[answer1 - 1] > this->inventory.countEmpty())
                {
                    cout << endl
                         << "Jumlah penyimpanan tidak cukup!" << endl;
                    return;
                }
                else
                {
                    sukses2 = true;
                }
            }
            else
            {
                cout << "Jumlah yang bisa dipanen hanya " << total[answer1 - 1] << "!!!" << endl;
            }
        }

        string slot;
        vector<string> petak;
        cout << "Pilih petak yang ingin dipanen: " << endl;
        for (int i = 0; i < answer2; i++)
        {
            bool sukses3 = false;
            while (!sukses3)
            {
                try
                {
                    cout << "Petak ke-" << i + 1 << " : ";
                    cin >> slot;
                    if (this->ranch.see(slot)->getCode() != kode[answer1 - 1])
                    {
                        cout << "Petak tidak sesuai. Silahkan input kembali!" << endl;
                    }
                    else
                    {
                        petak.push_back(slot);
                        sukses3 = true;
                    }
                }
                catch (const exception &e)
                {
                    cout << e.what() << endl;
                }
            }

            vector<string> tempP = this->ranch.take(slot)->collect();
            unsigned int k = 0;
            while (k < tempP.size())
            {
                this->inventory + make_shared<Product>(tempP[k]);
                k++;
            }
        }
        cout << endl
             << answer2 << " petak hewan " << kode[answer1 - 1] << " pada petak ";
        for (int l = 0; l < answer2; l++)
        {
            if (l != answer2 - 1)
            {
                cout << petak[l] << ", ";
            }
            else
            {
                cout << petak[l];
            }
        }
        cout << " telah dipanen" << endl;
    }
}

int Breeder::getWealth()
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
    for (int i = 0; i < this->ranch.getRow(); i++)
    {
        for (int j = 0; j < this->ranch.getCol(); j++)
        {
            if (this->ranch.see(i, j) != nullptr)
            {
                wealth += this->ranch.see(i, j)->getPrice();
            }
        }
    }
    return wealth;
}

int Breeder::tax()
{
    int kkp = getWealth() - KTKP_PETERNAK;
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

Ranch &Breeder::getRanch()
{
    return this->ranch;
}

void Breeder::saveFile(const string &filepath)
{
    ofstream file(filepath, ios::app);

    if (!file.is_open())
    {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    file << username << " Peternak " << weight << " " << gulden << endl;

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

    Ranch &ranchItems = getRanch();
    map<string, int> animalCount = ranchItems.countAnimal();
    file << animalCount.size() << endl;
    for (int i = 0; i < ranchItems.getRow(); i++)
    {
        for (int j = 0; j < ranchItems.getCol(); j++)
        {
            if (ranchItems.see(i, j) != nullptr)
            {
                string animalName = ranchItems.see(i, j)->getName();
                file << char('A' + j);
                if (i + 1 < 10)
                {
                    file << '0' << i + 1 << " " << animalName << " " << animalCount[animalName] << endl;
                }
                else
                {
                    file << i + 1 << " " << animalName << " " << animalCount[animalName] << endl;
                }
            }
        }
    }

    file.close();
}