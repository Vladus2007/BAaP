#include <iostream>

#include <cmath>
using namespace std;

struct Train {
    double price[256];
    int number[256];
    char start_town[256][256];
    char finish_town[256][256];
    char name[256][256];
    char date[256][256];
    char time[256][256];
    int n;
    //Функия поиска по двум городам
    void SearchByStartTown(char* s1,char* s2){
        bool flag=true;
        for(int i=0;i<n;i++){
            for(int j=0;s1[j]!='\0';j++){
                if(start_town[i][j]!=s1[j]){
                    flag=false;
                }
            }
            for(int j=0;s2[j]!='\0';j++){
                if(finish_town[i][j]!=s2[j]){
                    flag=false;
                }
            }
            if(flag){
                cout<<name[i]<<'\n';
                cout<<start_town[i]<<"->"<<finish_town[i]<<"\n";
                cout<<"Price: "<<price[i]<<'\n';
                cout<<"Number: "<<number[i]<<'\n';
                cout<<"Time: "<<time[i]<<'\n';
                cout<<"Date:"<<date[i]<<'\n';
            }
            flag=true;
        }


    }
    int strlen(const char* s) {
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
    return length;
}
     char* capitalizeWords(  char* str) {
    bool newWord = true; // флаг для определения начала нового слова

    for (int i = 0; str[i] != '\0'; ++i) {
        if (isspace(str[i])) {
            // если текущий символ пробел, значит следующее слово начинается
            newWord = true;
        } else if (newWord && isalpha(str[i])) {
            // если это начало слова и символ буква, делаем её заглавной
            str[i] = toupper(str[i]);
            newWord = false;
        } else {
            // остальные символы в слове - делаем строчными
            str[i] = tolower(str[i]);
        }
        
    }
    return str;
}
int countWords(const char* str) {
    int count = 0;
    bool inWord = false;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (isspace(str[i])) {
            // если текущий символ пробел, значит мы вышли из слова
            inWord = false;
        } else if (!inWord && isalpha(str[i])) {
            // если мы не в слове и встретили букву, значит новое слово
            inWord = true;
            ++count;
        }
        // остальные символы игнорируем
    }

