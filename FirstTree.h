#ifndef HEADER_H
#define HEADER_H

#include <bits/stdc++.h>
using namespace std;

class Node {
   private:
		int v;
		Node* right;
		Node* left;

	public:
		Node(int v) // construtor
		{
			this->v = v;
			this->right = NULL;
			this->left = NULL;
		}
		int getValor() // obtém o valor
		{
			return v;
		}
		Node* getright() // obtém o próximo Node
		{
			return right;
		}
		Node* getleft(){
			return left;
		}
		void setright(Node* p) // seta o próximo Node
		{
			right = p;
		}
		void setleft(Node* a){
			left = a;
		}   
};

class Tree {
    private:
        Node* root;
    public:
        Tree() {
            root = NULL;
        }

        void insert(int filho) {
            Node* novofilho = new Node(filho);
            if(root == NULL) {
                root = novofilho;
            }
            else if(novofilho->getValor() < root->getValor()) {
                if(root->getleft() == NULL) {
                    root->setleft(novofilho);
                    return;
                }
                root = root->getleft();
                insert(filho);
            }
            else if(novofilho->getValor() > root->getValor()) {
                if(root->getright() == NULL) {
                    root->setright(novofilho);
                    return;
                }
                root = root->getright();
                insert(filho);
            }

        }

        void print(Tree arvore) {
            if(arvore.root == NULL) {
                cout << "()";
            }
            else {
                cout<<"("<<arvore->getValor();
                print(arvore->getleft());
                print(arvore->getright());
                cout << ")";
            }
        }

        void search(int);
        bool exist();
};




#endif 
