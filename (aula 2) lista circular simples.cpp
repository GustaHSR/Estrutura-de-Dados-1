#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pb push_back

void print (char* vet, int n) {
    for (int i = 0; i < n;i++) {
		cout << vet[i];
	}
	cout << endl;
}
void remove (char* vet, int n) {
	char index;
	cout << "Qual elemento deseja remover? ";
	cin >> index;
    int i;
    for (i = 0; i < n and vet[i]!=index;i++);
    if (i == n) {
        cout << "Não foi possível achar o valor digitado para remover" << endl;
    }
    else {
        for (int j = i; j < n; j++) {
            vet[j] = vet[j+1];
        }
        n--;
    }
}

void inserir (char* vet, int n) {
	n++;
	char a;
	cout << "Qual elemento deseja inserir? ";
	cin >> a;
	vet[n-1] = a;
}

int main() {
    int n; cin >> n;
    char vet[n];
    for (int i = 0; i < n; i++) {
        cin >> vet[i];
    }
    print(vet,n);
    remove(vet,n);
    print(vet,n);
}
