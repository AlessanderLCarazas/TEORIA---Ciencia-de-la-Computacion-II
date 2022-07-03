#include <iostream>

using namespace std;

template <typename T>

void print_ar(T* arreglo, int n)
{
    for (int i=0; i<n; i++)
    {
        cout<<*(arreglo+i)<<"\t";
    }
    cout<<endl;
}

template <typename T>

bool comparar_menor(T x, T y)
{
    return x <= y;
}
template <typename T>

bool comparar_mayor(T x, T y)
{
    return x > y;
}

template <typename T>

void insertionSort(T* arreglo,int n, bool (*p)(T , T))
{
    for(int i=1; i<n; i++)
    {
        T temp = arreglo[i];
        int j = i-1;
        while(j>=0 && p(temp,arreglo[j]) )
        {
            arreglo[j+1] = arreglo[j];
            j--;
        }
        arreglo[j+1] = temp;
    }
}

int main(){
    cout<<"\t\tINSERTION SORT"<<endl;
    cout<<"\n\tArreglo INT: "<<endl;
    int arreglo_int[10] = {6,7,5,8,9,10,2,4,1,3};
    cout<<"\nArreglo Original: "<<endl;
    print_ar(arreglo_int,10);
    cout<<"\nArreglo Ordenado Ascendente: "<<endl;
    insertionSort(arreglo_int,10, comparar_menor);
    print_ar(arreglo_int,10);
    cout<<"\nArreglo Ordenado Descentente: "<<endl;
    insertionSort(arreglo_int,10, comparar_mayor);
    print_ar(arreglo_int,10);

    cout<<"\n\tArreglo FLOAT: "<<endl;
    float arreglo_float[12] = {10.2,5.2,44.2,8.2,50.12,100.2,15.2,96.,11.2,1.2,62.12,51.2};
    cout<<"\nArreglo Original: "<<endl;
    print_ar(arreglo_float,12);
    cout<<"\nArreglo Ordenado Ascendente: "<<endl;
    insertionSort(arreglo_float,12, comparar_menor);
    print_ar(arreglo_float,12);
    cout<<"\nArreglo Ordenado Descentente: "<<endl;
    insertionSort(arreglo_float,12, comparar_mayor);
    print_ar(arreglo_float,12);

    cout<<"\n\tArreglo Vocales: "<<endl;
    char arreglo_char[5] = {'o','i','u','a','e'};
    cout<<"\nArreglo Original: "<<endl;
    print_ar(arreglo_char,5);
    cout<<"\nArreglo Ordenado Ascendente: "<<endl;
    insertionSort(arreglo_char,5, comparar_menor);
    print_ar(arreglo_char,5);
    cout<<"\nArreglo Ordenado Descentente: "<<endl;
    insertionSort(arreglo_char,5, comparar_mayor);
    print_ar(arreglo_char,5);

    return 0;
}
