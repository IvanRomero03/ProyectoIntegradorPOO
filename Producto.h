#pragma once
//Iván Alberto Romero Wells A00833623
//Ariadna Daniela Medina García A01748822
#include <bits/stdc++.h>

using namespace std;

class Producto
{
private:
    string nombre;
    string descripcion;
    int precio;
    int cantidad;

public:
    Producto()
    {
        nombre = "";
        descripcion = "";
        precio = 0;
        cantidad = 0;
    }
    Producto(string nombre, string descripcion, int precio, int cantidad)
    {
        this->nombre = nombre;
        this->descripcion = descripcion;
        this->precio = precio;
        this->cantidad = cantidad;
    }
    Producto(Producto *p)
    {
        nombre = (*p).getNombre();
        descripcion = (*p).getDescripcion();
        precio = (*p).getPrecio();
        cantidad = (*p).getCantidad();
    }
    string getNombre()
    {
        return nombre;
    }
    string getDescripcion()
    {
        return descripcion;
    }
    int getPrecio()
    {
        return precio;
    }
    void setNombre(string nombre)
    {
        this->nombre = nombre;
    }
    void setDescripcion(string descripcion)
    {
        this->descripcion = descripcion;
    }
    void setPrecio(int precio)
    {
        this->precio = precio;
    }
    void setCantidad(int cantidad)
    {
        this->cantidad = cantidad;
    }
    int getCantidad()
    {
        return cantidad;
    }
    ~Producto()
    {
    }
};