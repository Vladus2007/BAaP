#include <iostream>
using namespace std;
int* b(int N,int* a){
    int i=0;
    if(N==0){
        a[0]=0;
        return a;
    }
    while (N>0){
        if ((N%10)%3==0){
        a[i]=N%10;
        i+=1;
        }
        N=N/10; 
    }
    return a;
}
int g(int N){
    int i=0;
    if(N==0){
        return 1;
    }
    while (N>0){
        if ((N%10)%3==0){
        i+=1;
        }
        N=N/10;
    }
    return i;
}
int main(){
    int N;
    cout<<"Enter N ";
    cin>>N;
    N=abs(N);
    int c=g(N);
    int* a=new int[c];
    a=b(N,a);
    for (int i=c-1; i>=0;i-=1){
        cout<<a[i]<<" ";
    }
    delete [] a;
    return 0;
}