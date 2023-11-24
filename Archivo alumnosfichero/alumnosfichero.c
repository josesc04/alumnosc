#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

struct alumno
{
	char dni[11];
	char nombre[100];
	char apellido[100];
	float nota;
};

int comprobar(char *namefile);
void altalumnodeprimeras(char *nomfich);
void listado(char *nomfich);
int buscalumno(char *pdni, struct alumno *pa, char *nomfich);
void leecadena(char *cadena, int longitud);
void consultanota(char *nomfich, char *pdni);
void listaaprobados(char *nomfich);
void modificalumno(char *nomfich, char *pdni);
void eliminar(char*nomfich, char *pdni);
int media(char *nomfich, struct alumno pa);

int main()
{
	FILE *pf1=NULL;
	int resultado=0;
	char name[100];
	int opcion;
	int sit=0;
	int sit0=0;
	struct alumno nalumno;
	char ddni[11];
	char nomlaumno[100];

	do 
	{
		puts("\n ");
		puts("---- Men� de Opciones ---");
		puts("1 .- Introducir nota de alumno.");
		puts("2 .- Modificar nota de alumno.");
		puts("3 .- Consultar nota de alumno.");
		puts("4 .- Obtener listado de alumnos.");
		puts("5 .- Calcular media, mayor y menor.");
		puts("6.- Lista de aprobados y suspensos");
		puts("7. Eliminar");
		puts("0 .- Salir del programa.");
		puts ("   Introduce opci�n:");
		scanf("%d",&opcion);
		
		switch(opcion)
		{
			case 1: 
					

				puts("Introduce un nombre para el archivo de almacenamiento de alumnos que vas a usar (de extension .dat)");
				puts("De no haber uno, se creara uno nuevo");
				scanf("%s", &name);
				sit = comprobar(name);
				if(sit==1)
				{
				puts("Introduce el DNI del alumno para asegurar que no figure en la base de datos");
				puts("De no figurar, tendra que registrarlo");
				scanf("%s", &ddni);
				sit0=buscalumno(ddni, &nalumno, name);
				}
				else
				{
						puts(" ");
						puts("Archivo creado, rellenelo para poder leerlo");
						puts(" ");
						altalumnodeprimeras(name);
				}
				
				if(sit0==-1)
				{
					puts("Este alumno no existe, registrelo");
					altalumnodeprimeras(name);
				}
				
				if(sit0==1)
				{
					puts("El alumno ya esta registrado, por favor registre otro DNI");
					break;
				}
				
				break;
				
				case 2: 
					puts("Introduce un nombre para el archivo de almacenamiento de alumnos que vas a usar (de extension .dat)");
					puts("De no haber uno, se creara uno nuevo, pero no se leera");
					scanf("%s", &name);
					resultado = comprobar(name);
					if(resultado==1)
					{
						puts("Introduzca el DNI del alumno que se va a modificar");
						scanf("%s", &ddni);
						sit0=buscalumno(ddni, &nalumno, name);
						if(sit0==1)
						{
							modificalumno(name ,ddni);		
						}
						else
						{
							puts("El alumno no se ha podido modificar, no existe");
						}
								
					
					}
					else
					{
						puts(" ");
						puts("Archivo creado, rellenelo para poder leerlo");
						puts(" ");
					}
				break;
				
				case 3:
					
					puts("Introduce un nombre para el archivo de almacenamiento de alumnos que vas a usar (de extension .dat)");
					puts("De no haber uno, se creara uno nuevo, pero no se leera");
					scanf("%s", &name);
					resultado = comprobar(name);
					if(resultado==1)
					{
						puts("Introduzca el DNI del alumno del que se quiere ver la nota");
						scanf("%s", &ddni);
						sit0=buscalumno(ddni, &nalumno, name);
						if(sit0==1)
						{
							consultanota(name, ddni);
						}
						else
						{
							puts("No se ha podido consultar la nota del alumno, el alumno no existe");
						}
						
					}
					else
					{
						puts(" ");
						puts("Archivo creado, rellenelo para poder leerlo");
						puts(" ");
					}

				break;
				
				case 4:
					puts("Introduce un nombre para el archivo de almacenamiento de alumnos que vas a usar (de extension .dat)");
					puts("De no haber uno, se creara uno nuevo, pero no se leera");
					scanf("%s", &name);
					resultado = comprobar(name);
					if(resultado==1)
					{
						listado(name);	
					}
					else
					{
						puts(" ");
						puts("Archivo creado, rellenelo para poder leerlo");
						puts(" ");
					}
				break;
			case 5: 
					puts("Introduce un nombre para el archivo de almacenamiento de alumnos que vas a usar (de extension .dat)");
					puts("De no haber uno, se creara uno nuevo, pero no se leera");
					scanf("%s", &name);
					resultado = comprobar(name);
					if(resultado==1)
					{
						media(name, nalumno);
					}
					else
					{
						puts(" ");
						puts("Archivo creado, rellenelo para poder leerlo");
						puts(" ");
					}
					
			break;
			
			case 6: 
					puts("Introduce un nombre para el archivo de almacenamiento de alumnos que vas a usar (de extension .dat)");
					puts("De no haber uno, se creara uno nuevo, pero no se leera");
					scanf("%s", &name);
					resultado = comprobar(name);
					if(resultado==1)
					{	
						listaaprobados(name);
					}
					else
					{
						puts(" ");
						puts("Archivo creado, rellenelo para poder leerlo");
						puts(" ");
					}
					
			break;
			
			case 7:
				puts("Introduce un nombre para el archivo de almacenamiento de alumnos que vas a usar (de extension .dat)");
					puts("De no haber uno, se creara uno nuevo, pero no se leera");
					scanf("%s", &name);
					resultado = comprobar(name);
					if(resultado==1)
					{
						puts("Introduzca el DNI del alumno que se quiere eliminar");
						scanf("%s", &ddni);
						sit0=buscalumno(ddni, &nalumno, name);
						if(sit0==1)
						{
							eliminar(name, ddni);	
						}
						else
						{
							puts("No se ha podido eliminar, el alumno no existe");
						}	
					}
					else
					{
						puts(" ");
						puts("Archivo creado, rellenelo para poder leerlo");
						puts(" ");
					}
				
			
			break;
			
			default:
					if (opcion != 0)
					{
						puts("Error: opci�n desconocida.");
					}
		}
	}
	while (opcion != 0);
}