    return count;
}
    //Поиск по городу отправления
    void SearchByOnlyStartTown(char* s1){
        bool flag=true;
        for(int i=0;i<n;i++){
            for(int j=0;s1[j]!='\0';j++){
                if(start_town[i][j]!=s1[j]){
                    flag=false;
                }
            }
            if(flag){
                cout<<name[i]<<'\n';
                cout<<start_town[i]<<"->"<<finish_town[i]<<"\n";
                cout<<"Price: "<<price[i]<<'\n';
                cout<<"Number: "<<number[i]<<'\n';
                cout<<"Time: "<<time[i]<<'\n';
                cout<<"Date:"<<date[i]<<'\n';
            }
            flag=true;
        }

    }
    //Поиск билетов по прибытию
    void SearchByOnlyFinishTown(char* s1){
        bool flag=true;
        for(int i=0;i<n;i++){
            for(int j=0;s1[j]!='\0';j++){
                if(finish_town[i][j]!=s1[j]){
                    flag=false;
                }
            }
            if(flag){
                cout<<name[i]<<'\n';
                cout<<start_town[i]<<"->"<<finish_town[i]<<"\n";
                cout<<"Price: "<<price[i]<<'\n';
                cout<<"Number: "<<number[i]<<'\n';
                cout<<"Time: "<<time[i]<<'\n';
                cout<<"Date:"<<date[i]<<'\n';
            }
            flag=true;
        }

    }
    //Cравнение строк по алфамиту
    bool String(char* str1,char* str2){
        for(int i=0;str1[i]!='\0' && str2[i]!='\0';i++){
            const char char1=str1[i];
            const char char2=str2[i];
            //char char1_1[2]={char1,'\0'};
            //char char2_1[2]={char2,'\0'};
            //int result=strcmp(char1_1,char2_1);
            int result=char2-char1;
            if(result>0) return true;
            if(result<0) return false;
            if(str1[i+1]=='\0') return true;
            if(str2[i+1]=='\0') return false;
        }
        return false;
        
    }
    //Функия сравнения первой и второй даты(true if date1<date2)
    bool dated(const char* date1, const char* date2, const char* time1, const char* time2) {
        char h1[3], m1[3], h2[3], m2[3];
        char d1[3], d2[3], mo1[3], mo2[3];
        char y1[5], y2[5];
    
        // Extract years
        for(int i = 6; i < 10; i++) {
            y1[i-6] = date1[i];
            y2[i-6] = date2[i];
        }
        y1[4] = '\0';
        y2[4] = '\0';
        if(Double(y1) < Double(y2)) {
            return true;
        } else if(Double(y2) < Double(y1)) {
            return false;
        }
    
        // Extract months
        mo1[0] = date1[3];
        mo1[1] = date1[4];
        mo1[2] = '\0';
        mo2[0] = date2[3];
        mo2[1] = date2[4];
        mo2[2] = '\0';
        if(Double(mo1) < Double(mo2)) {
            return true;
        } else if(Double(mo2) < Double(mo1)) {
            return false;
        }
    
        // Extract days
        d1[0] = date1[0];
        d1[1] = date1[1];
        d1[2] = '\0';
        d2[0] = date2[0];
        d2[1] = date2[1];
        d2[2] = '\0';
        if(Double(d1) < Double(d2)) {
            return true;
        } else if(Double(d2) < Double(d1)) {
            return false;
        }
    
        // Extract hours
        h1[0] = time1[0];
        h1[1] = time1[1];
        h1[2] = '\0';
        h2[0] = time2[0];
        h2[1] = time2[1];
        h2[2] = '\0';
        if(Double(h1) < Double(h2)) {
            return true;
        } else if(Double(h2) < Double(h1)) {
            return false;
        }
    
        // Extract minutes
        m1[0] = time1[3];
        m1[1] = time1[4];
        m1[2] = '\0';
        m2[0] = time2[3];
        m2[1] = time2[4];
        m2[2] = '\0';
        if(Double(m1) <= Double(m2)) {
            return true;
        } else {
            return false;
        }
    }
    //Функия перевода строки в число
    double Double(const char* s) {
        double result = 0.0;
        int length = 0, point = -1;

        // Find length and position of the decimal point
        for (int i = 0; s[i] != '\0'; i++) {
            length++;
            if (s[i] == '.') {
                point = i;
            }
        }

        // Calculate the ten factor based on decimal position
        double ten = pow(10, -(length - point - 1));

        // Calculate the result value
        for (int i = 0; i < length; i++) {
            if (s[i] != '.') {
                result = result * 10 + (s[i] - '0');
            }
        }
        return result * ten;
    }
    //Функия чтения
    void read(const char* inputFile, int& i) {
        char s[256];
        FILE* input = fopen(inputFile, "r");

        if (input) {
            while (fgets(s, sizeof(s), input)) {
                sscanf(s, "%255[^\n]", name[i]);
                fgets(s, sizeof(s), input);
                sscanf(s, "%255[^\n]", start_town[i]);
                fgets(s, sizeof(s), input);
                sscanf(s, "%255[^\n]", finish_town[i]);
                fgets(s, sizeof(s), input);
                sscanf(s, "%lf", &price[i]);
                fgets(s, sizeof(s), input);
                sscanf(s, "%d", &number[i]);
                fgets(s,sizeof(s),input);
                sscanf(s,"%255[^\n]",time[i]);
                fgets(s,sizeof(s),input);
                sscanf(s,"%255[^\n]",date[i]);
                i++;
            }
           

        }
        fclose(input);
        n=i;
    }
    bool isValidDate( char* dateStr) {
    // Проверка длины строки
    int len = strlen(dateStr);
    if (len != 10) {
        return false; // ожидаемый формат: "DD.MM.YYYY" (10 символов)
    }

    // Проверка формата: DD.MM.YYYY
    if (dateStr[2] != '.' || dateStr[5] != '.') {
        return false;
    }

    // Вырезаем части даты
    char dayStr[3] = { dateStr[0], dateStr[1], '\0' };
    char monthStr[3] = { dateStr[3], dateStr[4], '\0' };
    char yearStr[5] = { dateStr[6], dateStr[7], dateStr[8], dateStr[9], '\0' };

    // Проверка, что все символы — цифры
    for (int i = 0; i < 2; i++) {
        if (!isdigit(dayStr[i]) || !isdigit(monthStr[i])) {
            return false;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (!isdigit(yearStr[i])) {
            return false;
        }
    }

    // Преобразуем строки в числа
    int day = atoi(dayStr);
    int month = atoi(monthStr);
    int year = atoi(yearStr);

    // Проверка диапазонов дат
    if (year < 1900 || year > 2100) { // пример диапазона годов
        return false;
    }
    if (month < 1 || month > 12) {
        return false;
    }

    // Определяем количество дней в месяце
    int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    // Проверка на високосный год для февраля
    bool isLeapYear = (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
    if (isLeapYear) {
        daysInMonth[1] = 29;
    }

    if (day < 1 || day > daysInMonth[month -1]) {
        return false;
    }

    return true; // дата прошла все проверки
}
    void SearchByName(int start,char* s1){
        bool flag=true;
        for(int i=start;i<n;i++){
            for(int j=0;s1[j]!='\0';j++){
                if(name[i][j]!=s1[j]){
                    flag=false;
                }
            }
            if(flag){
                cout<<name[i]<<'\n';
                cout<<start_town[i]<<"->"<<finish_town[i]<<"\n";
                cout<<"Price: "<<price[i]<<'\n';
                cout<<"Number: "<<number[i]<<'\n';
                cout<<"Time: "<<time[i]<<'\n';
                cout<<"Date:"<<date[i]<<'\n';
            }
            flag=true;
        }

    }
    int SearchByNameInt(int start,char* s1){
        bool flag=true;
        for(int i=start;i<n;i++){
            for(int j=0;s1[j]!='\0';j++){
                if(name[i][j]!=s1[j]){
                    flag=false;
                }
            }
            if(flag){
                return i;
            }
            flag=true;
        }
        return -1;

    }
bool isValidTime(char* timeStr) {
    // Проверка длины строки: формат "ЧЧ:ММ" — 5 символов
    if (strlen(timeStr) != 5) {
        return false;
    }

    // Проверка наличия двоеточия в правильной позиции
    if (timeStr[2] != ':') {
        return false;
    }

    // Вырезаем части времени
    char hourStr[3] = { timeStr[0], timeStr[1], '\0' };
    char minuteStr[3] = { timeStr[3], timeStr[4], '\0' };

    // Проверка, что все символы — цифры
    for (int i = 0; i < 2; i++) {
        if (!isdigit(hourStr[i]) || !isdigit(minuteStr[i])) {
            return false;
        }
    }

    // Преобразуем строки в числа
    int hours = atoi(hourStr);
    int minutes = atoi(minuteStr);

    // Проверка диапазонов времени
    if (hours < 0 || hours > 23) {
        return false;
    }
    if (minutes < 0 || minutes > 59) {
        return false;
    }

    return true; // время валидно
}
    void write() {
        int num;
        cout << "Enter number of passengers: ";
        cin >> num;

        for (int i = n; i < num + n; i++) {
            cout << "Enter name & surname: ";
            cin.ignore();
            cin.getline(name[i], 256);
            sscanf(capitalizeWords(name[i]), "%255[^\n]", name[i]);
            cout << "Enter start town: ";
            cin.getline(start_town[i], 256);
            sscanf(capitalizeWords(start_town[i]), "%255[^\n]", start_town[i]);
            cout << "Enter finish town: ";
            cin.getline(finish_town[i], 256);
            sscanf(capitalizeWords(finish_town[i]), "%255[^\n]", finish_town[i]);
            cout<<"Enter date: ";
            cin.getline(date[i],256);
            while(!isValidDate(date[i])){
                cout<<"Input correct date!!\n";
                cin.getline(date[i],256);
            }
            cout<<"Enter time: ";
            
            cin.getline(time[i],256);
            while(!isValidTime(time[i])){
                cout<<"Input correct time!!\n";
                cin.getline(time[i],256);
            }
            cout << "Enter price: ";
            cin >> price[i];
            cout << "Enter number: ";
            cin >> number[i];
            
            
        }
        n += num;
    }
 void sortBinary(){
        int q;
        char qe[256];
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1;j++){
                if(number[j]>number[j+1]){
                    swap(j,j+1);
                    


                }
            }
        }
    }   
    int binary_search(int nimber, int right, int left) {
        if (left <= right) {
            int mid = left + (right - left) / 2;

            if (number[mid] == nimber) {
                return mid;
            }

            if (number[mid] > nimber) {
                return binary_search(nimber, left, mid - 1);
            }

            return binary_search(nimber, mid + 1, right);
        }
        return -1;
    }
    // Функия вывода
    void print(int i){
        cout<<name[i]<<'\n';
                cout<<start_town[i]<<"->"<<finish_town[i]<<"\n";
                cout<<"Price: "<<price[i]<<'\n';
                cout<<"Number: "<<number[i]<<'\n';
                cout<<"Time: "<<time[i]<<'\n';
                cout<<"Date:"<<date[i]<<'\n';
    }
    
    // Функция для разделения массива на две части
    int partition(int low, int high) {
        int pivot = high;
        int i = low-1;

        for (int j = low; j < high; j++) {
            if (dated(date[j], date[pivot], time[j], time[pivot])) {
                i++;
                swap(i, j);
                
                
            }
        }
        swap(i + 1, high);
        return i + 1;
    }

    // Рекурсивная функция для быстрой сортировки
    void quickSort(int low, int high) {
        if (low < high) {
            int pi = partition(low, high);
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }

    // Функция для обмена значениями
    void swap(int i, int j) {
        double temp_price = price[i];
        price[i] = price[j];
        price[j] = temp_price;

        int temp_number = number[i];
        number[i] = number[j];
        number[j] = temp_number;

        char temp_town[256];
        sscanf(start_town[i], "%s", temp_town);
        sscanf(start_town[j], "%s", start_town[i]);
        sscanf(temp_town, "%s", start_town[j]);

        sscanf(finish_town[i], "%s", temp_town);
        sscanf(finish_town[j], "%s", finish_town[i]);
        sscanf(temp_town, "%s", finish_town[j]);

        char temp_name[256];
        sscanf(name[i], "%s", temp_name);
        sscanf(name[j], "%s", name[i]);
        sscanf(temp_name, "%s", name[j]);

        char temp_date[256];
        sscanf(date[i], "%s", temp_date);
        sscanf(date[j], "%s", date[i]);
        sscanf(temp_date, "%s", date[j]);

        char temp_time[256];
        sscanf(time[i], "%s", temp_time);
        sscanf(time[j], "%s", time[i]);
        sscanf(temp_time, "%s", time[j]);

    }
    //Сортировка выбором
    void PickSort(){
        for(int i=0;i<n;i++){
            int max=0,index=0;
            for(int j=0;j<n-i;j++){
                if(price[j]>max){
                    index=j;
                    max=price[j];
                }

            }
            swap(index,n-1-i);
        }
    }
    //Сортировка вставками
    void InsertSort(){
        for(int i=1;i<n;i++){
            for(int j=i;j>0 && String(finish_town[j],finish_town[j-1]);j--){
                swap(j,j-1);
            }
        }
    }
    //Сортировка вставками по стоимости
    void InsertSortbyPrice(){
        for(int i=1;i<n;i++){
            for(int j=i;j>0 && finish_town[j]<finish_town[j-1];j--){
                swap(j,j-1);
            }
        }
    }
    //Вывод статистики в консоль
    void Statisticka(char* date_1,char* date_2){
        char time__[]="00:00";
        int counter=0;
        for(int i=0;i<n;i++){
            if(dated(date[i],date_2,time__,time__) && dated(date_1,date[i],time__,time__)){
                counter++;
                cout<<name[i]<<'\n';
                cout<<start_town[i]<<"->"<<finish_town[i]<<"\n";
                cout<<"Price: "<<price[i]<<'\n';
                cout<<"Number: "<<number[i]<<'\n';
                cout<<"Time: "<<time[i]<<'\n';
                cout<<"Date:"<<date[i]<<'\n';
            }
            
        }
        cout<<counter<<endl;
    }
    //Запись статистики в файл
    void StatistickaFile(char* date_1,char* date_2,char* file){
            char time_[]="00:00";
            int counter=0;
            FILE* outputFile = fopen(file, "a");
            for(int i=0;i<n;i++){
                if(dated(date[i],date_2,time_,time_) && dated(date_1,date[i],time_,time_)){
                    
                    fputs(name[i], outputFile);
            fputs("\n", outputFile);
    
            // Записываем начальный город и добавляем новую строку
            fputs(start_town[i], outputFile);
            fputs("\n", outputFile);
    
            // Записываем конечный город и добавляем новую строку
            fputs(finish_town[i], outputFile);
            fputs("\n", outputFile);
    
            // Записываем цену и добавляем новую строку
            fprintf(outputFile, "%lf\n", price[i]);
    
            // Записываем номер и добавляем новую строку
            fprintf(outputFile, "%d\n", number[i]);
    
            // Записываем время и добавляем новую строку
            fputs(time[i], outputFile);
            fputs("\n", outputFile);
    
            // Записываем дату и добавляем новую строку
            fputs(date[i], outputFile);
            fputs("\n", outputFile);
                    
                }

            }
            fprintf(outputFile, "%d", counter);
            fclose(outputFile);
        }

    
    //Создание файла
    void CreateFile(char* file){
        FILE* outputFile = fopen(file, "w");
        fclose(outputFile);
    }
    //Запись в файл
    void writeFile(const char* file) {
        FILE* outputFile = fopen(file, "w");
        if (!outputFile) {
            cout << "Error\n";
            return;
        }
    
        for (int i = 0; i < n; i++) {
            // Записываем имя и добавляем новую строку
            fputs(name[i], outputFile);
            fputs("\n", outputFile);
    
            // Записываем начальный город и добавляем новую строку
            fputs(start_town[i], outputFile);
            fputs("\n", outputFile);
    
            // Записываем конечный город и добавляем новую строку
            fputs(finish_town[i], outputFile);
            fputs("\n", outputFile);
    
            // Записываем цену и добавляем новую строку
            fprintf(outputFile, "%lf\n", price[i]);
    
            // Записываем номер и добавляем новую строку
            fprintf(outputFile, "%d\n", number[i]);
    
            // Записываем время и добавляем новую строку
            fputs(time[i], outputFile);
            fputs("\n", outputFile);
    
            // Записываем дату и добавляем новую строку
            fputs(date[i], outputFile);
            fputs("\n", outputFile);
        }
    
        fclose(outputFile);
        cout << "Success\n";
    }
    void writeFilewithRule(const char* filename, int rule) {
    FILE* outputFile = fopen(filename, "w");  // Открываем файл в текстовом режиме
    if (!outputFile) {
        cout << "Error opening file\n";
        return;
    }

    // Считаем количество записей для сохранения
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (i != rule) count++;
    }
    
    // Записываем количество записей

    for (int i = 0; i < n; i++) {
        if (i == rule) continue; // Пропускаем указанную запись

        // Записываем каждое поле в отдельной строке
        fputs(name[i], outputFile); fputc('\n', outputFile);
        fputs(start_town[i], outputFile); fputc('\n', outputFile);
        fputs(finish_town[i], outputFile); fputc('\n', outputFile);
        fprintf(outputFile, "%.2f\n", price[i]);  // Цена с 2 знаками после запятой
        fprintf(outputFile, "%d\n", number[i]);
        fputs(time[i], outputFile); fputc('\n', outputFile);
        fputs(date[i], outputFile); fputc('\n', outputFile);
    }

    fclose(outputFile);
    cout << "Success\n";
}
 
};

