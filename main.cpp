//Iván Alberto Romero Wells A00833623
//Ariadna Daniela Medina Gracia A01748822
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

    cout << "Bienvenido al sistema Gubernamental de administracion de la empresa" << endl;
    int opcion;
    while (true)
    {
        cout << "Menu de opciones" << endl;
        cout << "1. Crear usuario" << endl;
        cout << "2. Crear empresa" << endl;
        cout << "3. Crear producto" << endl;
        cout << "4. Ver usuarios" << endl;
        cout << "5. Ver empresas" << endl;
        cout << "6. Ver productos" << endl;
        cout << "7. Comprar producto" << endl;
        cout << "8. Ver Saldo" << endl;
        cout << "9. Ver Inventario" << endl;
        cout << "10. Guardar" << endl;
        cout << "11. Cargar" << endl;
        cout << "12. Salir" << endl;

        cout << "Ingrese una opcion: ";
        cin >> opcion;
        system("cls");
        string nombre, nombreEmpresa, nombreProducto, descripcion, compra;
        Arreglo<Producto> productos;
        Arreglo<Usuario> usuarios;
        Arreglo<Empresa> empresas;
        Usuario usuario;
        int saldo, cantidad, precio;
        switch (opcion)
        {
        case 1:
            // crear usuario
            cout << "Crear usuario" << endl;
            cout << "Ingrese el nombre del usuario: ";
            cin >> nombre;
            cout << "Ingrese el saldo del usuario: ";
            cin >> saldo;
            gobierno.agregarUsuario(nombre, saldo);
            break;
        case 2:
            // crear empresa
            cout << "Crear empresa" << endl;
            cout << "Ingrese el nombre de la empresa: ";
            cin >> nombreEmpresa;
            gobierno.agregarEmpresa(nombreEmpresa);
            break;
        case 3:
            // crear producto
            cout << "Crear producto" << endl;
            cout << "Ingrese el nombre de la empresa: ";
            cin >> nombreEmpresa;
            cout << "Ingrese el nombre del producto: ";
            cin >> nombreProducto;
            cout << "Ingrese la descripcion del producto: ";
            cin >> descripcion;
            cout << "Ingrese el precio del producto: ";
            cin >> precio;
            cout << "Ingrese la cantidad del producto: ";
            cin >> cantidad;
            gobierno.agregarProducto(nombreEmpresa, nombreProducto, descripcion, precio, cantidad);
            break;
        case 4:
            // ver usuarios
            cout << "Ver usuarios" << endl;
            usuarios = gobierno.listarUsuarios();
            for (int i = 0; i < usuarios.obtenerTamano(); i++)
            {
                cout << usuarios[i].getNombre() << endl;
            }
            break;
        case 5:
            // ver empresas
            cout << "Ver empresas" << endl;
            empresas = gobierno.listarEmpresas();

            for (int i = 0; i < empresas.obtenerTamano(); i++)
            {
                cout << empresas[i].getNombreEmpresa() << endl;
            }
            break;
        case 6:
            // ver productos
            cout << "Ver productos empresa" << endl;
            cout << "Ingrese el nombre de la empresa: ";
            cin >> nombreEmpresa;
            productos = gobierno.listarProductos(nombreEmpresa);
            for (int i = 0; i < productos.obtenerTamano(); i++)
            {
                cout << productos[i].getNombre() << endl;
            }
            break;
        case 7:
            // comprar producto
            cout << "Comprar producto" << endl;
            cout << "Ingrese el nombre de la empresa: ";
            cin >> nombreEmpresa;
            cout << "Ingrese el nombre del usuario: ";
            cin >> nombre;
            cout << "Ingrese el nombre del producto: ";
            cin >> nombreProducto;
            cout << "Ingrese la cantidad del producto: ";
            cin >> cantidad;
            compra = gobierno.Compra(nombre, nombreEmpresa, nombreProducto, cantidad);
            cout << compra << endl;
            break;
        case 8:
            // ver saldo
            cout << "Ver saldo" << endl;
            cout << "Ingrese el nombre del usuario: ";
            cin >> nombre;
            usuario = gobierno.getUsuario(nombre);
            cout << "El saldo del usuario es: " << usuario.getDinero() << endl;
            break;
        case 9:
            cout << "Ver inventario" << endl;
            cout << "Ingrese el nombre del usuario: ";
            cin >> nombre;
            usuario = gobierno.getUsuario(nombre);
            cout << "El inventario del usuario es: " << endl;
            for (int i = 0; i < usuario.getCarrito().obtenerTamano(); i++)
            {
                cout << usuario.getCarrito()[i].getNombre() << endl;
            }
            break;
        case 10:
            // guardar
            cout << "Guardar" << endl;
            gobierno.guardar();
            break;
        case 11:
            // cargar
            cout << "Cargar" << endl;
            gobierno.cargar();
            break;
        case 12:
            // salir
            cout << "Salir" << endl;
            return 0;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    }
}