int comprobar(char *namefile)
{
	FILE *pf1=fopen(namefile, "rb");
	
	if(pf1==NULL)
	{
		fclose(pf1);
		puts("No existe un fichero con ese nombre, se creara uno nuevo del mismo nombre");
		puts(" ");
		FILE *pf1=fopen(namefile, "ab");
		fclose(pf1);
		return -1;
	}
	else
	{
		fclose(pf1);
		puts("Ya existe un fichero con este nombre");
		puts("Se continuara con este fichero");
		puts(" ");
		fclose(pf1);
		return 1;
	}
	
}


void altalumnodeprimeras(char *nomfich)
{
	FILE *pf1=fopen(nomfich, "ab");
	struct alumno nalumno;
	puts("Introduce el DNI del alumno que desea registrar");
	leecadena(nalumno.dni, 10);
	puts("Introduce el nombre del alumno");
	leecadena(nalumno.nombre, 99);	
	puts("Introduce el apellido del alumno");
	leecadena(nalumno.apellido, 99);
	puts("Introduce la nota del alumno");
	scanf("%f", &nalumno.nota);
	fwrite(&nalumno, sizeof(struct alumno), 1, pf1);
	fclose(pf1);
	puts(" ");
	puts("Se a dado correctamente de alta al alumno");
	puts(" ");
	
}


void listado(char *nomfich)
{
	struct alumno nalumno;
	FILE *pf1=fopen(nomfich, "rb");

	fread(&nalumno, sizeof(struct alumno), 1, pf1);
	while(feof(pf1)==0)
	{
	printf("%s %s %s %f\n", nalumno.dni, nalumno.nombre, nalumno.apellido, nalumno.nota);
	fread(&nalumno, sizeof(struct alumno), 1, pf1);
	}
	fclose(pf1);
}


int buscalumno(char *pdni, struct alumno *pa, char *nomfich)
{
		FILE *pf1=fopen(nomfich, "rb");
		fread(pa, sizeof(struct alumno), 1, pf1);
	
		do
		{
		
			if(strcmp(pa->dni, pdni)==0)
			{
			
				fclose(pf1);
				return 1;
			}
			fread(pa, sizeof(struct alumno), 1, pf1);
		}while(feof(pf1)==0);
		
		if(strcmp(pa->dni, pdni)!=0)
		{
			fclose(pf1);
			return -1;
		}
}

void leecadena(char *cadena, int longitud)
{
	
	int i=0;
	char c;
	
	fflush(stdin);
	c=getchar();
	while (longitud > 0 && c != '\n')
	{
		cadena[i]=c;
		i++;
		longitud--;	
		c=getchar();
	}		
	
	cadena[i]='\0';
	
	fflush(stdin);
}

