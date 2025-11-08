#include <iostream> 
using namespace std;

int main() {
    int contrasena = 1234;
    int x, attempts = 0;
    int operacion; 
    
    do {
        attempts++;
        cout << "Ingrese su contrasena de 4 digitos: " << endl;
        cin >> x;

        if (x == contrasena) {
            cout << "Bienvenido al sistema" << endl;
            cout << "Seleccione la operacion que desea realizar: " << endl;
            cout << "1. Sumar 2 numeros" << endl;
            cout << "2. Restar 2 numeros" << endl;
            cout << "3. Multiplicar 2 numeros" << endl;
            cout << "4. Dividir 2 numeros" << endl;
            cout << "5. Salir" << endl;
            cin >> operacion;

            if (operacion == 1) {
                int a, b;
                cout << "Ingrese el primer numero: " << endl;
                cin >> a;
                cout << "Ingrese el segundo numero: " << endl;
                cin >> b;
                cout << "El resultado de la suma es: " << a + b << endl;
            }
            else if (operacion == 2) {
                int a, b;
                cout << "Ingrese el primer numero: " << endl;
                cin >> a;
                cout << "Ingrese el segundo numero: " << endl;
                cin >> b;
                cout << "El resultado de la resta es: " << a - b << endl;
            }
            else if (operacion == 3) {
                int a, b;
                cout << "Ingrese el primer numero: " << endl;
                cin >> a;
                cout << "Ingrese el segundo numero: " << endl;
                cin >> b;
                cout << "El resultado de la multiplicacion es: " << a * b << endl;
            }
            else if (operacion == 4) {
                int a, b;
                cout << "Ingrese el primer numero: " << endl;
                cin >> a;
                cout << "Ingrese el segundo numero: " << endl;
                cin >> b;
                if (b != 0) {
                    cout << "El resultado de la division es: " << a / b << endl;
                }
                else {
                    cout << "Error: No se puede dividir entre 0" << endl;
                }
            }
            else if (operacion == 5) {
                cout << "Saliendo del sistema..." << endl;
                return 0; 
            }

            return 0; 
        }

    } while (x != contrasena && attempts < 3);
      cout << "Contrasena incorrecta. Has excedido el numero de intentos." << endl;

    return 0;
}