#include <stdio.h>
#include <string.h>
#define PRODUCTOS 5
#define TAM 30

void limpiarBuffer(void);
void leerProductos(char nombres[][TAM], int demanda[], float tiempo[], int recursos[], int activo[]);
void mostrarProductos(char nombres[][TAM], int demanda[], float tiempo[], int recursos[], int activos[]);
int buscarProducto(char nombres[][TAM], int activo[], char nombreBuscar[]);
void editarProducto(char nombres[][TAM], int demanda[], float tiempo[], int recursos[], int activo[]);
void eliminarProducto(char nombres[][TAM], int activo[]);
void calcularProduccion(int demanda[], float tiempo[], int recursos[], int activo[]);

int main(void) {
    char nombres[PRODUCTOS][TAM];
    int demanda[PRODUCTOS];
    float tiempo[PRODUCTOS];
    int recursos[PRODUCTOS];
    int activo[PRODUCTOS] = {0};

    int opcion;
    do
    {
        printf("\n===== SISTEMA DE OPTIMIZACION DE PRODUCCION =====\n");
        printf("1. Ingresar productos\n");
        printf("2. Mostrar productos\n");
        printf("3. Editar producto\n");
        printf("4. Eliminar producto\n");
        printf("5. Calcular produccion\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        if (scanf("%d", &opcion) != 1) {
            printf("OPCION NO VALIDA \n");
            limpiarBuffer();
            opcion = 0;
            continue;
        }
        limpiarBuffer();

        switch (opcion)
        {
            case 1:
                leerProductos(nombres, demanda, tiempo, recursos, activo);
                break;
            
            case 2:
                mostrarProductos(nombres, demanda, tiempo, recursos, activo);
                break;
            case 3:
                editarProducto(nombres, demanda, tiempo, recursos, activo);
                break;
            case 4:
                eliminarProducto(nombres, activo);
                break;
            case 5:
                calcularProduccion(demanda, tiempo, recursos, activo);
                break;
            case 6:
                printf("SALIENDO DEL SISTEMA........\n");
                break;
            default:
                printf("OPCION NO VALIDA \n");
                break;
            }
    } while (opcion != 6);
    
    return 0;
}

void limpiarBuffer(void){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void leerProductos(char nombres[][TAM], int demanda[], float tiempo[], int recursos[], int activo[]){
    for (int i = 0; i < PRODUCTOS; i++)
    {
        printf("\n PRODUCTO N. %d\n", i+1);
        printf("INGRESE EL NOMBRE DEL PRODUCTO:");
        fgets(nombres[i], TAM, stdin);
        nombres[i][strcspn(nombres[i], "\n")]= '\0';
        printf("INGRESE LA CANTIDAD DEMANDADA:");
        scanf("%d", &demanda[i]);
        printf("INGRESE EL TIEMPO DE FABRICACION POR UNIDAD: \n");
        scanf("%f", &tiempo[i]);
        printf("INGRESE LA CANTIDAD DE RECURSOS POR UNIDAD: \n");
        scanf("%d", &recursos[i]);
        limpiarBuffer();
        activo[i]= 1;

    }
    
}
void mostrarProductos(char nombres[][TAM], int demanda[], float tiempo[], int recursos[], int activo[]){
    printf("\n LISTA DE PRODUCTOS DISPONIBLES \n");

    for (int i = 0; i < PRODUCTOS; i++)
    {
        if (activo[i]== 1)
        {
            printf("PRODUCTO %s \n", nombres[i]);
            printf("TIENE UNA DEMANDA DE: %d UNIDADES \n", demanda[i]);
            printf("EL TIEMPO DE FABRICACION POR UNIDAD ES DE: %.2f HORAS \n", tiempo[i]);
            printf("LOS RECURSOS UTILIZADOS POR CADA UNIDAD SON: %d\n", recursos[i]);
        }
        
    }
    
}
int buscarProducto(char nombres[][TAM], int activo[], char nombreBuscar[]){
    for (int i = 0; i < PRODUCTOS; i++)
    {
        if(activo[i] == 1 && strcmp(nombres[i], nombreBuscar) == 0) {
        return i;
        }
    }
    return -1;
}
void editarProducto(char nombres[][TAM], int demanda[], float tiempo[], int recursos[], int activo[]){
    char nombreBuscar[TAM];
    int pos;
    printf("INGRESE EL NOMBRE DEL PRODUCTO QUE DESEA EDITAR: \n");
    fgets(nombreBuscar, TAM, stdin);
    nombreBuscar[strcspn(nombreBuscar, "\n")]= '\0';

    pos= buscarProducto(nombres,activo, nombreBuscar); 
    if (pos == -1)
    {
        printf("PRODUCTO NO ENCONTRADO \n");
    }else{
        printf("INGRESE EL NUEVO NOMBRE DEL PRODUCTO: \n ");
        fgets(nombres[pos], TAM, stdin);
        nombres[pos][strcspn(nombres[pos], "\n")] = '\0';
        printf("INGRESE LA NUEVA CANTIDAD DEMANDADA: \n"); 
        scanf("%d", &demanda[pos]);
        printf("Ingrese el nuevo tiempo por unidad: ");
        scanf("%f", &tiempo[pos]);
        printf("Ingrese la nueva cantidad de recursos por unidad: ");
        scanf("%d", &recursos[pos]);
        limpiarBuffer();
        printf("Producto editado correctamente.\n");

    }
}
void eliminarProducto(char nombres[][TAM], int activo[]){
    char nombreBuscar[TAM];
    int pos;
    printf("\n INGRESE EL NOMBRE DEL PRODUCTO QUE DESEA ELIMINAR ");
    fgets(nombreBuscar, TAM, stdin);
    nombreBuscar[strcspn(nombreBuscar, "\n")] = '\0';
    pos = buscarProducto(nombres, activo, nombreBuscar);
     if(pos == -1) {
        printf("PRODUCTO NO ENCONTRADO\n");
    } else {
        activo[pos] = 0;
        printf("PRODUCTO ELIMINADO CORRECTAMENTE \n");
    }
}
void calcularProduccion(int demanda[], float tiempo[], int recursos[], int activo[]){
    float tiempoDisponible;
    int recursosDisponibles;
    float tiempoTotal = 0;
    int recursosTotales = 0;
    printf("INGRESE EL TIEMPO TOTAL DISPONIBLE DE PRODUCCION: \n");
    scanf("%f", &tiempoDisponible);
    printf("INGRESE LA CANTIDAD TOTAL DE RECURSOS DISPONIBLES: \n");
    scanf("%d", &recursosDisponibles);
    limpiarBuffer();
    for (int i = 0; i < PRODUCTOS; i++)
    {
        if (activo[i]==1)
        {
            tiempoTotal += demanda[i] * tiempo[i];
            recursosTotales += demanda[i] * recursos[i];
        }
        
    }
    printf("\n===== RESULTADO DE PRODUCCION =====\n");
    printf("Tiempo total requerido: %.2f horas\n", tiempoTotal);
    printf("Recursos totales requeridos: %d\n", recursosTotales);

    if(tiempoTotal <= tiempoDisponible && recursosTotales <= recursosDisponibles) {
        printf("La fabrica SI puede cumplir con la demanda.\n");
    } else {
        printf("La fabrica NO puede cumplir con la demanda.\n");

        if(tiempoTotal > tiempoDisponible) {
            printf("Falta tiempo de produccion.\n");
        }

        if(recursosTotales > recursosDisponibles) {
            printf("Faltan recursos disponibles.\n");

        }
    }
    
}






