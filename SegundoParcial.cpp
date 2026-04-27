#include <iostream>
#include <fstream>

using namespace std;

void registrarVenta();
void mostrarVentas();
void reporteGeneral();
void buscarVentas();

int main()
{
    int opcion;

    do
    {
        cout << "\n=============================\n";
        cout << "SISTEMA DE CONTROL DE VENTAS\n";
        cout << "Hans Douglas Edenilzon Alvarado Milian\n";
        cout << "=============================\n";
        cout << "1. Registrar venta\n";
        cout << "2. Mostrar ventas\n";
        cout << "3. Reporte general\n";
        cout << "4. Buscar por monto\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion)
        {
            case 1:
                registrarVenta();
                break;
            case 2:
                mostrarVentas();
                break;
            case 3:
                reporteGeneral();
                break;
            case 4:
                buscarVentas();
                break;
            case 5:
                cout << "Fin del programa\n";
                break;
            default:
                cout << "Opcion incorrecta\n";
        }

    }while(opcion != 5);

    return 0;
}

void registrarVenta()
{
    char cliente[50];
    char producto[50];
    int cantidad, pago;
    float precio, subtotal, descuento = 0, total;

    cout << "\nNombre del cliente: ";
    cin.getline(cliente,50);

    cout << "Nombre del producto: ";
    cin.getline(producto,50);

    cout << "Cantidad: ";
    cin >> cantidad;

    cout << "Precio unitario: ";
    cin >> precio;

    cout << "Tipo de pago\n";
    cout << "1. Efectivo\n";
    cout << "2. Tarjeta\n";
    cout << "3. Transferencia\n";
    cout << "Opcion: ";
    cin >> pago;
    cin.ignore();

    subtotal = cantidad * precio;

    if(subtotal >= 500)
        descuento = subtotal * 0.05;

    if(pago == 1 && subtotal >= 300)
        descuento = descuento + subtotal * 0.02;

    total = subtotal - descuento;

    ofstream archivo("ventas.txt", ios::app);

    archivo << cliente << endl;
    archivo << producto << endl;
    archivo << cantidad << endl;
    archivo << precio << endl;
    archivo << pago << endl;
    archivo << descuento << endl;
    archivo << total << endl;

    archivo.close();

    cout << "Venta guardada\n";
}

void mostrarVentas()
{
    ifstream archivo("ventas.txt");

    char cliente[50];
    char producto[50];
    int cantidad, pago;
    float precio, descuento, total;

    cout << "\nVENTAS REGISTRADAS\n";

    while(archivo.getline(cliente,50))
    {
        archivo.getline(producto,50);
        archivo >> cantidad;
        archivo >> precio;
        archivo >> pago;
        archivo >> descuento;
        archivo >> total;
        archivo.ignore();

        cout << "\nCliente: " << cliente << endl;
        cout << "Producto: " << producto << endl;
        cout << "Cantidad: " << cantidad << endl;
        cout << "Precio: Q" << precio << endl;

        if(pago == 1)
            cout << "Pago: Efectivo\n";
        else if(pago == 2)
            cout << "Pago: Tarjeta\n";
        else
            cout << "Pago: Transferencia\n";

        cout << "Descuento: Q" << descuento << endl;
        cout << "Total: Q" << total << endl;
    }

    archivo.close();
}

void reporteGeneral()
{
    ifstream archivo("ventas.txt");

    char cliente[50];
    char producto[50];
    int cantidad, pago;
    float precio, descuento, total;

    int ventas = 0;
    int efectivo = 0;
    int tarjeta = 0;
    int transferencia = 0;
    int conDescuento = 0;

    float suma = 0;
    float promedio = 0;

    while(archivo.getline(cliente,50))
    {
        archivo.getline(producto,50);
        archivo >> cantidad;
        archivo >> precio;
        archivo >> pago;
        archivo >> descuento;
        archivo >> total;
        archivo.ignore();

        ventas++;
        suma = suma + total;

        if(pago == 1)
            efectivo++;

        if(pago == 2)
            tarjeta++;

        if(pago == 3)
            transferencia++;

        if(descuento > 0)
            conDescuento++;
    }

    archivo.close();

    if(ventas > 0)
        promedio = suma / ventas;

    cout << "\nREPORTE GENERAL\n";
    cout << "Total ventas: " << ventas << endl;
    cout << "Suma total: Q" << suma << endl;
    cout << "Promedio: Q" << promedio << endl;
    cout << "Efectivo: " << efectivo << endl;
    cout << "Tarjeta: " << tarjeta << endl;
    cout << "Transferencia: " << transferencia << endl;
    cout << "Con descuento: " << conDescuento << endl;
}

void buscarVentas()
{
    ifstream archivo("ventas.txt");

    char cliente[50];
    char producto[50];
    int cantidad, pago;
    float precio, descuento, total, monto;

    cout << "\nIngrese monto minimo: Q";
    cin >> monto;
    cin.ignore();

    while(archivo.getline(cliente,50))
    {
        archivo.getline(producto,50);
        archivo >> cantidad;
        archivo >> precio;
        archivo >> pago;
        archivo >> descuento;
        archivo >> total;
        archivo.ignore();

        if(total >= monto)
        {
            cout << "\nCliente: " << cliente << endl;
            cout << "Producto: " << producto << endl;
            cout << "Total: Q" << total << endl;
        }
    }

    archivo.close();
}
