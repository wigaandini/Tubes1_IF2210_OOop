#include "Ranch.hpp"
using namespace std;
int main() {
    Animal def;
    Ranch g(6, 10, def);
    Animal mesac;
    mesac.setCode("MSC");
    Animal der;
    der.setCode("DER");
    g.put("A01", mesac);
    g.put("A02", der);
    cout << g;
    return 0;
}