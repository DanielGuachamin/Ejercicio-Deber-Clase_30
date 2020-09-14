#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
const int Max = 100;
using namespace std;
namespace ejer2
{
  void fusionar(int a[Max],int pinicial, int pfinal, int medio)
  {
    int i, j, k, temp[pfinal-pinicial+1];
    i = pinicial;
    k = 0;
    j = medio + 1;
    while (i <= medio && j <= pfinal)
    {
      if (a[i] < a[j])
      {
        temp[k] = a[i];
        k++;
        i++;
      }
      else
      {
        temp[k] = a[j];
        k++;
        j++;
      }
    }
    while (i <= medio)
    {
      temp[k] = a[i];
      k++;
      i++;
    }
    while (j <= pfinal)
    {
      temp[k] = a[j];
      k++;
      j++;
    }
    for (i = pinicial; i <= pfinal; i++)
    {
      a[i] = temp[i-pinicial];
    }
  }
  void ingresar_arreglo(int a[Max], int t)
  {
    for(int i = 0; i < t; i++)
    {
      cout << "Ingrese el elemento: ";
      cin >> a[i];
    }
  }
  void imprimir(int a[Max], int t)
  {
    for(int i = 0; i < t; i++)
    {
      cout << a[i] << " | ";
    }
  }
  void dividir(int a[Max], int inicial, int Final)
  {
    int mitad;
    if (inicial < Final)
    {
      mitad=(inicial+Final)/2;
      dividir(a,inicial,mitad);
      dividir(a,mitad+1,Final);
      fusionar(a,inicial,Final,mitad);
    }
  }
  
  
  void busqueda (int a[Max], int n)
  {
    ofstream archivo;
    archivo.open("ejercicio2.txt", ios::app);
    int busca, posicion = -1;
    bool hallado;
    cout << "\nIngrese un elemento a buscar: ";
    cin >> busca;
    for (int i=0 ; i <= n; i++)
    {
      if (a[i] == busca)
      {
        posicion = i;
      }
    }
    if (posicion != -1)
    {
      cout << "\nEl elemento " << busca << " fue hallado en la posicion: " << posicion + 1 << endl;
      archivo << "El elemento " << busca << " fue hallado en la posicion: " << posicion + 1 << endl;
    }
    else
    {
      cout << "\nEl elemento no existe en el vector" << endl;
      archivo << "El elemento no existe en el vector" << endl;
    }
    archivo.close();
  }
}