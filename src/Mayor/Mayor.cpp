#include "Mayor.hpp"
#include "../Breeder/Breeder.hpp"
#include "../Farmer/Farmer.hpp"
#include <algorithm>

Mayor::Mayor(): Player(){
    type = "Walikota";
}

Mayor::Mayor(int playerId, string username, float weight, int gulden): Player(username, weight, gulden){
    type = "Walikota";
}

Mayor::~Mayor(){}

string Mayor::getType(){
    return type;
}

void Mayor::taxCollection(vector<Player*> players){
    vector<Player*> residents; int tax, sumTax = 0 ;
    cout << "Cring cring cring..." << endl;
    cout << "Pajak sudah dipungut!" << endl << endl;
    cout << "Berikut adalah detil dari pemungutan pajak:" << endl;

    for(Player* player : players){
        if(player->getType() != "Walikota"){
            residents.push_back(player);
        } 
    }
    sort(players.begin(), players.end(), [](Player* a, Player* b){
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
    cout << "Bangunan yang ingin dibangun: ";
    cin >> buildingName;
           
}

void Mayor::addPlayer(vector<Player*> players){
    if(gulden >= 50){
        string playerType; string playerName;
        cout << "Masukkan jenis pemain: ";
        cin >> playerType;
        cout << "Masukkan nama pemain: ";
        cin >> playerName;
        auto itr = find_if(players.begin(), players.end(), [&playerName](Player* player){player->getName() == playerName;});
        if(itr == players.end()){
            Player* newPlayer;
            if(playerType == "Peternak"){
                newPlayer = new Breeder(playerName, 40, 50);
            } else{
                newPlayer = new Farmer(playerName, 40, 50);
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