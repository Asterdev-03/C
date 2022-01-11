#include<stdio.h>
#include<math.h>
float determinant(float [25][25], float);
void cofactor(float [25][25], float, float);
void transpose(float [25][25], float, float);
void minorMat(float[25][25], float[25][25], float, int, int);
int main() {
    float mat[25][25], order, det;
    printf("Enter the order of the Matrix : ");
    scanf("%f", &order);
    printf("Enter the elements of %.0fX%.0f Matrix : \n", order, order);
    for (int i = 0;i < order; i++)       
        for (int j = 0;j < order; j++)       
            scanf("%f", &mat[i][j]);
    det = determinant(mat, order);
    if (det == 0)
        printf("\nInverse of Entered Matrix is not possible\n");
    else
        cofactor(mat, order, det);
}
float determinant(float mat[25][25], float order) {
    float s = 1, det = 0, minor[25][25];
    if (order == 1)        
        return (mat[0][0]);        
    else
        for (int i = 0; i < order; i++) {
            minorMat(mat, *minor, order, i,0);
            det += s * (mat[0][i] * determinant(minor, order - 1));
            s = -1 * s;
        }
    return det;
}

void minorMat(float mat[25][25],float minor[25][25], float order, int row, int col) {

    int m = 0, n = 0;
    for (int i = 0;i < order; i++)
        for (int j = 0 ;j < order; j++) {
            if (i != col && j != row) {
                minor[m][n] = mat[i][j];
                if (n < (order - 2))
                    n++;
                else {
                    n = 0;
                    m++;
                }
            }
        }
}

void cofactor(float mat[25][25], float order, float det) {
    float minor[25][25], cofac[25][25];
    for (int i = 0;i < order; i++)
        for (int j = 0;j < order; j++) {
            minorMat(mat, *minor, order, j, i);
            cofac[i][j] = pow(-1, i + j) * determinant(minor, order - 1);
        }    
    transpose(cofac, order, det);
}
void transpose(float fac[25][25], float r, float det)
{
    int i, j;
    float adjoint[25][25], inverse[25][25];
    for (i = 0;i < r; i++)        
        for (j = 0;j < r; j++)        
            adjoint[i][j] = fac[j][i];
    for (i = 0;i < r; i++)       
        for (j = 0;j < r; j++)       
            inverse[i][j] = adjoint[i][j] / det;
    printf("The inverse of matrix is :\n");
    for (i = 0;i < r; i++) {
        for (j = 0;j < r; j++)        
            printf("%f ", inverse[i][j]);           
        printf("\n");
    }
}
