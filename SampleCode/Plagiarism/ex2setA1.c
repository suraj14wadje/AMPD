#include<stdio.h>
void accept (int a[], int n);
void merge (int a[], int l, int m, int u);
void display (int a[], int n);
void mergesort (int a[], int l, int u);
int
main ()
{
  int a[100], n;
  printf ("\nEnter the amount of numbers:");
  scanf("%d", &n);
  accept (a, n);
  display (a, n);
  printf ("\nSorted data using merge sort algorithm:\n");
  mergesort (a, 0, n - 1);
  display (a, n);
}

void
accept (int a[], int n)
{
  int i;
  for (i = 0; i < n; i++)
    {
      a[i] = rand () % 1000;
    }
}

void
merge (int a[], int l, int m, int u)
{
  int i, j, k, c[100];
  i = l;
  j = m + 1;
  k = 0;
  while (i <= m && j <= u)
    {
      if (a[i] < a[j])
	{
	  c[k] = a[i];
	  i++;
	}
      else
	{
	  c[k] = a[j];
	  j++;
	}
      k++;
    }
  while (i <= m)
    {
      c[k] = a[i];
      i++;
      k++;
    }
  while (j <= u)
    {
      c[k] = a[j];
      j++;
      k++;
    }
  for (i = l, j = 0; i <= u; i++, j++)
    {
      a[i] = c[j];
    }
}

void
display (int a[], int n)
{
  int i;
  for (i = 0; i < n; i++)
    {
      printf ("%d\t", a[i]);
    }
  if (i == n)
    {
      printf ("\n");
      printf ("\n");
    }
}
void
mergesort (int a[], int l, int u)
{
  int m;
  if (l < u)
    {
      m = ((l + u) / 2);
      mergesort (a, l, m);
      mergesort (a, m + 1, u);
      merge (a, l, m, u);
    }
}

/*Output
Enter the numbers:5
3       6       7       5       3


Sorted data using merge sort:
3       3       5       6       7



Enter the numbers:10
3       6       7       5       3       5       6       2       9       1


Sorted data using merge sort:
1       2       3       3       5       5       6       6       7       9

*/
