#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <stdlib.h>
#include <math.h>

/**

Francisco Iribarra Araya
Se pide desarrollar una solución computacional en C/C++
Que lea el siguiente archivo:
http://146.83.181.4/~seba/numeros.zip

Y muestre por pantalla los siguientes datos:
- Suma total.
- Cantidad de elementos.
- Media (promedio)
- Mediana
- Moda
- Desviación estándar.

Este trabajo debe subirse a un repositorio git y se podrá trabajar hasta el día 30/11/2018 a las 23:59:59.999 hora chilena continental.
**/


using namespace std;

string linea;
long double promed =0;
long double cont = 0;
long double suma =0;
long double desvia = 0;
long double diferencia = 0;
bool esta= false;
double v[7][9];
double moda =0;


void llenar ()
{
    for(int i=1;i<=7;i++)
    {
        for(int j=1;j<=9;j++)
        {
            v[i][j]=0;
        }
    }
}
void mostrarM ()
{
    for(int i=1;i<=7;i++)
    {
        for(int j=1;j<=9;j++)
        {
            cout<<"posicion: "<<i<<" "<<j<<" valor ";
            cout<<v[i][j]<<endl;
        }cout<<endl;
    }
}

void estado(double x)
{
    for(int i=0; i<70; i++)
    {
        if (x == v[i][0])
        {

        }
    }


}

void Promedio()
{
    ifstream txt;
    string line;
    txt.open("numeros.txt");
    while(!txt.eof())
    //while (getline(txt,linea))
        {
            //string line = linea.c_str();
            txt>>line;
            char c = ',';
            string cambiar = ".";
            for (int i = 0; i < (int)line.length(); ++i)
                {
                    if(line[i]==c)
                    {
                        line.replace(i,1,cambiar);
                    }
                }
            double temp = atof(line.c_str());

            //estado(temp);
            suma+=temp;
            cont ++;
        }
        txt.close();
        cout << "Suma de los datos:"<< suma << endl;
        cout << "Cantidad de datos : "<<cont<< endl;
        promed =suma/cont;
        cout << "Media...Promedio: "<< promed << endl;

}

void desviacionEstandar()
{
    cout<<"...Calcular la diferencia para la desviacion.."<<endl;
    cout<<"....Esto demorara un tiempo..."<<endl;
    ifstream txt;
    string line;
    txt.open("numeros.txt");
    while (getline(txt,linea))
        {
            //string line = linea.c_str();
             txt>>line;
             char c = ',';
             string cambiar = ".";
             for (int i = 0; i < (int)line.length(); ++i)
                {
                    if(line[i]==c)
                    {
                        line.replace(i,1,cambiar);
                    }

                }
            double temp = (double)atof(line.c_str());
            diferencia =abs(temp- promed); //calcula valor absoluto de la diferentcia entre los datos y la media
            diferencia = diferencia*diferencia ; // lo eleva al cuadrado
            suma+=diferencia; // realiza la sumatoria
        }
    txt.close();
    desvia= suma /cont; //
    desvia= sqrt(desvia); // calcula da raiz
    cout<<"La desviacion estandar es: "<<desvia<<endl;
}


int main()
{
    cout<<"...Calcular los datos.."<<endl;
    cout<<"....Esto demorara un tiempo..."<<endl;
    Promedio();
    desviacionEstandar();
    return 0;
}
