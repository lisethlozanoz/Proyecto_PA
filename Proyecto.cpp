#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

struct Empleados
{
  int codigo;
  char apellidos[20];
  char nombres[20];
  char celular[11];
};


int menu();

int crearArchivosBinarios();

void imprimirArchivosBinarios();

void crearArchivosTexto(int n);

int main(){

    int opcion, tamanio;

    do{
    	opcion=menu();
        switch(opcion){
            case 1:
            	tamanio=crearArchivosBinarios();
            	imprimirArchivosBinarios();
            	crearArchivosTexto(tamanio);
            break;

            case 2:

            break;

            case 3:

            break;

            case 4:
        
            break;
    
            case 5:

            break;

            default:
            break;
        }
    }while(opcion!=6);
}


////////////////////////////////////////////////////////////////////////////////////////////////////
int menu(){
    int x;
    
    cout<<endl<<"\t \t  * MENU * "<<endl<<endl;
    cout<<"Ingrese 1 para capturar los datos iniciales en los archivos e imprimirlos"<<endl<<endl;
    cout<<"Ingrese 2 para generar el archivo de datos (datos.txt)"<<endl<<endl;
    cout<<"Ingrese 3 para adicionar un empleado a datos.bin y modificar el indice en indice.bin"<<endl<<endl;
    cout<<"Ingrese 4 para crear el archivo cartas.txt"<<endl<<endl;
    cout<<"Ingrese 5 para generar un archivo binario por cada operador de telefonia"<<endl<<endl;
    cout<<"Ingrese 6 para salir del programa"<<endl<<endl;
    cin>>x;

    return x;

}


////////////////////////////////////////////////////////////////////////////////////////////////////
int crearArchivosBinarios(){
	
	int n, indice;
    Empleados empleados;
    
    ofstream archivoDatos("datos.bin", ios::binary | ios::out);
    
    if(!archivoDatos){
       cout<<"No se pudo crear el archivo"<<endl;
       exit(1);
    }
    
    cout<<endl<<"Digite el numero de empleados : ";
    cin>>n;
    
    for(int i=0; i<n; i++){
        cout<<endl<<"Digite el codigo del empleado : ";
        cin>>empleados.codigo;
        cin.ignore();
        cout<<"Digite los apellidos del empleado : ";
        cin.getline(empleados.apellidos,20,'\n');
        cout<<"Digite los nombres del empleado : ";
        cin.getline(empleados.nombres,20,'\n');
        cout<<"Digite el numero de celular del empleado : ";
        cin>>empleados.celular;
        archivoDatos.write((char*)&empleados,sizeof(Empleados));
    }    
    archivoDatos.close();
    
    ofstream archivoIndices("indice.bin",ios::binary | ios::out);
    
    if(!archivoIndices){
        cout<<"No se pudo crear el archivo"<<endl;
        exit(1);
    }
    
    else{
    	cout<<endl;
    
	    for(int i=0; i<n; i++){
        cout<<"Digite el indice :";
        cin>>indice;
        archivoIndices.write((char*)&indice,sizeof(int));
        }
	}
	archivoIndices.close();	
	
	return n;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
void imprimirArchivosBinarios(){
	
	int indice;
    Empleados empleados;
    
    ifstream archivoDatos("datos.bin", ios::binary | ios::in);
    
    if(!archivoDatos){
       cout<<"No se pudo leer el archivo"<<endl;
       exit(1);
    }
    
    cout<<endl<<"---------- Datos empleados ----------"<<endl;
    while(archivoDatos){
        archivoDatos.read((char *) &empleados, sizeof(Empleados));  
      
	    if(archivoDatos){
	    	cout<<empleados.codigo<<" "<<empleados.apellidos<<" "<<empleados.nombres<<" "<<empleados.celular<<endl;
		}
         
    }
    archivoDatos.close();
     
    ifstream archivoIndices("indice.bin",ios::binary | ios::in);
    if(!archivoIndices){
        cout<<"No se pudo leer el archivo"<<endl;
        exit(1);
    }
    
    cout<<endl;
    cout<<"---------- Indices empleados ----------"<<endl;
    
    while(archivoIndices){
        archivoIndices.read((char *) &indice, sizeof(int));  
        if(archivoIndices){
            cout<<indice<<endl;	
		}
    }
    archivoIndices.close();
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
void crearArchivosTexto(int n){
	
	Empleados *empleados = new Empleados[n];
	
	ifstream archivoDatosBinario;
	archivoDatosBinario.open("datos.bin");
	
	if(!archivoDatosBinario){
		cout<<"No se pudo abrir el archivo"<<endl;
	}
	
	while(archivoDatosBinario){
		
		for(int i=0; i<n/4; i++){
			
		}
	}
	
	
	ofstream archivoDatosTexto;
	archivoDatosTexto.open("datos.txt");
	
	if(!archivoDatosTexto){
		cout<<"No se pudo crear el archivo"<<endl;
		exit(1);
	}
	
	while(archivoDatosBinario){
		
	}
	
}
