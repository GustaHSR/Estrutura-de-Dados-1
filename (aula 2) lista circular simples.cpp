#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pb push_back

void print (char* vet, int n, int index) {
    for (int i = index; i < n+index;i++) {
		cout << vet[i%n];
	}
}

int main() {
    int n; cin >> n;
    char vet[n];
    int index;
    cin >> index;
    for (int i = 0; i < n; i++) {
        cin >> vet[i];
    }
    print(vet, n, index);
}
