#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back

using namespace std;

class Node {
    private:
        int no;
        Node* esq;
        Node* dir;
    public:
        Node(int no) {
            this->no = no;
            esq = dir = NULL;
        }
        virtual ~Node () {
            delete esq;
            delete dir;
        }
        void insertEsq (Node* x) {
            esq = x;
        }
        void insertDir (Node* x) {
            dir = x;
        }
        Node* travelEsq () {
            return esq;
        }
        Node* travelDir () {
            return dir;
        }
        void setNo (int x) {
            no = x;
        }
        int getNo () {
            return no;
        }
};

class Tree {
    private:

    public:
        Criar();
        Caminhar();
        ObterNo();
        RotEsq();
        RotDir();
        Balancear();
        InsertFolha();
        Existe();
        Empty();
        Remove();
        PrintTree();
        PrintGalho();
        PrintVal();
};

int main () {

}
