#include <iostream>
#include <stdio.h>
using namespace std;
bool Default(char* s,int length){
    for(auto i=0;s[i]!='\0';i++){
        if(s[i]!=s[length-1-i]){
            return false;
        }
    }
    return true;
}
bool Recurse(char* s,int length,int i){
    if (i==(length-1)){
        return true;
    }
    if (s[i]!=s[length-1-i]){
        return false;
    }
    return Recurse(s,length,i+1);
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
    fflush(stdin);
    if(n>0 && s[n-1]=='\n'){
        s[n-1]='\0';
    }
    n=length(s);
    cout<<"Result = "<<Default(s,n)<<'\n';
    cout<<"Result = "<<Recurse(s,n,0)<<'\n';
    delete [] s;
    return 0;  
}