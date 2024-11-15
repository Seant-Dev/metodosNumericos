#include <stdio.h>
#include <math.h>

float newton (int n, float *x, float *y, float valInterpolado);

int main() {
    int i, n = 0;
    printf ("Cual es el grado del polinomio: ");
    scanf ("%i", &n);
    float val1 [n];
    float val2 [n], x, fx, res;
    printf ("Ingresa los valores de los puntos que componen al polinomio: \n\n");
    for (i = 0; i < n+1; i++){
        scanf ("%f", &val1 [i]);
        scanf ("%f", &val2 [i]);
    }
    printf ("\nIngrese el valor que desea interpolar: ");
    scanf ("%f", &x);
    printf ("Ingrese el valor de f(%f): ", x);
    scanf ("%f", &fx);
    
    //se calcula el polinomio de newton
    res = newton (n, val1, val2, x);
    
    printf ("\nEl resultado de la intepolacion es: %f", res);
    printf ("\nEl porcentaje de error es: %f\n", fabs((fx-res)/fx*100));
}

float newton (int n, float *x, float *y, float valInterpolado){
    int i, j;
    
    float tabla [n+1][n+1];
    float valX;
    float valY;
    
    for  (i = 0; i < n+1; i++){
        tabla [i][0] = y[i];
    }
    
    for (j = 1; j <= n; j++){
        for (i = 0; i <= n-j; i++){
            tabla [i][j] = (tabla [i+1][j-1] - tabla [i][j-1])/ (x [i+j] - x[i]);
        }
    }
    
    valX = 1;
    valY = tabla [0][0];
    for (i = 0; i < n; i++){
        valX = valX * (valInterpolado - x[i]);
        valY = valY + tabla [0][i+1] * valX;
    }
    return valY;
}
