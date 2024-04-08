#include "Mayor.hpp"
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