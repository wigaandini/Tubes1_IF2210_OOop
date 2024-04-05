    #include "Inventory.hpp"
    using namespace std;

    int main() {
        Item def;
        Inventory g(6, 10, def);
        Item mesac("Mesac", "MSC", 0);
        Item der("Derwin", "DER", 0);
        g.put("A01", mesac);
        g.put("A02", der);
       

        g.displayStorage(true);
        return 0;
    }