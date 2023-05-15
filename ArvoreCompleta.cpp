#include <iostream>

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
        if (node->left)  VerifyBalance(node->left);
        if (node->right) VerifyBalance(node->right);
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
                VerifyBalance(Tree);
                return;
            } else {
                this->_insert_recursivo(Tree->right, new_node);
            }
        } else {
            if (Tree->left == nullptr) {
                Tree->left = new_node;
                VerifyBalance(Tree);
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
};

int main() {
    Tree arvore;
    arvore.insert(22);
    arvore.insert(15);
    arvore.print();
    cout << endl << endl;
    arvore.insert(7);
    arvore.insert(2);
    arvore.insert(14);
    arvore.print();
    cout << endl << endl;
}