int main() {
    
    Train train;
    train.n = 0;
    int menu=0;
    cout<<"GUIDE\n";
    cout<<"Enter 0 for check menu\n";
        cout<<"Enter 1 for create file\n"; //ПРОВЕРЕННО
        cout<<"Enter 2 for read file\n"; //ПРОВЕРЕННО
        cout<<"Enter 3 for fill file\n"; //ПРОВЕРЕННО
        cout<<"Enter 4 for search by name\n"; //ПРОВЕРЕННО
        cout<<"Enter 5 for binary_search by number\n"; // ПРОВЕРЕННО
        cout<<"Enter 6 for quick_sort by date \n"; //ПРОВЕРЕННО
        cout<<"Enter 7 for insert_sort by napravlenie\n"; //ПРОВЕРЕННО
        cout<<"Enter 8 for pick_sort by price\n"; //ПРОВЕРЕННО
        cout<<"Enter 9 for statistick\n"; //ПРОВЕРЕННО
        cout<<"Enter 10 for search by abject\n"; //ПРОВЕРЕННО
        cout<<"Enter 11 for add information\n"; //ПРОВЕРЕННО
        cout<<"Enter 12 for print\n"; 
        cout<<"Enter 13 for clear file\n";
        cout<<"Enter 14 for editing\n";
        cout<<"Enter -1 for exit\n"; //ПРОВЕРЕННО
    while(menu!=-1){
        
        cin>>menu;

        switch(menu){
            case 0:
            cout<<"GUIDE\n";
        cout<<"Enter 1 for create file\n"; //ПРОВЕРЕННО
        cout<<"Enter 2 for read file\n"; //ПРОВЕРЕННО
        cout<<"Enter 3 for fill file\n"; //ПРОВЕРЕННО
        cout<<"Enter 4 for search by name\n"; //ПРОВЕРЕННО
        cout<<"Enter 5 for binary_search by number\n"; // ПРОВЕРЕННО
        cout<<"Enter 6 for quick_sort by date \n"; //ПРОВЕРЕННО
        cout<<"Enter 7 for insert_sort by napravlenie\n"; //ПРОВЕРЕННО
        cout<<"Enter 8 for pick_sort by price\n"; //ПРОВЕРЕННО
        cout<<"Enter 9 for statistick\n"; //ПРОВЕРЕННО
        cout<<"Enter 10 for search by abject\n"; //ПРОВЕРЕННО
        cout<<"Enter 11 for add information\n"; //ПРОВЕРЕННО
        cout<<"Enter 12 for print\n"; 
        cout<<"Enter 13 for clear file\n";
        cout<<"Enter 14 for editing\n";
        cout<<"Enter -1 for exit\n"; //ПРОВЕРЕННО
            break;
            case 1:
            char file_name[256];
            cin.ignore();
            cout<<"Enter name of file\n";
            cin.getline(file_name,256);
            train.CreateFile(file_name);
            break;
            case 2:
            cin.ignore();
           
           
            
            train.read("database.bn",train.n);
            break;
            case 3:
            char file_n[256];
            cin.ignore();
            
            train.writeFile("database.bn");
            break;
            case 4:
            cin.ignore();
            int time_n1;
            
            
            
            time_n1=train.n;
            train.read("database.bn",train.n);
            
            
            
            cout<<"Enter a SNP\n";
            char name1[256];
            cin.getline(name1,256);
            train.SearchByName(time_n1,name1);
            train.n=time_n1;
            break;
            case 5:
           
            int time_n;
            cin.ignore();
         
            time_n=train.n;
            train.read("database.bn",train.n);
            int nmbr;
            
            cout<<"Enter a number\n";
            cin>>nmbr;
            
            train.sortBinary();
            train.print(train.binary_search(nmbr,train.n-1,time_n));
            train.n=time_n;
            break;
            case 6:
            train.quickSort(0,train.n-1);
            break;
            case 7:
            train.InsertSort();
            break;
            case 8:
            train.PickSort();
            break;
            case 9:
            int q;
            cin.ignore();
            char day1[256];
            char day2[256];
            cout<<"Enter first date\n";
            cin.getline(day1,256);
            cout<<"Enter second date\n";
            cin.getline(day2,256);
            cout<<"Enter 1 for in File\n";
            cout<<"Enter 2 for console\n";
            cin>>q;
            train.InsertSortbyPrice();
            if(q==1){
                
                cin.ignore();
                char output[256];
                cout<<"Enter file name\n";
                cin.getline(output,256);
                train.StatistickaFile(day1,day2,output);
            }
            if(q==2) train.Statisticka(day1,day2);
            
            break;
            case 10:
            int search_counter;
            cout<<"Enter 1 for start->finish\n";
            cout<<"Enter 2 for only start\n";
            cout<<"Enter 3 for only finish\n";
            cin>>search_counter;
            if(search_counter==1){
            cin.ignore();
            char finish[256];
            char start[256];
            cout<<"Enter start town\n";
            cin.getline(start,256);
            cout<<"Enter finish town\n";
            cin.getline(finish,256);
            train.SearchByStartTown(start,finish);
            }
            if(search_counter==2){
                cin.ignore();
                char start[256];
                cout<<"Enter start town\n";
                cin.getline(start,256);
                train.SearchByOnlyStartTown(start);
            }
            if(search_counter==3){
                cin.ignore();
                char finish[256];
                cout<<"Enter finish town\n";
                cin.getline(finish,256);
                train.SearchByOnlyStartTown(finish);
            }
            break;
            case 11:
            train.write();
            break;
            case 12:
            for(int i=0;i<train.n;i++){
            train.print(i);
            }
            break;
            case 13:
            char fille[256];
            cout<<"Enter file for clear\n";
            cin.ignore();
            cin.getline(fille,256);
            train.CreateFile(fille);
            break;
            case 14:
            cout<<"Enter 1 for deleted by name\n";
            cout<<"Enter 2 for deleted by number\n";
            int nvmb1;
            cin>>nvmb1;
            switch(nvmb1){
                case 1:
                cin.ignore();
            int time_n1;
            
            
            
            time_n1=train.n;
            train.read("database.bn",train.n);
            
            
            
            cout<<"Enter a SNP\n";
            char name1[256];
            cin.getline(name1,256);
            train.writeFilewithRule("database.bn",train.SearchByNameInt(time_n1,name1));
            train.n=time_n1;
                break;
                case 2:
                int time_n;
            
            time_n=train.n;
            train.read("database.bn",train.n);
            int nmbr;
            
            cout<<"Enter a number\n";
            cin>>nmbr;
            
            train.sortBinary();
            train.writeFilewithRule("database.bn",train.binary_search(nmbr,train.n-1,time_n));
            train.n=time_n;
                break;

            }
            break;
            case -1:
            return 0;
            break;
        }
    }
}
