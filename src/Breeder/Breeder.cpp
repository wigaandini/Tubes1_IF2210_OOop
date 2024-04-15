#include "Breeder.hpp"
#include "../Game/Game.hpp"
#include "../Item/Herbivore.hpp"
#include "../Item/Carnivore.hpp"
#include "../Item/Omnivore.hpp"
#include "../Utils/Utils.hpp"
#include <exception>
#include <limits>
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


void Breeder::cattle()
{

    Resident::placeTo<Ranch, AnimalConfig, Animal>(this->ranch, Game::getAnimalConfig(), [this](){ return this->inventory.checkInventoryAnimal();}, "Peternakan");
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

void Breeder::harvest()
{

    Resident::harvest<Ranch, AnimalConfig>(this->ranch, Game::getAnimalConfig(), Animal::getHarvestResult(),"Peternakan");
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

int Breeder::calculateTax()
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
    file << ranchItems.countOccupied() << endl;
    for (int j = 0; j < ranchItems.getCol(); j++)
    {
        for (int i = 0; i < ranchItems.getRow(); i++)
        {
            if (ranchItems.see(i, j) != nullptr)
            {
                shared_ptr<Animal> animal = ranchItems.see(i, j);
                file << char('A' + j);
                if (i + 1 < 10)
                {
                    file << '0' << i + 1 << " " << animal->getName() << " " << animal->getWeight() << endl;
                }
                else
                {
                    file << i + 1 << " " << animal->getName() << " " << animal->getWeight() << endl;
                }
            }
        }
    }

    file.close();
}