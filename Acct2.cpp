#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//inciializadores de las variables para las dimensiones los arreglos
const int FILAS = 5;
const int COLUMNAS = 5;


// Estructura para representar la posición del agente y su percepción
struct Posicion 
{
    int fila;
    int col;
    int puntuacion = 0;
    int movimientos = 0;
    int MAX_PASOS = 20;
    int Posicion_actual;
};

struct Percepcion 
{
    string celdaActual;
    string arriba;
    string abajo;
    string izquierda;
    string derecha;
};

// Función para obtener el tipo de celda
string tipoCelda(char c)
{
    if (c == '.') return "Vacia";
    if (c == 'X') return "Obstaculo";
    if (c == 'P') return "Paquete";
    return "Desconocido";
}


//Su función será obtener la información disponible
//mediante los sensores. QUE VEO 
void percibir(const vector<vector<char>>& entorno, Percepcion& p, const Posicion& agente)
{
p.celdaActual = tipoCelda(entorno[agente.fila][agente.col]);
p.arriba = tipoCelda(entorno[agente.fila - 1][agente.col]);
p.abajo = tipoCelda(entorno[agente.fila + 1][agente.col]);
p.izquierda = tipoCelda(entorno[agente.fila][agente.col -1]);
p.derecha = tipoCelda(entorno[agente.fila][agente.col + 1]);
}

//Esta función representará la lógica que utiliza el agente
//para seleccionar una acción. A DONDE PUEDO IR 
//string decidir (const vector<vector<char>> const Percepcion& p )
//{
  //  if (p.arriba == "Paquete") return "arriba";
    //else if (p.abajo == "Paquete") return "abajo";
    //else if (p.izquierda == "Paquete") return "izquierda";
    //else if (p.derecha == "Paquete") return "derecha";

   // vector<string> seguras;
//if (p.arriba == "Vacia") seguras.push_back("arriba");
//if (p.abajo == "Vacia") seguras.push_back("abajo");
//if (p.izquierda == "Vacia") seguras.push_back("izquierda");
//if (p.derecha == "Vacia") seguras.push_back("derecha");   

//if (seguras.empty()) return "NINGUNA, ACABO.";

//return seguras[rand() % seguras.size()];
//}

//Será responsable de modificar el entorno o la posición del
//agente. ME MUEVO Y ACTUALIZO EL MUNDO
void Actuar (vector<vector<char>>& mundo, Posicion& agente, const string& direccion, int& puntuacion, int& paquetesDisponibles )
{
if (direccion == "arriba") agente.fila --;
else if (direccion == "abajo") agente.fila ++;
else if (direccion == "izquierda")agente.col --;
else if (direccion == "derecha") agente.col ++;
else return;
   agente.movimientos ++;
   if
    (mundo[agente.fila][agente.col] == 'P') 
    {
        puntuacion ++;
        paquetesDisponibles --;
        mundo[agente.fila][agente.col] = '.';
    }
}

    //Confirmacion de paquetes activos
bool hayPaquetes(const vector<vector<char>>& entorno) 
{
    for (int i = 0; i < FILAS; i++) 
    {
        for (int j = 0; j < COLUMNAS; j++) 
        {
            if (entorno[i][j] == 'P') return true;
        }
    }
    return false;
}

// Mostrar el entorno y la posición del agente
void mostrarEntorno(const vector<vector<char>>& entorno, const Posicion& agente) 
{
    cout << "\n";
    for (int i = 0; i < FILAS; i++) 
    {
        for (int j = 0; j < COLUMNAS; j++) 
        {
            if (agente.fila == i && agente.col == j) 
            {
                cout << "A ";
            } else 
            {
                cout << entorno[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() 
{
srand(time(0));
    //CREACION DEL ARREGLO
    vector<vector<char>> entorno = 
    {
        {'.', '.', '.', 'P', '.'},
        {'.', 'X', '.', '.', '.'},
        {'.', '.', '.', 'X', 'P'},
        {'.', '.', 'P', '.', '.'},
        {'.', 'X', '.', '.', '.'}
    };

    Posicion agente = {2, 0};


    ///INICIO SEGUIR 
//while ( hayPaquetes(entorno) && movimientos < MAX_PASOS) 
//{
  //  Percepcion p;
   // percibir(entorno, p, agente);

    //percibir(entorno, p, agente);

//string accion = decidir( entorno, p, agente);

//Actuar(entorno, agente, accion, puntuacion, paquetesDisponibles);

//mostrar = mostrarEntorno(entorno, agente);



//}

    return 0;
}