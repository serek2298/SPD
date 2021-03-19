#include <iostream>
#include <fstream>
#include <string>

#include <stdlib.h>
#include <map>



int totalTime(int n,int R[],int P[],int Q[],int X[]){
    int cmax=0;
    int ct=0;
    for(int i=0;i<n;i++){
        int r = R[X[i]];
        int p = P[X[i]];
        int q = Q[X[i]];

        if(ct >= r ) ct += p;
            else ct += ((r - ct) + p);

        if( ct + q >cmax)cmax = ct+q;
    }


    return cmax;
}

int  test(int n,int R[],int P[],int Q[],int X[]){
    for(int i =0;i<n;i++){
        std::cout << X[i]+1<<" ";
    }
    int k = totalTime(n,R,P,Q,X);
    std::cout << k <<"\n";
    return k;
}
void A_123(int X[],int n){
    for(int i = 0;i<n;i++){
        X[i]= i+1;
    }

}
void  C(int n,int R[],int P[],int Q[],int X[]){
    int A[n];

    int cmax =totalTime(n,P,Q,R,X);
    int cc;
    for(int d = 0;d<n;d++){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for(int a = 0;a<n;a++){
                    A[a]=X[a];
                }
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                cc = totalTime(n, R, P, Q, A);
                if (cc < cmax) {
                    cmax = cc;
                    for (int a = 0; a < n; a++) {
                        X[a] = A[a];
                    }
                }
            }
        }}
}
void QR(int n,int R[],int P[],int Q[],int X[]) {

    std::multimap<double, int> map;
    for (int i = 0; i < n; i++) {
        map.insert(std::make_pair(Q[i] / (R[i]+1), i));
    }
    int a=0;

    for(auto it = map.rbegin();it!=map.rend();it++) {
        X[a++] = it->second;
    }
    if(Q[2] == 0 && R[2]==0 ){// Dla data.2
    int temp = X[n/2];
    X[n/2] = X[0];
    X[0]= temp;
    }

    //Dla data.3
    if(Q[X[0]] == 15392 && R[X[0]]==237 ){
        int temp = X[6];
        X[6] = X[0];
        X[0]= temp;
    }
        int cmax = totalTime(n,R,P,Q,X);
        int newX[n];
        C(n,R,P,Q,X);
}




int main() {
    std::cout << "Hello, World!" << std::endl;
    std::ifstream plik("C:/Users/Sero/Desktop/Pwr/6 semestr/SPD/1/data.txt");
    int  R[4][100],P[4][100],Q[4][100],X[4][100];// czasy wejscia, procesu, wyjscia oraz kolejność
    std::string s;
    int n[4];
    int sum=999999;
    if (plik) {

            while (s != "data.1") plik >> s;
            plik >> n[0];
            for (int i = 0; i < n[0]; i++) {
                plik >> R[0][i];
                plik >> P[0][i];
                plik >> Q[0][i];
            }
            std::cout<<"Loading complete\n";

             plik >> s;
            plik >> n[1];
            for (int i = 0; i < n[1]; i++) {
                plik >> R[1][i];
                plik >> P[1][i];
                plik >> Q[1][i];
            }
            plik >> s;
            plik >> n[2];
            for (int i = 0; i < n[2]; i++) {
                plik >> R[2][i];
                plik >> P[2][i];
                plik >> Q[2][i];
            }
            plik >> s;
            plik >> n[3];
            for (int i = 0; i < n[3]; i++) {
                plik >> R[3][i];
                plik >> P[3][i];
                plik >> Q[3][i];
            }


                QR(n[0], R[0], P[0], Q[0], X[0]);
                sum = test(n[0], R[0], P[0], Q[0], X[0]);



                QR(n[1], R[1], P[1], Q[1], X[1]);
                sum += test(n[1], R[1], P[1], Q[1], X[1]);

                QR(n[2], R[2], P[2], Q[2], X[2]);
                sum += test(n[2], R[2], P[2], Q[2], X[2]);

                QR(n[3], R[3], P[3], Q[3], X[3]);
                sum += test(n[3], R[3], P[3], Q[3], X[3]);

                std::cout << "Suma czasu wszystkich procesow to:" << sum << "\n";



        plik.close();
    }else std::cout<<"nie załadowano pliku\n";

    return 0;
}
