#include <iostream>
using namespace std;
double** mat(double** a, int n, double** b){
    double** c;
    c=new double* [n];
    for (int i=0;i<n;i++){
        c[i]= new double [n];
    }
    double sum=0;
    for(int j=0;j<n;j++){
        
            for(int o=0;o<n;o++){
            
                sum=0;
                for (int s=0;s<n;s++){
                    sum+=b[j][s]*a[s][o];
                }
                c[j][o]=sum;
            }
                
        

    }
    return c;
}
int main(){
    int n,k;
    double** a;
    cout<<"Vvedite n ";
    cin>>n;
    cout<<"Vvedite k ";
    cin>>k;
    double** b;
    b=new double* [n];
    for (int i=0;i<n;i++){
        b[i]= new double [n];
    }
    a= new double* [n];
    for (int i=0;i<n;i++){
        a[i]= new double [n];
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            b[i][j]=a[i][j];
        }
    }
    for (int i=1;i<k;i++){
        b=mat(a,n,b);
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout<<b[i][j]<<" ";
        }
        cout<<""<<endl;
    }
    for (int i=0;i<n;i++){
        delete [] a[i];
    }
    delete [] a;
    return 0;



}