#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define f first
#define s second
#define endl '\n'

class No
{
    private:
		int v;
		No* prox;
		No* ant;

	public:
		No(int v) // construtor
		{
			this->v = v;
			this->prox = NULL;
			this->ant = NULL;
		}

		int obterValor() // obtém o valor
		{
			return v;
		}

		No* obterProx() // obtém o próximo No
		{
			return prox;
		}

		No* obterAnt(){
			return ant;
		}

		void setProx(No* p) // seta o próximo No
		{
			prox = p;
		}

		void setAnt(No* a){
			ant = a;
		}

};

class ListaCircular
{
    private:
		int qtd = 0;
		No* cauda;
		No* cabeca;
	public:
		ListaCircular(){
			cabeca = NULL;
			cauda = NULL;
		}

		ListaCircular(int v){
			cabeca = new No(v);
			cauda = cabeca;
		}

		virtual ~ListaCircular(){
			No* atual = cabeca;
			No* proximo;
			for(int i = 0; i < qtd; i++){
				proximo = atual->obterProx();
				delete atual;
				atual = proximo;
			}
		}

		void mostrar(){
			No* c = cabeca;
			if(vazia())
				cout << "Lista Vazia!!\n";
			else{
				cout << "\nImprimindo a lista circular: \n";
				int cont = 1;
				while(cont <= qtd){
					cout << c->obterValor() << " ";
					c = c->obterProx();
					cont++;
				}
				cout << endl;
			}
		}

		bool vazia(){
			return cabeca == NULL;
		}

		void inserir(int v) {       
			if (qtd == 0) {
				No* newNo = new No(v);
				newNo->setProx(newNo);
				cabeca = newNo;
				cauda = newNo;
				qtd++;
			}
			else {
				No* newNo = new No(v);
				newNo->setProx(newNo);
				cauda->setProx(newNo);
				newNo->setAnt(cauda);
				cauda = newNo;
				qtd++;
			}
			
		}

		bool existe(int v){
			No* c = cabeca;
			for(int i = 0; i < qtd; i++){
				if(c->obterValor() == v){
					return true;
				}
				c = c->obterProx();
			}
			return false;
		}
		void remover(int v){
			No* c = cabeca;
			if(!existe(v)){
				cout<<"Valor nao existe na lista! ";
			}
			else {
				while(c->obterValor() != v) {
					c = c->obterProx();
				}
				if(c->obterProx()) c->obterProx()->setAnt(c->obterAnt());
				if(c->obterAnt()) c->obterAnt()->setProx(c->obterProx());
				delete c;
				qtd--;
			}
		}

		void percorrer	(int v) {
			No* c = cabeca;
			if(vazia()) {
				cout << "Fila vazia!" << endl;
			}
			else {
				cout << "Quantas vezes você quer percorrer a lista? ";
				int a;
				cin >> a;
				cout << endl;
				cout << "Percorrendo lista " << a << " vezes a partir do valor: " << v << endl << endl;
				int p = 0;
				while (c->obterValor() != v) {
					c = c->obterProx();
				}
				while (p != a) {
					cout << c->obterValor() << " ";
					c = c->obterProx();
					if(c->obterValor()==v) p++;
				}
			}
		}
};
int main(){
    ListaCircular* l = new ListaCircular();
    int cases;
    cout << "Digite 1 para inserir algum elemento na lista." << endl;
    cout << "Digite 2 para remover algum elemento da lista." << endl;
    cout << "Digite 3 para ver se existe algum elemento na lista." << endl;
    cout << "Digite 4 para percorrer a lista a partir de um elemento especifico." << endl;
    cout << "Digite 5 para mostrar a lista." << endl;
    cout << "Digite 0 para encerrar o programa." << endl;
    

    return 0;
}
