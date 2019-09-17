#include<iostream>
#include<cstdlib>
#include<stdlib.h>
#include<string>

using namespace std;

struct Alumno
{
	string cedula;
	string nombre;
	int nota;
	int edad;
	char genero;
	
};


void print(string tring)
{
	cout << tring <<"\n";
}

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  



void imprimirAlumno(struct Alumno a)
{
	if(a.genero=='F')
		cout << "*Alumna: " <<a.nombre <<"\n";
	else
		cout << "*Alumno: " <<a.nombre <<"\n";
	cout << "**Cedula: " <<a.cedula <<"\n";
	cout << "**Edad: " <<a.edad <<"\n";
	cout << "**Genero: " <<a.genero <<"\n";
	cout << "**Nota: " <<a.nota <<"\n";
}

//Se ordena la lista con Bubble sort
void ordenarLista(struct Alumno lista[], int n)
{
	int i, j;  
    for (i = 0; i < n-1; i++)     
      {
	  
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)
        if (lista[j].nota > lista[j+1].nota)  
            swap(&lista[j].nota, &lista[j+1].nota);
  }
    print("Menor: ");
    print(lista[n-1].nombre);
    print("Mayor: ");
    print(lista[0].nombre);        
}


void imprimirPorGenero(struct Alumno lista[], int n)
{
	int i;
	print("* NINAS");
	for(i=0;i<n;i++)
		if(lista[i].genero == 'F' )
			imprimirAlumno(lista[i]);
	print("* NINOS");
	for(i=0;i<n;i++)
		if(lista[i].genero == 'M' )
			imprimirAlumno(lista[i]);
}

//Funcion que busca un alumno por cedula
void buscarPorCedula(struct Alumno lista[], int n, string cedula)
{
	int i;
	for(i=0;i<n;i++)
		if(lista[i].cedula.compare(cedula)==0)
			imprimirAlumno(lista[i]);
}

//Funcion para extraer informacion de un alumno y guardarlo en un struct
Alumno opcion1()
{
	struct Alumno a;	
	print("Digite la cedula del Alumno:");
	cin >> a.cedula;
	print("Digite el nombre del Alumno:");
	cin >> a.nombre;
	print("Digite la edad del Alumno:");
	cin >> a.edad;
	print("Digite la nota del Alumno:");
	cin >> a.nota;
	print("Digite F si es Sexo Femenino o M si es masculino:");
	cin >> a.genero;
	return a;
}
void menu()
{
	print("1. Ingresar alumnos");
	print("2. Imprimir el listado de alumnos");
	print("3. Muestra el alumno de mayor y menor edad");
	print("4. Imprime el listado de las niñas y los niños");
	print("5. Busca un alumno por el numero de cedula");
	print("6. Elimina los alumnos");
	print("0. Salir");
}

int main()
{
	Alumno p;
	int opcion = -1;
	int i=0;
	int numAlumnos;
	string cedula;
	int cantidad = 0;
	struct Alumno * lista = NULL; // arreglo vacio.
	
	//obtenemos un valor de cantidad capturado de consola
	cout<< "Por favor digite la cantidad de estudiantes ";
	cin>>numAlumnos;
	// creamos el arreglo dinámico con el parametro capturado
	lista = new Alumno[numAlumnos];
		
	//struct Alumno *lista;
	//lista = (struct Alumno*)malloc(sizeof(struct Alumno) * numAlumnos);
	///Repetimos el menu siempre que la opcion que se recepta no sea 0
	while(opcion!=0)
	{
		system("cls");
		menu();
		print("Ingrese una opcion: ");
		cin >> opcion;
		switch(opcion)
		{
			case 1:	
				print("- Haga un listado con todos los datos dado el numero de alumnos\n");
				
				for(i=0;i<numAlumnos;i++)
				{
					p=opcion1();
					lista[i]=p;
				}
				break;
			case 2:
				print("- Imprimiendo el listado de alumnos");
				if(lista!=NULL)
					for(i=0;i<numAlumnos;i++)
					{
						imprimirAlumno(lista[i]);
					}
				else 
					print("Lista vacia");
				system("pause");
				break;
			case 3:
				print("- Muestre los alumnos de mayor y menor edad");
				ordenarLista(lista,numAlumnos);
				system("pause");
				break;
			case 4:
				print("- Imprime el listado de las niñas y los niños");
				imprimirPorGenero(lista,numAlumnos);
				system("pause");
				break;
			case 5:
				print("- Busque un alumno por el numero de cedula");
				print("Ingrese la cedula: ");
				cin >> cedula;
				buscarPorCedula(lista, numAlumnos, cedula);
				system("pause");
				break;
			case 6:
				print("- Elimine los alumnos");
				lista = NULL;
				//delete [] lista;
				break;
			default:
				print("Finalizado con exito");
				break;
		}
	}
	
	
	return 0;
}
