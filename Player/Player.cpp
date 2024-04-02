#include "Player.hpp"


int Player::countPlayer = 0;
Player::Player(int playerId, string username, float weight, int gulden){
    this->playerId = playerId;
    this->username = username;
    this->weight = weight;
    this->gulden = gulden;
    countPlayer++;
}

Player::~Player(){
    countPlayer--;
}

void eat(string slot){}