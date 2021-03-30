#include <iostream>
#include <fstream>
#include <string>


int main() {
    std::cout << "Hello, World!" << std::endl;
    int n[11],P[11][30],W[11][30],D[30][30];
    std::string names[11] = {"data.10:","data.11:","data.12:","data.13:","data.14:","data.15:","data.16:","data.17:","data.18:","data.19:","data.20:"};
    std::ifstream f("data.txt");
    std::string s;
    //////WCZYTYWANIE////
    if(f) {
        for (int k = 0; k < 11; k++) {
            while (s != names[k])f >> s;
            f >> n[k];
            for (int i = 0; i < n[k]; i++) {
                f >> P[k][i] >> W[k][i] >> D[k][i];
                std::cout << n << "\n";
                std::cout << P[k][i] << "\t" << W[k][i] << "\t" << D[k][i] << "\n";
            }
        }
        std::cout << P[2][10] << "P210\n";
        f.close();
        //////ALGORYTM//////
        int N = 1 << n[0];
        std::cout << N;


    }else std::cout<<"file not opened";
    return 0;
}
