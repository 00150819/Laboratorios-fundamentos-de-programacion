#include <iostream>
using namespace std;

int num, factorial=1;


int main(){

    cout <<"ingrese un numero a calcular: ";
    cin>>num;
    
    if(num<0){
        cout<<"ingrese un numero mayor a 0"<<endl;  
    }
    else{
        
        for(int i=1; i<=num; i++){
            factorial*=i;

        }
        cout <<"el factorial de su numero es: "<<factorial<<endl;
        
    }
    
return 0;
}