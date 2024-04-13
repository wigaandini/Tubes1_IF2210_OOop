#include "Breeder.hpp"
#include "../Game/Game.hpp"
#include "../Item/Herbivore.hpp"
#include "../Item/Carnivore.hpp"
#include "../Item/Omnivore.hpp"
#include <exception>
#include <fstream>

Breeder::Breeder(): Resident() {
    type = "Peternak";
}
        
Breeder::Breeder(string username, float weight, int gulden):Resident(username,weight,gulden) {
    type = "Peternak";
}
        
Breeder::~Breeder(){

}

string Breeder::getType(){
    return type;
}

void Breeder::cattle()
{

    if (this->inventory.isEmpty())
    {
        cout << "Inventory Kosong" << endl;
    }
    else if (this->ranch.countEmpty() == 0)
    {
        cout << "Peternakan sudah penuh" << endl;
    }
    else if (this->inventory.checkInventoryAnimal() == false)
    {
        cout << "Tidak ada hewan yang bisa diternak." << endl;
    }
    else
    {
        cout << "Pilih hewan dari penyimpanan" << endl;
        this->inventory.displayStorage(false);
        string answer;
        cout << endl
             << "Slot: ";
        cin >> answer;
        bool sukses = false;
        while (!sukses)
        {
            if (this->inventory.see(answer) == nullptr)
            {
                cout << "Petak yang kamu pilih kosong." << endl;
                cout << "SLot: ";
                cin >> answer;
            }
            else if (Game::getAnimalConfig().find(this->inventory.see(answer)->getName()) == Game::getAnimalConfig().end())
            {
                cout << "Maaf yang kamu pilih bukan animal" << endl;
                cout << "Slot: ";
                cin >> answer;
            }
            else
            {
                sukses = true;
            }
        }

        cout << endl
             << "Pilih petak tanah yang akan ditinggali" << endl;
        this->ranch.displayStorage(false);

        cout << endl
             << "Petak tanah:";
        string answer2;
        cin >> answer2;
        while (!this->ranch.isSlotEmpty(answer2))
        {
            cout << "Slot yang dipilih sudah diisi" << endl;
            cout << endl
                 << "Petak tanah:";
            cin >> answer2;
        }

        string itemName = this->inventory.see(answer)->getName();
        // shared_ptr<Item> itemRef = this->inventory.take(answer);
        if (auto _ = dynamic_pointer_cast<Carnivore>(this->inventory.see(answer)))
        {
            this->ranch.put(answer2, dynamic_pointer_cast<Carnivore>(this->inventory.see(answer)));

        }
        else if (auto _ = dynamic_pointer_cast<Herbivore>(this->inventory.see(answer)))
        {
            this->ranch.put(answer2, dynamic_pointer_cast<Herbivore>(this->inventory.see(answer)));
        }
        else if (auto _ = dynamic_pointer_cast<Omnivore>(this->inventory.see(answer)))
        {
            this->ranch.put(answer2, dynamic_pointer_cast<Omnivore>(this->inventory.see(answer)));
        }

        this->inventory.take(answer);

        cout << "Dengan hati-hati, kamu meletakkan seekor " << itemName << " di kandang." << endl;
        cout << itemName << " telah menjadi peliharaanmu sekarang!" << endl;
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
        cout << "Pilih petak kandang yang akan ditinggal" << endl;
        this->ranch.displayStorage(false);

        string answer;
        cout << "Petak Kandang: ";
        cin >> answer;

        bool sukses = false;
        while (!sukses)
        {
            if (this->ranch.see(answer) == nullptr)
            {
                cout << "Petak yang kamu pilih kosong." << endl;
                cout << "Petak Kandang: ";
                cin >> answer;
            }
            else if (Game::getAnimalConfig().find(this->ranch.see(answer)->getName()) == Game::getAnimalConfig().end())
            {
                cout << "Maaf yang kamu pilih bukan animal" << endl;
                cout << "Petak Kandang: ";
                cin >> answer;
            }
            else
            {
                sukses = true;
            }
        }

        cout << "Kamu memilih " << this->ranch.see(answer)->getName() << " untuk diberi makan. " << endl;
        cout << "Pilih pangan yang akan diberikan:" << endl;

        this->inventory.displayStorage(false);
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
        // if(this->ranch.see(answer).getAnimalType() == AnimalType::HERBIVORE){
        //     adaMakanan = this->inventory.checkInventoryFruit();
        // }else if(this->ranch.see(answer).getAnimalType() == AnimalType::CARNIVORE){
        //     adaMakanan = this->inventory.checkInventoryMeat();
        // }else{
        //     adaMakanan = (this->inventory.checkInventoryFruit()) || (this->inventory.checkInventoryMeat());
        // }

        if (!adaMakanan)
        {
            cout << "Tidak ada makannan untuk hewan tersebut." << endl;
        }
        else
        {
            string answer1;

            cout << "Slot : ";
            cin >> answer1;

            shared_ptr<Item> itemRef = this->inventory.see(answer1);
            shared_ptr<Product> productRef = dynamic_pointer_cast<Product>(itemRef);

            if (productRef != nullptr)
            {

                try
                {
                    this->inventory.take(answer1);
                    this->ranch.see(answer)->eat(*productRef);

                    cout << this->ranch.see(answer)->getName() << " sudah diberi makan dan beratnya bertambah " << productRef->getAddedWeight() << endl
                         << endl;
                }
                catch (exception &e)
                {
                    cout << e.what();
                }

                // }catch(exception& e){
                //     cout << e.what();
                // }
            }
            else
            {
                cout << "Makanan yang dipilih tidak dapat dikonsumsi" << endl;
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

        for (const auto &entry : plantReady)
        {
            cout << "    " << number << ". " << entry.first << " (" << entry.second << " petak siap panen)" << endl;
            number++;
            kode.push_back(entry.first);
            total.push_back(entry.second);
        }

        int answer1, answer2;
        bool sukses1 = false;
        while (!sukses1)
        {
            cout << endl
                 << "Nomor Hewan yang ingin dipanen: ";
            cin >> answer1;
            if (answer1 > 0 && answer1 < number)
            {
                sukses1 = true;
            }
        }

        bool sukses2 = false;
        while (!sukses2)
        {
            cout << endl
                 << "Berapa petak yang ingin dipanen: ";
            cin >> answer2;

            if (answer2 <= total[answer1 - 1])
            {
                if (answer2 > this->inventory.countEmpty())
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
        }

        string slot;
        vector<string> petak;
        cout << "Pilih petak yang ingin dipanen: " << endl;
        for (int i = 0; i < answer2; i++)
        {
            bool sukses3 = false;
            while (!sukses3)
            {
                cout << "Petak ke-" << i << ": ";
                cin >> slot;
                if (this->ranch.see(slot)->getName() != kode[answer1 - 1])
                {
                    cout << "Petak tidak sesuai. Silahkan input kembali!" << endl;
                }
                else
                {
                    petak.push_back(slot);
                    sukses3 = true;
                }
            }

            vector<string> tempP = this->ranch.take(slot)->collect();
            unsigned int k = 0;
            while (k < tempP.size())
            {
                this->inventory.putRandom(make_shared<Product>(tempP[k]));
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

int Breeder::getWealth(){
    int wealth = gulden;
    for(int i = 0; i < this->inventory.getRow(); i++){
        for(int j = 0; j < this->inventory.getCol(); j++){
            if(this->inventory.see(i,j) != nullptr){
                wealth += this->inventory.see(i, j)->getPrice();
            }
        }
    }
    for(int i = 0; i < this->ranch.getRow(); i++){
        for(int j = 0; j < this->ranch.getCol(); j++){
            if(this->ranch.see(i,j) != nullptr){
                wealth += this->ranch.see(i, j)->getPrice();
            }
        }
    }
    return wealth;
}



int Breeder::tax(){
    int kkp = getWealth() - KTKP_PETERNAK;
    if(kkp <= 0){
        return 0;
    } else{
        if(kkp <= 6){
            return 0.05*kkp;
        } else if(kkp <= 25 && kkp > 6){
            return 0.15*kkp;
        } else if(kkp <= 50 && kkp > 25){
            return 0.25*kkp;
        } else if(kkp <= 500 && kkp > 50){
            return 0.30*kkp;
        } else{
            return 0.35*kkp;
        }
    }
}

Ranch& Breeder::getRanch(){
    return this->ranch;
}