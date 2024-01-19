#include<stdio.h>
#include<conio.h>

int main(void)
{
	int a, b, c;

	printf("nr1:");
	scanf("%d",&a);
	printf("nr2:");
	scanf("%d",&b);
	c = a * b;
	printf("rezultat: %d", c);
	getch();
	return 0;

}