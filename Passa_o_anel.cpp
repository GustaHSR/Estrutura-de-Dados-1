#include <bits/stdc++.h>

using namespace std;

#define para(x,y) for(int i = 0; i < y;i++) x[i]=i
#define rpara(x,y) for(int i = 0; i < y;i++) x[i]=rand()%100
#define impv(x,y) for(int i = 0; i < y;i++) cout << x[i] << " "
#define imp(x,y) for(int i = 0; i < y;i++) cout << x << '\n'
#define out(x) cout << x << '\n'
#define outl() cout << '\n';
#define pb push_back
#define ff first
#define ss second
#define ll long long
#define ld long double
#define endl '\n'

void preenche_com_o (int *fila, int n) {
    for (int i = 0; i < n; i++) {
        fila[i] = 0;
    }
}

void passa_o_anel (int n, int aux) {
    int fila[n];
    preenche_com_o(fila, n);
    int rando;
    for (int i = 0; i < n;i++) {
        aux++;
        rando = rand() %100;
        if(rando <= 19) {
            fila[i] = 1;
            impv(fila,n);
            outl();
            return;
        }
        if(aux == 2 and i == n-1) {
            fila[i] = 1;
            impv(fila,n);
            outl();
            return;
        }
    }
    return passa_o_anel(n,aux+1);

    
}

int main () {
    int n; cin >> n;
    srand(time(NULL));
    int aux = 0;
    passa_o_anel(n,aux);
}
