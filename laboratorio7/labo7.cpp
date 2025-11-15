#include <iostream>
#include <fstream>
using namespace std;

int leerArchivo(int numeros[]);
void clasificarNumeros(int numeros[], int n);
void ordenarArchivo(const char nombre[]);
void mostrarArchivo(const char nombre[]);

int main() {
    int opcion;
    int numeros[200];  
    int n = 0;

    do {
        cout << "\n==== MENU ====\n";
        cout << "1. Clasificar numeros (pares/impares)\n";
        cout << "2. Ordenar archivos (pares.txt e impares.txt)\n";
        cout << "3. Ver resultados\n";
        cout << "4. Salir\n";
        cout << "Ingrese opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                n = leerArchivo(numeros);
                clasificarNumeros(numeros, n);
                cout << "Numeros clasificados correctamente.\n";
                break;

            case 2:
                ordenarArchivo("pares.txt");
                ordenarArchivo("impares.txt");
                cout << "Archivos ordenados.\n";
                break;

            case 3:
                cout << "\n--- Archivo pares.txt ---\n";
                mostrarArchivo("pares.txt");
                cout << "\n--- Archivo impares.txt ---\n";
                mostrarArchivo("impares.txt");
                break;

            case 4:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 4);

    return 0;
}

int leerArchivo(int numeros[]) {
    ifstream archivo("datos.txt");
    int num, i = 0;

    if (!archivo) {
        cout << "No se pudo abrir datos.txt\n";
        return 0;
    }

    while (archivo >> num) {
        numeros[i] = num;
        i++;
    }

    archivo.close();
    return i; 
}


void clasificarNumeros(int numeros[], int n) {
    ofstream pares("pares.txt");
    ofstream impares("impares.txt");

    for (int i = 0; i < n; i++) {
        if (numeros[i] % 2 == 0)
            pares << numeros[i] << endl;
        else
            impares << numeros[i] << endl;
    }

    pares.close();
    impares.close();
}


void ordenarArchivo(const char nombre[]) {
    ifstream archivo(nombre);
    int arr[200], n = 0;

    if (!archivo) return;

    while (archivo >> arr[n]) n++;
    archivo.close();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }

    ofstream salida(nombre);
    for (int i = 0; i < n; i++)
        salida << arr[i] << endl;

    salida.close();
}


void mostrarArchivo(const char nombre[]) {
    ifstream archivo(nombre);
    int num;

    if (!archivo) {
        cout << "No se pudo abrir " << nombre << endl;
        return;
    }

    while (archivo >> num)
        cout << num << " ";

    cout << endl;
    archivo.close();
}