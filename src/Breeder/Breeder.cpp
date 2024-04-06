#include "Breeder.hpp"
#include "../Game/Game.hpp"
#include "../Item/Herbivore.hpp"
#include "../Item/Carnivore.hpp"
#include "../Item/Omnivore.hpp"
#include <exception>

Breeder::Breeder():Player(), ranch(new Ranch(Game::getMainConfig().ranchSize[0],Game::getMainConfig().ranchSize[1],Animal())){

}
        
Breeder::Breeder(int playerId, string username, float weight, int gulden):Player(username,weight,gulden), ranch(new Ranch(Game::getMainConfig().ranchSize[0],Game::getMainConfig().ranchSize[1],Animal())) {
    
}
        
Breeder::~Breeder(){

}
        
void Breeder::cattle(){

    if(this->inventory->isEmpty()){
        cout << "Invenotry Kosong" <<endl;
    }else if(this->ranch->countEmpty() == 0){
        cout << "Peternakan sudah penuh" <<endl;
    }else if(this->inventory->checkInventoryAnimal() == false){
        cout << "Tidak ada hewan yang bisa diternak."<<endl;
    }else{
        cout << "Pilih hewan dari peternakan"<<endl;
        this->inventory->displayStorage(false);
        string answer;
        cout << endl << "Slot: ";
        cin >> answer;
        while (Game::getAnimalConfig().find(this->inventory->see(answer).getName()) == Game::getAnimalConfig().end()){
            cout << "Maaf yang kamu pilih bukan animal"<<endl;
            cout << endl << "Slot: ";
            cin >> answer;
        }

        cout << endl << "Pilih petak tanah yang akan ditinggali"<<endl;
        this->ranch->displayStorage(false);

        cout<< endl<<"Petak tanah:";
        string answer2;
        cin >> answer2;
        while(this->ranch->see(answer2).getAnimalId() == -1){
            cout << "SLot yang dipilih sudah diisi" <<endl;
            cout<< endl<<"Petak tanah:";
            cin >> answer;
        }
        string itemName = this->inventory->see(answer).getName();
        const Item& itemRef = this->inventory->take(answer);
        const Animal* animalRef = dynamic_cast<const Animal*>(&itemRef); 
        this->ranch->put(answer2, *animalRef);

        cout << "Dengan hati-hati, kamu meletakkan seekor"<< itemName << " di kandang."<<endl;
        cout << itemName << "telah menjadi peliharaanmu sekarang!"<<endl;
    }
}
        
void Breeder::feedAnimal(){
    if(this->ranch->isEmpty()){
        cout << "Peternakan Kosong" << endl;
    }else{
        cout << "Pilih petak kandang yang akan ditinggal"<<endl;
        this->ranch->displayStorage(false);

        string answer;
        cout << "Petak Kandang: ";
        cin >> answer;
        while (Game::getAnimalConfig().find(this->ranch->see(answer).getName()) == Game::getAnimalConfig().end()){
            cout << "Maaf yang kamu pilih bukan animal"<<endl;
            cout << "Petak Kandang: ";
            cin >> answer;
        }

        cout << "Kamu memilih "<< this->ranch->see(answer).getName()<< " untuk diberi makan. "<<endl;
        cout << "Pilih pangan yang akan diberikan:"<<endl;

        this->inventory->displayStorage(false);
        bool adaMakanan = false;
         if (const Herbivore *_ = dynamic_cast<const Herbivore *>(&this->ranch->see(answer))){
            adaMakanan = this->inventory->checkInventoryFruit();

         }else if(const Carnivore *_ = dynamic_cast<const Carnivore *>(&this->ranch->see(answer))){
            adaMakanan = this->inventory->checkInventoryMeat();
        }else{
            adaMakanan = (this->inventory->checkInventoryFruit()) || (this->inventory->checkInventoryMeat());
        }
        // if(this->ranch->see(answer).getAnimalType() == AnimalType::HERBIVORE){
        //     adaMakanan = this->inventory->checkInventoryFruit();
        // }else if(this->ranch->see(answer).getAnimalType() == AnimalType::CARNIVORE){
        //     adaMakanan = this->inventory->checkInventoryMeat();
        // }else{
        //     adaMakanan = (this->inventory->checkInventoryFruit()) || (this->inventory->checkInventoryMeat());
        // }

        if(!adaMakanan){
            cout << "Tidak ada makannan untuk hewan tersebut."<<endl;
        }else{
            string answer1;

            cout << "Slot : ";
            cin >> answer1;

            const Item& itemRef = this->inventory->take(answer);
            const Product* productRef = dynamic_cast<const Product*>(&itemRef); 
            try{
                this->ranch->see(answer).eat(*productRef);

                cout << this->ranch->see(answer).getName() << " sudah diberi makan dan beratnya bertambah " << productRef->getAddedWeight() << endl;
            }catch(exception& e){
                cout << e.what();
            }
            
            
        }
        

    }   
    

}
        
void Breeder::sell(){

}
        
void Breeder::buy(){

}
        
void Breeder::harvest(){
    if(this->ranch->isEmpty()){
        cout << endl << "Peternakan anda kosong" << endl;
    } else if (!this->ranch->checkAnimalReadyToHarvest()){
        cout << endl << "Peternakan anda tidak ada yang siap dipanen" << endl;
    } else {
        this->ranch->displayStorage(true);
        cout << endl << "Pilih hewan siap panen yang kamu miliki" << endl;
        map<string, int> plantReady = this->ranch->countAnimal();
        int number = 1;
        vector<int> total;
        vector<string> kode;

        for (const auto& entry : plantReady) {
            cout << "    " << number << ". " << entry.first << " (" << entry.second << " petak siap panen)" << endl;
            number++;
            kode.push_back(entry.first);
            total.push_back(entry.second);
        }

        int answer1, answer2;
        bool sukses1 = false;
        while(!sukses1){
            cout << endl << "Nomor Hewan yang ingin dipanen: ";
            cin >> answer1;  
            if(answer1 > 0 && answer1 < number){
                sukses1 = true;
            }
        }
        
        bool sukses2 = false;
        while (!sukses2){
            cout << endl << "Berapa petak yang ingin dipanen: ";
            cin >> answer2;

            if(answer2 <= total[answer1 - 1]){
                if (answer2 > this->inventory->countEmpty()){
                    cout << endl << "Jumlah penyimpanan tidak cukup!" << endl;
                    return;
                } else {
                    sukses2 = true;
                }
            }
        }

        string slot;
        vector<string> petak;
        cout << "Pilih petak yang ingin dipanen: " << endl;
        for (int i = 0; i < answer2; i++){
            bool sukses3 = false;
            while(!sukses3){
                cout << "Petak ke-"<< i << ": ";
                cin >> slot;
                if(this->ranch->see(slot).getCode() != kode[answer1 - 1]){
                    cout << "Petak tidak sesuai. Silahkan input kembali!" << endl;
                } else{
                    petak.push_back(slot);
                    sukses3 = true;
                }
            }

            vector<Product> tempP = this->ranch->take(slot).collect();
            unsigned int k = 0;
            while( k < tempP.size()){
                this->inventory->putRandom(tempP[k]);
                k++;
            }
            
        }
        cout << endl << answer2 << "petak hewan "<<  kode[answer1 - 1] << " pada petak ";
        for(int l = 0; l < answer2; l++){
            if (l != answer2 - 1){
                cout << petak[l] << ", ";
            } else {
                cout << petak[l];
            }
        }
        cout << " telah dipanen" << endl;
    }
}
        
int Breeder::tax(){
    return 0;
}