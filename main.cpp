#include <iostream>
#include <fstream>
using namespace std;
int op;
void menu();
void ingreso(int a[]);
void imprimir0(int a[],int x);
void intercambio(int a[]);

void Ejercicio2();
void datos(int a[], int b);
void imprimir(int a[], int b);
void ordenado(int a[], int b);
//Ejercicio 3 y funciones
void Ejercicio3();
void Ingresar(float Mes[]);
int Busqueda(float Mes[],float Monto);



int main() {
  do{     
    menu();
    switch(op){
      case 1:
      int a[6];
      ingreso(a);
      cout<<"Arreglo ingresado:\n";
      imprimir0(a,1);
      intercambio(a);
      cout<<"Arreglo con intercambio:\n";
      imprimir0(a,2);
      break;
      
      case 2:
      Ejercicio2();
      break;

      case 3:
      Ejercicio3();      
      break;
      
      case 4:
      cout<<"Gracias\n";
      break;
      default: cout<<"Error intente de nuevo:\n\n";

    }

  }while(op!=4);



return 0;  
}

void menu(){
  cout<<"\t\tTRABAJO EN GRUPO.\n\n";
  cout<<"\tALGORITMO Y ESTRUCTURA DE DATOS\n\n";
  cout<<"\tSELECCIONE UNA OPCION DEL MENU:\n\n";
  cout<<"1. Intercambiar posiciones de un vector:\n";
  cout<<"2. Ordenamiento de un vector:\n";
  cout<<"3. Cuenta de ahorros virtual del Banco Pichincha\n";
  cout<<"4. Salir.\n";
  cout<<"OPCION: ";
  cin>>op;
}

void ingreso(int a[]){
  int p=0;
  for (int i=1;i<=6;i++){
  cout<<"Ingrese el elemento "<<i<<" : ";
  cin>>p;
  if(p<0){
    cout<<"Error de ingreso, intente de nuevo.\n";
    i--;
  }
    else
    a[i]=p;  
}
}

void imprimir0(int a[], int x)
{
  ofstream ArchivoEj1;
  ArchivoEj1.open("Intercambiar.txt",ios::out| ios:: app);
  if(x==2)
  {
  ArchivoEj1 << "Arreglo intercambiado :{";
  }else 
  {
    ArchivoEj1 << "Arreglo Ingresado: {";
  }

for(int j=1;j<=6;j++){
  ArchivoEj1 << a[j] << ",";
  cout<<a[j]<<"\t";
}
ArchivoEj1 << "}\n";
ArchivoEj1.close();
cout<<endl;
}

void intercambio(int a[]){
  int aux;
  int x=6;
  for(int i=1;i<=3;i++){    
    aux=a[i];
    a[i]=a[x];
    a[x]=aux;
    x--;    
  }
}

void Ejercicio2()
{
  int n;
  ofstream ArchivoEj2;
  ArchivoEj2.open("Ordenamiento.txt",ios::out | ios::app);
  cout << endl;
  cout << "Escriba el número de elementos que va a ingresar: ";
  cin >> n;
  ArchivoEj2 << "Numero de elemntos: "<< n << endl;
  ArchivoEj2.close();
  int arreglo[n];
  datos(arreglo, n);
  cout << "Datos ingresados: ";
  imprimir(arreglo, n);
  ordenado(arreglo, n); // Método de la burbuja

}


void Ejercicio3()
{

  ofstream ArchivoEj3;
  
  int mes,opcion;
  do{  
  float Mes[12];
  cout << "\n_____________________________________\n";
  cout << "Bienvenido Alberto Perez\n";
  cout << "Que desea Hacer?\n";
  cout << "1.-Ingresar los montos de dinero\n";
  cout << "2.-Revisar monto Ingresado en un mes\n";
  cout << "3.-Salir\n";
  do{
  cin >> opcion;
  if(opcion>3)
  {
    cout << "Opcion Invalida\nVuelva a ingresar\n";
  }
  }while (opcion>3);
  ArchivoEj3.open("Cuenta.txt",ios:: out |ios::app);
   switch(opcion)
   {
     case 1:
     Ingresar(Mes);
     break;
     case 2:
     float Monto;
     cout << "Ingrese el Monto que desea buscar:  ";
     cin >> Monto;   
     ArchivoEj3 << "Monto a Buscar: " << Monto << endl;  
       if(Busqueda(Mes, Monto)==-1)
        {             
          ArchivoEj3 << "Elemento no Encontrado\n";
            cout << "Elemento no encontrado";
        }
       else
       { 
         ArchivoEj3 << "Elemento encontrado En el mes : " << Busqueda(Mes, Monto);
         cout << "Elemento encontrado En el mes : " << Busqueda(Mes, Monto);

        }
      break;
     
     case 3:
     cout<<"Gracias por su visita:\n";
     break;
     default: cout<<"Error, vuelta a intentar:\n"; 
         
   }
   ArchivoEj3.close();
  }while(opcion!=3);

  

    
}

void Ingresar(float Mes[])
{
  ofstream ArchivoEj3;
   ArchivoEj3.open("Cuenta.txt",ios:: out |ios::app);
   ArchivoEj3 << "Arreglo de meses: {";
  for (int i=0;i<12;i++)
  {
    do{
  
    cout << "Ingrese El monto en el Mes " << i+1 << ": "  ;
    
    cin >> Mes[i];
    if(Mes[i]<0)
    {
      cout << "Valor invalido\n";
    }
    }while(Mes[i]<0);

    ArchivoEj3 << Mes[i] << ",";    
  }

  ArchivoEj3 << "}\n";
  ArchivoEj3.close();

}

int Busqueda(float Mes[],float Monto)
{    
  for (int i = 1; i<=12 ;i++)
        {
            if(Mes[i]==Monto)
                {
                    return i+1;
                }
        }
    return -1; 
}

void datos(int a[], int b){
  ofstream ArchivoEj2;
  ArchivoEj2.open("Ordenamiento.txt",ios::out | ios::app);

  ArchivoEj2 << "Arreglo ingresado: {";
  for (int i = 0; i < b; i++){
    cout << "Ingrese el elemento "  << i+1 << ": ";
    cin >> a[i]; 
    ArchivoEj2 << a[i] << ","; 
  }
  ArchivoEj2 << "}\n";
  ArchivoEj2.close();
  cout << endl;
}

void imprimir(int a[], int b){
 
  for (int i = 0; i < (b-1); i++){
    cout << a[i] << ", ";
  }
  cout << a[b-1];
  cout << endl;
}

void ordenado(int a[], int b){
  int tem;
  ofstream ArchivoEj2;
   ArchivoEj2.open("Ordenamiento.txt",ios::out | ios::app);
   ArchivoEj2 << "Arreglo ordenado: {";
  cout << "Datos ordenados: ";
  for(int i=0; i<b; i++)
    {
        for(int j=i+1; j<b;j++)
        {
            if(a[j]<a[i])
            {
                tem=a[i];

                a[i]=a[j];
                
                a[j] = tem;
              
            }
        
        }
      ArchivoEj2 << a[i] << ",";
    }

    ArchivoEj2 << "}\n";
    ArchivoEj2.close();

  imprimir(a, b);
  cout << endl;
}