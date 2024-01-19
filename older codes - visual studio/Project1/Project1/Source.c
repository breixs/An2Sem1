#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int main() {
	char** s;
	int i, j;
	s = (char**)malloc(5 * sizeof(char*));
	for (i = 0; i < 5; i++)
		s[i] = (char*)malloc(2 * sizeof(char));
	for (i = 0; i < 5; i++)
	{	
	
		scanf("%s", s[i]);
	}
	for (i = 0; i < 5; i++)
		printf("%s ", s[i]);
	for (i = 0; i < 5; i++)
		free(s[i]);
	free(s);
}