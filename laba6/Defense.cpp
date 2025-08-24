#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    char s[100];
    cout<<"Enter s ";
    fgets(s,100,stdin);
    fflush(stdin);
    if(s[0]!=' '){
        s[1]='A';
    }
    for(int i=0;s[i]!='\0';i++){
        if (s[i]==' ' && s[i+1]!=' ' && s[i+2]!=' '  && s[i+2]!='\0' && s[i+2]!='\n'){
            s[i+2]='A';
        }
    }
    for(int i=0;s[i]!='\0';i++){
        cout<<s[i];
    }
}