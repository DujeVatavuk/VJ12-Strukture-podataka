/*
Napisati program koji iz datoteke �ita dio teksta, rije� po rije� i unosi ih u red s prioritetom (maksimalna
duljina rije�i 1024 znaka, prioritet=1 => rije� po�inje samoglasnikom, prioritet=2 => rije� po�inje
suglasnikom;). Rije�i u redu moraju biti sortirane po prioritetu.
Iz tako kreiranog reda kreirati dvije datoteke, u prvoj �e se nalaziti rije�i sa prioritetom=1, a u drugoj rije�i
s prioritetom=2; s tim da su te rije�i u datoteci zapisane sortirane po abecedi.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct list *pos;
typedef struct list
{
	char rijec[1024];
	int prioritet;
	pos next;
}list;

void unosIzFilea(pos);
//void printList(pos);
void printListUFileove(pos);

int main()
{
	list head;
	head.next = NULL;

	unosIzFilea(&head);

	//printList(&head);

	printListUFileove(&head);

	return 0;
}

void unosIzFilea(pos P)
{
	FILE *dat;
	dat = fopen("Text.txt", "r");
	while (!feof(dat))
	{
		pos temp = (pos)malloc(sizeof(list));
		fscanf(dat, " %s", temp->rijec);
		switch (temp->rijec[0])
		{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			temp->prioritet = 1;
			break;
		default:
			temp->prioritet = 2;
			break;
		}
		temp->next = P->next;
		P->next = temp;
	}
	fclose(dat);
}

void printListUFileove(pos P)
{
	FILE *samoglasnik, *suglasnik;
	samoglasnik = fopen("samoglasnici.txt", "w");
	suglasnik = fopen("suglasnici.txt", "w");
	P = P->next;
	while (NULL != P)
	{
		if (1 == P->prioritet)
		{
			fprintf(samoglasnik, "\n%s", P->rijec);
		}
		else
		{
			fprintf(suglasnik, "\n%s", P->rijec);
		}
		P = P->next;
	}
	fclose(samoglasnik);
	fclose(suglasnik);
}

//void printList(pos P)
//{
//	P = P->next;
//	while (NULL != P)
//	{
//		printf("\n\t%s %d", P->rijec, P->prioritet);
//		P = P->next;
//	}
//}

