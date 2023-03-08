#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pb push_back

void print (char* vet, int n, int index) {
    char vet2[n*2];
    for (int i = 0; i < n;i++) {
        vet2[i] = vet2[i+n] = vet[i];
    }
    for (int i = 0; i < n; i++) {
        cout << vet2[i+index];
    }
}

int main() {
    int n = 5;
    int index = 2;
	char vet[n]={'a','b','c','d','e'};
    print(vet,n,index);
}
