#include<stdio.h>
#include<math.h>
//#define e 0.001
int main()
    {
        int i,j,k,n;
        double a[10][10],x[10];
        double sum,temp,error,big;
        float e;
        printf("Introduce el numero de ecuaciones: ");
        scanf("%d",&n) ;
        printf("Introduce el valor de epsilon: ");
        scanf("%f",&e) ;
        printf("Introduce los coeficientes de las ecuaciones: \n");

                for(i=1;i<=n;i++)
                    {
                        for(j=1;j<=n+1;j++)
                            {
                                printf("a[%d][%d] = ",i,j);
                                scanf("%lf",&a[i][j]);
                            }
                    }

                for(i=1;i<=n;i++)
                    {
                        x[i]=0;
                    }
               do
               {
                        big=0;
                        for(i=1;i<=n;i++)
                            {
                                sum=0;

                        for(j=1;j<=n;j++)
                            {

                                if(j!=i)
                                    {
                                        sum=sum+a[i][j]*x[j];
                                    }
                            }

                    temp=(a[i][n+1]-sum)/a[i][i];
                    error=fabs(x[i]-temp);
                        if(error>big)
                            {
                                big=error;
                            }
                            x[i]=temp;
                            printf("\nx[%d] =%lf",i,x[i]);
                        }
                        printf("\n");
                 }while(big>=e);
                  printf("\n\n Converge en la solucion");

for(i=1;i<=n;i++)

{

printf("\nx[%d]=%lf",i,x[i]);

}
return 0;
}
