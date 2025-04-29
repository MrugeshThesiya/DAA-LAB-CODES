#include <stdio.h>
#include <limits.h>

float power(float base, int exponent)
{
  float ans = 1;
  for (int i = 1; i <= exponent; i++)
  {
    ans = ans * base;
  }
  return ans;
}

void merge(float *a, int l, int m, int r)
{
  int n1 = m - l + 1;
  int n2 = r - m;

  float L[n1 + 1];
  float R[n2 + 1];

  for (int i = 0; i < n1; i++)
  {
    L[i] = a[l + i];
  }

  L[n1] = 0;

  for (int j = 0; j < n2; j++)
  {
    R[j] = a[m + 1 + j];
  }

  R[n2] = 0;

  int i = 0, j = 0, k = l;
  while (k <= r)
  {

    if (L[i] > R[j])
    {

      a[k++] = L[i++];
    }
    else
    {

      a[k++] = R[j++];
    }
  }
}

void mergeSort(float *a, int l, int r)
{
  if (l < r)
  {
    int m = (l + r) / 2;

    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);

    merge(a, l, m, r);
  }
}

float calcCost(float *r, int n)
{
  mergeSort(r, 0, n - 1);

  float cost = 0;

  for (int i = 0; i < n; i++)
  {
    printf("%.2f ", r[i]);
    cost = cost + 100 * power(r[i], i + 1);
  }
  return cost;
}

int main()
{
  float r[] = {1.1, 1.3, 1.5, 1.6, 0.7, 0.9};
  int size = sizeof(r) / sizeof(r[0]);

  float total_cost = calcCost(r, size);

  printf("\nThe total cost is %.2f.", total_cost);

  return 0;
}
