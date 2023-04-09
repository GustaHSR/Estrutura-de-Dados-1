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
			cauda->setProx(cabeca);
			cabeca->setAnt(cauda);
			
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
			if(vazia()) cout << "Lista vazia!\n" << endl;
			else if(!existe(v)){
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
				if(qtd == 0) cabeca = NULL;
				
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
				sleep(1);
				while (c->obterValor() != v) {
					c = c->obterProx();
				}
				while (p < a) {
					cout << c->obterValor() << " ";
					c = c->obterProx();
					if(c->obterValor()==v) p++;
				}
				sleep(1);
			}
		}
};
ListaCircular* l = new ListaCircular();
int main(){
	system("clear");
    
    int cases;
    cout << "Digite 1 para inserir algum elemento na lista." << endl;
    cout << "Digite 2 para remover algum elemento da lista." << endl;
    cout << "Digite 3 para ver se existe algum elemento na lista." << endl;
    cout << "Digite 4 para percorrer a lista a partir de um elemento especifico." << endl;
    cout << "Digite 5 para mostrar a lista." << endl;
    cout << "Digite 0 para encerrar o programa.\n" << endl;

	cin >> cases;
	int a;

	switch(cases) {
		case 1:
			cout<< "Qual numero deseja inserir na lista? ";
			cin>>a;
			l->inserir(a);
			cout << "Numero " << a << " inserido na lista com sucesso!" << endl;
			sleep(1);
			return main();
		case 2:
			cout << "Qual numero deseja remover da lista? ";
			cin >> a;
			l->remover(a);
			if(l->existe(a)) cout <<"\nElemento " << a << " removido com sucesso!" << endl;
			sleep(1);
			return main();
		case 3:
			cout << "Digite um elemento a ser procurado na lista: ";
			cin >> a;
			if(l->existe(a)) cout << "\nO elemento " << a << " está na fila!" << endl;
			else cout << "\nO elemento não está na lista!" << endl;
			sleep(1);
			return main ();
		case 4:
			if(l->vazia()) cout << "Lista Vazia!\n";
			else {
				l->mostrar();
				cout << "\nDigite o elemento elemento da lista para começar a percorrer: ";
				cin >> a;
				l->percorrer(a);
				cout << "\nLista percorrida!" << endl;
				sleep(3);
			} 
			return main ();
		case 5:
			l->mostrar();
			sleep(1);
			return main();
		case 0:
			break;		
	}
    return 0;
}
