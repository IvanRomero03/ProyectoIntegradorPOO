//Iván Alberto Romero Wells A00833623
//Ariadna Daniela Medina García A01748822
#include <bits/stdc++.h>
#include "Arreglo.h"
#include "Empresa.h"
#include "Producto.h"
#include "Usuarios.h"

using namespace std;

int main()
{
    cout << "Iván Alberto Romero Wells A00833623" << endl;
    cout << "Ariadna Daniela Medina García A01748822" << endl;
    Producto Pan("Pan", "Pan blanco BIMBO", 24, 15);
    cout << "Producto 1: " << Pan.getNombre() << endl;
    Producto Leche("Leche", "Leche de vaca Jersey", 25, 10);
    cout << "Producto 2: " << Leche.getNombre() << endl;
    Producto Carne("Carne", "Carne de cerdo", 30, 20);
    cout << "Producto 3: " << Carne.getNombre() << endl;
    Producto Queso("Queso", "Queso de cabra", 35, 15);
    cout << "Producto 4: " << Queso.getNombre() << endl;
    Producto Arroz("Arroz", "Arroz de maiz", 40, 10);
    cout << "Producto 5: " << Arroz.getNombre() << endl;
    Producto TV("TV", "TV de plasma", 3500, 5);
    cout << "Producto 6: " << TV.getNombre() << endl;

    Arreglo<Producto> Productos;
    Productos.agregar(Pan);
    Productos.agregar(Leche);
    Productos.agregar(Carne);
    Productos.agregar(Queso);
    Productos.agregar(Arroz);
    Productos.agregar(TV);

    Empresa Soriana("Soriana", Productos);
    cout << "Empresa: " << Soriana.getNombreEmpresa() << endl;
    cout << "Productos: " << endl;
    Arreglo<Producto> ProductosEmpresa(Soriana.getProductos());
    for (int i = 0; i < ProductosEmpresa.obtenerTamano(); i++)
    {
        cout << ProductosEmpresa[i].getNombre() << endl;
    }
    Usuario Usuario1("Ivan", 1000);
    Usuario Usuario2("Ariadna", 2000);
    Usuario Usuario3("Yair", 4000);

    //Interaccion Mercado-Usuarios
    cout << endl;
    //usuario1 comprar pan, leche y carne
    cout << "Usuario1 comprar Pan, Leche y Carne" << endl;
    string compra1 = Soriana.comprarProducto(&Usuario1, "Pan", 1);
    cout << "Pan: " << compra1 << endl;
    string compra2 = Soriana.comprarProducto(&Usuario1, "Leche", 1);
    cout << "Leche: " << compra2 << endl;
    string compra3 = Soriana.comprarProducto(&Usuario1, "Carne", 2);
    cout << "Carne: " << compra3 << endl;
    cout << endl;
    //usuario2 comprar queso, leche y arroz
    cout << "Usuario2 comprar Queso, Leche y Arroz" << endl;
    string compra4 = Soriana.comprarProducto(&Usuario2, "Queso", 1);
    cout << "Queso: " << compra4 << endl;
    string compra5 = Soriana.comprarProducto(&Usuario2, "Leche", 1);
    cout << "Leche: " << compra5 << endl;
    string compra6 = Soriana.comprarProducto(&Usuario2, "Arroz", 1);
    cout << "Arroz: " << compra6 << endl;
    cout << endl;
    //usuario1 intenta comprar una TV
    cout << "Usuario1 intenta comprar una TV" << endl;
    string compra7 = Soriana.comprarProducto(&Usuario1, "TV", 1);
    cout << "TV: " << compra7 << endl;
    cout << endl;
    //usuario3 compar TV
    cout << "Usuario3 comprar TV" << endl;
    string compra8 = Soriana.comprarProducto(&Usuario3, "TV", 1);
    cout << "TV: " << compra8 << endl;
    cout << endl;

    Usuario Usuario4("Juan", 5000);
    //usuario4 intenta comprar toda la leche
    cout << "Usuario4 intenta comprar toda la leche" << endl;
    string compra9 = Soriana.comprarProducto(&Usuario4, "Leche", Soriana.obtenerProducto("Leche").getCantidad());
    cout << "Leche: " << compra9 << endl;
    cout << endl;
    //usuario4 intenta comprar una leche mas
    cout << "Usuario4 intenta comprar una leche mas" << endl;
    string compra11 = Soriana.comprarProducto(&Usuario4, "Leche", 1);
    cout << "Leche: " << compra11 << endl;
    cout << endl;

    //Usuario2 intenta comprar un producto que no esta en la lista
    cout << "Usuario2 intenta comprar un producto que no esta en la lista" << endl;
    string compra10 = Soriana.comprarProducto(&Usuario2, "Cafe", 1);
    cout << "Cafe: " << compra10 << endl;
    cout << endl;
}