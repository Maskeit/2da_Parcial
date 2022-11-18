#include<stdio.h>
#include<stdlib.h>

int A[6];
int list[] = {9,8,7,6,5};

void leer_archivo(){
  FILE* archivo;
  char texto[20];
  char c;
  int i=0;
  int j=0;

  archivo = fopen("datos.txt","rt");
  do{
    c = fgetc(archivo);
    if(c == ','){
      A[j] = atoi(texto);
      j++;
      for(int z=0; z<i; z++)
              texto[z]=0;
      i=0;
      continue;
    }
    texto[i] = c;
    i++;
  }while(c != EOF); //EOF End Of File
}

void pantalla(int A[], int n){
  for(int i=0; i<n-1; i++)
        printf("%d, ", A[i]);
  printf("%d", A[n-1]);
}
///
void intercambio(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void exchange(int A[], int n){
	for(int i = 1; i<=n-1; i++){
	 int min = i;
		for( int j=i+1; j<=n; j++ )
			if(A[j] < A[min]){
			intercambio(&A[j],&A[min]);	
			}
	}
}


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void main(){
	int n = 6;
	leer_archivo();
	printf("\nValores antes de ordenarse: ");
	pantalla(A, n);
	//aplicamos la funcion
	exchange(A,n);
	printf("\n\nVALORES ordenados: ");
	pantalla(A, n);
	printf("\n\n");

}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
