/******************************************************************************
                            Lagrange.
Este programa sirve para calcular la aproximacion a un punto usando el método
de Lagrange, se debe de tener a mano varios puntos tabulados y el valor real 
del punto evaluado para calcular el error.
*******************************************************************************/

#include<stdio.h>
#include<math.h>
#define MAX 100

int main()
{
    double x[MAX],y[MAX],s=1,t=1,k=0;
    double a, re, er;
    int n,i,j,op=0,d=1;

 do
   {   
    printf("\n ¿Cuántos puntos vas a introducir?: ");
    scanf("%d",&n);
    printf("\n Teclea las parejas de puntos X y Y separadas por un espacio: \n");
    
    for(i=0; i<n; i++)
    {
        scanf ("%lf",&x[i]);
        scanf ("%lf",&y[i]);
    }

    printf("\n Esta es la tabla de datos que has tecleado :\n\n");
    for(i=0; i<n; i++){
        printf("\t%f\t%f\n",x[i],y[i]);
    }

    printf("\n ¿En que punto \"x\" vas a aproximar con el polinomio?:  ");
    scanf("%lf",&a);      
    printf("\n ¿Cuál es el valor real de evaluar \"x\" en f(x)?: ");
    scanf("%lf",&re);

    for(i=0; i<n; i++){
        s=1;
        t=1;
        for(j=0; j<n; j++){
            if(j!=i){
                s = s * (a-x[j]);
                t = t * (x[i]-x[j]);
            }
        }
        
        k = k + ((s/t)*y[i]);
    }

    er=((re-k)/re)*100;
    printf("\n El valor obtenido en la interpolacion para %0.3f es: %lf",a,k);
    printf("\n El porcentaje de error es %lf\n\n", fabs(er));

    s=1,t=1,k=0,d=1;
	printf(" Para ejecutar de nuevo el programa presiona 1, para terminar presiona 0: ");
	scanf("%d", &op);
	printf("\n");

   } while(op==1); 
    
    return 0;
}

