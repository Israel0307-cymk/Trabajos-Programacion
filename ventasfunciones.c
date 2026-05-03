#include <stdio.h>
#include <string.h>
//ISRAEL NOLIVOS Y MATHIAS VILLAGOMEZ
//VC<3

void lectura (int i, char nombres[][100], char id[][100]);
int calcularStock(int stockActual, int cant);
float calcularTotal(float precioUnitario, int cant);
int reabastecimiento(int stock, int nstock);
void impresion(int cont1, float pfinal);



int main (int argc, char *argv[]) {
    int nproductos;
    int opc1;
    int cant;
    int tstock=0;
    float ptotal=0;
    int opc2;
    int nstock;
    float pfinal=0;
    int cont1=0;
    do
    {
        printf("INGRESE EL NUMERO DE PRODUCTOS CON LOS QUE SE VA A TRABAJAR: \n");
        scanf("%d", &nproductos);
        if (nproductos <= 0)
        {
            printf("INGRESE  UNA CANTIDAD VALIDA\n");
        }
    } while (nproductos <= 0);


    char nombres[nproductos][100];
    char id[nproductos][100];
    getchar();
    for (int i = 0; i < nproductos; i++)
    {
        lectura(i, nombres, id);
    }
    int stock[nproductos];
    float punitario[nproductos];
    for (int i = 0; i < nproductos; i++)
    {
        do
        {
            printf("INGRESE EL STOCK DEL PRODUCTO: %s \n", nombres[i]);
            scanf("%d", &stock[i]);
            if (stock[i] < 0)
            {
                printf("INGRESE UN STOCK VALIDO\n");

            }

        } while (stock[i] < 0);
        do
        {
            printf("INGRESE EL PRECIO UNITARIO DEL PRODUCTO %s \n", nombres[i]);
            scanf("%f",&punitario[i]);
            if (punitario[i] <= 0)
            {
                printf("INGRESE UN PRECIO VALIDO\n");
            }

        } while (punitario[i] <= 0);
    }


        char opc;
        int opcion;
        do
        {
            do
            {
                printf("\n=======MENU DE OPERACIONES=======\n");
                printf("SELECCIONE UNA OPCION:\n");
                printf("1. VENTA DE UNIDADES\n");
                printf("2. REABASTECER STOCK DEL PRODUCTO\n");
                printf("3. CONSULTAR INFORMACION DEL PRODUCTO\n");
                printf("4. CALCULO DE GANANCIAS OBTENIDAS HASTA EL MOMENTO\n");
                printf("SELECCIONE UNA OPCION:\n");
                scanf("%d", &opcion);
                if (opcion < 1 || opcion > 4)
                {
                    printf("SELECCIONE UNA OPCION VALIDA\n");
                }
            } while (opcion < 1 || opcion > 4);

            switch (opcion)
            {
                case 1:
                    printf("\n========BIENVENIDO AL MODULO DE VENTA DE UNIDADES=========\n");
                    printf("SELECCIONE EL PRODUCTO:\n");
                    for (int i = 0; i < nproductos; i++)
                    {
                        printf("%d. %s (STOCK: %d)\n", i, nombres[i], stock[i]);
                    }
                    do
                    {
                        printf("Ingrese una opcion: ");
                        scanf("%d", &opc1);

                        if (opc1 < 0 || opc1 >= nproductos)
                        {
                            printf("INGRESE UNA OPCION VALIDA\n");
                        }

                    } while (opc1 < 0 || opc1 >= nproductos);

                    do
                    {
                        printf("INGRESE LA CANTIDAD QUE SE DESEA COMPRAR:\n");
                        scanf("%d", &cant);

                        if (cant <= 0 || cant > stock[opc1])
                        {
                            printf("INGRESE UNA CANTIDAD VALIDA\n");
                        }

                    } while (cant <= 0 || cant > stock[opc1]);
                    stock[opc1] = calcularStock(stock[opc1], cant);
                    ptotal = calcularTotal(punitario[opc1], cant);
                    pfinal += ptotal;
                    cont1++;
                    printf("SU VENTA FUE REALIZADA CON EXITO\n");
                    printf("TOTAL: %.2f\n", ptotal);
                    printf("STOCK ACTUAL: %d\n", stock[opc1]);
                    break;
                case 2:
                    printf("=======\nBIENVENIDO AL MODULO DE REABASTECIMIENTO\n=======");
                    printf("\nSELECCIONE EL PRODUCTO QUE SE VA A REABASTECER:\n");
                    for (int i = 0; i < nproductos; i++)
                    {
                        printf("%d %s (STOCK ACTUAL: %d)\n", i, nombres[i], stock[i]);
                    }
                    do
                    {
                        printf("SELECCIONE UNA OPCION: \n");
                        scanf("%d", &opc2);
                        if (opc2 < 0 || opc2 >= nproductos)
                        {
                            printf("INGRESE UNA OPCION VALIDA\n");
                        }

                    } while (opc2 < 0 || opc2 >= nproductos);
                    do
                    {
                        printf("INGRESE LA CANTIDAD DE PRODUCTO QUE SE VA A REABASTECER\n");
                        scanf("%d", &nstock);
                        if (nstock<= 0)
                        {
                            printf("INGRESE UN STOCK VALIDO\n");
                        }

                    } while (nstock<= 0);
                    stock[opc2]= reabastecimiento(stock[opc2], nstock);

                    printf("EL NUEVO STOCK DEL PRODUCTO %s ES DE: %d \n", nombres[opc2], stock[opc2]);
                    break;
                case 3:
                    printf("========\nBIENVENIDO AL MODULO DE CONSULTA DE INFORMACION\n==========");
                    printf("LA INFORMACION ACTUAL DE LOS PRODUCTOS ES:\n");
                    for (int i = 0; i < nproductos; i++)
                    {
                        printf("%d. %s (STOCK ACTUAL: %d)\n", i, nombres[i], stock[i]);
                    }
                    break;
                case 4:
                    impresion(cont1, pfinal);
                    break;
            }
                printf("DESEA REALIZAR ALGUNA OTRA OPERACION? (S/N)");
                scanf(" %c", &opc);

        } while (opc == 's'|| opc=='S');

        printf("GRACIAS POR USAR NUESTRO SISTEMA\n");
    return 0;
}
void lectura (int i, char nombres[][100], char id[][100])
  {         
        printf("INGRESE EL NOMBRE DEL PRODUCTO N.%d \n", i+1);
        fgets(nombres[i], sizeof(nombres[i]), stdin);
        nombres[i][strcspn(nombres[i], "\n")] = 0;

        printf("INGRESE EL ID DEL PRODUCTO %s \n", nombres[i]);
        fgets(id[i], sizeof(id[i]), stdin);
        id[i][strcspn(id[i], "\n")] = 0;
        
  }

  int calcularStock(int stockActual, int cant){
    return stockActual - cant;

  }

  float calcularTotal(float precioUnitario, int cant){
    return precioUnitario * cant;

  }

  int reabastecimiento(int stock, int nstock){
    return stock + nstock;
  }

  void impresion(int cont1, float pfinal){
    printf("\n=======MODULO DE GANANCIAS FINALES==========\n");
    printf("SE REALIZAR %d VENTAS\n", cont1);
    printf("LAS GANANCIAS TOTALES FUERON DE %.2f\n", pfinal);

  }



