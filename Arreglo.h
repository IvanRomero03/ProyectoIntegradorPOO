#pragma once
//Iván Alberto Romero Wells A00833623
//Ariadna Daniela Medina García A01748822
//  Documentacion en: https://github.com/IvanRomero03/MemoriaDinamica.git
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Arreglo
{
private:
    T *arreglo;
    int tamano;
    int capacidad;
    void redimensionar(int nuevaCapacidad)
    {
        T *nuevoArreglo = new T[nuevaCapacidad];
        for (int i = 0; i < tamano; i++)
        {
            nuevoArreglo[i] = arreglo[i];
        }
        delete[] arreglo;
        arreglo = nuevoArreglo;
        capacidad = nuevaCapacidad;
    }

public:
    Arreglo()
    {
        this->capacidad = 4;
        this->arreglo = new T[capacidad];
        this->tamano = 0;
    }
    Arreglo(const Arreglo<T> &otro)
    {
        this->capacidad = otro.capacidad;
        this->tamano = otro.tamano;
        this->arreglo = new T[capacidad];
        for (int i = 0; i < tamano; i++)
        {
            this->arreglo[i] = otro.arreglo[i];
        }
    }
    void agregar(T elemento)
    {
        if (tamano == capacidad)
        {
            redimensionar(capacidad * 2);
        }
        this->arreglo[tamano] = elemento;
        this->tamano++;
    }
    T consultar(int posicion)
    {
        if (posicion < 0 || posicion >= tamano)
        {
            throw "Posicion invalida";
        }
        return arreglo[posicion];
    }
    void eliminar(int posicion)
    {
        if (posicion < 0 || posicion >= tamano)
        {
            return;
        }
        for (int i = posicion; i < tamano - 1; i++)
        {
            arreglo[i] = arreglo[i + 1];
        }
        tamano--;
    }
    int obtenerTamano()
    {
        return tamano;
    }
    int obtenerCapacidad()
    {
        return capacidad;
    }
    void modificar(int posicion, T elemento)
    {
        if (posicion < 0 || posicion >= tamano)
        {
            return;
        }
        arreglo[posicion] = elemento;
    }
    T &operator[](int posicion)
    {
        if (posicion < 0 || posicion >= tamano)
        {
            throw "Posicion invalida";
        }
        return arreglo[posicion];
    }
    bool operator==(Arreglo<T> &otroArreglo)
    {
        if (this->tamano != otroArreglo.obtenerTamano())
        {
            return false;
        }
        for (int i = 0; i < tamano; i++)
        {
            if (this->arreglo[i] != otroArreglo[i])
            {
                return false;
            }
        }
        return true;
    }
    bool operator!=(Arreglo<T> &otroArreglo)
    {
        return !(*this == otroArreglo);
    }
    void operator=(Arreglo<T> *otroArreglo)
    {
        this->tamano = (*otroArreglo).obtenerTamano();
        this->capacidad = (*otroArreglo).obtenerCapacidad();
        this->arreglo = new T[capacidad];
        for (int i = 0; i < tamano; i++)
        {
            this->arreglo[i] = (*otroArreglo)[i];
        }
    }
    ~Arreglo()
    {
        delete[] arreglo;
    }
};
