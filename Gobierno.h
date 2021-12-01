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
        if (indice != -1)
        {
            Producto producto(nombreProducto, descripcion, precio, cantidad);
            empresas[indice].agregarProducto(producto);
            Arreglo<Producto> pasrsa = empresas[indice].getProductos();
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
    Arreglo<Producto> listarProductos(string nombreEmpresa)
    {
        int indice = buscarEmpresa(nombreEmpresa);
        if (indice != -1)
        {
            return empresas[indice].getProductos();
        }
        Arreglo<Producto> vacio;
        return vacio;
    }
    Arreglo<Empresa> listarEmpresas()
    {
        return empresas;
    }
    Arreglo<Usuario> listarUsuarios()
    {
        return usuarios;
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
                archivo << empresas[i].getProductos()[j].getDescripcion() << endl;
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
    Usuario getUsuario(string nombre)
    {
        int indice = buscarUsuario(nombre);
        if (indice != -1)
        {
            return usuarios[indice];
        }
        Usuario vacio;
        return vacio;
    }
    Empresa getEmpresa(string nombre)
    {
        int indice = buscarEmpresa(nombre);
        if (indice != -1)
        {
            return empresas[indice];
        }
        Empresa vacio;
        return vacio;
    }
    void cargar()
    {
        ifstream archivo;
        archivo.open("Gobierno.txt");
        if (archivo.is_open())
        {
            cout << "Archivo abierto" << endl;
            int tamanoUsuarios;
            archivo >> tamanoUsuarios;
            cout << "Usuarios: " << tamanoUsuarios << endl;
            string nombre, nombreProducto, descripcion;
            int dinero, precio, cantidad, tamanoCarrito;
            Usuario usuario;
            Producto producto;
            for (int i = 0; i < tamanoUsuarios; i++)
            {
                archivo >> nombre;
                archivo >> dinero;
                cout << "Usuario: " << nombre << endl;
                cout << "Dinero: " << dinero << endl;
                usuario = Usuario(nombre, dinero);
                cout << "Carrito: " << endl;
                archivo >> tamanoCarrito;
                cout << "Cantidad de productos: " << tamanoCarrito << endl;
                for (int j = 0; j < tamanoCarrito; j++)
                {
                    archivo >> nombreProducto;
                    archivo >> descripcion;
                    archivo >> precio;
                    archivo >> cantidad;
                    cout << "Producto: " << nombreProducto << endl;
                    cout << "Descripcion: " << descripcion << endl;
                    cout << "Precio: " << precio << endl;
                    cout << "Cantidad: " << cantidad << endl;

                    producto = Producto(nombreProducto, descripcion, precio, cantidad);
                    cout << "Producto agregado" << endl;
                    usuario.agregarProducto(producto);
                    cout << "Producto agregado al carrito" << endl;
                }
                usuarios.agregar(usuario);
                cout << "Usuario agregado" << endl;
            }
            cout << "Usuarios cargados" << endl;
            int tamanoEmpresas, tamanoProductos;
            archivo >> tamanoEmpresas;
            cout << "Empresas: " << tamanoEmpresas << endl;
            string nombreEmpresa;
            Empresa empresa;
            for (int i = 0; i < tamanoEmpresas; i++)
            {
                archivo >> nombreEmpresa;
                archivo >> tamanoProductos;
                cout << "Empresa: " << nombreEmpresa << endl;
                cout << "Cantidad de productos: " << tamanoProductos << endl;
                empresa = Empresa(nombreEmpresa);
                for (int j = 0; j < tamanoProductos; j++)
                {
                    archivo >> nombreProducto;
                    archivo >> descripcion;
                    archivo >> precio;
                    archivo >> cantidad;
                    cout << "Producto: " << nombreProducto << endl;
                    cout << "Descripcion: " << descripcion << endl;
                    cout << "Precio: " << precio << endl;
                    cout << "Cantidad: " << cantidad << endl;
                    //producto = Producto(nombreProducto, descripcion, precio, cantidad);
                    cout << "Producto agregado" << endl;
                    //Verificar si el producto se guardo bien
                    /*cout << "nom: " << producto.getNombre() << endl;
                    cout << "des: " << producto.getDescripcion() << endl;
                    cout << "pre: " << producto.getPrecio() << endl;
                    cout << "can: " << producto.getCantidad() << endl;*/
                    empresa.agregarProducto(Producto(nombreProducto, descripcion, precio, cantidad));
                    cout << "Producto agregado a la empresa" << endl;
                }
                empresas.agregar(empresa);
            }
        }
        archivo.close();
    }
    ~Gobierno()
    {
    }
};