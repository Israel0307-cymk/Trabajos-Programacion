// Israel Nolivos , Mathias Villagomez
#include <stdio.h>
#include <string.h>

int main() {
    char nombre[100];
    char id[100];
    int stock, opcion, vunidades, reabastecimiento;
    float punitario, ganancias = 0;

    printf("INGRESE EL NOMBRE DEL PRODUCTO:\n");
    fgets(nombre, sizeof(nombre), stdin);

    printf("INGRESE EL ID DEL PRODUCTO:\n");
    fgets(id, sizeof(id), stdin);

    nombre[strcspn(nombre, "\n")] = 0;
    id[strcspn(id, "\n")] = 0;

    do {
        printf("INGRESE EL STOCK DEL PRODUCTO:\n");
        scanf("%d", &stock);
        if (stock < 0) {
            printf("INGRESE UNA CANTIDAD DE STOCK VALIDA\n");
        }
    } while (stock < 0);

    do {
        printf("INGRESE EL PRECIO UNITARIO DEL PRODUCTO:\n");
        scanf("%f", &punitario);
        if (punitario <= 0) {
            printf("INGRESE UN PRECIO VALIDO\n");
        }
    } while (punitario <= 0);

    do {
        printf("\n========== MENU ==========\n");
        printf("1. VENTA DE UNIDADES\n");
        printf("2. REABASTECER STOCK DEL PRODUCTO\n");
        printf("3. CONSULTAR INFORMACION DEL PRODUCTO\n");
        printf("4. CALCULO DE GANANCIAS OBTENIDAS HASTA EL MOMENTO\n");
        printf("5. SALIR\n");
        printf("SELECCIONE UNA OPCION:\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                do {
                    printf("INGRESE EL NUMERO DE UNIDADES QUE DESEA VENDER:\n");
                    scanf("%d", &vunidades);

                    if (vunidades <= 0) {
                        printf("INGRESE UNA CANTIDAD VALIDA DE UNIDADES\n");
                    } else if (vunidades > stock) {
                        printf("NO SE PUEDE REALIZAR LA VENTA. EL STOCK ACTUAL ES DE %d UNIDADES\n", stock);
                    }
                } while (vunidades <= 0 || vunidades > stock);

                stock = stock - vunidades;
                ganancias = ganancias + (punitario * vunidades);

                printf("LA VENTA SE REALIZO EXITOSAMENTE\n");
                printf("STOCK ACTUAL: %d UNIDADES\n", stock);
                break;

            case 2:
                do {
                    printf("INGRESE LA CANTIDAD DE UNIDADES A REABASTECER:\n");
                    scanf("%d", &reabastecimiento);

                    if (reabastecimiento <= 0) {
                        printf("INGRESE UNA CANTIDAD VALIDA\n");
                    }
                } while (reabastecimiento <= 0);

                stock = stock + reabastecimiento;
                printf("REABASTECIMIENTO REALIZADO CON EXITO\n");
                printf("NUEVO STOCK: %d UNIDADES\n", stock);
                break;

            case 3:
                printf("\n===== INFORMACION ACTUALIZADA DEL PRODUCTO =====\n");
                printf("NOMBRE DEL PRODUCTO: %s\n", nombre);
                printf("ID DEL PRODUCTO: %s\n", id);
                printf("STOCK ACTUAL: %d\n", stock);
                printf("PRECIO UNITARIO: %.2f\n", punitario);
                break;

            case 4:
                printf("LAS GANANCIAS OBTENIDAS HASTA EL MOMENTO SON: %.2f\n", ganancias);
                break;

            case 5:
                printf("GRACIAS POR USAR NUESTRO SISTEMA :)\n");
                break;

            default:
                printf("OPCION INVALIDA. INTENTE NUEVAMENTE.\n");
        }

    } while (opcion != 5);

    return 0;
}