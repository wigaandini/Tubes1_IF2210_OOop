    #include "Inventory.hpp"
    using namespace std;

    int main() {
        Inventory<string> g(6, 10, "000");

        g.put("A01", "HTL");
        g.put("A02", "XXX");
        g.put("C04", "YYY");
        g.put("D04", "HHH");
        g.put("C05", "HHH");
        g.put("D05", "YYY");

        g.displayStorage(true);
        return 0;
    }