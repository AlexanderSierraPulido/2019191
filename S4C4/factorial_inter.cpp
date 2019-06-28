#include<iostream>
using namespace std;

int factorial(int valor);

int main()
    {
    cout<<factorial(0)<<endl;
    return 0;
    }

int factorial(int valor)
    {
    cout<<"ingrese el valor"<<endl;
    cin>> valor;
    int fact = valor;
    for(int i =1;i<valor;i++)
        {
        fact = fact*i;
        }
    return fact;
    }