#include <iostream>
#include <vector>
#include <string>
using namespace std;
void menuAhorcado();
class LoteProduccion {
private:
    string codigo;
    string color;
    string talla;
    int cantidad;
    float precio;
    float humedad;

public:
    LoteProduccion(string c, string col, string t, int cant, float p, float h) {
        codigo = c;
        color = col;
        talla = t;
        cantidad = cant;
        precio = p;
        humedad = h;
    }

    float calcularMerma() {
        return cantidad * (humedad / 100);
    }

    void secar(int minutos) {
        if (minutos > 0) {
            humedad -= 0.8;
            if (humedad < 0) humedad = 0;
            secar(minutos - 1);
        }
    }

    void mostrar() {
        cout << "\nCodigo: " << codigo;
        cout << "\nColor: " << color;
        cout << "\nTalla: " << talla;
        cout << "\nCantidad: " << cantidad;
        cout << "\nPrecio: " << precio;
        cout << "\nHumedad: " << humedad;
        cout << "\nMerma: " << calcularMerma() << endl;
    }

    float getMerma() { return calcularMerma(); }
};

class SistemaTextil {
private:
    vector<LoteProduccion> lotes;

public:
    void registrar() {
        string c, col, t;
        int cant;
        float p, h;

        cout << "Codigo: "; cin >> c;
        cout << "Color: "; cin >> col;
        cout << "Talla: "; cin >> t;

        do {
            cout << "Cantidad (>0): ";
            cin >> cant;
        } while (cant <= 0);

        cout << "Precio: "; cin >> p;

        do {
            cout << "Humedad (0-100): ";
            cin >> h;
        } while (h < 0 || h > 100);

        lotes.push_back(LoteProduccion(c, col, t, cant, p, h));
    }

    void mostrar() {
        for (auto &l : lotes) {
            l.mostrar();
        }
    }

    void ordenar() {
        for (int i = 0; i < lotes.size(); i++) {
            for (int j = i + 1; j < lotes.size(); j++) {
                if (lotes[j].getMerma() > lotes[i].getMerma()) {
                    swap(lotes[i], lotes[j]);
                }
            }
        }
    }
};

int main() {
    SistemaTextil sistema;
    int op;

    do {
        cout << "\n=== SISTEMA TEXTIL ===";
        cout << "\n1. Registrar lote";
        cout << "\n2. Mostrar lotes";
        cout << "\n3. Ordenar por merma";
        cout << "\n4. Ahorcado";
        cout << "\n5. Salir";
        cout << "\nOpcion: ";
        cin >> op;

        switch (op) {
            case 1:
                sistema.registrar();
                break;
            case 2:
                sistema.mostrar();
                break;
            case 3:
                sistema.ordenar();
                cout << "Ordenado correctamente\n";
                break;
            case 4:
                cout << "Modulo Ahorcado no disponible (lo hace el otro integrante).\n";
                break;
            case 5:
                cout << "Saliendo del sistema...\n";
                break;
                case 6:
    menuAhorcado();
    break;
            default:
                cout << "Opcion invalida. Intenta de nuevo.\n";
        }

    } while (op != 5);

    return 0;
}
