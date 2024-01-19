#include <stdio.h>
#include <stdlib.h>

typedef struct nod {
	int id;
	struct nod* urm;
}nod;

nod* rad = NULL;

nod* adauga(nod* lista, nod* aux)
{
	nod* q = lista;
	if (q == NULL) {
		lista = aux;
		return lista;
	}
	else {
		while (q->urm != NULL)
		{
			q = q->urm;
		}
		q->urm = aux;
	}
	return lista;
}

nod* citire(nod* lista)
{
	nod* aux;
	int i=1;
	while(i<101) {
		aux = (nod*)malloc(sizeof(nod));
		aux->urm = NULL;
		aux->id = i;
		lista = adauga(lista, aux);
		i++;
	}
	return lista;
}

void afisare(nod* lista) {
	nod* q = lista;
	while (q != NULL)
	{
		printf("nr crt %d: ", q->id);
		printf("%d \n", q->id);
		q = q->urm;
	}
	printf("\n");
}

int main(void)
{
	rad = citire(rad);
	afisare(rad);
	return 0;

}

