#include <iostream>
#include <math.h>
using namespace std;
double S(double x,double Y,double e){
    double sum=0;
    int k=0;
    int b=1;
    
    while   ((fabs(sum-Y))>=e){
        b=1;
        for (int i=1;i<=2*k+1;i++){
            b=b*i;
    }
        sum=sum+(pow(-1,k)*pow(x,2*k+1)/b);
        k=k+1;
    }
    return sum;
}
double S1(double x,double Y,double e){
    double sum=0;
    int k=0;
    int b=1;
    while   ((fabs(sum-Y))>=e){
            b=1;
        for (int i=1;i<=2*k+1;i++){
            b=b*i;
    }
        sum=sum+(pow(-1,k)*pow(x,2*k+1)/b);
        k=k+1;
    }
    return k;
}
double Y(double x){
    return sin(x);
}
int main(){
    double x, a, b, h, e=0.000000001;
    cout<<"Vvedite a";
    cin>>a;
    cout<<"Vvedite b";
    cin>>b;
    cout<<"Vvedite h";
    cin>>h;
    for (double x=a;x<=b;x+=h){
        cout<<"|"<<Y(x)<<"|"<<S(x,Y(x),e)<<"|"<<S1(x,Y(x),e)<<"|"<<endl;
    }
    return 0;

}