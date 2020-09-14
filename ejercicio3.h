#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
const int maX = 100;
  typedef struct
{
  string codigo;
  string nombre;
  string ciudad;
  int telefono;
}tProveedores;

typedef struct
{
  string producto;
  double precio;
  int cantidad;
  string estado;
}tProductos;

using namespace std;
namespace ejer3
{

/*
  void ejercicio3()
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
}
*/
void ingresar_PP(tProveedores &Proveedor, tProductos Producto[maX], int &conta)
{
  cin.ignore();
  char sigue = '$';
  int i = 0;
  cout << "\n* * * * INGRESE LOS DATOS DEL PROVEEDOR * * * *" << endl;
  cout << "Código: ";
  getline(cin, Proveedor.codigo);
  cout << "Nombre: ";
  getline(cin, Proveedor.nombre);
  cout << "Ciudad: ";
  getline(cin, Proveedor.ciudad);
  cout << "Teléfono: ";
  cin >> Proveedor.telefono;
  cout << "\n* * * * INGRESE LOS DATOS DEL PRODUCTO * * * *" << endl;
  do
  {
    cin.ignore();
    cout << "\nProducto: ";
    getline(cin, Producto[i].producto);
    cout << "Precio: ";
    cin >> Producto[i].precio;
    cout << "Unidades: ";
    cin >> Producto[i].cantidad;
    cin.ignore();
    cout << "Estado: ";
    getline(cin, Producto[i].estado);
    cout << "\nPara ingresar otro producto presione '#' para salir '*': ";
    cin >> sigue;
    conta++;
    i++;
  }while(sigue != '*');
}
double total_productos(tProductos Producto[maX], int &conta)
{
  double productos = 0;
  for(int i = 0; i < conta; i++)
  {
    productos += Producto[i].precio;
  }
  return productos;
}
int cantidad_productos(tProductos Producto[maX], int &conta)
{
  int cantidad = 0;
  for(int i = 0; i < conta; i++)
  {
    cantidad += Producto[i].cantidad;
  }
  return cantidad;
}
double total_valor(tProductos Producto[maX], int &conta)
{
  double total = 0;
  for(int i = 0; i < conta; i++)
  {
    total += Producto[i].precio * Producto[i].cantidad;
  }
  return total;
}
void mostrar_productos(tProveedores &Proveedor, tProductos Producto[maX], int &conta , double produc, int unid, double total)
{
  cout << "\n\t\t* * * * DATOS DEL PROVEEDOR * * * *" << endl;
  cout << "Código " << "Nombre " << setw(20) << "Ciudad " << setw(20) << "Teléfono" << endl;
  cout << right << setw(6) << Proveedor.codigo << " " << left << setw(20) << Proveedor.nombre << left << setw(17) << Proveedor.ciudad << " " << Proveedor.telefono << endl;
  cout << "\n\t\t* * * * DATOS DEL PRODUCTO * * * *" << endl;
  cout << setw(20) << "Nombre" << setw(5) << left << "Precio " << setw(6) << "Cantidad " << setw(10) << "Estado" << endl;
  for(int i = 0; i < conta; i++)
  {
    cout << left << setw(20) << Producto[i].producto << " " << setw(5) << right << Producto[i].precio << " " << right << setw(8) << Producto[i].cantidad << " " << setw(10) << left << Producto[i].estado << endl;
  }
  cout << "\nTotal de productos " << right << setw(22) << produc;
  cout << "\nCantidad de productos adquiridos " << right << setw(8) << unid;
  cout << "\nEl valor total " << right << setw(26) << total << endl;
}
void guardar_productos(tProveedores &Proveedor, tProductos Producto[maX], int &conta , double produc, int unid, double total)
{
  ofstream archivo;
  archivo.open("productos.txt", ios::out);
  if(archivo.is_open())
  {
    archivo << "\n\t\t* * * * DATOS DEL PROVEEDOR * * * *" << endl;
    archivo << "Código " << "Nombre " << setw(20) << "Ciudad " << setw(20) << "Teléfono" << endl;
    archivo << right << setw(6) << Proveedor.codigo << " " << left << setw(20) << Proveedor.nombre << left << setw(17) << Proveedor.ciudad << " " << Proveedor.telefono << endl;
    archivo << "\n\t\t* * * * DATOS DEL PRODUCTO * * * *" << endl;
    archivo << setw(20) << "Nombre" << setw(5) << left << "Precio " << setw(6) << "Cantidad " << setw(10) << "Estado" << endl;
    for(int i = 0; i < conta; i++)
    {
      archivo << left << setw(20) << Producto[i].producto << " " << setw(5) << right << Producto[i].precio << " " << right << setw(8) << Producto[i].cantidad << " " << setw(10) << left << Producto[i].estado << endl;
    }
    archivo << "\nTotal de productos " << right << setw(22) << produc;
    archivo << "\nCantidad de productos adquiridos " << right << setw(8) << unid;
    archivo << "\nEl valor total " << right << setw(26) << total << endl;
  }
  else
  {
    cout << "\nEl abrio no abrio exitosamente" << endl;
    
  }
}
}