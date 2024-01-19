#include <stdio.h>
#include <stdlib.h>

typedef struct nod {
	int id;
	struct nod* urm;
}nod;

nod* rad = NULL;
//adaugare in capul listei
/*nod* adauga(nod* lista, nod* aux)
{
	aux->urm = lista;
	lista = aux;
	return lista;
}*/

//adaugare la finalul listei
nod* adauga(nod* lista, nod* aux)
{
	nod* q = lista;
	if(q == NULL){
		lista = aux;
		return lista;
	}
	else {
		while (q->urm != NULL)
		{
			q = q->urm;
		}
		q->urm = aux;
		//lista = aux;
	}
	return lista;
}

nod* citire(nod* lista)
{
	FILE* f;
	nod* aux;
	if ((f = fopen("m1.txt", "r")) == NULL)
	{
		printf("nu s-a citit fisierul");
		return lista;
	}
	while (!feof(f))
	{
		aux = (nod*)malloc(sizeof(nod));
		aux->urm = NULL;
		fscanf(f, "%d", &aux->id);
		lista = adauga(lista, aux);
	}
	fclose(f);
	return lista;
}

nod* sterge(nod* lista, int id)
{
	nod* q1, *q2;
	for (q1 = q2 = lista; q1 != NULL && q1->id != id; q2 = q1, q1 = q1->urm);
	if (q1 == NULL)
		return lista;
	if (q1 == q2) {
		lista = lista->urm;
	}
	else
	{
		q2->urm = q1->urm;
	}
	free(q1);
	return lista;
}

void afisare(nod* lista) {
	nod* q = lista;
	while (q!=NULL)
	{
		printf("%d ", q->id);
		q = q->urm;
	}
	printf("\n");
}

int main(void)
{
	rad = citire(rad);
	afisare(rad);
	rad = sterge(rad, 34);
	printf("\n");
	afisare(rad);
}

