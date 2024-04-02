#include "Player.hpp"


int Player::countPlayer = 0;

Player::Player(){
    playerId = ++countPlayer;
    username = "anonim";
    weight = 40;
    gulden = 50;
    countPlayer++;
}

Player::Player(string username, float weight, int gulden){
    this->playerId = ++countPlayer;
    this->username = username;
    this->weight = weight;
    this->gulden = gulden;
    countPlayer++;
}

Player::~Player(){
    countPlayer--;
}

void eat(string slotFood){}