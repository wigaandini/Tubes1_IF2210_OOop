#include "Player.hpp"
#include "../Game/Game.hpp"


int Player::countIdPlayer = 1;

Player::Player(){
    this->playerId = countIdPlayer++;
    this->username = "anonim";
    this->weight = 40;
    this->gulden = 50;
    Item i;

    this->inventory = new Inventory(Game::getMainConfig().inventorySize[0], Game::getMainConfig().inventorySize[1], i);
}

Player::Player(string username, int weight, int gulden){
    this->playerId = countIdPlayer++;
    this->username = username;
    this->weight = weight;
    this->gulden = gulden;
    Item i;
    this->inventory = new Inventory(Game::getMainConfig().inventorySize[0], Game::getMainConfig().inventorySize[1], i); 
    countIdPlayer++;
}

Player::~Player(){
    delete this->inventory;
}

void Player::eat(){
    cout << "Pilih makanan dari penyimpanan" << endl;
    this->inventory->displayStorage(false);
    cout << endl << "Slot: ";
    string slot;
    cin >> slot;

    if(this->inventory->see(slot).getItemId() == -1){
        cout << "Kamu mengambil harapan kosong dari penyimpanan." << endl << "Silahkan masukan slot yang berisi makanan." << endl;
    } else{
        if(Game::getProductConfig().find(this->inventory->see(slot).getName()) != Game::getProductConfig().end()){
            
            int x = Game::getProductConfig()[this->inventory->see(slot).getName()].addedWeight;
        
            this->inventory->take(slot);
            cout << "Dengan lahapnya, kamu memakanan hidangan itu" << endl << "Alhasil, berat badan kamu naik menjadi " << this->weight + x << endl;
        } else{
           cout << "Apa yang kamu lakukan?!! Kamu mencoba untuk memakan itu?!!" << endl << "Silahkan masukan slot yang berisi makanan." << endl;
        }
    }
}

void Player::buy() {
    cout << "halo";
}
void Player::sell() {

}