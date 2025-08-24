#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct shop {
    vector<string> FIO;
    vector<string> data;
    vector<string> number;
    vector<string> home;
    vector<string> date{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    void read(string s) {
        ifstream inFile(s);
        cout << "Enter counter members" << endl;
        int n;
        cin >> n;
        string z;
        for (int i = 0; i < n; i++) {
            inFile >> z;
            number.push_back(z);
            inFile >> z;
            FIO.push_back(z);
            inFile >> z;
            home.push_back(z);
            inFile >> z;
            data.push_back(z);
        }
        inFile.close();
    }

    int add(string s) {
        string z;
        int n;
        ofstream outFile(s, ios::app); // Открываем файл в режиме добавления данных
        cout << "Enter counter members" << endl;
        cin >> n;
        cout << "Start write" << endl;
        for (int i = 0; i < n; i++) {
            cin >> z;
            outFile << z << endl;
            cin >> z;
            outFile << z << endl;
            cin >> z;
            outFile << z << endl;
            cin >> z;
            outFile << z << endl;
        }
        outFile.close();
        return n;
    }

    void linesearch(string goal) {
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == goal) {
                cout << number[i] << endl;
                cout << FIO[i] << endl;
                cout << home[i] << endl;
                cout << data[i] << endl;
                return;
            }
        }
    }

    void Delete() {
        for (int i = 0; i < number.size(); i++) {
            for (int j = i + 1; j < number.size(); j++) {
                if (FIO[i] == FIO[j] && home[i] == home[j]) {
                    FIO.erase(FIO.begin() + i);
                    home.erase(home.begin() + i);
                    number.erase(number.begin() + i);
                    data.erase(data.begin() + i);
                }
            }
        }
    }

    int write(string s) {
        string z;
        int n;
        ofstream outFile(s);
        cout << "Enter counter members" << endl;
        cin >> n;
        cout << "Start write" << endl;
        for (int i = 0; i < n; i++) {
            cin >> z;
            outFile << z << endl;
            cin >> z;
            outFile << z << endl;
            cin >> z;
            outFile << z << endl;
            cin >> z;
            outFile << z << endl;
        }
        outFile.close();
        return n;
    }

    int index(string s) {
        for (int i = 0; i < date.size(); i++) {
            if (s == date[i]) {
                return i;
            }
        }
        return -1;
    }

    void SortByPick() {
        string s1, s2, s3, s4;
        for (int i = 0; i < data.size() - 1; i++) {
            for (int j = data[i].size() - 1; j >= 0; j--) {
                if (index(data[i][j]) < index(data[i + 1][j])) {
                    s1 = data[i];
                    s2 = number[i];
                    s3 = home[i];
                    s4 = FIO[i];
                    data[i] = data[i + 1];
                    number[i] = number[i + 1];
                    home[i] = home[i + 1];
                    FIO[i] = FIO[i + 1];
                    data[i + 1] = s1;
                    number[i + 1] = s2;
                    home[i + 1] = s3;
                    FIO[i + 1] = s4;
                }
            }
        }
    }
};

int main() {
    string s;
    shop myShop;
    int n = 0;
    cout << "Pick file" << endl;
    getline(cin, s);
    int q = 0;
    while (q != -1) {
        cout << "Pick Operation" << endl;
        cout << "1 - add" << endl;
        cout << "2 - read" << endl;
        cout << "3 - write" << endl;
        cout << "-1 - close" << endl;
        cout << "4 - complete task" << endl;
        cin >> q;
        if (q == 1) {
            n += myShop.add(s);
        }
        if (q == 2) {
            myShop.read(s);
        }
        if (q == 3) {
            n = myShop.write(s);
        }
        if (q == -1) {
            break;
        }
        if (q == 4) {
            myShop.Delete();
        }
    }
    return 0;
}
