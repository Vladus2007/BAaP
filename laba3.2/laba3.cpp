#include <iostream>
#include <cstdlib> 
using namespace std;

struct Stack {
    int data;
    Stack* next;
};

Stack* push(int in, Stack* p) {
    Stack* t = new Stack;
    t->data = in;
    t->next = p;
    return t;
}

void printStack(Stack* p) {
    Stack* current = p;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << '\n';
}

int main() {
    int n;
    Stack* begin = nullptr;
    Stack* begin1 = nullptr;
    Stack* begin2 = nullptr;

    int q;
    while(q!=3){
    cout<<"Enter q = 1 random q=2 pick q=3 exit ";
    cin>>q;
        if(q==1){
            cout << "Enter n: ";
            cin>>n;
    for (int i = 0; i < n; i++) {
        int in = rand() % 20 - 10; // Генерация случайного числа от -10 до 9
        begin = push(in, begin);
    }

    }
    if(q==2){
        cout << "Enter n: ";
        cin>>n;
for (int i = 0; i < n; i++) {
    int in;
    cin>>in;// Генерация случайного числа от -10 до 9
    begin = push(in, begin);
}
    }

}

    
    Stack* current = begin;
    while (current) {
        if (current->data > 0) {
            begin1 = push(current->data, begin1);
        } else {
            begin2 = push(current->data, begin2);
        }
        current = current->next;
    }
    cout<<"Stack: ";
    printStack(begin);
    cout << "Positive numbers: ";
    printStack(begin1);

    
    cout << "Negative numbers: ";
    printStack(begin2);
    while(begin1){
        Stack* term=begin1;
        begin1=begin1->next;
        delete term;
    }
    while(begin){
        Stack* term=begin;
        begin=begin->next;
        delete term;
    }
    while(begin2){
        Stack* term=begin2;
        begin2=begin2->next;
        delete term;
    }
    return 0;
}
