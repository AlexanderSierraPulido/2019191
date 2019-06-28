#include<iostream>
using namespace std;

int factorial(int valor);

int main()
    {
    cout<<"el factorial de 7 es:"<<factorial(7)<<", mientras que el factorial de 77 es:"<<factorial(77)<<endl;
    return 0;
    }

int factorial(int valor)
    {
    int i = 1;
    int fact = valor;
    for(int i =1;i<valor;i++)
        {
        fact = fact*i;
        }
    return fact;
    }