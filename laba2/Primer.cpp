#include <iostream>
#include <math.h>
using namespace std;
int main(){
    double x, y;
    int z;
    cout<<"enter x ";
    cin>>x;
    cout<<"enter y ";
    cin>>y;
    cout<<"enter z ";
    cin>>z;
    switch(z){
        case 1:
            cout<<pow(x-y,3)+atan(x);
            break;
        case 2:
            cout<<pow(x-y,3)+atan(x);
            break;
        case 3:
            cout<<pow(x-y,3)+atan(x);
            break;
        
        case 12:
            cout<<pow(y-x,3)+atan(x);
            break;
        case 13:
            cout<<pow(y-x,3)+atan(x);;
            break;
        case 14:

            cout<<pow(y-x,3)+atan(x);;
            break;
        default:
            cout<<pow(y+x,3)+0.5;
            break;
    }
}