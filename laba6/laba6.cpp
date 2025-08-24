#include <iostream>
#include <stdio.h>
using namespace std;
int line_search(char* s){
    int result=0;
    for(auto i=0;s[i]!='\0';i++){
        if (s[i]=='a'){
            result++;
        }
    }
    return result;
}
int length(char* s){
    int result=0;
    for(auto i=0;s[i]!='\0';i++){
        result++;
    }
    return result;
}
int main(){
    char s[100];
    int n;
    cout<<"Enter s ";
    fgets(s,100,stdin);
    n=length(s);
    if(n>0 && s[n-1]=='\n'){
        s[n-1]='\0';
    }
    fflush(stdin);
    n=length(s);
    cout<<"Kolichestvo a = "<<line_search(s)<<endl;
    cout<<"Dlina = "<<n<<endl;
    delete [] s;
    return 0;
}