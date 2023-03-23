#include <iostream>

using namespace std;

// classe Node
class No
{
    private:
    int v;
    No* prox;
    public:
    No(int v) // construtor
    {
        this->v = v;
        this->prox = NULL;
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

// classe Lista
class Lista
{
    private:
    No* cabeca; // primeiro elemento
    No* cauda; // último elemento

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
        cabeca = new No(v);
        cauda = cabeca;
    }

    virtual ~Lista() // destrutor
{
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

    // insere no início
    void inserir_inicio(int v)
    {
        No* novo_no = new No(v);

        if(vazia())
        {
            cabeca = novo_no;
            cauda = novo_no;
        }
        else
        {
            novo_no->setProx(cabeca);
            cabeca = novo_no;
        }
    }

    // insere no final
    void inserir_final(int v)
    {
        No* novo_no = new No(v);

        if(vazia())
        {
            cabeca = novo_no;
            cauda = novo_no;
        }
        else
        {
            cauda->setProx(novo_no);
            cauda = novo_no;
        }
    }

    // retorna o tamanho da lista
    int tamanho()
    {
        if(vazia()) // se for vazia, então retorna 0
            return 0;

        No* c = cabeca;
        int tam = 0;

        // percorre a lista
        do
        {
            c = c->obterProx();
            tam++;
        }
        while(c);

        return tam;
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
    void remover()
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

                while(corrente)
                {
                    No* aux = ant;
                    ant = corrente;
                    ant_ant = aux;
                    corrente = corrente->obterProx();
                }
                delete ant_ant->obterProx(); // libera memória
                ant_ant->setProx(NULL); // seta o prox como NULL
                cauda = ant_ant; // atualiza a cauda
            }
        }
    }
};

class Fila {
    private:
    No* cabeca; // primeiro elemento
    No* cauda; // último elemento

    public:
    Fila()
    {
        // se não passar elemento, então cabeca e cauda são NULL
        cabeca = NULL;
        cauda = NULL;
    }

    Fila(int v)
    {
        // se passar elemento, então cria novo No
        cabeca = new No(v);
        cauda = cabeca;
    }

    virtual ~Fila() // destrutor
{
    delete cabeca;
}

    void show() // mostra todos os elementos da lista
    {
        cout << "\nImprimindo todos os elementos...\n";
        No* c = cabeca;

        if(empty())
            cout << "A fila NAO possui elementos!!\n";
        else
        {
            while(c) // percorre a fila
            {
                cout << c->obterValor() << endl;
                c = c->obterProx();
            }
            cout << endl;
        }
    }

    bool empty() // verifica se a fila está vazia
    {
        return (cabeca == NULL);
    }

    // insere no início
    void push(int v)
    {
        No* novo_no = new No(v);

        if(empty())
        {
            cabeca = novo_no;
            cauda = novo_no;
        }
        else
        {
            novo_no->setProx(cabeca);
            cabeca = novo_no;
        }
    }

    // retorna o tamanho da fila
    int size()
    {
        if(empty()) // se for vazia, então retorna 0
            return 0;

        No* c = cabeca;
        int tam = 0;

        // percorre a fila
        do
        {
            c = c->obterProx();
            tam++;
        }
        while(c);

        return tam;
    }

    // verifica se um elemento existe na fila
    bool have(int v)
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

    // remove da fila, remoção do final
    void pop()
    {
        if(!empty())
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

                while(corrente)
                {
                    No* aux = ant;
                    ant = corrente;
                    ant_ant = aux;
                    corrente = corrente->obterProx();
                }
                delete ant_ant->obterProx(); // libera memória
                ant_ant->setProx(NULL); // seta o prox como NULL
                cauda = ant_ant; // atualiza a cauda
            }
        }
    }
};

class Pilha {
    private:
    No* cabeca; // primeiro elemento
    No* cauda; // último elemento

    public:
    Pilha()
    {
        // se não passar elemento, então cabeca e cauda são NULL
        cabeca = NULL;
        cauda = NULL;
    }

    Pilha(int v)
    {
        // se passar elemento, então cria novo No
        cabeca = new No(v);
        cauda = cabeca;
    }

    virtual ~Pilha() // destrutor
{
    delete cabeca;
}

    void top() // mostra todos os elementos da pilha
    {
        No* c = cauda;

        if(empty())
            cout << "A fila NAO possui elementos!!\n";
        else
        {
           cout << "O topo da pilha é: " << c->obterValor() << endl;
        }
    }

    bool empty() // verifica se a pilha está vazia
    {
        return (cabeca == NULL);
    }

    // insere no final
    void push(int v)
    {
        No* novo_no = new No(v);

        if(empty())
        {
            cabeca = novo_no;
            cauda = novo_no;
        }
        else
        {
            cauda->setProx(novo_no);
            cauda = novo_no;
        }
    }
    void show() // mostra todos os elementos da lista
    {
        cout << "\nImprimindo todos os elementos...\n";
        No* c = cabeca;

        if(empty())
            cout << "A fila NAO possui elementos!!\n";
        else
        {
            while(c) // percorre a fila
            {
                cout << c->obterValor() << endl;
                c = c->obterProx();
            }
            cout << endl;
        }
    }

    // retorna o tamanho da fila
    int size()
    {
        if(empty()) // se for vazia, então retorna 0
            return 0;

        No* c = cabeca;
        int tam = 0;

        // percorre a fila
        do
        {
            c = c->obterProx();
            tam++;
        }
        while(c);

        return tam;
    }

    // verifica se um elemento existe na fila
    bool have(int v)
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

    // remove da fila, remoção do final
    void pop()
    {
        if(!empty())
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

                while(corrente)
                {
                    No* aux = ant;
                    ant = corrente;
                    ant_ant = aux;
                    corrente = corrente->obterProx();
                }
                delete ant_ant->obterProx(); // libera memória
                ant_ant->setProx(NULL); // seta o prox como NULL
                cauda = ant_ant; // atualiza a cauda
            }
        }
    }
};


int main () {
  //usar os m
}
