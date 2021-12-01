#pragma once
//Iván Alberto Romero Wells A00833623
//Ariadna Daniela Medina García A01748822
#include <bits/stdc++.h>
#include "Empresa.h"
#include "Usuarios.h"
#include "Producto.h"
#include "Arreglo.h"
#include <fstream>

using namespace std;

class Gobierno
{
private:
    Arreglo<Usuario> usuarios;
    Arreglo<Empresa> empresas;

public:
    Gobierno()
    {
    }
    Gobierno(Arreglo<Usuario> usuarios, Arreglo<Empresa> empresas)
    {
        this->usuarios = usuarios;
        this->empresas = empresas;
    }
    void agregarUsuario(string nombre, int dinero)
    {
        Usuario usuario = Usuario(nombre, dinero);
        this->usuarios.agregar(usuario);
    }
    void agregarEmpresa(string nombre)
    {
        Empresa empresa = Empresa(nombre);
        this->empresas.agregar(empresa);
    }
    int buscarUsuario(string nombre)
    {
        int indice = -1;
        for (int i = 0; i < usuarios.obtenerTamano(); i++)
        {
            if (usuarios[i].getNombre() == nombre)
            {
                indice = i;
                break;
            }
        }
        return indice;
    }
    int buscarEmpresa(string nombre)
    {
        int indice = -1;
        for (int i = 0; i < empresas.obtenerTamano(); i++)
        {
            if (empresas[i].getNombreEmpresa() == nombre)
            {
                indice = i;
                break;
            }
        }
        return indice;
    }
    void eliminarUsuario(string nombre)
    {
        int indice = buscarUsuario(nombre);
        if (indice != -1)
        {
            usuarios.eliminar(indice);
        }
    }
    void eliminarEmpresa(string nombre)
    {
        int indice = buscarEmpresa(nombre);
        if (indice != -1)
        {
            empresas.eliminar(indice);
        }
    }
    void modificarUsuario(string nombre, Usuario usuario)
    {
        int indice = buscarUsuario(nombre);
        if (indice != -1)
        {
            usuarios[indice] = usuario;
        }
    }
    void modificarEmpresa(string nombre, Empresa empresa)
    {
        int indice = buscarEmpresa(nombre);
        if (indice != -1)
        {
            empresas[indice] = empresa;
        }
    }
    void agregarProducto(string nombreEmpresa, string nombreProducto, string descripcion, int precio, int cantidad)
    {
        //Producto producto(nombreProducto, descripcion, precio, cantidad);
        int indice = buscarEmpresa(nombreEmpresa);
        cout << "indice " << nombreEmpresa << ": " << indice << endl;
        if (indice != -1)
        {
            Producto producto(nombreProducto, descripcion, precio, cantidad);
            cout << "producto: " << producto.getNombre() << endl;
            empresas[indice].agregarProducto(producto);
            cout << "producto agregado" << endl;
            cout << "Empresa: " << empresas[indice].getNombreEmpresa() << endl;
            Arreglo<Producto> pasrsa = empresas[indice].getProductos();
            cout << "producto: " << pasrsa[indice].getNombre() << endl;
        }
    }
    void eliminarProducto(string nombreEmpresa, string nombreProducto)
    {
        int indice = buscarEmpresa(nombreEmpresa);
        if (indice != -1)
        {
            empresas[indice].eliminarProducto(nombreProducto);
        }
    }
    void modificarProducto(string nombreEmpresa, string nombreProducto, Producto producto)
    {
        int indice = buscarEmpresa(nombreEmpresa);
        if (indice != -1)
        {
            empresas[indice].modificarProducto(nombreProducto, producto);
        }
    }
    string Compra(string nombreUsuario, string nombreEmpresa, string nombreProducto, int cantidad)
    {
        int indiceUsuario = buscarUsuario(nombreUsuario);
        int indiceEmpresa = buscarEmpresa(nombreEmpresa);
        if (indiceUsuario != -1 && indiceEmpresa != -1)
            return empresas[indiceEmpresa].comprarProducto(&usuarios[indiceUsuario], nombreProducto, cantidad);
        else
            return "No se encontraron los datos";
    }
    Arreglo<Producto> *listarProductos(string nombreEmpresa)
    {
        int indice = buscarEmpresa(nombreEmpresa);
        if (indice != -1)
        {
            return empresas[indice].punteroProductos();
        }
        return NULL;
    }
    Arreglo<Empresa> *listarEmpresas()
    {
        return &empresas;
    }
    Arreglo<Usuario> *listarUsuarios()
    {
        return &usuarios;
    }
    void guardar()
    {
        ofstream archivo;
        archivo.open("Gobierno.txt");
        archivo << usuarios.obtenerTamano() << endl;
        for (int i = 0; i < usuarios.obtenerTamano(); i++)
        {
            archivo << usuarios[i].getNombre() << endl;
            archivo << usuarios[i].getDinero() << endl;
            archivo << usuarios[i].getCarrito().obtenerTamano() << endl;
            for (int j = 0; j < usuarios[i].getCarrito().obtenerTamano(); j++)
            {
                archivo << usuarios[i].getCarrito()[j].getNombre() << endl;
                archivo << usuarios[i].getCarrito()[j].getDescripcion() << endl;
                archivo << usuarios[i].getCarrito()[j].getPrecio() << endl;
                archivo << usuarios[i].getCarrito()[j].getCantidad() << endl;
            }
        }
        archivo << empresas.obtenerTamano() << endl;
        for (int i = 0; i < empresas.obtenerTamano(); i++)
        {
            archivo << empresas[i].getNombreEmpresa() << endl;
            archivo << empresas[i].getProductos().obtenerTamano() << endl;
            for (int j = 0; j < empresas[i].getProductos().obtenerTamano(); j++)
            {
                archivo << empresas[i].getProductos()[j].getNombre() << endl;
                archivo << empresas[i].getProductos()[j].getPrecio() << endl;
                archivo << empresas[i].getProductos()[j].getCantidad() << endl;
            }
        }
        archivo.close();
    }
    Gobierno(ifstream &archivo)
    {
        int tamanoUsuarios;
        archivo >> tamanoUsuarios;
        for (int i = 0; i < tamanoUsuarios; i++)
        {
            string nombre;
            int dinero;
            archivo >> nombre;
            archivo >> dinero;
            Usuario usuario(nombre, dinero);
            int tamanoCarrito;
            archivo >> tamanoCarrito;
            for (int j = 0; j < tamanoCarrito; j++)
            {
                string nombreProducto;
                string descripcion;
                int precio;
                int cantidad;
                archivo >> nombreProducto;
                archivo >> descripcion;
                archivo >> precio;
                archivo >> cantidad;
                Producto producto(nombreProducto, descripcion, precio, cantidad);
                usuario.agregarProducto(producto);
            }
            usuarios.agregar(usuario);
        }
        int tamanoEmpresas;
        archivo >> tamanoEmpresas;
        for (int i = 0; i < tamanoEmpresas; i++)
        {
            string nombreEmpresa;
            archivo >> nombreEmpresa;
            int tamanoProductos;
            archivo >> tamanoProductos;
            for (int j = 0; j < tamanoProductos; j++)
            {
                string nombreProducto;
                string descripcion;
                int precio;
                int cantidad;
                archivo >> nombreProducto;
                archivo >> descripcion;
                archivo >> precio;
                archivo >> cantidad;
                Producto producto(nombreProducto, descripcion, precio, cantidad);
                empresas[i].agregarProducto(producto);
            }
        }
        archivo.close();
    }
    Usuario *getUsuario(string nombre)
    {
        int indice = buscarUsuario(nombre);
        if (indice != -1)
        {
            return &usuarios[indice];
        }
        return NULL;
    }
    Empresa *getEmpresa(string nombre)
    {
        int indice = buscarEmpresa(nombre);
        if (indice != -1)
        {
            return &empresas[indice];
        }
        return NULL;
    }
    void cargar()
    {
        ifstream archivo;
        archivo.open("Gobierno.txt");
        if (archivo.is_open())
        {
            int tamanoUsuarios;
            archivo >> tamanoUsuarios;
            for (int i = 0; i < tamanoUsuarios; i++)
            {
                string nombre;
                int dinero;
                archivo >> nombre;
                archivo >> dinero;
                Usuario usuario(nombre, dinero);
                int tamanoCarrito;
                archivo >> tamanoCarrito;
                for (int j = 0; j < tamanoCarrito; j++)
                {
                    string nombreProducto;
                    string descripcion;
                    int precio;
                    int cantidad;
                    archivo >> nombreProducto;
                    archivo >> descripcion;
                    archivo >> precio;
                    archivo >> cantidad;
                    Producto producto(nombreProducto, descripcion, precio, cantidad);
                    usuario.agregarProducto(producto);
                }
                usuarios.agregar(usuario);
            }
            int tamanoEmpresas;
            archivo >> tamanoEmpresas;
            for (int i = 0; i < tamanoEmpresas; i++)
            {
                string nombreEmpresa;
                archivo >> nombreEmpresa;
                int tamanoProductos;
                archivo >> tamanoProductos;
                for (int j = 0; j < tamanoProductos; j++)
                {
                    string nombreProducto;
                    string descripcion;
                    int precio;
                    int cantidad;
                    archivo >> nombreProducto;
                    archivo >> descripcion;
                    archivo >> precio;
                    archivo >> cantidad;
                    Producto producto(nombreProducto, descripcion, precio, cantidad);
                    empresas[i].agregarProducto(producto);
                }
            }
        }
    }
    ~Gobierno()
    {
    }
};