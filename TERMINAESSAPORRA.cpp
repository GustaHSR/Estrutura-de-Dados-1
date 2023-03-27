#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define endl '\n'

class Pessoa  {
    private:
        string *Nome,*Cpf,*Tel;
    public:
        Pessoa();
        void getNome(string *Nome) {
            cout << endl << "Nome: ";
            string b;
            cin >> b;
            *Nome = b;
            
        }
        void getCpf(string *Cpf) {
            cout << endl << "CPF: ";
            string b;
            cin >> b;
            *Cpf = b;
        }
        void getTel(string *Tel) {
            cout << endl << "Telefone: ";
            string b;
            cin >> b;
            *Tel = b;
        }   

    
};

class No
{
    private:
        Pessoa p;
        string Data;
        int v;
    No* prox;
    public:
    No(int v, Pessoa p, string Data) // construtor
    {
        this->v = v;
        this->prox = NULL;
        this->p = p;
        this->Data = Data;
    }


    int obterValor() // obtém o valor
    {
        return v;
    }

    No* obterProx() // obtém o próximo No
{
    return prox;
}

    void setProx(No* p) // seta o próximo No
    {
        prox = p;
    }
};

class Lista
{
    private:
    No* cabeca; // primeiro elemento
    No* cauda; // último elemento
    Pessoa* nome;
    Pessoa* cpf;
    Pessoa* tel;

    public:
    Lista()
    {
        // se não passar elemento, então cabeca e cauda são NULL
        cabeca = NULL;
        cauda = NULL;
    }

    Lista(int v)
    {
        // se passar elemento, então cria novo No
        cabeca = new No(v,p,Data);
        cauda = cabeca;
    }

    virtual ~Lista() {// destrutor 
        delete cabeca;
    }

    void mostrar() // mostra todos os elementos da lista
    {
        cout << "\nImprimindo todos os elementos...\n";
        No* c = cabeca;

        if(vazia())
            cout << "A lista NAO possui elementos!!\n";
        else
        {
            while(c) // percorre a lista
            {
                cout << c->obterValor() << endl;
                c = c->obterProx();
            }
            cout << endl;
        }
    }

    bool vazia() // verifica se a lista está vazia
    {
        return (cabeca == NULL);
    }
    // insere no final
    void inserir_final(int v)
    {
        No* novo_no = new No(v,p,Data);
        string novo_nome;
        string novo_cpf;
        string novo_tel;
        

        if(vazia())
        {
            cabeca = novo_no;
            cauda = novo_no;
        }
        else
        {
            cauda->setProx(novo_no);
            cauda = novo_no;
            nome->getNome(&novo_nome);
            cpf->getCpf(&novo_cpf);
            tel->getTel(&novo_tel);
        }
    }

    // verifica se um elemento existe na lista
    bool existe(int v)
    {
        No* c = cabeca;

        while(c)
        {
            if(c->obterValor() == v)
                return true;
            c = c->obterProx();
        }
        return false;
    }

    // remove da lista, remoção do final
    void remover(int v)
    {
        if(!vazia())
        {
            // se houver só 1 elemento
            if(cabeca->obterProx() == NULL)
                cabeca = NULL;
            else if(cabeca->obterProx()->obterProx() == NULL) // 2 elementos
            cabeca->setProx(NULL);
         else // > 2 elementos
            {
                No* ant_ant = cabeca;
                No* ant = cabeca->obterProx();
                No* corrente = cabeca->obterProx()->obterProx();

               if (existe(int v)) {
                   
               }
            }
        }
    }
};



int main () {
   cout << "aaa" << endl;

}
