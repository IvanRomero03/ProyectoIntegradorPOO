//Iván Alberto Romero Wells A00833623
#include <bits/stdc++.h>
#include "Empresa.h"
#include "Gobierno.h"
#include "Usuarios.h"
#include "Producto.h"
#include "Arreglo.h"

using namespace std;

int main()
{
    Arreglo<Usuario> usuarios;
    Arreglo<Producto> productosComericales;
    Arreglo<Empresa> empresas;
    cout << "Bienvenido al sistema de gestion de empresas" << endl;

    Usuario usuario1("Ivan", 1000);
    Usuario usuario2("Ariadna", 2000);
    Usuario usuario3("Juan", 3000);
    Usuario usuario4("Pedro", 4000);
    Usuario usuario5("Juan", 5000);
    usuarios.agregar(usuario1);
    usuarios.agregar(usuario2);
    usuarios.agregar(usuario3);
    usuarios.agregar(usuario4);
    usuarios.agregar(usuario5);

    cout << "Usuarios agregados" << endl;
    productosComericales.agregar(Producto("Leche", "Leche de vaca", 30, 10));
    productosComericales.agregar(Producto("Pan", "Pan de trigo", 20, 15));
    productosComericales.agregar(Producto("Jabon", "Jabon de coco", 10, 5));
    productosComericales.agregar(Producto("Jamon", "Jamon de pavo", 10, 5));

    cout << "Productos agregados" << endl;
    Arreglo<Producto> productosTecnologicos;

    productosTecnologicos.agregar(Producto("Laptop", "Laptop de Lenovo", 100, 10));
    productosTecnologicos.agregar(Producto("Smartphone", "Smartphone de Samsung", 50, 5));
    productosTecnologicos.agregar(Producto("Tablet", "Tablet de Samsung", 80, 15));
    productosTecnologicos.agregar(Producto("Smartwatch", "Smartwatch de Apple", 30, 20));

    cout << "Productos tecnologicos agregados" << endl;

    Arreglo<Producto> productosDeportivos;
    productosDeportivos.agregar(Producto("Bicicleta", "Bicicleta de Trek", 100, 10));
    productosDeportivos.agregar(Producto("Patinete", "Patinete de Trek", 50, 5));
    productosDeportivos.agregar(Producto("Tenis", "Tenis de Nike", 80, 15));
    productosDeportivos.agregar(Producto("Pelota", "Pelota de futbol", 30, 20));

    cout << "Productos deportivos agregados" << endl;

    empresas.agregar(Empresa("Soriana", productosComericales));
    empresas.agregar(Empresa("BestBuy", productosTecnologicos));
    empresas.agregar(Empresa("Adidas", productosDeportivos));

    cout << "Empresas agregadas" << endl;

    Gobierno gobierno(usuarios, empresas);

    cout << "Gobierno creado" << endl;
    //Desplegar todos los usuarios
    cout << "Usuarios: " << endl;
    Arreglo<Usuario> *usuariosDesplegar = gobierno.listarUsuarios();
    for (int i = 0; i < usuariosDesplegar->obtenerTamano(); i++)
    {
        cout << (*usuariosDesplegar)[i].getNombre() << endl;
    }
}