#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>

void a_minusculas(char *cadena) {
	for (int i = 0; cadena[i]; i++) {
		cadena[i] = tolower(cadena[i]);
	}
}

int main() {
	char palabra[30];
	char significado[500];
	char parecidas[50];
	char palabra_archivo[30];
	char parecidas_archivo[50];
	char significado_archivo[500];
	int encontrado;
	int interruptor = 1;
	
#ifdef _WIN32
	mkdir("base_datos");
#else
	mkdir("base_datos", 0777);
#endif
	
	char ruta_archivo[] = "base_datos/memoria.txt";
	
	do {
		encontrado = 0;
		
		printf("\n=== IA APRENDIZ ===\n");
		printf("Escribi una palabra: ");
		scanf("%s", palabra);
		
		a_minusculas(palabra);
		
		FILE *archivo_lectura = fopen(ruta_archivo, "r");
		
		if (archivo_lectura != NULL) {
			while (fscanf(archivo_lectura, "%s %s %[^\n]", palabra_archivo, parecidas_archivo, significado_archivo) == 3) {
				if (strcmp(palabra, palabra_archivo) == 0 || strstr(parecidas_archivo, palabra) != NULL) {
					printf("\n[IA]: ¡Ya lo se! '%s' significa: %s\n", palabra, significado_archivo);
					encontrado = 1;
					break;
				}
			}
			fclose(archivo_lectura);
		}
		
		if (!encontrado) {
			printf("\n[IA]: No se que significa '%s'. ¿Me explicas que es?\n", palabra);
			printf("Tu explicacion: ");
			scanf(" %499[^\n]", significado);
			
			printf("\n[IA]: ¿Hay otras palabras parecidas separadas por coma? (Ej: nave,jet o 'ninguna'): ");
			scanf(" %[^\n]", parecidas);
			a_minusculas(parecidas);
			
			FILE *archivo_escritura = fopen(ruta_archivo, "a");
			if (archivo_escritura != NULL) {
				fprintf(archivo_escritura, "%s %s %s\n", palabra, parecidas, significado);
				fclose(archivo_escritura);
				printf("\n[IA]: ¡Guardado con exito en '%s'!\n", ruta_archivo);
			} else {
				printf("\n[ERROR]: No se pudo guardar en el archivo.\n");
			}
		}
		
		printf("\n\t0 = Salir\n\t1 = Continuar\nEleccion: ");
		scanf("%d", &interruptor);
		
	} while (interruptor != 0);
	
	return 0;
}
