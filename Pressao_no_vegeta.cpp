#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define endl '\n'

double pressao_no_vegeta (double area, double pressao, int gravidade) {
    double peso = 70.6 * gravidade;
    pressao = peso / area;

    if (gravidade == 500) {
        cout << "Pressao = ";
        return pressao;
    }
    cout << "Pressao = " << pressao << endl;
    return pressao_no_vegeta(area,pressao,gravidade+10);
    
}

int main () {
   double area = 20;
   double pressao = 0.0;
   int gravidade = 10;
   cout << pressao_no_vegeta(area,pressao,gravidade) << endl << endl;
}
