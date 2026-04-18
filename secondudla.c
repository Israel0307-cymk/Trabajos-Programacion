#include <stdio.h>
#include <string.h>

#define nestudiantes 5
#define asignaturas 3

int main() {

    float calificaciones[nestudiantes][asignaturas];
    char nombre[nestudiantes][100];

    // INGRESO DE DATOS :)
    for (int i = 0; i < nestudiantes; i++) {
        printf("INGRESE EL NOMBRE DEL ESTUDIANTE:\n");
        fgets(nombre[i], sizeof(nombre[i]), stdin);
        nombre[i][strcspn(nombre[i], "\n")] = 0;

        for (int j = 0; j < asignaturas; j++) {
            do {
                printf("INGRESE LA CALIFICACION N. %d DEL ESTUDIANTE %s:\n", j+1, nombre[i]);
                scanf("%f", &calificaciones[i][j]);

                if (calificaciones[i][j] < 0 || calificaciones[i][j] > 10) {
                    printf("INGRESE UNA CALIFICACION VALIDA\n");
                }

            } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 10);
        }
        getchar();
    }

    // PROMEDIO POR ESTUDIANTE :)
    float promedioe[nestudiantes];
    for (int i = 0; i < nestudiantes; i++) {
        promedioe[i] = 0;
        for (int j = 0; j < asignaturas; j++) {
            promedioe[i] += calificaciones[i][j];
        }
        promedioe[i] /= asignaturas;
    }

    // PROMEDIO POR ASIGNATURA :)
    float promediom[asignaturas];
    for (int j = 0; j < asignaturas; j++) {
        promediom[j] = 0;
        for (int i = 0; i < nestudiantes; i++) {
            promediom[j] += calificaciones[i][j];
        }
        promediom[j] /= nestudiantes;
    }

    // MAYOR Y MENOR GLOBAL :)
    float max_nota = calificaciones[0][0];
    float min_nota = calificaciones[0][0];

    for (int i = 0; i < nestudiantes; i++) {
        for (int j = 0; j < asignaturas; j++) {
            if (calificaciones[i][j] > max_nota) {
                max_nota = calificaciones[i][j];
            }
            if (calificaciones[i][j] < min_nota) {
                min_nota = calificaciones[i][j];
            }
        }
    }

    // MAYOR Y MENOR POR ASIGNATURA :)
    float max_nasignatura[asignaturas];
    float min_nasignatura[asignaturas];

    for (int j = 0; j < asignaturas; j++) {
        max_nasignatura[j] = calificaciones[0][j];
        min_nasignatura[j] = calificaciones[0][j];

        for (int i = 0; i < nestudiantes; i++) {
            if (calificaciones[i][j] > max_nasignatura[j]) {
                max_nasignatura[j] = calificaciones[i][j];
            }
            if (calificaciones[i][j] < min_nasignatura[j]) {
                min_nasignatura[j] = calificaciones[i][j];
            }
        }
    }

    // MAYOR Y MENOR POR ESTUDIANTE :)
    float max_estudiante[nestudiantes];
    float min_estudiante[nestudiantes];

    for (int i = 0; i < nestudiantes; i++) {
        max_estudiante[i] = calificaciones[i][0];
        min_estudiante[i] = calificaciones[i][0];

        for (int j = 1; j < asignaturas; j++) {
            if (calificaciones[i][j] > max_estudiante[i]) {
                max_estudiante[i] = calificaciones[i][j];
            }
            if (calificaciones[i][j] < min_estudiante[i]) {
                min_estudiante[i] = calificaciones[i][j];
            }
        }
    }

    // APROBADOS Y REPROBADOS POR ASIGNATURA :)
    int aprobados[asignaturas];
    int reprobados[asignaturas];

    for (int j = 0; j < asignaturas; j++) {
        aprobados[j] = 0;
        reprobados[j] = 0;

        for (int i = 0; i < nestudiantes; i++) {
            if (calificaciones[i][j] >= 6) {
                aprobados[j]++;
            } else {
                reprobados[j]++;
            }
        }
    }



    printf("\n===== PROMEDIO POR ESTUDIANTE =====\n");
    for (int i = 0; i < nestudiantes; i++) {
        printf("%s: %.2f\n", nombre[i], promedioe[i]);
    }

    printf("\n===== PROMEDIO POR ASIGNATURA =====\n");
    for (int j = 0; j < asignaturas; j++) {
        printf("Asignatura %d: %.2f\n", j+1, promediom[j]);
    }

    printf("\n===== NOTA GLOBAL =====\n");
    printf("Mayor nota: %.2f\n", max_nota);
    printf("Menor nota: %.2f\n", min_nota);

    printf("\n===== NOTAS POR ASIGNATURA =====\n");
    for (int j = 0; j < asignaturas; j++) {
        printf("Asignatura %d:\n", j+1);
        printf("  Mayor: %.2f\n", max_nasignatura[j]);
        printf("  Menor: %.2f\n", min_nasignatura[j]);
    }

    printf("\n===== NOTAS POR ESTUDIANTE =====\n");
    for (int i = 0; i < nestudiantes; i++) {
        printf("%s:\n", nombre[i]);
        printf("  Mayor: %.2f\n", max_estudiante[i]);
        printf("  Menor: %.2f\n", min_estudiante[i]);
    }

    printf("\n===== APROBADOS / REPROBADOS =====\n");
    for (int j = 0; j < asignaturas; j++) {
        printf("Asignatura %d:\n", j+1);
        printf("  Aprobados: %d\n", aprobados[j]);
        printf("  Reprobados: %d\n", reprobados[j]);
    }

    return 0;
}