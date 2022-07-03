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

template<typename T>

void div(T* arreglo, int menor, int mayor, int medio, bool (*p)(T,T))
{
    int i = menor,k = i;
    int j = medio+1, a[1000];

    while (i <= medio && j <= mayor)
    {
        if (p(arreglo[i],arreglo[j]))
        {
            a[k] = arreglo[i];
            i++;
        }
        else
        {
            a[k] = arreglo[j];
            j++;
        }
        k++;
    }
    while (i <= medio)
    {
        a[k] = arreglo[i];
        k++;
        i++;
    }
    while (j <= mayor)
    {
        a[k] = arreglo[j];
        k++;
        j++;
    }
    for (i = menor; i < k; i++)
        arreglo[i] = a[i];
}

template<typename T>

void mergeSort(T *arreglo, int menor, int mayor, bool (*p)(T,T))
{
    T medio;
    if (menor < mayor)
    {
        medio=(menor+mayor)/2;
        mergeSort(arreglo,menor,medio,p);
        mergeSort(arreglo,medio+1,mayor,p);
        div(arreglo,menor,mayor,medio,p);
    }
}

int main()
{
    cout<<"\t\tMERGE SORT"<<endl;
    cout<<"\n\tArreglo INT: "<<endl;
    int arreglo_int[5] = {2,3,4,5,1};
    cout<<"\nArreglo Original: "<<endl;
    print_ar(arreglo_int,5);
    cout<<"\nArreglo Ordenado Ascendente: "<<endl;
    mergeSort(arreglo_int,0, 5-1,comparar_menor);
    print_ar(arreglo_int,5);
    cout<<"\nArreglo Ordenado Descentente: "<<endl;
    mergeSort(arreglo_int,0, 5-1,comparar_mayor);
    print_ar(arreglo_int,5);

    cout<<"\n\tArreglo FLOAT: "<<endl;
    float arreglo_float[7] = {25.5,65.2,10.5,59.2,10.6,236.52,175.2};
    cout<<"\nArreglo Original: "<<endl;
    print_ar(arreglo_float,7);
    cout<<"\nArreglo Ordenado Ascendente: "<<endl;
    mergeSort(arreglo_float,0, 7-1,comparar_menor);
    print_ar(arreglo_float,7);
    cout<<"\nArreglo Ordenado Descentente: "<<endl;
    mergeSort(arreglo_float,0, 7-1,comparar_mayor);
    print_ar(arreglo_float,7);

    cout<<"\n\tArreglo Vocales: "<<endl;
    char arreglo_char[11] = {'b','e','a','c','d','k','h','f','i','g','j'};
    cout<<"\nArreglo Original: "<<endl;
    print_ar(arreglo_char,11);
    cout<<"\nArreglo Ordenado Ascendente: "<<endl;
    mergeSort(arreglo_char,0, 11-1,comparar_menor);
    print_ar(arreglo_char,11);
    cout<<"\nArreglo Ordenado Descentente: "<<endl;
    mergeSort(arreglo_char,0, 11-1,comparar_mayor);
    print_ar(arreglo_char,11);

    return 0;
}
