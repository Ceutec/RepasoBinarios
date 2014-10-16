#include <iostream>
#include <fstream>

using namespace std;

class Pastel
{
public:
    string nombre;
    float precio;
    bool esta_vencido;
    Pastel(string nombre,float precio,bool esta_vencido)
    {
        this->nombre=nombre;
        this->precio=precio;
        this->esta_vencido=esta_vencido;
    }
};

void agregarPastel(string nombre_archivo, Pastel*pastel)
{
    ofstream out(nombre_archivo.c_str(),ios::app);
    out.write(pastel->nombre.c_str(),20);
    out.write((char*)&pastel->precio,4);
    out.write((char*)&pastel->esta_vencido,1);
    out.close();
}

void imprimir(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());
    in.seekg(0,in.end);
    int tam = in.tellg()/25;
    in.seekg(0);

    for(int i=0;i<tam;i++)
    {
        char nombre[20];
        float precio;
        bool esta_vencido;

        in.read(nombre,20);
        in.read((char*)&precio,4);
        in.read((char*)&esta_vencido,1);

        cout<<"Nombre: "<<nombre<<endl;
        cout<<"Precio: "<<precio<<endl;
        cout<<"Esta vencido: "<<esta_vencido<<endl;
    }

}

int main()
{
    int opcion;
    do
    {
        cout<<"Menu"<<endl;
        cout<<"1. Imprimir"<<endl;
        cout<<"2. Agregar"<<endl;
        cout<<"3. Modificar"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;

        if(opcion==1)
        {
            string nombre_archivo;
            cout<<"Seleccione el archivo: ";
            cin>>nombre_archivo;
            imprimir(nombre_archivo);
        }
        if(opcion==2)
        {
            string nombre_archivo;
            cout<<"Seleccione el archivo: ";
            cin>>nombre_archivo;

            string nombre;
            float precio;
            bool esta_vencido;
            cout<<"Nombre: ";
            cin>>nombre;
            cout<<"Precio: ";
            cin>>precio;
            cout<<"Esta vencido: ";
            cin>>esta_vencido;
            Pastel* pastel = new Pastel(nombre,precio,esta_vencido);

            agregarPastel(nombre_archivo,pastel);
        }

    }while(opcion!=0);


    return 0;
}
