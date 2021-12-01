#pragma once
//Iván Alberto Romero Wells A00833623
//Ariadna Daniela Medina García A01748822
#include <bits/stdc++.h>
#include "Producto.h"
#include "Arreglo.h"

using namespace std;

class Usuario
{
private:
    string nombre;
    int dinero;
    Arreglo<Producto> carrito;

public:
    Usuario()
    {
        nombre = "";
        dinero = 0;
    }
    Usuario(string nombre, int dinero)
    {
        this->nombre = nombre;
        this->dinero = dinero;
    }
    string getNombre()
    {
        return nombre;
    }
    int getDinero()
    {
        return dinero;
    }
    void setDinero(int dinero)
    {
        this->dinero = dinero;
    }
    void agregarProducto(Producto producto)
    {
        carrito.agregar(producto);
    }
    Arreglo<Producto> getCarrito()
    {
        return carrito;
    }
    ~Usuario()
    {
    }
};