#include <iostream>
using namespace std;

int main() {
    string nombreCliente;
    int tipoEntrada; 
    double precioEntrada = 0;
    char seguirProceso = 'S';
    int contadorGeneral = 0;
    int contadorVIP = 0;
    double ingresoTotalGeneral = 0.0;
    double ingresoTotalVIP = 0.0;

    cout << "--- Sistema de Venta de Entradas ---" << endl;

    while (seguirProceso == 's' || seguirProceso == 'S') {
        cout << "Datos de la venta:" << endl;
        cout << "Ingrese nombre del cliente: ";
        getline(cin, nombreCliente); 	
        cout << "Seleccione tipo de entrada (1 para General, 2 para VIP): ";
        cin >> tipoEntrada;

        if (tipoEntrada == 1) { 
            precioEntrada = 50.0;
            contadorGeneral++;
            ingresoTotalGeneral += precioEntrada;
        } else if (tipoEntrada == 2) {
            precioEntrada = 80.0;
            contadorVIP++;
            ingresoTotalVIP += precioEntrada;
        } else {
            cout << "Tipo de entrada invalido. Se asumira General." << endl;
            tipoEntrada = 1;
            precioEntrada = 50.0;
            contadorGeneral++;
            ingresoTotalGeneral += precioEntrada;
        }

        cout << "Entrada para: " << nombreCliente << " (" 
             << (tipoEntrada == 1 ? "General" : "VIP") << ")" << endl;
        cout << "Precio: $" << precioEntrada << endl;

        // se corrige el S para si y el N para el no 
        do {
            cout << "¿Desea realizar otra venta? (s/n): ";
            cin >> seguirProceso;
            cin.ignore();

            if (seguirProceso != 's' && seguirProceso != 'S' && 
                seguirProceso != 'n' && seguirProceso != 'N') {
                cout << "Opcion invalida. Ingrese 's' para si o 'n' para no." << endl;
            }

        } while (seguirProceso != 's' && seguirProceso != 'S' &&
                 seguirProceso != 'n' && seguirProceso != 'N');
    }

   
    cout << "--- FIN DE VENTAS ---" << endl;
    cout << "Generando reporte..." << endl;

    cout << "--- Resumen de Tipos de Entradas Vendidas ---" << endl;
    cout << "Entradas Generales vendidas: " << contadorGeneral << endl;
    cout << "Ingreso total por Generales: $" << ingresoTotalGeneral << endl;
    cout << "Entradas VIP vendidas: " << contadorVIP << endl;
    cout << "Ingreso total por VIP: $" << ingresoTotalVIP << endl;

    if (contadorGeneral == 0 && contadorVIP == 0) {
        cout << "No se registraron ventas en ambas categorías." << endl;
    } else {
        cout << "Total de entradas vendidas: " << contadorGeneral + contadorVIP << endl;
        cout << "Ingreso total global: $" << ingresoTotalGeneral + ingresoTotalVIP << endl;
    }

    return 0;
}
