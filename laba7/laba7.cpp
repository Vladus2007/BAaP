#include <iostream>
#include <cstdio>
#include <cstring>
#include <windows.h>
#include <cctype>
#include <algorithm>
#define MAX_LINES 100 // Максимальное количество строк
#define MAX_LINE_LENGTH 256 // Максимальная длина строки
using namespace std;
void sortCharactersInString(char* str) {
    char filtered[256]; // Массив для хранения цифр и букв
    int count = 0;

    // Фильтруем символы
    for (int i = 0; str[i] != '\0'; ++i) {
        if (isalnum(str[i])) { // Проверяем, является ли символ буквой или цифрой
            filtered[count++] = str[i];
        }
    }
    filtered[count] = '\0'; // Завершаем строку

    // Сортируем отфильтрованную строку
    sort(filtered, filtered + count);

    // Копируем отсортированные символы обратно в исходную строку
    strcpy(str, filtered);
}


void sortLinesInFile(const char* filePath) {
    FILE* inputFile = fopen(filePath, "r"); // Открываем файл для чтения
    if (!inputFile) {
        cerr << "Ошибка при открытии файла для чтения: " << filePath << endl;
        return;
    }

    char lines[100][256]; // Массив для хранения строк
    int lineCount = 0;

    // Читаем строки из файла
    while (fgets(lines[lineCount], sizeof(lines[lineCount]), inputFile)) {
        // Убираем символ новой строки, если он есть
        lines[lineCount][strcspn(lines[lineCount], "\n")] = 0;
        // Сортируем символы в строке
        sortCharactersInString(lines[lineCount]);
        lineCount++;
    }
    fclose(inputFile); // Закрываем входной файл

    // Открываем файл для записи, чтобы перезаписать его
    FILE* outputFile = fopen(filePath, "w");
    if (!outputFile) {
        cerr << "Ошибка при открытии файла для записи: " << filePath << endl;
        return;
    }

    // Записываем отсортированные строки в файл
    for (int i = 0; i < lineCount; ++i) {
        fprintf(outputFile, "%s\n", lines[i]);
    }
    fclose(outputFile); // Закрываем выходной файл
}
// Функция для обработки и записи данных о студентах в выходной файл
void kak(const char* filename, const char* outfile, bool* arr, int studentCount) {
    FILE* file = fopen(filename, "r"); // Открываем файл для чтения
    FILE* out = fopen(outfile, "w"); // Открываем выходной файл для записи
    char g[100];
    int k = 0;

    if (file == nullptr) {
        cerr << "Ошибка: не удалось открыть файл " << filename << endl;
        return;
    }
    int q=0; //Счетчик для инфы
    int k1=0;
    while (fgets(g, sizeof(g), file)) {
        char firstChar = g[0];
        if (k1==k){
        q=0;
        
        // Проверка, является ли первый символ буквой
        if (isalpha(firstChar)){
            if (arr[k] && k < studentCount) { // проверка индекса
                fputs(g, out); // Записываем строку в выходной файл
                k++;
            }
            
        }
        
    }
    else{
    fputs(g, out);
    q++;
    k1+=q/5;
    }
    }
    fputs("-------------------------------------------------\n", out);
    // Закрываем файлы
    fclose(file);
    fclose(out);
}
void Delete(char* filename){
        FILE *file = fopen(filename, "w");
}
void output(const char* inputFile, const char* filename) {
    char s[100];
    FILE* input = fopen(inputFile, "r"); // Открываем файл для чтения
    FILE* outputFile = fopen(filename, "a"); // Открываем выходной файл для записи

    if (input) {
        while (fgets(s, sizeof(s), input)) {
            fputs(s, outputFile); // Записываем строку в выходной файл
        }
        fclose(input);
    }
    fclose(outputFile);
}
// Функция для ввода данных студентов и записи в файл
bool* input(const char* filename, int& studentCount) {
    FILE* outputFile = fopen(filename, "a"); // Открываем выходной файл для добавления
    bool* arr = new bool[100]; // выделение памяти для массивов

    cout << "Введите количество студентов: ";
    cin >> studentCount;
    cin.ignore(); // Очистка буфера после cin

    for (int i = 0; i < studentCount; i++) {
        char surname[50];
        char group[50];
        double totalMarks = 0.0;

        cout << "Введите фамилию студента: ";
        cin.getline(surname, 50);
        fputs(surname, outputFile);
        fputs("\n", outputFile); // Добавляем новую строку в файл

        cout << "Введите номер группы: ";
        cin.getline(group, 50);
        fputs(group, outputFile);
        fputs("\n", outputFile); // Добавляем новую строку в файл

        const char* subjects[] = {"физика", "математика", "информатика"};
        bool flag = true;

        for (int j = 0; j < 3; j++) {
            double mark;
            cout << "Введите оценку по " << subjects[j] << ": ";
            cin >> mark;
            cin.ignore(); // Очистка буфера после cin

            totalMarks += mark;
            if (mark < 8) {
                flag = false;
            }
            fprintf(outputFile, "%.2f\n", mark); // Записываем оценку в файл
        }

        arr[i] = flag; // Сохраняем результат
        fprintf(outputFile, "%.2f\n", totalMarks / 3); // Записываем средний балл
    }

    fclose(outputFile);
    return arr;
}

// Главная функция
int main() {
    char q[1];
    char inpud[100];
    char s[100];
    bool* n;
    int studentCount = 0; // переменная для хранения числа студентов
    int k;
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    cout<<"Нажмите Enter чтобы продолжить";
    cin.getline(q,1);
    cout << "Введите имя файла для ввода: ";
    cin.getline(inpud, 100); // чтение имени файла
    cout << "Введите имя файла для вывода: ";
    cin.getline(s, 100);
    n = input(inpud, studentCount);
    cout<<"Введите 1 чтобы вывести хороших студентов"<<endl;
    cout<<"Введите 2 чтобы вывести ввод"<<endl;
    cout<<"Введите 3 чтобы очистить выходной файл"<<endl;
    cout<<"Введите 4 чтобы отсортировать  информацию"<<endl;
    cout<<"Введите 5 чтобы выйти"<<endl;
    cout<<"Введите 6 чтобы добавить студентов"<<endl;
    while(true){
    cin>>k;

    if(k==1){
    kak(inpud,s,n,studentCount);
    }
    if(k==2){
    output(inpud, s);
    }
  
    if(k==3){
    Delete(s);
    }
    if(k==4){
        sortLinesInFile(s);
    }
    if(k==5){
        break;
    }
    if(k==6){
       delete [] n;
       n = input(s, studentCount); 
    }
    }
    return 0;
    
}