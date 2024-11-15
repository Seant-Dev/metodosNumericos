/******************************************************************************
                                GAUSS-JORDAN
	Se deben ingresar los coeficientes de la matriz aumentada
*******************************************************************************/

#include <stdio.h> 
int main() 
{
    int m, n, i, j, k;
    float  a[25][26], b[25][26], apoyo;
    printf ( "\n GAUSS-JORDAN");
    printf ( "\n Ingrese el numero de incognitas o numero de ecuaciones = " ); 
    scanf ( "%d", &n ); 

    printf ( "\n Ingrese coeficientes \n" );

    for ( i = 1; i <= n; i++) 
	{ 
	  printf ( "\n Fila %d", i ); 
	    for ( j = 1; j <= n+1; j++) 
		{ 
		  printf ( "\n Ingrese a(%d, %d): ", i, j );
		  scanf ( "%f", &a[i][j] ); 
		}
	} 
 m = n+1;
	do 
	{
	    if ( a[1][1] ==0 ) 
		{   
		  k=m-1;
		    for ( i = 2; i <= k; i++) 
			{ 
			    if ( a[i][1] !=0 ) 
				{   
				    for ( j = 1; j <= m; j++) 
					{ 
					  apoyo = a[i][j];
					  a[i][j] = a[1][j];
					  a[1][j] = apoyo;
					} 
				} 
			} 
		} 

	    else 
		{   
		    for ( j = 2; j <= m; j++) 
			{
			    for ( i = 2; i <= n; i++) 
				{ 
				  b[ i-1 ][ j-1] = a[ i ] [ j ] - a[ 1 ][ j ] * a[ i ] [ 1 ]/a[ 1 ] [ 1];
				} 
			}
		    for ( j = 2; j <= m; j++) 
			{ 
			  b[ n] [ j-1 ] = a[ 1 ][ j ]/a[ 1 ][ 1 ];
			} 
		m = m-1;
		    for ( j = 1; j <= m; j++) 
			{ 
			    for ( i = 1; i <= n; i++) 
				{ 
				  a[ i ][ j ] = b[ i ][ j ];
				} 
			} 
		} 
	}
	while ( m > 1 );
    printf ( "\n\n SOLUCION DEL SISTEMA\n" ); 
    for ( i = 1; i <= n; i++) 
	{ 
	  printf ( "\n X( %d ) = %1.4f ", i, a[ i ][ 1 ] ); 
	} 
    printf("\n\n");
}


