#include "src/Ranch/Ranch.hpp"

using namespace std;
int main() {
    Animal def;
    Ranch g(6, 10, def);
    Animal mesac;
    mesac.setCode("MSC");
    mesac.setAnimalId(1);
    mesac.setName("Mesac");
    Animal der;
    der.setName("der");
    der.setAnimalId(2);
    der.setCode("DER");
    der.setWeight(100);
    der.setWeightToHarvest(90);
    mesac.setWeight(10);
    mesac.setWeightToHarvest(20);
    g.put("A01", mesac);
    g.put("A02", der);
    g.displayStorage(true);
    return 0;
}