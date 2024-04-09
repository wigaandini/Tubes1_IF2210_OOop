#include "Mayor.hpp"
#include "../Breeder/Breeder.hpp"
#include "../Farmer/Farmer.hpp"
#include <algorithm>

Mayor::Mayor(): Player(){
    type = "Walikota";
}

Mayor::Mayor( string username, float weight, int gulden): Player(username, weight, gulden){
    type = "Walikota";
}

Mayor::~Mayor(){}

string Mayor::getType(){
    return type;
}

int Mayor::getWealth(){
    return 0;
}

string Mayor::toLower(string s){
    string snew;
    for(char c: s){
        snew += tolower(c);
    }
    return snew;
}

void Mayor::taxCollection(vector<shared_ptr<Player>>& players){
    vector<shared_ptr<Player>> residents; int tax, sumTax = 0 ;
    cout << "Cring cring cring..." << endl;
    cout << "Pajak sudah dipungut!" << endl << endl;
    cout << "Berikut adalah detil dari pemungutan pajak:" << endl;

    for(auto player : players){
        if(player->getType() != "Walikota"){
            residents.push_back(player);
        } 
    }
    sort(players.begin(), players.end(), [](auto a, auto b){
        if(a->getWealth() == b->getWealth()){
            return a->getName() < b->getName();
        }
        return a->getWealth() > b->getWealth();
    });

    for(int i = 0; i < int(residents.size()); i++){
        cout << "    "<< i+1 << ". " << residents[i]->getName() << " - " << residents[i]->getType() << ": ";
        tax = (residents[i]->getGulden() >= residents[i]->tax())? residents[i]->tax(): residents[i]->getGulden(); // Bayar pajak semampunya
        cout << tax << " gulden" << endl;
        residents[i]->setGulden(residents[i]->getGulden()-tax);
        sumTax += tax;
    }
    cout << "Negara mendapatkan pemasukan sebesar " << sumTax << " gulden." << endl;
    cout << "Gunakan dengan baik dan jangan dikorupsi ya!" << endl;
    gulden += sumTax;
}

bool Mayor::canBuild(string buildingName, map<string, RecipeConfig> recipe){
    auto itr = find_if(recipe.begin(), recipe.end(), [buildingName](pair<string, RecipeConfig> building){return buildingName == building.second.name;});
    if(itr != recipe.end()){
        map<string, int> availableMaterials;
        for(auto material: itr->second.materials){
            availableMaterials[material.first] = 0;
            for(int i = 0; i < this->inventory.getRow(); i++){
                for(int j = 0; j < this->inventory.getcol(); j++){
                    if(this->inventory.see(i,j)->getName() == material.first){
                        availableMaterials[material.first]++;
                    }
                }
            }
            availableMaterials[material.first] -= material.second;
        }
        
        auto checkNegItr = find_if(availableMaterials.begin(), availableMaterials.end(), [](pair<string,int> material){return material.second < 0;});
        if(checkNegItr != availableMaterials.end() || gulden < itr->second.price){
            cout << "Kamu tidak punya sumber daya yang cukup! Masih memerlukan ";
            if(gulden < itr->second.price){
                cout << itr->second.price - gulden << " gulden ";
            }
            if(checkNegItr != availableMaterials.end()){
                for(auto availableMaterial: availableMaterials){
                    if(availableMaterial.second < 0 ){
                        cout << availableMaterial.second*-1 << " " << availableMaterial.first << " "; 
                    }
                }
            }
            cout << "!" << endl;
            return false;
        }
        // Kasus ketika SDA cukup untuk membangun building
        gulden -= itr->second.price;
        for(auto material: itr->second.materials){
            for(int k = 0; k < material.second; k++){
                for(int i = 0; i < inventory.getRow(); i++){
                    for(int j = 0; j < inventory.getcol(); j++){
                        if(this->inventory.see(i,j)->getName() == material.first){
                            inventory.remove(i,j);
                        }
                    }
                }
            }
        }
    } else{
        cout << "Kamu tidak punya resep bangunan tersebut!" << endl;
        cout << "Resep bangunan yang ada adalah sebagai berikut." << endl;
        for(auto itr = recipe.begin(); itr != recipe.end(); itr++){
            cout << "   " << itr->second.id << ". " << itr->second.name << "(" << itr->second.price << " gulden, "; 
            int ctr = 0;
            for(auto material: itr->second.materials){
                cout << material.first << " " <<  material.second;
                if(ctr < int(itr->second.materials.size())){
                    cout << ",";
                }
                ctr++;
            }
            cout << ")" << endl;
        }
        return false;
    }
    return true;
}

void Mayor::buildBuilding(map<string, RecipeConfig> recipe){
    cout << "Resep bangunan yang ada adalah sebagai berikut." << endl;
    for(auto itr = recipe.begin(); itr != recipe.end(); itr++){
        cout << "   " << itr->second.id << ". " << itr->second.name << "(" << itr->second.price << " gulden, "; 
        int ctr = 0;
        for(auto material: itr->second.materials){
            cout << material.first << " " <<  material.second;
            if(ctr < int(itr->second.materials.size())){
                cout << ",";
            }
            ctr++;
        }
        cout << ")" << endl;
    }
    cout << endl;
    string buildingName;
    do{
        cout << "Bangunan yang ingin dibangun: ";
        cin >> buildingName;
    } while(!canBuild(buildingName, recipe));
    cout << buildingName << "berhasil dibangun dan telah menjadi hak milik walikota!" << endl;
    inventory.putRandom(make_shared<Building>(buildingName));
}

void Mayor::addPlayer(vector<shared_ptr<Player>>& players){
    if(gulden >= 50){
        string playerType; string playerName;
        cout << "Masukkan jenis pemain: ";
        cin >> playerType;
        playerType = toLower(playerType);
        cout << "Masukkan nama pemain: ";
        cin >> playerName;
        auto itr = find_if(players.begin(), players.end(), [&playerName, this](auto player){return toLower(player->getName()) == toLower(playerName);});
        if(itr == players.end()){
            shared_ptr<Player> newPlayer;
            if(playerType == "peternak"){
                newPlayer = make_shared<Breeder>(playerName, 40, 50);
            } else if (playerType == "petani"){
                newPlayer = make_shared<Farmer>(playerName, 40, 50);
            }
            players.push_back(newPlayer);
            gulden -= 50;
            cout << "Pemain baru ditambahkan!" << endl;
            cout << "Selamat datang \"" << playerName <<"\" di kota ini!" << endl;
        } else{
            cout << "Pemain dengan nama " << playerName << "telah terdaftar!" << endl; 
        }

    } else{
        cout << "Uang tidak cukup!" << endl;
    }
}

int Mayor::tax(){
    return 0;
}

void Mayor::buy(){
    cout<<"ini beli";
}

void Mayor::sell(){
    cout<<"ini jual";
}