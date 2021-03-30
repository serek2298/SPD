#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    int n[11],P[11][30],W[11][30],D[11][30];
    std::string names[11] = {"data.10:","data.11:","data.12:","data.13:","data.14:","data.15:","data.16:","data.17:","data.18:","data.19:","data.20:"};
    std::ifstream f("data.txt");
    std::string s;

    if(f) {
        //////WCZYTYWANIE////
        for (int k = 0; k < 11; k++) {
            while (s != names[k])f >> s;
            f >> n[k];
            for (int i = 0; i < n[k]; i++)
                f >> P[k][i] >> W[k][i] >> D[k][i];
        }
        f.close();

        //////ALGORYTM//////
        for(int k=0;k<11;k++){
            int N = 1 << n[k];
            int* F = new int[N];
            F[0]=0;
            for(int set=1;set<N;set++){
                int c=0;
                for(int i=0,b=1;i<n[k];i++,b*=2)if(set&b) c += P[k][i];
                    F[set] = 99999999;
                    for(int i=0,b=1;i<n[k];i++,b*=2)
                            F[set] = std::min(F[set], F[set - b] + (W[k][i] * std::max(c - D[k][i], 0)));

            }
            std::cout<<"opt: "<<F[N-1]<<std::endl;
            delete[] F;
        }


    }else std::cout<<"file not opened";
    return 0;
}
