#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define MAX 100

// Função para particionar o vetor
int particionar(int v[], int inicio, int fim) {
    int pivo = v[fim];
    int i = inicio - 1; 
    int j, aux;
    
    for (j = inicio; j < fim; j++) {
        if (v[j] <= pivo) {
           i++;    
           aux = v[i]; 
           v[i] = v[j]; 
           v[j] = aux;
        }
    } // O loop for termina aqui!
    
    // O pivô é colocado na sua posição final correta após o término do loop
    aux = v[i + 1]; 
    v[i + 1] = v[fim]; 
    v[fim] = aux;
    return i + 1;
}

void quickSort(int v[], int n) {
    int pilhainicio[MAX];
    int pilhaFIM[MAX]; 
    int topo = -1; 
    int inicio, fim, p;
    
    topo++; 
    pilhainicio[topo] = 0; 
    pilhaFIM[topo] = n - 1;
    
    while (topo >= 0) {
        inicio = pilhainicio[topo];
        fim = pilhaFIM[topo];
        topo--;
        
        p = particionar(v, inicio, fim);
        
        if (inicio < p - 1) {
            topo++;
            pilhainicio[topo] = inicio;
            pilhaFIM[topo] = p - 1;
        }
        if (p + 1 < fim) {
            topo++;
            pilhainicio[topo] = p + 1;
            pilhaFIM[topo] = fim;
        }
    }
}

int main() {
    int v[MAX];
    int n, i;
    
    printf("Digite a quantidade de elementos: ");
    scanf("%d", &n);
    
    if (n < 1 || n > MAX) {
        printf("Quantidade inválida!\n");
        return 1;
    }
    
    printf("Digite os elementos:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    
    quickSort(v, n);
    
    printf("Elementos ordenados:\n"); 
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);     
    }
    printf("\n");
    
    return 0;
}