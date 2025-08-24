#include <iostream>
#include <queue>
using namespace std;

enum Color {RED, BLACK};

struct Tree {
    public:
    string name;
    int key;
    bool color;
    Tree* left;
    Tree* right;
    Tree* parent;
    Tree(string name, int key) : name(name), key(key), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

// Функция для вставки узла
Tree* insert_Tree(Tree* root, Tree* node) {
    if (!root) {
        return node;
    }
    if (node->key < root->key) {
        root->left = insert_Tree(root->left, node);
        root->left->parent = root;
    } else if (node->key > root->key) {
        root->right = insert_Tree(root->right, node);
        root->right->parent = root;
    }
    return root;
}

// Функция для левого поворота
void leftRotate(Tree* &root, Tree* &node) {
    Tree* nodeRight = node->right;
    node->right = nodeRight->left;

    if (node->right != nullptr) {
        node->right->parent = node;
    }
    nodeRight->parent = node->parent;

    if (node->parent == nullptr) {
        root = nodeRight;
    } else if (node == node->parent->left) {
        node->parent->left = nodeRight;
    } else {
        node->parent->right = nodeRight;
    }

    nodeRight->left = node;
    node->parent = nodeRight;
}

// Функция для правого поворота
void rightRotate(Tree* &root, Tree* &node) {
    Tree* nodeLeft = node->left;
    node->left = nodeLeft->right;

    if (node->left != nullptr) {
        node->left->parent = node;
    }
    nodeLeft->parent = node->parent;

    if (node->parent == nullptr) {
        root = nodeLeft;
    } else if (node == node->parent->left) {
        node->parent->left = nodeLeft;
    } else {
        node->parent->right = nodeLeft;
    }

    nodeLeft->right = node;
    node->parent = nodeLeft;
}

// Функция для исправления дерева после вставки
void fixInsert(Tree* &root, Tree* &node) {
    Tree* parent = nullptr;
    Tree* grandparent = nullptr;

    while ((node != root) && (node->color != BLACK) && (node->parent->color == RED)) {
        parent = node->parent;
        grandparent = node->parent->parent;

        if (parent == grandparent->left) {
            Tree* uncle = grandparent->right;
            if (uncle != nullptr && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            } else {
                if (node == parent->right) {
                    leftRotate(root, parent);
                    node = parent;
                    parent = node->parent;
                }
                rightRotate(root, grandparent);
                swap(parent->color, grandparent->color);
                node = parent;
            }
        } else {
            Tree* uncle = grandparent->left;
            if ((uncle != nullptr) && (uncle->color == RED)) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            } else {
                if (node == parent->left) {
                    rightRotate(root, parent);
                    node = parent;
                    parent = node->parent;
                }
                leftRotate(root, grandparent);
                swap(parent->color, grandparent->color);
                node = parent;
            }
        }
    }
    root->color = BLACK;
}

// Функция для печати дерева (инфиксный обход)
void print(Tree* root) {
    if (!root) return;
    print(root->left);
    cout << root->name << " (" << root->key << ") ";
    print(root->right);
}

// Функция для обратной печати дерева
void inverseprint(Tree* root){
    if(!root) return;
    inverseprint(root->right);
    cout<<root->name<<" ("<<root->key<<") ";
    inverseprint(root->left);
}

// Функция для обмена значений минимального и максимального узлов
void swapMinMax(Tree* root) {
    if (!root) return;

    Tree* minNode = root;
    while (minNode->left != nullptr) {
        minNode = minNode->left;
    }

    Tree* maxNode = root;
    while (maxNode->right != nullptr) {
        maxNode = maxNode->right;
    }

    if (minNode != maxNode) {
        swap(minNode->name, maxNode->name);
    }
}


int search_by_key(Tree* root, int argument){
    if(!root){
       return -1;
    }
    if(root->key == argument){
        cout<<root->name<<" ("<<root->key<<")\n";
        return argument;
    }
    if(argument < root->key) {
        return search_by_key(root->left, argument);
    } else {
        return search_by_key(root->right, argument);
    }
    
}


void printFromRoot(Tree* root) {
    if (!root) return;
    
    queue<Tree*> q;
    q.push(root);
    
    while (!q.empty()) {
        Tree* current = q.front();
        q.pop();
        
        cout << current->name << " (" << current->key << ") ";
        
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    cout << endl;
}


void printFromChildren(Tree* root) {
    if (!root) return;
    
    printFromChildren(root->left);
    printFromChildren(root->right);
    cout << root->name << " (" << root->key << ") ";
}

// Функция для поиска минимального узла в поддереве
Tree* minValueNode(Tree* node) {
    Tree* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

// Функция для удаления узла по ключу
Tree* deleteNode(Tree* root, int key) {
    if (!root) return root;

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (!root->left) {
            Tree* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Tree* temp = root->left;
            delete root;
            return temp;
        }

        Tree* temp = minValueNode(root->right);
        root->name = temp->name;
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}


int main() {
    Tree* root = nullptr;
    string name;
    int key;
    int q;

    while (true) {
        cout << "-1 = exit: " << endl;
        cout << "0 = complete task: " << endl;
        cout<<"1 = search_by_key: "<<endl;
        cout << "2 = Add:  "<<endl;
        cout<<"3 = DeleteNode: "<<endl;
        cout<<"4 = Print: ";
        cin >> q;
        if(q>4 || q<-1  || cin.fail()){
            cout<<"Error\n";
            return -1;
        }
        if (q == -1) {
            break;
        } else if (q == 0) {
            cout << "Inorder traversal of the tree: ";
            print(root);

            cout<<"\nTree ivverse:";
            inverseprint(root);
            cout<<"\nTree from childer:";
            printFromChildren(root);
            cout<<"\nTree from root:";
            printFromRoot(root);
           
            swapMinMax(root);
            cout << endl;
            cout << "Tree after swap: ";
            print(root);
            cout << endl;
        } else {
            if(q==1){
                int argument;
                
                cout<<"Enter key\n";
                cin>>argument;
                search_by_key(root,argument);
            }else{
            if(q==3){
                int arg;
                cin.ignore();
                cout<<"Enter key: ";
                cin>>arg;
                root=deleteNode(root,arg);
            }else{
            if(q==4){
                cout << "Inorder traversal of the tree: ";
            print(root);

            cout<<"\nTree ivverse:";
            inverseprint(root);
            cout<<"\nTree from childer:";
            printFromChildren(root);
            cout<<"\nTree from root:";
            printFromRoot(root);
            }else{
            cin>>q;
            for (int i = 0; i < q; ++i) { 
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter key: ";
                cin >> key;
                while(search_by_key(root,key)!=-1){
                    cin >> key;
                }
                
                Tree* newNode = new Tree(name, key);
                root = insert_Tree(root, newNode);
                fixInsert(root, newNode);
            }
        }
        }
        }
        }
    }

    return 0;
}
