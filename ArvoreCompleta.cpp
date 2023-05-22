#include <bits/stdc++.h>

using namespace std;

class No {
public:
    int value;
    No* left;
    No* right;
    No(int value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }

    int BalancedFactor () {
        int right_height = this->right ? this->right->height() : -1;
        int left_height = this->left ? this->left->height() : -1;
        return right_height - left_height;
    }

    int height() {
        int right_height = this->right ? this->right->height() : -1;
        int left_height = this->left ? this->left->height() : -1;
        return 1 + max(right_height, left_height);
    }
};

class Tree {
public:
    No* root;
    Tree() {
        this->root = nullptr;
    }

    bool exist() {
        return this->root != nullptr;
    }

    void VerifyBalance (No* node) {
        int bf = node->BalancedFactor();
        if (bf >1) {
            if (node->right->BalancedFactor() < 0)
                Double_Left_Right_Rotation(node);
            else 
                Simple_Left_Rotation(node);
        } else if (bf < -1) {
            if (node->left->BalancedFactor() > 0)
                Double_Right_Left_Rotation(node);
            else 
                Simple_Right_Rotation(node);
        }
        if (node->left != NULL)  VerifyBalance(node->left);
        if (node->right != NULL) VerifyBalance(node->right);
    }

    void Simple_Right_Rotation (No* node) {
        cout << "Simple Right Rotation..." << endl;
        No* temp = node->left;
        node->left = temp->right;
        temp->right = node;
        if(node == root) root = temp;
    }

    void Simple_Left_Rotation (No* node) {
        cout << "Simple Left Rotation..." << endl;
        No* temp = node->right;
        node->right = temp->left;
        temp->left = node;
        if (node == root) root = temp;
    }

    void Double_Right_Left_Rotation (No* node) {
        cout << "Double Rotation: Right to Left..." << endl;
        Simple_Right_Rotation(node->left);
        Simple_Left_Rotation(node);
    }

    void Double_Left_Right_Rotation (No* node) {
        cout << "Double Rotation: Left to Right ..." << endl;
        Simple_Left_Rotation(node->right);
        Simple_Right_Rotation(node);
    }

    void insert(int value) {
        No* new_node = new No(value);

        if (this->root == nullptr) {
            this->root = new_node;
        } else {
            this->_insert_recursivo(this->root, new_node);
        }
    }

    void _insert_recursivo(No* Tree, No* new_node) {
        if (new_node->value > Tree->value) {
            if (Tree->right == nullptr) {
                Tree->right = new_node;
                VerifyBalance(root);
                return;
            } else {
                this->_insert_recursivo(Tree->right, new_node);
            }
        } else {
            if (Tree->left == nullptr) {
                Tree->left = new_node;
                VerifyBalance(root);
                return;
            } else {
                this->_insert_recursivo(Tree->left, new_node);
            }
        }
    }

    bool search(int value) {
        return this->recursive_search(this->root, value);
    }

    bool recursive_search(No* Tree, int value) {
        if (Tree == nullptr) {
            return false;
        } else if (value == Tree->value) {
            return true;
        } else if (value > Tree->value) {
            return this->recursive_search(Tree->right, value);
        } else {
            return this->recursive_search(Tree->left, value);
        }
    }

    void print() {
        recursive_print(root);
    }

    void recursive_print(No* Tree) {
		if (Tree == NULL) {
			cout << "()";
		}
		else {
			cout << "(" << Tree->value;
			recursive_print (Tree->left);
			recursive_print (Tree->right);
			cout << ")";
		}
    }

    void pre_print() {
        recursive_pre_print(root);
    }
    void recursive_pre_print(No* tree) {
        if (tree != NULL)  {
            cout << tree->value;
            cout << "(";
            recursive_pre_print(tree->left);
            recursive_pre_print(tree->right);
            cout << ")";
        }
    }

    void symetric_print() {
        recursive_symetric_print(root);
    }
    void recursive_symetric_print(No* tree) {
        if (tree != NULL)  {
            cout << "(";
            recursive_symetric_print(tree->left);
            cout << tree->value;
            recursive_symetric_print(tree->right);
            cout << ")";
        }
    }

