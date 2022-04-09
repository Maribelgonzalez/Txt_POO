#include <iostream>
#include <stdio.h>  
#include <string.h> 

using namespace std;
const char *nombre_archivo = "archivo.dat";

class Estudiante {
	private:
		int Codigo;
		string Nombre;
		string Apellido;
		string Direccion;
		string Telefono;
		
		public:
		Estudiante ();
		void setCodigo (int);
		void setNombre (string);
		void setApellido (string);
		void setDireccion (string);
		void setTelefono (string);
		int getCodigo ();
		string getNombre();
		string getApellido();
		string getDireccion();
		string getTelefono ();
		
};

Estudiante :: Estudiante (){
	
}

void Estudiante :: setCodigo (int codigo){
	Codigo = codigo;
}
void Estudiante :: setNombre (string nombre){
	Nombre = nombre;
}
void Estudiante :: setApellido (string apellido){
	Apellido = apellido;
}
void Estudiante :: setDireccion (string direccion){
	Direccion = direccion;
}
void Estudiante :: setTelefono (string telefono){
	Telefono = telefono;
}


int Estudiante :: getCodigo (){
	return Codigo;
}

string Estudiante :: getNombre (){
	return Nombre;
}

string Estudiante :: getApellido (){
	return Apellido;
}

string Estudiante :: getDireccion (){
	return Direccion;
}

string Estudiante :: getTelefono (){
	return Telefono;
}
void ingresar_estudiante();
void abrir_estudiante();
 void modificar_estudiante();
int main (){
	int op=0;
	char continuar;
	do{
cout<<"Ingrese la Opccion que desea realizar: 1- Ingresar estudiante, 2- Abrir estudiante, 3- modificar estudiante,"<<endl;
cin>>op;
switch (op){
	
 		case 1 :
		 	ingresar_estudiante ();
 		break;
 			case 2 : 
 			abrir_estudiante();
 		break;
 			case 3 : 
 				modificar_estudiante();
 		break;
 		default: cout <<"opcion ingresada no valida" << endl;
 	}
 cout<<"Desea regresar al menu principal s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
	return 0;	
}

void ingresar_estudiante(){
	
	char continuar;
	FILE* archivo = fopen(nombre_archivo, "ab"); // ab
		
	int codigo;	
	string nombre, apellido, direccion, telefono ;
	
	do{
		fflush(stdin);
	Estudiante estu;
	cout <<"Ingrese Codigo del estudiante:";
	cin >> codigo;
	cout << "Ingrese Nombres:";
	cin >> nombre;
	cout << "Apellidos:";
	cin >> apellido;
	cout << "Ingrese la direccion:";
	cin >> direccion;
	
cout<< "Ingrese el numero de telefono:";
cin >> telefono;

	estu.setCodigo(codigo);
	estu.setNombre(nombre);
	estu.setApellido(apellido);
	estu.setDireccion(direccion);
	estu.setTelefono(telefono);
	
		fwrite( &estu, sizeof(Estudiante), 1, archivo );
	
 	cout<<"Desea Agregar otro Nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
fclose(archivo);
abrir_estudiante();
}
void abrir_estudiante (){
	system("cls");
	FILE* archivo = fopen(nombre_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombre_archivo, "w+b");
	}
	Estudiante estudiante;
	int registro= 0;
	fread ( &estudiante, sizeof(Estudiante), 1, archivo );
	cout<<"____________________________________________________________________"<<endl;
	cout << "id" <<"|"<< "CODIGO" <<"|"<< "NOMBRE"<<" | "<<"APELLIDO"<<" | "<<"DIRECCION"<<" | "<<" TELEFONO "<<endl;	
		do{
		cout<<"____________________________________________________________________"<<endl;
		cout << registro <<" |  "<< estudiante.getCodigo() <<" | "<< estudiante.getNombre()<<" | "<<estudiante.getApellido()<<" | "<<estudiante.getDireccion()<<" | "<<estudiante.getTelefono()<<endl;
        
        
        
		fread ( &estudiante, sizeof(Estudiante), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);
	}
void modificar_estudiante (){
	
		FILE* archivo = fopen(nombre_archivo, "r+b");
	
		int id, codigo;
	string nombre, apellido, direccion, telefono ;
	
		cout << "Ingrese el ID que desea Modificar: ";
    		cin >> id;
    		fseek ( archivo, id * sizeof(Estudiante), SEEK_SET );

	Estudiante estu;
	cout <<"Ingrese Codigo del estudiante:";
	cin >> codigo;
	cout << "Ingrese Nombres:";
	cin >> nombre;
	cout << "Apellidos:";
	cin >> apellido;

	cout << "Ingrese la direccion:";
	cin >> direccion;
	
cout<< "Ingrese el numero de telefono:";
cin >> telefono;

	estu.setCodigo(codigo);
	estu.setNombre(nombre);
	estu.setApellido(apellido);
	estu.setDireccion(direccion);
	estu.setTelefono(telefono);
    		fwrite( &estu, sizeof(Estudiante), 1, archivo );
		
	fclose(archivo);
}





