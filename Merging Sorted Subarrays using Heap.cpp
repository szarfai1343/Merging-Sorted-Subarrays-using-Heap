#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;
void merge(int arr1[], int arr2[], int n1, int n2, int arr3[]) //scalanie podtablic
{
	int a=0, b=0;
	int i=0;
	int j;
	while(a<n1 && b < n2)
	{
		if(arr1[a]<=arr2[b])
		{
			arr3[i++] = arr1[a++];
		}
		else
		{
			arr3[i++] = arr2[b++];
		}
	}
	if(a<n1)
	{
		for(j=a; j<n1; j++)
		{
			arr3[i++] = arr1[j];
		}
	}
	else
	{
		for(j=b; j<n2; j++)
		{
			arr3[i++]=arr2[j];
		}
	}
}
void swap(int *a, int *b)	//funkcja swap
{
    int tmp = *a;
      *a = *b;
      *b = tmp;
}
void kopiec(int tab[], int Z, int i) //down-heap funkcja do budowy kopca
{
int root = i;
int l = 2*i+1;
int r = 2*i+2;
if(l<Z && tab[l] > tab[root]) root=l;
if(r<Z && tab[r] > tab[root]) root=r;
if(root!=i) 
	{
		swap(&tab[i], &tab[root]);
		kopiec(tab, Z, root);
	}
}

void heapsort(int tab[], int Z) //sortowanie przez kopcowanie
{
int start=(Z/2)-1;
int i;
for(i=start; i>=0; i--)
	{
		kopiec(tab, Z, i);
	}
for (int i=Z-1; i>0; i--) {
    swap(&tab[0], &tab[i]);
    kopiec(tab, i, 0);	
}
}

void display(int tab[], int n) //wy¶wietlanie tablic
{
int i;
for(i=0; i<n; i++)
	{
	printf("%d,",tab[i]);
	}
printf("\n");
}
void pes(int n, int tab[]) //przypadek pesymistyczny
{
int i;
	for(i=0; i<n; i++)
	{
	tab[i]=i;
	}
}
void opt(int n, int tab[]) //przypadek optymistyczny
{
int i;
	for(i=0; i<n; ++i)
	{
	tab[i]=1;
	}
}
void gen(int n, int tab[])	//przypadek losowy
{
int i;
srand(time(0));
	for(i=0; i<n; ++i)
	{
	tab[i]=0 + rand() % 20;
	}
}
void disheap(int tab[], int Z) //wy¶wietlanie kopca
{
int i;
	for(i=0; i<Z; i++) printf("%d,",tab[i]);
printf("\n");
}

main()
{
int l_prob=10;
int n, i, a, b, c;
double avg;
double dev;
double czas;
clock_t start, finish;
printf("Podaj rozmiar tablicy\n");
scanf("%d", &n);
int *tab, *pod1, *pod2;
tab = new int [n];
int przypadek;
printf("Podaj przypadek w jaki tablica ma zostac zaimplementowana 1:optymistyczny 2:pesymistyczny default:losowy\n");
scanf("%d", &przypadek);
int x=(n%2==0)? n/2:floor(n/2);
//printf("%d",x);
//int pod1[x];
//int pod2[x + n%2];
pod1 = new int [x];
pod2 = new int [x+n%2];
a=x;
b=x+n%2;
switch(przypadek)
{
	case 1:
		printf("Wybrano przypadek optymistyczny\n");
		opt(n,tab);
		break;
	case 2:
		printf("Wybrano przypadek pesymistyczny\n");
		pes(n,tab);
		break;
	default:
		printf("Wybrano przypadek losowy\n");
		gen(n,tab);
		break;
}
for(c=0; c<l_prob; c++)
{
//podzia³ na dwie podtablice
start=clock();
int j=b;
for(i=0; i<n; i++)
	{
		if(i<x) pod1[i]=tab[i];
		else pod2[i-x]=tab[i];
	}
//wy¶wietlanie	

//display(tab,n);
//display(pod1, a);
//display(pod2, b);
heapsort(pod1, a);
//disheap(pod1, a);
heapsort(pod2, b);
//disheap(pod2, b);

merge(pod1,pod2, a, b, tab);
//display(tab, n);
finish=clock();
czas=(double(finish-start))/CLOCKS_PER_SEC;
avg+=czas;
printf("Czas trwania algorytmu:%f s\n",czas);
}
avg=avg/10;
printf("Sredni czas trwania algorytmu:%f s\n",avg);	
	
	
	
	
	
	
}
//generacja losowego
/*
srand(time(0));
	for(i=0; i<n; i++)
	{
	tab[i]=0 + rand() % 20;
	}
*/