void consultanota(char *nomfich, char *pdni)
{
	struct alumno pa;
	FILE *pf1=fopen(nomfich, "rb");
	fread(&pa, sizeof(struct alumno), 1, pf1);
		
		
		do
		{
			
			if(strcmp(pa.dni, pdni)==0)
			{
				printf("%s %s %f", pa.nombre, pa.apellido, pa.nota);
				return;
			}
			else
			{
				fread(&pa, sizeof(struct alumno), 1, pf1);
			}
		}while(feof(pf1)==0);
		
		if(strcmp(pa.dni, pdni)!=0)
		{
			puts("El alumno que se ha introducido no existe, registrelo");
		}
		
	fclose(pf1);
					
}

void listaaprobados(char *nomfich)
{
	struct alumno pa;
	
	FILE *pf1=fopen(nomfich, "rb");
	puts("\nLos aprobados son:");
	
	fread(&pa, sizeof(struct alumno), 1, pf1);
	do
	{
		
		if(pa.nota > 5)
		{
			printf("%s %s\n", pa.nombre, pa.apellido);		
		}
		fread(&pa, sizeof(struct alumno), 1, pf1);
	}
	while(feof(pf1)==0);
	
	fseek(pf1, 0, SEEK_SET);
	
	puts("------------------------------------------------------");
	puts("Los suspensos son:");
			
	do
	{
		
		if(pa.nota <= 4)
		{
			printf("%s %s\n", pa.nombre, pa.apellido);		
		}
		fread(&pa, sizeof(struct alumno), 1, pf1);
	}
	while(feof(pf1)==0);
	
	close(pf1);
	
}

void modificalumno(char *nomfich, char *pdni)
{
	struct alumno palumno;
	int contador=0;
	
	FILE *pf1=fopen(nomfich, "rb");
	
	fread(&palumno, sizeof(struct alumno), 1, pf1);
	
	while(strcmp(palumno.dni, pdni)!=0 && feof(pf1)==0)
	{
		contador=contador+1;
		fread(&palumno, sizeof(struct alumno), 1, pf1);
	}

	fclose(pf1);
	
	pf1=fopen(nomfich, "r+b");
	fseek(pf1, sizeof(struct alumno)*contador, SEEK_SET);
	puts("Introduce la nota del alumno que se quiere modificar");
	scanf("%f", &palumno.nota);
	fwrite(&palumno, sizeof(struct alumno), 1, pf1);
	fclose(pf1);
	
}







void eliminar(char *nomfich, char *pdni)
{

	struct alumno palumno;
	
	FILE *pf1=fopen(nomfich, "rb");
	
	FILE *pf2=fopen("_backup.dat", "ab");
	
	fread(&palumno, sizeof(struct alumno), 1, pf1);
	while(feof(pf1)==0)
	{
		
		if(strcmp(palumno.dni, pdni)==0)
		{
			fread(&palumno, sizeof(struct alumno), 1, pf1);
		}
		else
		{
			fwrite(&palumno, sizeof(struct alumno), 1, pf2);
			fread(&palumno, sizeof(struct alumno), 1, pf1);
		}
	}
	
	fclose(pf1);
	fclose(pf2);
	remove(nomfich);
	rename("_backup.dat", nomfich);
	puts("Alumno dado de baja");

}

int media(char *nomfich, struct alumno pa)
{
	FILE *pf1=fopen(nomfich, "rb");
	float med=0;
	int may=0;
	int men=10;
	int i=0;
	float contmed=0;

	fread(&pa, sizeof(struct alumno), 1, pf1);

	while(feof(pf1)==0)
	{
		contmed=contmed+pa.nota;
		fread(&pa, sizeof(struct alumno), 1, pf1);
	}
	
	fseek(pf1, 0, SEEK_SET);
	
	fread(&pa, sizeof(struct alumno), 1, pf1);
	
	while(feof(pf1)==0)
	{
		i=i+1;
		fread(&pa, sizeof(struct alumno), 1, pf1);
	}

	med=contmed/i;
	printf("La media es %f\n", med);
	
	fseek(pf1, 0, SEEK_SET);
	
	fread(&pa, sizeof(struct alumno), 1, pf1);
	
	do
	{
		if(pa.nota>may)
		{
			may=pa.nota;
		}
		fread(&pa, sizeof(struct alumno), 1, pf1);
		
	}while(feof(pf1)==0);
	
	printf("La nota mayor es %d\n", may);
	
	fseek(pf1, 0, SEEK_SET);
	
	fread(&pa, sizeof(struct alumno), 1, pf1);
	
	do
	{
		if(pa.nota<men)
		{
			men=pa.nota;
		}
		fread(&pa, sizeof(struct alumno), 1, pf1);
		
	}while(feof(pf1)==0);

	printf("La nota menor es %d\n", men);
	fclose(pf1);
	
	return 0;
}