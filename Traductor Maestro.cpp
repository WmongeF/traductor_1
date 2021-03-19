#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#define s 150
using namespace std;
void gotoxy(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void cambiarcolor(int X)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), X);
}
void fondo()
{
    system("COLOR f3");
}

void co(int, int);
const char *nombe_archivo = "traduc7.dat";
const char *nom_temporal = "tempo8.dat";

struct Traducir
{

    char palabra[s];
    char traduccion[s];
    char funcionalidad[s];
    int codigo;
};
void eliminar33();

void ingresar_palabra();
void mostrar_palabra();
void control();
void modificar_palabra();
void comparar();

int main()
{
    control();
}

void control()
{
    int a, b, c;
    do
    {
        fondo();
        system("cls");
        co(0, 241);
        gotoxy(40, 5);
        cout << (" 1. Insertar  Datos");
        gotoxy(40, 6);
        cout << (" 2. Ver Datos");
        gotoxy(40, 7);
        cout << (" 3. Eliminar datos");
        gotoxy(40, 8);
        cout << (" 4. Usar traductor");
        gotoxy(40, 9);
        cout << (" 5. Modificar palabra");
        gotoxy(40, 10);
        cout << (" 6. Salir");
        gotoxy(40, 15);
        cout << ("Ingrese opcion: ");
        cin >> a;
        switch (a)
        {
        case 1:
            system("cls");
            ingresar_palabra();
            break;
        case 2:
            system("cls");
            mostrar_palabra();
            break;
        case 3:
            system("cls");
            eliminar33();
            break;
        case 4:
            system("cls");
            comparar();
            break;

        case 5:
            system("cls");
            modificar_palabra();
            break;
        }
    } while (a != 6);
}

void ingresar_palabra()
{
    char continuar;
    FILE *archivo = fopen(nombe_archivo, "ab"); // ab
    Traducir traductor;
    string palabra, traduccion, funcionalidad;
    do
    {
        system("cls");
        fflush(stdin);
        traductor.codigo = 0;
        traductor.codigo = traductor.codigo + 1;
        gotoxy(20, 5);
        cout << "Ingrese palabra: ";
        getline(cin, palabra);
        strcpy(traductor.palabra, palabra.c_str());

        gotoxy(20, 7);
        cout << "Ingrese traduccion: ";
        getline(cin, traduccion);
        strcpy(traductor.traduccion, traduccion.c_str());

        gotoxy(20, 9);
        cout << "Ingrese Funcionalidad: ";
        getline(cin, funcionalidad);
        strcpy(traductor.funcionalidad, funcionalidad.c_str());

        fwrite(&traductor, sizeof(Traducir), 1, archivo);

        gotoxy(20, 11);
        cout << "Desea Agregar otro Palabra s/n : ";
        cin >> continuar;
    } while ((continuar == 's') || (continuar == 'S'));
    fclose(archivo);
    system("cls");
}

void modificar_palabra()
{
    FILE *archivo = fopen(nombe_archivo, "r+b");
    int id;
    char respuesta[s];
    string palabras, traduccions, funcionalidads;
    Traducir traductor;

    cout << "Ingrese el ID que desea Modificar: ";
    cin >> id;
    fseek(archivo, id * sizeof(Traducir), SEEK_SET); // esto es lo que permite modificar en la pocision
    fread(&traductor, sizeof(Traducir), 1, archivo);

    gotoxy(25, 4);
    cout << ("------------   Datos Encontrados -------------");
    gotoxy(25, 7);
    cout << ("Palabra:  [") << traductor.palabra << ("]");
    gotoxy(25, 8);
    cout << ("Traduccion:  [") << traductor.traduccion << ("]");
    gotoxy(25, 9);
    cout << ("Funcionalidad:  [") << traductor.funcionalidad << ("]");
    gotoxy(25, 10);
    cout << ("---------------------------------------------");

    co(0,242); cout << "<\n\npalabra: " << traductor.palabra << endl;
    cout << ("Desea modificar la palabra [s/n]: ");
    cin >> respuesta, s;

    if (strcmp(respuesta, "s") == 0)
    {

        fseek(archivo, id * sizeof(Traducir), SEEK_SET);
        cin.ignore();
        cout << ("Nueva palabra : ");
        getline(cin, palabras);
        strcpy(traductor.palabra, palabras.c_str());
        fwrite(&traductor, sizeof(Traducir), 1, archivo);
    }

    co(0,242);cout << "\n\nTraduccion: " << traductor.traduccion << endl;
    cout << ("Desea modificar la traduccion [s/n]: ");
    cin >> respuesta, s;
    if (strcmp(respuesta, "s") == 0)
    {
        fseek(archivo, id * sizeof(Traducir), SEEK_SET);
        cin.ignore();
        cout << "Ingrese nueva traduccion: ";
        getline(cin, traduccions);
        strcpy(traductor.traduccion, traduccions.c_str());
        fwrite(&traductor, sizeof(Traducir), 1, archivo);
    }

    co(0,242);cout << "\n\nFuncionalidad: " << traductor.funcionalidad << endl;
    cout << ("Desea modificar la funcionalidad [s/n]: ");
    cin >> respuesta, s;
    if (strcmp(respuesta, "s") == 0)
    {
        fseek(archivo, id * sizeof(Traducir), SEEK_SET);
        cin.ignore();

        cout << "Ingrese nueva funcionalidad: ";
        getline(cin, funcionalidads);
        strcpy(traductor.funcionalidad, funcionalidads.c_str());
        fwrite(&traductor, sizeof(Traducir), 1, archivo);
    }
    gotoxy(20,25);cout << ("Datos actualizados!!");
    fclose(archivo);
    getch();
mostrar_palabra();
}

