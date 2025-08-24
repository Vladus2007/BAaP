#include <iostream>
#include <stack>
#include <math.h>
using namespace std;
void solution(int N,int p){
    int result=0,counter=0;
    if(N==0){
        cout<<"0"<<endl;
        return;
    }
    while(N>0){
        result+=N%p*pow(10,counter);
        N=N/p;
        counter++;
    }
    cout<<result;
    cout<<'\n';
}
void recurse(int N,int p,int ten,int counter){
    if(N==0){
        cout<<counter<<endl;
        return;
    }
    counter+=(N%p)*ten;
    N=N/p;
    return recurse(N,p,ten*10,counter);
}
int main(){
    int N;
    cout<<"Enter N"<<endl;
    cin>>N;
    if(N<0){
        N*=-1;
    }
    int p;
    cout<<"Pick p "<<endl;
    cin>>p;
    while(p<=0 || p>=10){
        cout<<"P is incorrect"<<endl;
        cin>>p;
    }
    solution(N,p); 
    recurse(N,p,1,0);
    return 0;
}