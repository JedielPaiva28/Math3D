#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int i = 0, j = 0;
int MAIOR_VALOR(int *Vetor_A, int tam){
	int maior = 0;
	
	for(i=0; i < tam; i++){
		if(Vetor_A[i] > maior)
			maior = Vetor_A[i];
	}
	return maior;
} // Fim da Função MAIOR_VALOR

void COUNTING_SORT(int *A, int *B, int tam, int k){
	int C[k];  // Declaraçãodo vetor auxiliar
	
	for(i=0, i<=k; i++)
		C[i] = 0; // Preenchendo po vetor C com zero
	for(j=0, j<tam; j++) 
		C[A[j]] = C[A[j]] + 1;  //Contagem de cada elemento do intervalo
	for(i=1, i<=k; i++)
		C[i] = C[i] + C[i-1]; // Complemento de casas de cada valor
	for(j=tam-1, j>=0; j--){ // Alocação dos valores no vetor ordenado
		int c = C[A[j]];  //Recebe o valor do indice do vetor B
		B[c] = A[j];  // Recebe o valor que ficara no indice
		C[A[j]] = C[A[j]] - 1;  // Decrementando o valor do vetor C[A[j]]
	}
}  // Fim da funcao COUNTING_SORT

int main() {
	int k = 0, tam =0;
	int A[] = {2, 5, 3, 0, 2, 3, 0,5, 3, 0};
	tam = sizeof(A) / sizeof(int);  // Calculo do tamando do vetor
	k = MAIOR_VALOR(A,tam);  // Calculo do intervalo k
	printf("\nVetor A Desordenado:\n");
	for(i=0; i<tam; i++)
		printf("%d," , A[i]);
	int B[tam];  // Vetor ordenado
	COUNTING_SORT(A, B, tam, k);  //Chamada da função
	printf("\n\n\nVetor A Ordenado:\n");
	for(i=0; i<tam; i++){
		A[i] = B[i];
		printf("%d," , A[i]);
	}
	getchar();
	return 0;
}
