    #include "src/Grid/Grid.hpp"
    using namespace std;

    int main() {
        Grid<string> g(6, 10, "000");

        g.put("A01", "HTL");
        g.put("A02", "XXX");
        g.put("C04", "YYY");
        g.put("D04", "HHH");
        g.put("C05", "HHH");
        g.put("D05", "YYY");

        cout << "Grid awal" << endl << g << endl;

        cout << "Item diambil: " << g.take("C04") << " 4C" << endl;
        cout << "Item dilihat: " << g.see("A01") << " 1A" << endl;
        g.remove("A01");
        
        cout << "Grid setelah diambil dan dihapus" << endl << g << endl;

        
        return 0;
    }