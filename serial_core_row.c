#include <stdio.h>
#include <stdlib.h>

int main()
{
    double **a = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++)
        a[i] = (double *)malloc(n+1 * sizeof(double));

    // Randomly generate augmented matrix
    for(int i=0; i<n; i++)
        for(int j=0; j<n+1; j++)
            a[i][j] = rand() % 10000;

    // Row reduction
    for(int i=0; i<n-1; i++)
    {
        double div = a[i][i];
        for(int j=i+1; j<n; j++)
        {
            // double ratio = a[j][i]/a[i][i];
            double ratio = a[j][i]/div;
            for(int k=i; k<n+1; k++)
                a[j][k] -= ratio * a[i][k];
        }
    }

    // Back substitution
    for(int i=n-1; i>=0; i--)
    {
        double sum = 0;
        for(int j=i+1; j<n; j++)
        {
            // a[i][n] -= a[i][j] * a[j][n];
            sum += a[i][j] * a[j][n];
        }
        a[i][n] -= sum;
        a[i][n] /= a[i][i];
    }
}