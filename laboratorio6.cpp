#include <iostream>
#include <string>
using namespace std;

struct Direccion {
    string calle;
    string numero;
    string ciudad;
};

struct Estudiante {
    string nombre;
    int edad;
    float calificaciones[5];
    Direccion direccion;
};

void ingresarEstudiantes(Estudiante *estudiantes, int &cantidad);
void mostrarEstudiantes(Estudiante *estudiantes, int cantidad);
void buscarEstudiante(Estudiante *estudiantes, int cantidad);
void modificarEstudiante(Estudiante *estudiantes, int cantidad);

int main() {
    const int MAX = 100;
    Estudiante estudiantes[MAX];
    int cantidad = 0;
    int opcion;

    do {
        cout << endl << "   GESTION DE ESTUDIANTES   " << endl;
        cout << "1. Ingresar estudiantes" << endl;
        cout << "2. Mostrar estudiantes" << endl;
        cout << "3. Buscar estudiante" << endl;
        cout << "4. Modificar estudiante" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                ingresarEstudiantes(estudiantes, cantidad);
                break;
            case 2:
                mostrarEstudiantes(estudiantes, cantidad);
                break;
            case 3:
                buscarEstudiante(estudiantes, cantidad);
                break;
            case 4:
                modificarEstudiante(estudiantes, cantidad);
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
        }
    } while (opcion != 5);

    return 0;
}


void ingresarEstudiantes(Estudiante *estudiantes, int &cantidad) {
    cout << endl << "Ingrese el nombre del estudiante : ";
    cin >> estudiantes[cantidad].nombre;
    cout << "Edad: ";
    cin >> estudiantes[cantidad].edad;

    cout << "Ingrese 5 calificaciones:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Nota " << i + 1 << ": ";
        cin >> estudiantes[cantidad].calificaciones[i];
    }

    cout << "Direccion - Calle : ";
    cin >> estudiantes[cantidad].direccion.calle;
    cout << "Numero: ";
    cin >> estudiantes[cantidad].direccion.numero;
    cout << "Ciudad : ";
    cin >> estudiantes[cantidad].direccion.ciudad;

    cantidad++;
    cout << "Estudiante agregado correctamente." << endl;
}

void mostrarEstudiantes(Estudiante *estudiantes, int cantidad) {
    if (cantidad == 0) {
        cout << "No hay estudiantes registrados." << endl;
        return;
    }

    cout << endl << "    LISTA DE ESTUDIANTES    " << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << endl << "Estudiante " << i + 1 << ":" << endl;
        cout << "Nombre: " << estudiantes[i].nombre << endl;
        cout << "Edad: " << estudiantes[i].edad << endl;
        cout << "Calificaciones: ";
        for (int j = 0; j < 5; j++) {
            cout << estudiantes[i].calificaciones[j] << " ";
        }
        cout << endl;
        cout << "Direccion: " << estudiantes[i].direccion.calle << " #"
             << estudiantes[i].direccion.numero << ", "
             << estudiantes[i].direccion.ciudad << endl;
    }
}

void buscarEstudiante(Estudiante *estudiantes, int cantidad) {
    string nombreBuscado;
    cout << endl << "Ingrese el nombre del estudiante a buscar: ";
    cin >> nombreBuscado;

    for (int i = 0; i < cantidad; i++) {
        if (estudiantes[i].nombre == nombreBuscado) {
            cout << endl << "Estudiante encontrado:" << endl;
            cout << "Nombre: " << estudiantes[i].nombre << endl;
            cout << "Edad: " << estudiantes[i].edad << endl;
            cout << "Direccion: " << estudiantes[i].direccion.calle << " #"
                 << estudiantes[i].direccion.numero << ", "
                 << estudiantes[i].direccion.ciudad << endl;
            return;
        }
    }
    cout << "No se encontro ningun estudiante con ese nombre." << endl;
}

void modificarEstudiante(Estudiante *estudiantes, int cantidad) {
    string nombreBuscado;
    cout << endl << "Ingrese el nombre del estudiante a modificar: ";
    cin >> nombreBuscado;

    for (int i = 0; i < cantidad; i++) {
        if (estudiantes[i].nombre == nombreBuscado) {
            cout << "Nuevo nombre (una sola palabra): ";
            cin >> estudiantes[i].nombre;
            cout << "Nueva edad: ";
            cin >> estudiantes[i].edad;

            cout << "Nuevas 5 calificaciones:" << endl;
            for (int j = 0; j < 5; j++) {
                cout << "Nota " << j + 1 << ": ";
                cin >> estudiantes[i].calificaciones[j];
            }

            cout << "Nueva direccion - Calle: ";
            cin >> estudiantes[i].direccion.calle;
            cout << "Numero: ";
            cin >> estudiantes[i].direccion.numero;
            cout << "Ciudad: ";
            cin >> estudiantes[i].direccion.ciudad;

            cout << "Datos actualizados correctamente." << endl;
            return;
        }
    }
    cout << "No se encontro ningun estudiante con ese nombre." << endl;
}