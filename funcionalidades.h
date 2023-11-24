#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRODUCTOS_MAXIMOS 100

char nombres[PRODUCTOS_MAXIMOS][50];
int cantidades[PRODUCTOS_MAXIMOS];
float precios[PRODUCTOS_MAXIMOS];
int numero_productos = 0;

void añadir_producto() {
    if (numero_productos == PRODUCTOS_MAXIMOS) {
        printf("No se pueden ingresar más productos.\n");
        return;
    }

    char nombre[50];
    int cantidad;
    float precio;

    printf("\nIngrese el nombre del producto: ");
    scanf("%s", nombre);
    printf("Ingrese la cantidad del producto: ");
    scanf("%d", &cantidad);
    printf("Ingrese el precio del producto: ");
    scanf("%f", &precio);

    strcpy(nombres[numero_productos], nombre);
    cantidades[numero_productos] = cantidad;
    precios[numero_productos] = precio;

    numero_productos++;

    printf("\nProducto ingresado exitosamente.\n");
}

void editar_producto() {
    if (numero_productos == 0) {
        printf("No hay productos para editar.\n");
        return;
    }

    int producto_ingresado;
    printf("\nIngrese el índice del producto que desea editar: ");
    scanf("%d", &producto_ingresado);

    if (producto_ingresado < 0 || producto_ingresado >= numero_productos) {
        printf("Índice de producto inválido.\n");
        return;
    }

    char nombre[50];
    int cantidad;
    float precio;

    printf("\nIngrese el nuevo nombre del producto: ");
    scanf("%s", nombre);
    printf("Ingrese la nueva cantidad del producto: ");
    scanf("%d", &cantidad);
    printf("Ingrese el nuevo precio del producto: ");
    scanf("%f", &precio);

    strcpy(nombres[producto_ingresado], nombre);
    cantidades[producto_ingresado] = cantidad;
    precios[producto_ingresado] = precio;

    printf("\nProducto editado exitosamente.\n");
}

void elmininar_producto() {
    if (numero_productos == 0) {
        printf("No hay productos para eliminar.\n");
        return;
    }

    int producto_ingresado;
    printf("\nIngrese el índice del producto que desea eliminar: ");
    scanf("%d", &producto_ingresado);

    if (producto_ingresado < 0 || producto_ingresado >= numero_productos) {
        printf("Índice de producto inválido.\n");
        return;
    }

    for (int i = producto_ingresado; i < numero_productos - 1; i++) {
        strcpy(nombres[i], nombres[i + 1]);
        cantidades[i] = cantidades[i + 1];
        precios[i] = precios[i + 1];
    }

    numero_productos--;

    printf("\nProducto eliminado exitosamente.\n");
}

void mostrar_productos() {
    if (numero_productos == 0) {
        printf("No hay productos ingresados.\n");
        return;
    }

    printf("\nProductos ingresados:\n");
    printf("Índice\tNombre\tCantidad\tPrecio\n");

    for (int i = 0; i < numero_productos; i++) {
        printf("%d\t%s\t%d\t       %.2f\n", i, nombres[i], cantidades[i], precios[i]);
    }
}