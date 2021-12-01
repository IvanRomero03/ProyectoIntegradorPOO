//Iván Alberto Romero Wells A00833623
#include <bits/stdc++.h>
#include "Arreglo.h"
#include "Empresa.h"
#include "Usuarios.h"
#include "Producto.h"
#include "Gobierno.h"

using namespace std;

int main()
{
    Gobierno gobierno;

    gobierno.agregarUsuario("Ivan", 1000);
    gobierno.agregarUsuario("Ariadna", 2000);
    gobierno.agregarUsuario("Pedro", 3000);

    Arreglo<Usuario> usuarios = gobierno.listarUsuarios();
    for (int i = 0; i < usuarios.obtenerTamano(); i++)
    {
        cout << usuarios[i].getNombre() << endl;
    }

    gobierno.agregarEmpresa("HeB");

    gobierno.agregarProducto("HeB", "Leche", "Leche de Vaca", 30, 10);
    gobierno.agregarProducto("HeB", "Pan", "Pan de trigo", 50, 15);
    gobierno.agregarProducto("HeB", "Jabon", "Jabon de cocina", 20, 5);
    gobierno.agregarProducto("HeB", "Suavitel", "Suavitel de flores", 30, 10);

    gobierno.agregarEmpresa("BestBuy");

    gobierno.agregarProducto("BestBuy", "TV 4k", "Television Samsung HD 4k", 30, 10000);
    gobierno.agregarProducto("BestBuy", "Iphone", "Celular inteligente Apple", 50, 1500);
    gobierno.agregarProducto("BestBuy", "Laptop", "Computadora personal", 20, 5000);
    gobierno.agregarProducto("BestBuy", "Celular", "Celular de 4G", 30, 1000);

    gobierno.agregarEmpresa("Nike");
    gobierno.agregarProducto("Nike", "Zapatillas", "Zapatillas de futbol", 30, 100);
    gobierno.agregarProducto("Nike", "Pantalon", "Pantalon de futbol", 50, 150);
    gobierno.agregarProducto("Nike", "Camiseta", "Camiseta de futbol", 20, 50);
    gobierno.agregarProducto("Nike", "Sandalia", "Sandalia de futbol", 30, 10);

    Arreglo<Empresa> empresas = gobierno.listarEmpresas();
    for (int i = 0; i < empresas->obtenerTamano(); i++)
    {
        cout << (*empresas)[i].getNombreEmpresa() << endl;
    }

    cout << "Productos de las empresas: " << endl;
    for (int i = 0; i < empresas->obtenerTamano(); i++)
    {
        cout << (*empresas)[i].getNombreEmpresa() << ": " << endl;
        Arreglo<Producto> productos = (*empresas)[i].getProductos();
        for (int j = 0; j < productos.obtenerTamano(); j++)
        {
            cout << productos[j].getNombre() << endl;
        }
        cout << endl;
    }

    /*
    Arreglo<Producto> prodsasd = (*empresas)[0].getProductos();
    for (int i = 0; i < prodsasd.obtenerTamano(); i++)
    {
        cout << "prod" << prodsasd[i].getNombre() << endl;
    }*/
    /*
    Arreglo<Producto> productos = gobierno.listarProductos("Empresa1");
    cout << productos.obtenerTamano() << endl;
    for (int i = 0; i < productos.obtenerTamano(); i++)
    {
        cout << productos[i].getNombre() << endl;
    } */
    /*
    cout << "a" << endl;
    string asdasd = gobierno.Compra("Ivan", "Empresa1", "Producto3", 1);
    cout << asdasd << endl;
    Usuario *usuario = gobierno.getUsuario("Ivan");
    cout << "Ivan tiene " << (*usuario).getDinero() << " pesos" << endl;
    */
}