void mostrar_palabra()
{
    system("cls");
    FILE *archivo = fopen(nombe_archivo, "rb");
    if (!archivo)
    {
        archivo = fopen(nombe_archivo, "w+b");
    }

    Traducir traductor;
    int registro = 0;
    fread(&traductor, sizeof(Traducir), 1, archivo);
    cout << "____________________________________________________________________" << endl;
    cout << "id|"<< "  PALABRA\t|"<< "\tTRADUCCION\t |" << "FUNCIONALIDAD" << endl;

    do
    {

       // printf("\n%3d%25s\t%25s\t%8d\t%20s",guardado[i].codigo,guardado[i].nombre,guardado[i].apellido,guardado[i].telefono,guardado[i].correo);
        cout << "____________________________________________________________________" << endl;
        cout << registro << "|\t"<< traductor.palabra << "\t|\t" << traductor.traduccion << " \t\t|" << traductor.funcionalidad << endl;

        fread(&traductor, sizeof(Traducir), 1, archivo);
        registro += 1;

    } while (feof(archivo) == 0);

    cout << endl;

    fclose(archivo);
    getch();
}

void comparar()
{

    int error = 0;
    int comparacion;
    Traducir traductor;
    FILE *busqueda = fopen(nombe_archivo, "rb");
    char palabra[40]; //buscar dato
    gotoxy(20, 5);
    cout << "Buscar Palabra: ";
    cin >> palabra;

    while (!feof(busqueda))
    {
        fread(&traductor, sizeof(Traducir), 1, busqueda);

        comparacion = strcmp(palabra, traductor.palabra);

        if (comparacion == 0)
        {
            gotoxy(20, 8);
            cout << "Datos Encontrados";
            gotoxy(20, 12);
            cout << "palabra:  " << traductor.palabra;
            gotoxy(20, 13);
            cout << ("----------------------------------------------------------------");
            gotoxy(20, 15);
            cout << "Traduccion:  " << traductor.traduccion;
            gotoxy(20, 16);
            cout << ("----------------------------------------------------------------");
            gotoxy(20, 18);
            cout << "Funcionalidad:  " << traductor.funcionalidad;
            gotoxy(20, 19);
            cout << ("----------------------------------------------------------------");
            error = 1;
            break;
        }
    }

    if (error == 0)
    {
        cout << endl
            << "Error! Palabra no existe";
    }
    fclose(busqueda);
    getch();
}

void co(int x, int c)
{
    cambiarcolor(c);
    int i;
    for (i = 1; i <= x; i++)
    {
        cout << char(219) << char(219);
    }
}

void eliminar33()
{
    Traducir traductor;
    FILE *temporal = fopen(nom_temporal, "w+b");
    FILE *archivo = fopen(nombe_archivo, "r+b");
    int id;
    cout << "Ingrese el ID que desea eliminar: ";
    cin >> id;
    fseek(archivo, id * sizeof(Traducir), SEEK_SET);
    traductor.codigo = -1;
    fwrite(&traductor, sizeof(Traducir), 1, archivo);
    fclose(archivo);

    archivo = fopen(nombe_archivo, "r+b");

    fread(&traductor, sizeof(Traducir), 1, archivo);
    temporal = fopen(nom_temporal, "a+b");
    do
    {
        if (traductor.codigo == -1)
        {
            cout << "Dato eliminado";
        }
        if (traductor.codigo >= 0)
        {
            fwrite(&traductor, sizeof(Traducir), 1, temporal);
        }
        fread(&traductor, sizeof(Traducir), 1, archivo);
    } while (feof(archivo) == 0);
    fclose(temporal);
    fclose(archivo);

    archivo = fopen(nombe_archivo, "w");
    fclose(archivo);

    temporal = fopen(nom_temporal, "r+b");

    fread(&traductor, sizeof(Traducir), 1, temporal);
    archivo = fopen(nombe_archivo, "a+b");
    do
    {
        fwrite(&traductor, sizeof(Traducir), 1, archivo);
        fread(&traductor, sizeof(Traducir), 1, temporal);
    } while (feof(temporal) == 0);
    fclose(archivo);
    fclose(temporal);

    temporal = fopen(nom_temporal, "w");
    fclose(temporal);

    mostrar_palabra();
}
