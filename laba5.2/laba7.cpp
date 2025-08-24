#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Структура студента
struct Student {
    string surname;  // Фамилия
    int group;       // Номер группы
    int mark;        // Оценка (ключ)
};

const int M = 15; 
Student H[M];      

void initHashTable() {
    for (int i = 0; i < M; i++) {
        H[i].mark = -1;
    }
}

int hashFunction(int key) {
    return abs(key) % M;
}


void addStudent(const Student &student) {
    int index = hashFunction(student.mark);
    int originalIndex = index;
    int step = 1;

    while (H[index].mark != -1) {  
        index = (originalIndex + step * step) % M;  
        step++;

        
        if (step > M) {
            cout << "Overflow" << endl;
            return;
        }
    }

    H[index] = student;  
}


int searchStudent(int mark) {
    int index = hashFunction(mark);
    int originalIndex = index;
    int step = 1;

    while (H[index].mark != -1) {  
        if (H[index].mark == mark) {
            return index;  
        }
        index = (originalIndex + step * step) % M;  
        step++;

        
        if (step > M) {
            break;
        }
    }

    return -1;  
}


void printHashTable() {
    cout << "Index Surname Group Mark" << endl;
    cout << "------------------------" << endl;
    for (int i = 0; i < M; i++) {
        if (H[i].mark != -1) {
            cout << i << " " << H[i].surname << " " << H[i].group << " " << H[i].mark << endl;
        } else {
            cout << i << " (empty)" << endl;
        }
    }
}
int main() {
    initHashTable();  

    
    Student students[] = {
        {"Ivanov", 101, 5},
        {"Bashura", 102, 4},
        {"ADADdda", 101, 3},
        {"Ermakov", 103, 5},
        {"Novik", 102, 4},
        {"Vasilevskiy", 103, 2}
    };

    
    for (const auto &student : students) {
        addStudent(student);
    }

    
    printHashTable();

    
    int markToFind;
    cout << "\nInput mark: ";
    cin >> markToFind;

    int foundIndex = searchStudent(markToFind);
    if (foundIndex != -1) {
        cout << "Find student: " << H[foundIndex].surname 
             << ", group " << H[foundIndex].group 
             << ", mark " << H[foundIndex].mark << endl;
    } else {
        cout << "Student with mark: " << markToFind << " not found" << endl;
    }

    return 0;
}