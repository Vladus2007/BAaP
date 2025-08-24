#include <iostream>
#include <cstdlib> // Для функции rand()
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
Stack* split1(Stack* p){
    Stack* term=new Stack;
    if(p->data>0){
        term=p;
    }
    else p=p->next;
    return term;
    
}
Stack* split2(Stack* p){
    Stack* term=new Stack;
    if(p->data<0){
        term=p;
    }
    else p=p->next;
    return term;
    
}
int main() {
    int n;
    Stack* begin = nullptr;
    cout << "Enter n: ";
    cin >> n;

    // Генерация случайных чисел и добавление их в стек begin
    for (int i = 0; i < n; i++) {
        int in = rand() % 20 - 10; // Генерация случайного числа от -10 до 9
        begin = push(in, begin);
    }
    Stack* term_positive=split1(begin);
    Stack* term_negative=split2(begin);
    while(term_positive->next){
        cout<<term_positive->data<<" ";
        

    }
    cout<<'\n';
    while(term_negative->next){
        cout<<term_negative->data<<" ";
    

    }
    cout<<'\n';
    

    
    
    return 0;
}
