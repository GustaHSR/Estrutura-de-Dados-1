#include "Arvore.h"

int main()
{
    Tree arvore;
    int menu = -1;
    int v;

    do
    {

        system("clear");
        cout << "0: EXIT" << endl;
        cout << "1: INSERT" << endl;
        cout << "2: PRINT" << endl;
        cout << "3: EXCLUIR" << endl;
        cout << "4: CLEAR" << endl;
        cout << "5: COUNT NODES" << endl;
        cout << "6: HEIGHT" << endl
             << endl;

        arvore.horizontal_print();
        cout << endl
             << ">> ";
        cin >> menu;

        switch (menu)
        {
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

            if (!arvore.exist())
            {
                cout << "Empty Tree" << endl;
                cout << endl;
            }
            else
            {
                cout << "Tree elements: " << endl;
                switch (menu)
                {
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
            system("clear");
            cout << "Type the value to delete: ";
            int v;
            cin >> v;
            if (arvore.deleteValue(v))
            {
                cout << "\nSuccess" << endl;
                arvore.update();
                arvore.VerifyBalance(arvore.root);
                arvore.update();
            }
            else
            {
                cout << "Leaf not found!" << endl;
            }
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
    } while (menu != 0);
}
