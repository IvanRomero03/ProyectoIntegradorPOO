#pragma once
//Iván Alberto Romero Wells A00833623
//Ariadna Daniela Medina García A01748822
#include <bits/stdc++.h>
#include "Producto.h"
#include "Arreglo.h"
#include "Empresa.h"
#include "Usuarios.h"

using namespace std;

class Empresa
{
private:
    string nombreEmpresa;
    Arreglo<Producto> productos;

public:
    Empresa()
    {
        nombreEmpresa = "";
    }
    Empresa(string nombreEmpresa)
    {
        this->nombreEmpresa = nombreEmpresa;
    }
    Empresa(string nombreEmpresa, Arreglo<Producto> &productos)
    {
        this->nombreEmpresa = nombreEmpresa;
        this->productos = productos;
    }
    string getNombreEmpresa()
    {
        return nombreEmpresa;
    }
    void setNombreEmpresa(string nombreEmpresa)
    {
        this->nombreEmpresa = nombreEmpresa;
    }
    Arreglo<Producto> getProductos()
    {
        return productos;
    }
    void imprimirProductos()
    {
        for (int i = 0; i < productos.obtenerTamano(); i++)
        {
            cout << productos[i].getNombre() << endl;
        }
    }
    void agregarProducto(Producto producto)
    {
        productos.agregar(producto);
    }
    int buscarProducto(string nombre)
    {
        for (int i = 0; i < productos.obtenerTamano(); i++)
        {
            if (productos[i].getNombre() == nombre)
            {
                return i;
            }
        }
        return -1;
    }
    Producto obtenerProducto(string nombre)
    {
        int indice = buscarProducto(nombre);
        if (indice != -1)
        {
            return productos[indice];
        }
        else
        {
            return Producto();
        }
    }
    void eliminarProducto(string nombre)
    {
        int indice = buscarProducto(nombre);
        if (indice != -1)
        {
            productos.eliminar(buscarProducto(nombre));
        }
    }
    Arreglo<Producto> *punteroProductos()
    {
        return &productos;
    }
    void modificarProducto(string nombre, Producto producto)
    {
        int indice = buscarProducto(nombre);
        if (indice != -1)
        {
            productos.modificar(indice, producto);
        }
    }
    string comprarProducto(Usuario *usuario, string nombre, int cantidad)
    {
        int indice = buscarProducto(nombre);
        if (indice != -1)
        {
            if (productos[indice].getCantidad() >= cantidad)
            {
                int dineroCliente = usuario->getDinero();
                int precioProducto = productos[indice].getPrecio();
                precioProducto = precioProducto * cantidad;
                if (dineroCliente >= precioProducto)
                {
                    usuario->setDinero(dineroCliente - precioProducto);
                    productos[indice].setCantidad(productos[indice].getCantidad() - cantidad);
                    Producto producto(&productos[indice]);
                    producto.setCantidad(cantidad);
                    usuario->agregarProducto(producto);
                    return "Compra realizada con exito";
                }
                else
                {
                    return "No tiene dinero suficiente";
                }
            }
            else
            {
                return "No hay suficiente cantidad de producto";
            }
        }
        else
        {
            return "No existe el producto";
        }
    }
    ~Empresa()
    {
    }
};