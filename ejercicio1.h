#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
using namespace std;
namespace ejer1
{
  /*
  void ejercicio1()
{
  ofstream arreglo;
  arreglo.open("ejercicio1.txt", ios::out);
  if(arreglo.is_open())
  {
    int a[MAX];
    ingresar(a);
    arreglo << "Arreglo original: " << '\n';
    for(int i = 0; i < MAX; i++)
    { 
      arreglo << a[i] << "|"; 
    }
    arreglo << '\n';
    ordenar(a);
    arreglo << "El minimo elemento del arreglo es: " << a[0] << " y se repite " << hallar_min(a) << " veces" << endl; 
    arreglo << "El maximo elemento del arreglo es: " << a[MAX-1] << " y se repite " << hallar_max(a) << " veces";
  }
  else
  {
    cout << "\nEl abrio no abrio exitosamente" << endl;
  }
  arreglo.close();
  cout << "\nEl ejercicio 1 se ha realizado con exito. Favor revisar el archivo 'ejercicio1'" << endl;
}
*/

void ingresar(int Arreglo[100])
{
  srand(time(0));
  for(int i = 0; i < 100; i++)
  {
    Arreglo[i] = 1 + rand() % (99-1);
  }
}

void ordenar(int Arreglo[100])
{
  int i, j, aux;
  for(i = 0; i < 100; i++)
  {
    for(j = i + 1; j < 100; j++)
    {
      if(Arreglo[j]<Arreglo[i])
      {
        aux = Arreglo[i];
        Arreglo[i] = Arreglo[j];
        Arreglo[j] = aux;
      }
    }
  }
}

int hallar_min(int Arreglo[100])
{
  int cont_min = 0;
  for(int i = 0; i < 100; i++)
  {
    if(Arreglo[i] == Arreglo[0])
    {
      cont_min++;
    }
  }
  return cont_min;
}

int hallar_max(int Arreglo[100])
{
  int cont_max = 0;
  for(int i = 0; i < 100; i++)
  {
    if(Arreglo[i] == Arreglo[99])
    {
      cont_max++;
    }
  }
  return cont_max;
}
}