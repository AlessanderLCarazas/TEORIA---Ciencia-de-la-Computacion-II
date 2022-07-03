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

void cambiar(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

template <typename T>

int particion(T *arreglo, int menor, int mayor, bool (*p)(T,T))
{
    T pivot = arreglo[mayor];
    int i = (menor - 1);
    for (int j = menor; j < mayor; j++)
    {
        if (p(arreglo[j],pivot))
        {
            i++;
            cambiar(&arreglo[i],&arreglo[j]);
        }
    }
    cambiar(&arreglo[i + 1], &arreglo[mayor]);
    return (i + 1);
}

template <typename T>

void quickSort(T *arreglo, int menor, int mayor,bool (*p)(T,T))
{
    if (menor < mayor)
    {
        T pivot = particion(arreglo,menor,mayor,p);
        quickSort(arreglo,menor,pivot - 1,p);
        quickSort(arreglo,pivot + 1,mayor,p);
    }
}

int main()
{
    cout<<"\t\tQUICK SORT"<<endl;
    cout<<"\n\tArreglo INT: "<<endl;
    int arreglo_int[10] = {3,10,4,2,8,1,7,9,5,6};
    cout<<"\nArreglo Original: "<<endl;
    print_ar(arreglo_int,10);
    cout<<"\nArreglo Ordenado Ascendente: "<<endl;
    quickSort(arreglo_int,0, 10-1,comparar_menor);
    print_ar(arreglo_int,10);
    cout<<"\nArreglo Ordenado Descentente: "<<endl;
    quickSort(arreglo_int,0, 10-1,comparar_mayor);
    print_ar(arreglo_int,10);

    cout<<"\n\tArreglo FLOAT: "<<endl;
    float arreglo_float[12] = {50.2,58.8,36.5,47.5,15.2,16.9,85.6,74.5,123.2,22.15,32.45,12.2};
    cout<<"\nArreglo Original: "<<endl;
    print_ar(arreglo_float,12);
    cout<<"\nArreglo Ordenado Ascendente: "<<endl;
    quickSort(arreglo_float,0, 12-1,comparar_menor);
    print_ar(arreglo_float,12);
    cout<<"\nArreglo Ordenado Descentente: "<<endl;
    quickSort(arreglo_float,0, 12-1,comparar_mayor);
    print_ar(arreglo_float,12);

    cout<<"\n\tArreglo Vocales: "<<endl;
    char arreglo_char[5] = {'i','a','o','e','u'};
    cout<<"\nArreglo Original: "<<endl;
    print_ar(arreglo_char,5);
    cout<<"\nArreglo Ordenado Ascendente: "<<endl;
    quickSort(arreglo_char,0, 5-1,comparar_menor);
    print_ar(arreglo_char,5);
    cout<<"\nArreglo Ordenado Descentente: "<<endl;
    quickSort(arreglo_char,0, 5-1,comparar_mayor);
    print_ar(arreglo_char,5);

    return 0;
}