    void pos_print() {
        recursive_pos_print(root);
    }
    void recursive_pos_print(No* tree) {
         if (tree != NULL)  {
            cout << "(";
            recursive_symetric_print(tree->left);
            recursive_symetric_print(tree->right);
            cout << ")";
            cout << tree->value;
        }
    }

    void horizontal_print() {
        bool mapa[255] = {};
        recursive_horizontal_print(root,mapa);
    }
    void recursive_horizontal_print(No* tree, bool *mapa, int nivel = 0, bool esq = true) {
        if (tree != NULL) {
            mapa[nivel] = true; //Este nivel deve ser escrito
            if (nivel)
                mapa[nivel-1] = (esq)? false: true;
            recursive_horizontal_print(tree->left, mapa, nivel+1, true);
            cout << left;
            for (int i = 0; i < nivel; i++) {
                cout.width(4);
                if (i < nivel-1) {
                    cout << (mapa[i]?"|":"");
                }else {
                    cout.fill('-');
                    cout << "+";
                    cout.fill(' ');
                }
            }
            cout << "(" << tree->value << ")" << endl;

            if (nivel)
                mapa[nivel-1] = (!esq) ? false : true;
            recursive_horizontal_print(tree->right,mapa,nivel+1,false);
        }
    }

    int node_count() {
        return recursive_node_count(root);
    }
    int recursive_node_count(No* tree) {
        if (tree == NULL) {
            return 0;
        }
        return recursive_node_count(tree->left)+1+recursive_node_count(tree->right);
    }

    No* clear () {
        if (root == NULL) {
            cout << "Empty Tree" << endl;
            return NULL;
        }
        else {
            root = NULL;
            return recursive_clear(root);
        }
    }
    No* recursive_clear(No* tree) {
        if (tree == NULL) {
            return NULL;
        }
        tree->left = recursive_clear(tree->left);
        tree->right = recursive_clear(tree->right);
        delete tree;
        return NULL;

    }
    int getHeight() {
        return recursive_getHeight(root);
    }
    int recursive_getHeight (No* tree) {
        if (tree == NULL) {
            return -1;
        }
        int esq, dir;
        esq = recursive_getHeight(tree->left);
        dir = recursive_getHeight(tree->right);

        if (esq > dir) {
            return 1 + esq;
        }
        else {
            return 1 + dir;
        }
    }


};

int main() {
    Tree arvore;
    int menu = -1;
    int v;

    do {

        system("clear");
        cout << "0: EXIT" << endl;
        cout << "1: INSERT" << endl;
        cout << "2: PRINT" << endl;
        cout << "3: EXCLUIR" << endl;
        cout << "4: CLEAR" << endl;
        cout << "5: COUNT NODES" << endl;
        cout << "6: HEIGHT" << endl << endl;

        arvore.horizontal_print();
        cout << endl << ">> ";
        cin >> menu;

        switch(menu) {
            case 0:
                cout << "Ending Program...";
                break;
            case 1:
                cout << "Type the element you wanna insert in the tree: ";
                cin >> v;
                arvore.insert(v);
                break;
            case 2:
                system("clear");
                cout << "Which type of impression?" << endl;
                cout << "1: Prefixed" << endl;
                cout << "2: Symetric" << endl;
                cout << "3: Posfixed" << endl;
                cout << "4: Horizontal" << endl;
                cin >> menu;

                if(!arvore.exist()) {
                    cout << "Empty Tree" << endl;
                    cout << endl;
                }else {
                    cout << "Tree elements: " << endl;
                    switch(menu) {
                        case 1:
                            arvore.pre_print();
                            
                            break;
                        case 2:
                            arvore.symetric_print();
                           
                            break;
                        case 3:
                            arvore.pos_print();
                            
                            break;
                        case 4:
                            arvore.horizontal_print();
                            
                            break;
                        default:
                            arvore.horizontal_print();
                            break;
                    }
                    cout << endl;
                }
                menu = 2;
                sleep(2);
                break;
            case 3:
                cout << "MAINTENANCE..." << endl;
                sleep(2);
                break;
            case 4:
                arvore.clear();
                cout << "Tree successfully cleared" << endl;
                sleep(2);
                break;
            case 5:
                cout << "The tree has " << arvore.node_count() << endl;
                sleep(2);
                break;
            case 6:
                cout << "The height of the tree is " << arvore.getHeight() << "." << endl;
                sleep(2);
                break;
        }
    }while(menu!= 0);
}
