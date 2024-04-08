#include "Mayor.hpp"

Mayor::Mayor(): Player(){

}

Mayor::Mayor(string username, float weight, int gulden):Player(username,weight,gulden){
    
}

Mayor::~Mayor(){

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