#include<stdio.h>
#include<stdlib.h>
void generate (int *a, int n);
void display (int *a, int n);
void mergesort(int *a,int low,int high);
void merge (int a[], int low, int mid, int high);
int a[20];

int main ()
{
  int n,x;
  printf ("\nEnter value of n:");
  scanf ("%d", &n);
  generate (a, n);
  display (a, n);
  mergesort (a, 0, n - 1);
  printf("\nMerge Sorted List:");
  display (a,n);
  return 0;
}

void generate (int a[], int n)
{
  int i;
  srand (time (NULL));
  for (i = 0; i < n; i++)
    {
     a[i] = rand () % 100;
    }
}

void display (int a[], int n)
{
  int i;
  printf ("\n");
  for (i = 0; i < n; i++)
    {
      printf ("\t %d", a[i]);
    }
}

void mergesort (int a[], int low, int high)
{
  int mid;
  if (low < high)
    {
      mid = (low + high) / 2;
      mergesort (a, low, mid);
      mergesort (a, mid + 1, high);
      merge (a, low, mid, high);
    }
}

void merge(int a[], int low, int mid, int high)
{
  int i, j, k = 0;
  int b[20];
  i = low;
  j = mid + 1;
  while (i <= mid && j <= high)
    {
      if (a[i] < a[j])
	{
	  b[k] = a[i];
	  k++;
	  i++;
	}
      else
	{
	  b[k] = a[j];
	  k++;
	  j++;
	}
    }
  while (i <= mid)
    {
      b[k] = a[i];
      k++;
      i++;
    }
  while (j <= high)
    {
      b[k] = a[j];
      k++;
      j++;
    }
  for (i = low, j = 0; i <= high; i++, j++)
    {
      a[i] = b[j];
    }
}
