#include <stdio.h> 
float punt, A[50][50], B[50][50];
int i, j, n, k, l;
char op;
void lee_mat();
void fil_punt();
void col_punt();
void ot();
void imp();
int main() 
{ 
	lee_mat();
	for ( i=0; i<n; i++) 
	{ 
		j=i;
		punt=A[i][j];
		B[i][j] =1/punt;
		fil_punt();
		col_punt();
		ot();
		for ( k=0; k<n; k++) 
			for ( l=0; l<n; l++)
				A[k][l] = B[k][l];
	} 
	imp();
}

void lee_mat() 
{
	printf ( "\n INVERSA DE UNA MATRIZ nxn\n\n\n" ); 
	printf ( " ¿Cual es la dimension de la Matriz? " );
	scanf ( "%d", &n ); 
	for ( i=0; i<n; i++)
		for ( j=0; j<n; j++) 
		{ 
			printf ( " Elemento A[%d][%d]: ", i+1, j+1 ); 
			scanf ( "%f", &A[i][j] ); 
		} 
}

void fil_punt()
{
	int m;
	for ( m=0; m<n; m++)
		if ( m != i ) 
			B[i][m]=A[i][m] / punt;
}

void col_punt()
{
	int m;
	for ( m=0; m<n; m++)
		if ( m != j ) 
			B[m][j] = -A[m][j] / punt;
}

void ot()
{
	int x, y;
	for ( x=0; x<n; x++) 
		for ( y=0; y<n; y++) 
			if ( x != i && y != j ) 
				B[x][y] = A[x][y] - (A[i][y]*A[x][j])/punt;
} 

void imp()
{
	printf ( "\n Matriz Inversa:\n " ); 
	for ( i=0; i<n; i++) 
	{ 
		for ( j=0; j<n; j++)
			printf ( "%f ", A[i][j] ); 
		printf ( "\n " ); 
	} 
}

