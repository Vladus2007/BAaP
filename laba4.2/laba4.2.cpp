#include <iostream>
#include <cstdlib> 
using namespace std;

struct Queue {
    int data;
    Queue* next;
    Queue* prev;
};

Queue* push(Queue* end, int in) {
    Queue* term = new Queue;
    term->data = in;
    term->next = nullptr;
    term->prev = end;
    if (end) {
        end->next = term;
    }
    return term;
}

Queue* front_push(Queue* begin, int in) {
    Queue* term = new Queue;
    term->prev = nullptr;
    term->next = begin;
    if (begin) {
        begin->prev = term;
    }
    return term;
}

void split(Queue* begin, Queue*& end1, Queue*& begin1, Queue*& end2, Queue*& begin2) {
    while (begin) {
        if (begin->data > 0) {
            end1 = push(end1, begin->data);
            if (!begin1) {
                begin1 = end1;
            }
        } else if (begin->data < 0) {
            end2 = push(end2, begin->data);
            if (!begin2) {
                begin2 = end2;
            }
        }
        begin = begin->next;
    }
}

void read_reverse(Queue* term) {
    while (term) {
        cout << term->data << " ";
        term = term->prev;
    }
    cout << '\n';
}

void read(Queue* term) {
    while (term) {
        cout << term->data << " ";
        term = term->next;
    }
    cout << '\n';
}

int main() {
    Queue* begin = nullptr;
    Queue* end = nullptr;
    Queue* begin1 = nullptr;
    Queue* end1 = nullptr;
    Queue* begin2 = nullptr;
    Queue* end2 = nullptr;

    int n;
    cout << "Enter n: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int in = rand() % 20 - 10;// Генерация случайного числа от -10 до 9
        begin = front_push(begin, in);
        if (!end) end = begin;
    }
    split(begin, end1, begin1, end2, begin2);
    read(begin);
    read(begin1);
    read(begin2);
    read_reverse(end1);
    read_reverse(end2);

    return 0;
}
