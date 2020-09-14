#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include "ejercicio1.h"
#include "ejercicio2.h"
#include "ejercicio3.h"
using namespace std;
using namespace ejer1;
using namespace ejer2;
using namespace ejer3;

const int MAX = 100;
int menu_gral();

int main() {
  int opcion;
  do
  {
    opcion = menu_gral();
    switch (opcion)
    {
      case 1:
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
      break; 
      }
      case 2:
      {
        int opc, i = 0, num = 0, num2 = 0, numeros[MAX], busca;
        ofstream archivo;
        archivo.open("ejercicio2.txt",fstream::out);
        if(archivo.is_open())
        {
          cout << "\nIngrese el tamaño del vector: ";
          cin >> num;
          ingresar_arreglo(numeros, num);
          archivo << "Vector origninal: " << endl;
          for(int i = 0; i < num; i++)
          {
          archivo << numeros[i] << " | ";
          }
          cout << "\nLos elementos del vector: ";
          imprimir(numeros, num);
          cout << "\nLos elementos ordenados del vector: ";
          dividir(numeros, 0, num-1);
          imprimir(numeros, num);
          archivo << "\nVector ordenado: " << endl;
          for(int i = 0; i < num; i++)
          {
          archivo << numeros[i] << " | ";
          }
          archivo << endl;
          busqueda(numeros, num);
        }
        else
        {
          cout << "\nEl abrio no abrio exitosamente" << endl;
        }
      break; 
      }
      case 3:
      {
        tProveedores proveedor;
        tProductos producto[MAX];
        int contador = 0, cantidad;
        double produc, total;
        ingresar_PP(proveedor, producto, contador);
        produc = total_productos(producto, contador);
        cantidad = cantidad_productos(producto, contador);
        total = total_valor(producto, contador);
        mostrar_productos(proveedor, producto, contador, produc, cantidad, total);
        guardar_productos(proveedor, producto, contador, produc, cantidad, total);
      break; 
      }
    }
  }while (opcion != 0);
  cout << "\nGRACIAS POR USAR NUESTRO SERVICIO" << endl;
  return 0;
}

int menu_gral()
{
  int op;
  do
  {
    cout << "\n* * * MENU DE OPCIONES GENERALES * * *" << endl;
    cout << "1. Ejercicio 1" << endl;
    cout << "2. Ejercicio 2" << endl;
    cout << "3. Ejercicio 3" << endl;
    cout << "0. Salir" << endl;
    cout << "Eliga una opcion: ";
    cin >> op;
    if ((op < 0) || (op > 3))
    {
      cout << "\nEliga una opcion correcta del MENU" << endl;
    }
  }while((op < 0) || (op > 3));
  return op;
}