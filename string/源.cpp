#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#define size 131072
char string2[40], string3[20], path2[20];
void insert();
void merge();
void quick();
void heap();
void insertsort(char string[size][33], int *length);
void stringquicksort(char string[size][33], int *a, int p, int r);
int stringpartition(char string[size][33], int *a, int p, int r);
void mergesort(char string[size][33], int *a, int p, int r);
void merge(char string[size][33], int *a, int p, int q, int r);
void heapsort(char string[size][33], int *a);
void maxheapity(char string[size][33], int *a, int i, int heapsize);
void buildmaxheap(char string[size][33], int *a, int heapsize);
int stringsize = 4;
void main()
{
	while (stringsize <= 131072)
	{
		if (stringsize == 4)
		{
			strcpy(string2, "The time of the sort of 2:");
			strcpy(path2, "result_2.txt");
		}
		else if (stringsize == 32)
		{
			strcpy(string2, "The time of the sort of 5:");
			strcpy(path2, "result_5.txt");
		}
		else if (stringsize == 256)
		{
			strcpy(string2, "The time of the sort of 8:");
			strcpy(path2, "result_8.txt");
		}
		else if (stringsize == 2048)
		{
			strcpy(string2, "The time of the sort of 11:");
			strcpy(path2, "result_11.txt");
		}
		else if (stringsize == 16384)
		{
			strcpy(string2, "The time of the sort of 14:");
			strcpy(path2, "result_14.txt");
		}
		else if (stringsize == 131072)
		{
			strcpy(string2, "The time of the sort of 17:");
			strcpy(path2, "result_17.txt");
		}
		insert();
		merge();
		quick();
		heap();
		stringsize *= 8;
	}
}
void insert()
{
	FILE *fp;
	char  ch, string[size][33], path1[100] = { "../output/insertsort/" };
	int i, j;
	int p = 0;
	int length[size];
	if ((fp = fopen("../input/input.txt", "r")) == NULL)
	{
		printf("error");
		exit(0);
	}
	for (i = 0; i < stringsize; i++)
	{
		ch = fgetc(fp);
		j = 0;
		while (ch != '\n')
		{
			string[i][j] = ch;
			j++;
			ch = fgetc(fp);
		}
		string[i][j] = '\0';
	}
	for (i = 0; i < stringsize; i++)
		length[i] = strlen(string[i]);
	double f;
	LARGE_INTEGER start, fin, fre;
	QueryPerformanceFrequency(&fre);
	QueryPerformanceCounter(&start);//测量执行时间
	insertsort(string, length);
	QueryPerformanceCounter(&fin);
	f = (double)(fin.QuadPart - start.QuadPart) / (double)fre.QuadPart;
	printf("%f\n", f);
	strcat(path1, path2);
	if ((fp = fopen(path1, "w")) == NULL)
	{
		printf("error");
		exit(0);
	}
	for (i = 0; i < stringsize; i++)
	{
		fputs(string[i], fp);
		fputs("\n", fp);
	}
	fclose(fp);
	if ((fp = fopen("../output/insertsort/time.txt", "a")) == NULL)
	{
		fp = fopen("../output/insertsort/time.txt", "w");
	}
	fputs(string2, fp);
	sprintf(string3, "%lf", f);
	fputs(string3, fp);
	fputs("s\n", fp);
	fclose(fp);
}
void quick()
{
	FILE *fp;
	char  ch, string[size][33], path1[100] = { "../output/quicksort/" };
	int i, j;
	int p = 0;
	int length[size];
	if ((fp = fopen("../input/input.txt", "r")) == NULL)
	{
		printf("error");
		exit(0);
	}
	for (i = 0; i < stringsize; i++)
	{
		ch = fgetc(fp);
		j = 0;
		while (ch != '\n')
		{
			string[i][j] = ch;
			j++;
			ch = fgetc(fp);
		}
		string[i][j] = '\0';
	}
	for (i = 0; i < stringsize; i++)
		length[i] = strlen(string[i]);
	double f;
	LARGE_INTEGER start, fin, fre;
	QueryPerformanceFrequency(&fre);
	QueryPerformanceCounter(&start);
	stringquicksort(string, length, p, stringsize - 1);//quicksort
	QueryPerformanceCounter(&fin);
	f = (double)(fin.QuadPart - start.QuadPart) / (double)fre.QuadPart;
	printf("%f\n", f);
	strcat(path1, path2);
	if ((fp = fopen(path1, "w")) == NULL)
	{
		printf("error");
		exit(0);
	}
	for (i = 0; i < stringsize; i++)
	{
		fputs(string[i], fp);
		fputs("\n", fp);
	}
	fclose(fp);
	if ((fp = fopen("../output/quicksort/time.txt", "a")) == NULL)
	{
		fp = fopen("../output/quicksort/time.txt", "w");
	}
	fputs(string2, fp);
	sprintf(string3, "%lf", f);
	fputs(string3, fp);
	fputs("s\n", fp);
	fclose(fp);
}
void heap()
{
	FILE *fp;
	char  ch, string[size][33],path1[100] = { "../output/heapsort/" };
	int i, j;
	int p = 0;
	int length[size];
	if ((fp = fopen("../input/input.txt", "r")) == NULL)
	{
		printf("error");
		exit(0);
	}
	for (i = 0; i < stringsize; i++)
	{
		ch = fgetc(fp);
		j = 0;
		while (ch != '\n')
		{
			string[i][j] = ch;
			j++;
			ch = fgetc(fp);
		}
		string[i][j] = '\0';
	}
	for (i = 0; i < stringsize; i++)
		length[i] = strlen(string[i]);
	double f;
	LARGE_INTEGER start, fin, fre;
	QueryPerformanceFrequency(&fre);
	QueryPerformanceCounter(&start);
	heapsort(string, length);//heapsort
	QueryPerformanceCounter(&fin);
	f = (double)(fin.QuadPart - start.QuadPart) / (double)fre.QuadPart;
	printf("%f\n", f);
	strcat(path1, path2);
	if ((fp = fopen(path1, "w")) == NULL)
	{
		printf("error");
		exit(0);
	}
	for (i = 0; i < stringsize; i++)
	{
		fputs(string[i], fp);
		fputs("\n", fp);
	}
	fclose(fp);
	if ((fp = fopen("../output/heapsort/time.txt", "a")) == NULL)
	{
		fp = fopen("../output/heapsort/time.txt", "w");
	}
	fputs(string2, fp);
	sprintf(string3, "%lf", f);
	fputs(string3, fp);
	fputs("s\n", fp);
	fclose(fp);
}
void merge()
{
	FILE *fp;
	char  ch, string[size][33], path1[100] = { "../output/mergesort/" };
	int i, j;
	int p = 0;
	int length[size];
	if ((fp = fopen("../input/input.txt", "r")) == NULL)
	{
		printf("error");
		exit(0);
	}
	for (i = 0; i < stringsize; i++)
	{
		ch = fgetc(fp);
		j = 0;
		while (ch != '\n')
		{
			string[i][j] = ch;
			j++;
			ch = fgetc(fp);
		}
		string[i][j] = '\0';
	}
	for (i = 0; i < stringsize; i++)
		length[i] = strlen(string[i]);
	double f;
	LARGE_INTEGER start, fin, fre;
	QueryPerformanceFrequency(&fre);
	QueryPerformanceCounter(&start);
	mergesort(string, length, p, stringsize - 1);//mergesort
	QueryPerformanceCounter(&fin);
	f = (double)(fin.QuadPart - start.QuadPart) / (double)fre.QuadPart;
	printf("%f\n", f);
	strcat(path1, path2);
	if ((fp = fopen(path1, "w")) == NULL)
	{
		printf("error");
		exit(0);
	}
	for (i = 0; i < stringsize; i++)
	{
		fputs(string[i], fp);
		fputs("\n", fp);
	}
	fclose(fp);
	if ((fp = fopen("../output/mergesort/time.txt", "a")) == NULL)
	{
		fp = fopen("../output/mergesort/time.txt", "w");
	}
	fputs(string2, fp);
	sprintf(string3, "%lf", f);
	fputs(string3, fp);
	fputs("s\n", fp);
	fclose(fp);
}
void insertsort(char string[size][33], int *length)
{
	int i, j, x, result;
	char string1[33];
	for (j = 1; j < stringsize; j++)
	{
		x = length[j];
		strcpy(string1, string[j]);
		i = j - 1;
		while (i >= 0 && length[i] >= x)
		{
			if (length[i]>x)
			{
				length[i + 1] = length[i];
				strcpy(string[i + 1], string[i]);
				i--;
			}
			else if (length[i] == x)
			{
				result = strcmp(string1, string[i]);
				if (result >= 0)	break;
				else
				{
					length[i + 1] = length[i];
					strcpy(string[i + 1], string[i]);
					i--;
				}
			}
		}
		length[i + 1] = x;
		strcpy(string[i + 1], string1);
	}
}
void stringquicksort(char string[size][33], int *a, int p, int r)
{
	int q;
	if (p < r)
	{
		q = stringpartition(string, a, p, r);
		stringquicksort(string, a, p, q - 1);
		stringquicksort(string, a, q + 1, r);
	}
}
int stringpartition(char string[size][33], int *a, int p, int r)
{
	int i, j, b, result;
	char string1[33];
	i = p - 1;
	for (j = p; j < r; j++)
	{
		if (a[j] < a[r])
		{
			i++;
			b = a[j];
			a[j] = a[i];
			a[i] = b;
			strcpy(string1, string[i]);
			strcpy(string[i], string[j]);
			strcpy(string[j], string1);
		}
		else if (a[j] == a[r])
		{
			result = strcmp(string[r], string[j]);
			if (result >= 0)
			{
				i++;
				b = a[j];
				a[j] = a[i];
				a[i] = b;
				strcpy(string1, string[i]);
				strcpy(string[i], string[j]);
				strcpy(string[j], string1);
			}
		}
	}
	b = a[i + 1];
	a[i + 1] = a[r];
	a[r] = b;
	strcpy(string1, string[i + 1]);
	strcpy(string[i + 1], string[j]);
	strcpy(string[j], string1);
	return i + 1;
}
void mergesort(char string[size][33], int *a, int p, int r)
{
	int q;
	if (p < r)
	{
		q = (p + r) / 2;
		mergesort(string, a, p, q);
		mergesort(string, a, q + 1, r);
		merge(string, a, p, q, r);
	}
}
void merge(char string[size][33], int *a, int p, int q, int r)
{
	int m, n, i, j, k, result;
	m = q - p + 1;
	n = r - q;
	int *l = new int[m + 1];//开动态数组
	char **string1 = new char *[m];
	for (i = 0; i < m; i++)
		string1[i] = new char[33];
	int *r1 = new int[n + 1];
	char **string2 = new char *[n];
	for (i = 0; i < m; i++)
		string2[i] = new char[33];
	for (i = 0; i < m; i++)
	{
		l[i] = a[p + i];
		strcpy(string1[i], string[p + i]);
	}
	for (i = 0; i < n; i++)
	{
		r1[i] = a[q + i + 1];
		strcpy(string2[i], string[q + i + 1]);
	}
	l[m] = 33;
	r1[n] = 33;
	i = 0;
	j = 0;
	for (k = p; k <= r; k++)
	{
		if (l[i] < r1[j])
		{
			a[k] = l[i];
			strcpy(string[k], string1[i]);
			i++;
		}
		else if (l[i] == r1[j])
		{
			result = strcmp(string1[i], string2[j]);
			if (result <= 0)
			{
				a[k] = l[i];
				strcpy(string[k], string1[i]);
				i++;
			}
			else
			{
				a[k] = r1[j];
				strcpy(string[k], string2[j]);
				j++;
			}
		}
		else
		{
			a[k] = r1[j];
			strcpy(string[k], string2[j]);
			j++;
		}
	}
}
void heapsort(char string[size][33], int *a)
{
	int heapsize = stringsize, i, b;
	char string1[33];
	buildmaxheap(string, a, heapsize);
	for (i = stringsize - 1; i >= 1; i--)
	{
		b = a[i];
		a[i] = a[0];
		a[0] = b;
		strcpy(string1, string[i]);
		strcpy(string[i], string[0]);
		strcpy(string[0], string1);
		heapsize--;
		maxheapity(string, a, 0, heapsize);
	}
}
void maxheapity(char string[size][33], int *a, int i, int heapsize)
{
	int l, r, large, b, result;
	char string1[33];
	l = 2 * i + 1;
	r = 2 * i + 2;
	if (l<heapsize&&a[l]>a[i])
		large = l;
	else if (l < heapsize&&a[l] == a[i])
	{
		result = strcmp(string[l], string[i]);
		if (result>0) large = l;
		else large = i;
	}
	else large = i;
	if (r<heapsize&&a[r]>a[large])
		large = r;
	else if (r < heapsize&&a[r] == a[large])
	{
		result = strcmp(string[r], string[large]);
		if (result>0) large = r;
	}
	if (large != i)
	{
		b = a[i];
		a[i] = a[large];
		a[large] = b;
		strcpy(string1, string[i]);
		strcpy(string[i], string[large]);
		strcpy(string[large], string1);
		maxheapity(string, a, large, heapsize);
	}
}
void buildmaxheap(char string[size][33], int *a, int heapsize)
{
	int i;
	for (i = heapsize / 2; i >= 0; i--)
		maxheapity(string, a, i, heapsize);
}
