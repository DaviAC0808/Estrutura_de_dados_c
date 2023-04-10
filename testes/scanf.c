#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"Portuguese_Brazil");

    char s[10];
	
	printf("Digite algo (scanf convencional):\n");
	scanf("%s", s);
	fflush(stdin);
	
	printf("Resultado: %s\n\n", s);
	
	printf("Digite algo (scanf aprimorado):\n");
	scanf("%10[^\n]s", s);
	fflush(stdin);
	
	printf("Resultado: %s\n\n", s);

    printf("---------------\n");

    
	int i, n;

    printf("Quantos dados deseja inserir?\n");
    scanf("%d", &n);

    //n = n-1;
    
    int v[n];

	for(i=0;i<n;i++){
		printf("Insira um dado(%d de %d):\n",i,n);
		scanf("%d", &v[i]);
	}
	
	printf("Dados inseridos:\n");
	for(i=0;i<n;i++){
		printf("%d ", v[i]);
	}

}