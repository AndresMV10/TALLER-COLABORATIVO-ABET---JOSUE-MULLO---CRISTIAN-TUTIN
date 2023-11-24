#include "funcionalidades.h"

int main() {
    int eleccion;

    while (1) {
        printf("\n\n1. Ingresar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Listar productos ingresados\n");
        printf("5. Salir\n");
        printf("Ingrese su elección: ");
        if (scanf("%d", &eleccion) != 1) {
            printf("\nError: Ingrese un número válido.\n");
            while (getchar() != '\n'); 
            continue;  
        }

        switch (eleccion) {
            case 1:
                añadir_producto();
                break;

            case 2:
                editar_producto();
                break;

            case 3:
                elmininar_producto();
                break;

            case 4:
                mostrar_productos();
                break;

            case 5:
                printf("\nGracias por usar nuestro programa. ¡Hasta luego!\n");
                exit(0);

            default:
                printf("\nOpción inválida. Intente de nuevo.\n");
                break;
        }
    }
    
    return 0;
}