#include "Farmer.hpp"
#include "../Game/Game.hpp"

Farmer::Farmer() : Player(){
    type = "Petani";
    Plant p;
    this->farm = new Farm(Game::getMainConfig().farmSize[0], Game::getMainConfig().farmSize[1], p);
}

Farmer::Farmer(string username, int weight, int gulden) : Player(username, weight, gulden){
    type = "Petani";
    Plant p;
    this->farm = new Farm(Game::getMainConfig().farmSize[0], Game::getMainConfig().farmSize[1], p);
}

Farmer::~Farmer(){
    delete farm;
}

string Farmer::getType(){
    return type;
}
void Farmer::plant(){
    if(this->inventory->isEmpty()){
        cout << endl << "Inventory anda kosong" << endl;
    } else if (!this->inventory->checkInventoryPlant()){
        cout << endl << "Inventory anda tidak ada tanaman" << endl;
    }else if(!this->farm->isEmpty()){
        cout << endl << "Ladang anda penuh" << endl;
    } else {
        this->inventory->displayStorage(false);
        bool success = false;
        while(!success){
            cout << endl << "Slot: ";
            string slot;
            cin >> slot;
            if(this->inventory->see(slot).getItemId() == -1){
                cout << endl << "Kamu mengambil harapan kosong dari penyimpanan." << endl << "Silahkan masukan slot yang berisi tanaman." << endl;
            } else{
                if(Game::getPlantConfig().find(this->inventory->see(slot).getName()) != Game::getPlantConfig().end()){
                    string s = Game::getPlantConfig()[this->inventory->see(slot).getName()].name;
                    cout << endl << "Kamu memilih " << s << "." << endl;
                    cout << endl << "Pilih petak tanah yang akan ditanami" << endl; 
                    const Item& itemRef = this->inventory->take(slot);
                    const Plant& plantRef = dynamic_cast<const Plant&>(itemRef); 

                    this->farm->displayStorage(false);
                    bool done = false;
                    while(!done){
                        cout << endl << "Petak: ";
                        string petak;
                        cin >> petak;
                        if(this->farm->see(petak).getItemId() != -1){
                            cout << endl << "Petak sudah terisi." << endl << "Silahkan masukan petak yang kosong." << endl;
                        } else {
                            this->farm->put(petak, plantRef);
                            cout << endl << "Cangkul, cangkul, cangkul yang dalam~!" << endl << "Orange tree berhasil ditanam!" << endl;
                            done = true;
                        }
                    }
                    success = true;
                } else {
                    cout << "Apa yang kamu lakukan?!! Kamu mencoba untuk menanam itu?!!" << endl << "Silahkan masukan slot yang berisi tanaman." << endl;
                }
            }
        }
    }

}

void Farmer::sell(){

}

void Farmer::buy(){

}

void Farmer::harvest(){
    if(this->farm->isEmpty()){
        cout << endl << "Ladang anda kosong" << endl;
    } else if (!this->farm->checkPlantReadyToHarvest()){
        cout << endl << "Ladang anda tidak ada yang siap dipanen" << endl;
    } else {
        this->farm->displayStorage(true);
        cout << endl << "Pilih tanaman siap panen yang kamu miliki" << endl;
        map<string, int> plantReady = this->farm->countPlant();
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
            cout << endl << "Nomor tanaman yang ingin dipanen: ";
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
                if(this->farm->see(slot).getCode() != kode[answer1 - 1]){
                    cout << "Petak tidak sesuai. Silahkan input kembali!" << endl;
                } else{
                    petak.push_back(slot);
                    sukses3 = true;
                }
            }

            vector<Product> tempP = this->farm->take(slot).collect();
            unsigned int k = 0;
            while( k < tempP.size()){
                this->inventory->putRandom(tempP[k]);
                k++;
            }
            
        }
        cout << endl << answer2 << "petak tanaman "<<  kode[answer1 - 1] << " pada petak ";
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

int Farmer::getWealth(){
    int wealth = gulden;
    for(int i = 0; i < inventory->getRow(); i++){
        for(int j = 0; j < inventory->getcol(); j++){
            wealth += inventory->getElmt(i,j).getPrice();
        }
    }
    for(int i = 0; i < farm->getRow(); i++){
        for(int j = 0; j < farm->getcol(); j++){
            wealth += farm->getElmt(i,j).getPrice();
        }
    }
    for(auto building: buildings){
        wealth += building.getPrice();
    }
    return wealth;
}

int Farmer::tax(){
    int kkp = getWealth() - KTKP;
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

