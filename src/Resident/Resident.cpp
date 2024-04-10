#include "Resident.hpp"


Resident::~Resident(){

}

Resident::Resident(): Player() {

}

Resident::Resident(string username, int weight, int gulden):Player(username,weight,gulden) {
}