#include <iostream>
#include <cctype>
using namespace std;

struct Stack {
    double data;
    Stack* next{nullptr};
};

Stack* push(Stack* p, double in) {
    Stack* term = new Stack();
    term->data = in;
    term->next = p;
    return term;
}

double pop(Stack*& p) {
    if (!p) return 0.0;
    double data = p->data;
    Stack* temp = p;
    p = p->next;
    delete temp;
    return data;
}

struct Queue {
    char data_q;
    Queue* next_q{nullptr};
    Queue* prev{nullptr};
};

Queue* front_push(Queue* begin, char in) {
    Queue* term = new Queue();
    term->next_q = begin;
    term->prev = nullptr;
    term->data_q = in;
    if (begin) begin->prev = term;
    return term;
}

Queue* back_push(Queue* end, char in) {
    Queue* term = new Queue();
    term->next_q = nullptr;
    term->prev = end;
    term->data_q = in;
    if (end) end->next_q = term;
    return term;
}

class Solution {
public:
    Stack* begin_original = nullptr;
    Queue* begin_finish = nullptr;
    Queue* end = nullptr;
    double a, b, c, d, e;

    bool validateExpression(const char* s) {
        int bracketBalance = 0;
        bool lastWasOperator = true; 

        for (int i = 0; s[i] != '\0'; ++i) {
            if (s[i] == ' ') continue; 

            if (s[i] == '(') {
                bracketBalance++;
                lastWasOperator = true; 
            } 
            else if (s[i] == ')') {
                if (bracketBalance == 0) {
                    cerr << "Error\n";
                    return false;
                }
                bracketBalance--;
                lastWasOperator = false;
            } 
            else if (IsArgument(s[i])) {
                lastWasOperator = false;
            } 
            else if (Operator(s[i]) != -1) {
                if (lastWasOperator && s[i] != '-') { 
                    cerr << "Error\n";
                    return false;
                }
                lastWasOperator = true;
            } 
            else {
                cerr << "Error'" << s[i] << "'\n";
                return false;
            }
        }

        if (bracketBalance != 0) {
            cerr << "Error\n";
            return false;
        }

        if (lastWasOperator) {
            cerr << "Error\n";
            return false;
        }

        return true;
    }

    void str(char* s) {
        if (!validateExpression(s)) {
            return;
        }

        int i = 0;
        while (s[i] != '\0') {
            if (s[i] == ' ') {
                i++;
                continue;
            }

            if (IsArgument(s[i])) {
                end = back_push(end, s[i]);
                if (!begin_finish) begin_finish = end;
                i++;
            } 
            else if (s[i] == '(') {
                begin_original = push(begin_original, s[i]);
                i++;
            } 
            else if (s[i] == ')') {
                while (begin_original && begin_original->data != '(') {
                    end = back_push(end, pop(begin_original));
                    if (!begin_finish) begin_finish = end;
                }
                if (!begin_original) {
                    cerr << " Invalid input\n";
                    return;
                }
                pop(begin_original); 
                i++;
            } 
            else if (Operator(s[i]) != -1) {
                while (begin_original && Operator(begin_original->data) >= Operator(s[i])) {
                    end = back_push(end, pop(begin_original));
                    if (!begin_finish) begin_finish = end;
                }
                begin_original = push(begin_original, s[i]);
                i++;
            } 
            else {
                i++;
            }
        }

        while (begin_original) {
            if (begin_original->data == '(') {
                cerr << "Invalid input\n";
                return;
            }
            end = back_push(end, pop(begin_original));
            if (!begin_finish) begin_finish = end;
        }
    }

    bool IsArgument(char argument) {
        return (argument >= 'a' && argument <= 'e');
    }

    int Operator(char s) {
        switch (s) {
            case '+': return 1;
            case '-': return 1;
            case '/': return 2;
            case '*': return 2;
            default: return -1;
        }
    }

    void printQueue() {
        Queue* current = begin_finish;
        cout << "OPZ: ";
        while (current) {
            cout << current->data_q << " ";
            current = current->next_q;
        }
        cout << '\n';
    }

    void computing(Queue* begin) {
        if (!begin) {
            cerr << "Invalid input\n";
            return;
        }

        Stack* compute_stack = nullptr;
        Queue* current = begin;
        while (current) {
            if (IsArgument(current->data_q)) {
                compute_stack = push(compute_stack, CharToInt(current->data_q));
            } 
            else {
                if (!compute_stack || !compute_stack->next) {
                    cerr << "Invalid input\n";
                    return;
                }
                double b = pop(compute_stack);
                double a = pop(compute_stack);
                double result;
                switch (current->data_q) {
                    case '+': result = a + b; break;
                    case '-': result = a - b; break;
                    case '*': result = a * b; break;
                    case '/': 
                        if (b == 0) {
                            cerr << "Delenie na nol\n";
                            return;
                        }
                        result = a / b; 
                        break;
                    default:
                        cerr << "Undefinded operator '" << current->data_q << "'\n";
                        return;
                }
                compute_stack = push(compute_stack, result);
            }
            current = current->next_q;
        }

        if (!compute_stack || compute_stack->next) {
            cerr << "Invalid input\n";
            return;
        }

        cout << "Result: " << pop(compute_stack) << endl;
    }

    double CharToInt(char s) {
        switch (s) {
            case 'a': return a;
            case 'b': return b;
            case 'c': return c;
            case 'd': return d;
            case 'e': return e;
            default: return 0;
        }
    }
};

int main() {
    Solution sol;
    char s[256];
    cout << "Input: ";
    cin.getline(s, 256);

    if (s[0] == '\0') {
        cerr << "Empty input\n";
        return 1;
    }

    cout << "Fill a, b, c, d, e: ";
    cin >> sol.a >> sol.b >> sol.c >> sol.d >> sol.e;

    sol.str(s);
    sol.printQueue();
    sol.computing(sol.begin_finish);

    return 0;
}