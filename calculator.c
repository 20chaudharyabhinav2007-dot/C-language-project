//Calculator to solve simultaneous equatins
#include<stdio.h>

int main ()
{
    int n;
    printf("Enter value of n: ");

    if (scanf("%d",&n) != 1)
    {
        printf("Invalid input!");
        return 0;
    }

    if(n > 4)
    {
        printf("Enter n less than or equal to 4");
        return 0;
    }
    if(n < 1)
    {
        printf("Syntax Error");
        return 0;
    }

    int A[n][n], B[n][1], i, j;
    float X[n][1];
    float determinant2=0, determinant3=0, determinant4=0;

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            printf("Initialising of the coefficient matrix:");
            scanf("%d",&A[i][j]);
        }

    printf("\nThe coefficient matrix is:");
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
            printf("%d\t",A[i][j]);
    }
    printf("\n");

    for(i=0;i<n;i++)
    {
        printf("Initialising of the constant matrix:");
        scanf("%d",&B[i][0]);
    }

    printf("\nThe constant matrix is:");
    for(i=0;i<n;i++)
        printf("\n%d\t", B[i][0]);

    if(n==1)
    {
        printf("\nDeterminant: %d", A[0][0]);
        X[0][0] = (float)B[0][0]/A[0][0];
    }
    else if(n==2)
    {
        determinant2 = A[0][0]*A[1][1]-A[0][1]*A[1][0];
        printf("\nDeterminant: %f", determinant2);

        if(determinant2 == 0)
        {
            printf("\nDeterminant is zero. No unique solution exists.");
            return 0;
        }

        float inv[2][2];
        inv[0][0] =  A[1][1]/determinant2;
        inv[0][1] = -A[0][1]/determinant2;
        inv[1][0] = -A[1][0]/determinant2;
        inv[1][1] =  A[0][0]/determinant2;

        for(i=0;i<2;i++)
        {
            X[i][0] = 0;
            for(j=0;j<2;j++)
                X[i][0] += inv[i][j]*B[j][0];
        }
    }
    else if(n==3)
    {
        for(i=0;i<3;i++)
            determinant3 += A[0][i]*(A[1][(i+1)%3]*A[2][(i+2)%3] - A[1][(i+2)%3]*A[2][(i+1)%3]);
        printf("\nDeterminant: %f", determinant3);

        if(determinant3 == 0)
        {
            printf("\nDeterminant is zero. No unique solution exists.");
            printf("\n\n\nAbhinav Chaudhary\nShamit Garg\nRajvansh Singh Chauhan\nSarthak Sharma");
            return 0;
        }

        int cof[3][3];
        cof[0][0] =  A[1][1]*A[2][2] - A[1][2]*A[2][1];
        cof[0][1] = -(A[1][0]*A[2][2] - A[1][2]*A[2][0]);
        cof[0][2] =  A[1][0]*A[2][1] - A[1][1]*A[2][0];

        cof[1][0] = -(A[0][1]*A[2][2] - A[0][2]*A[2][1]);
        cof[1][1] =  A[0][0]*A[2][2] - A[0][2]*A[2][0];
        cof[1][2] = -(A[0][0]*A[2][1] - A[0][1]*A[2][0]);

        cof[2][0] =  A[0][1]*A[1][2] - A[0][2]*A[1][1];
        cof[2][1] = -(A[0][0]*A[1][2] - A[0][2]*A[1][0]);
        cof[2][2] =  A[0][0]*A[1][1] - A[0][1]*A[1][0];

        float adj[3][3], inv[3][3];
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
            {
                adj[i][j] = cof[j][i];
                inv[i][j] = adj[i][j]/determinant3;
            }

        for(i=0;i<3;i++)
        {
            X[i][0] = 0;
            for(j=0;j<3;j++)
                X[i][0] += inv[i][j]*B[j][0];
        }
    }
    else if(n==4)
    {
        determinant4 = A[0][0]*( A[1][1]*(A[2][2]*A[3][3]-A[2][3]*A[3][2])
                                -A[1][2]*(A[2][1]*A[3][3]-A[2][3]*A[3][1])
                                +A[1][3]*(A[2][1]*A[3][2]-A[2][2]*A[3][1]))
                     -A[0][1]*( A[1][0]*(A[2][2]*A[3][3]-A[2][3]*A[3][2])
                                -A[1][2]*(A[2][0]*A[3][3]-A[2][3]*A[3][0])
                                +A[1][3]*(A[2][0]*A[3][2]-A[2][2]*A[3][0]))
                     +A[0][2]*( A[1][0]*(A[2][1]*A[3][3]-A[2][3]*A[3][1])
                                -A[1][1]*(A[2][0]*A[3][3]-A[2][3]*A[3][0])
                                +A[1][3]*(A[2][0]*A[3][1]-A[2][1]*A[3][0]))
                     -A[0][3]*( A[1][0]*(A[2][1]*A[3][2]-A[2][2]*A[3][1])
                                -A[1][1]*(A[2][0]*A[3][2]-A[2][2]*A[3][0])
                                +A[1][2]*(A[2][0]*A[3][1]-A[2][1]*A[3][0]));

        printf("\nDeterminant: %f", determinant4);

        if(determinant4 == 0)
        {
            printf("\nDeterminant is zero. No unique solution exists.");
            return 0;
        }

        int cof[4][4];
        float adj[4][4], inv[4][4];

        cof[0][0] =  (A[1][1]*(A[2][2]*A[3][3]-A[2][3]*A[3][2]) - A[1][2]*(A[2][1]*A[3][3]-A[2][3]*A[3][1]) + A[1][3]*(A[2][1]*A[3][2]-A[2][2]*A[3][1]));
        cof[0][1] = -(A[1][0]*(A[2][2]*A[3][3]-A[2][3]*A[3][2]) - A[1][2]*(A[2][0]*A[3][3]-A[2][3]*A[3][0]) + A[1][3]*(A[2][0]*A[3][2]-A[2][2]*A[3][0]));
        cof[0][2] =  (A[1][0]*(A[2][1]*A[3][3]-A[2][3]*A[3][1]) - A[1][1]*(A[2][0]*A[3][3]-A[2][3]*A[3][0]) + A[1][3]*(A[2][0]*A[3][1]-A[2][1]*A[3][0]));
        cof[0][3] = -(A[1][0]*(A[2][1]*A[3][2]-A[2][2]*A[3][1]) - A[1][1]*(A[2][0]*A[3][2]-A[2][2]*A[3][0]) + A[1][2]*(A[2][0]*A[3][1]-A[2][1]*A[3][0]));

        cof[1][0] = -(A[0][1]*(A[2][2]*A[3][3]-A[2][3]*A[3][2]) - A[0][2]*(A[2][1]*A[3][3]-A[2][3]*A[3][1]) + A[0][3]*(A[2][1]*A[3][2]-A[2][2]*A[3][1]));
        cof[1][1] =  (A[0][0]*(A[2][2]*A[3][3]-A[2][3]*A[3][2]) - A[0][2]*(A[2][0]*A[3][3]-A[2][3]*A[3][0]) + A[0][3]*(A[2][0]*A[3][2]-A[2][2]*A[3][0]));
        cof[1][2] = -(A[0][0]*(A[2][1]*A[3][3]-A[2][3]*A[3][1]) - A[0][1]*(A[2][0]*A[3][3]-A[2][3]*A[3][0]) + A[0][3]*(A[2][0]*A[3][1]-A[2][1]*A[3][0]));
        cof[1][3] =  (A[0][0]*(A[2][1]*A[3][2]-A[2][2]*A[3][1]) - A[0][1]*(A[2][0]*A[3][2]-A[2][2]*A[3][0]) + A[0][2]*(A[2][0]*A[3][1]-A[2][1]*A[3][0]));

        cof[2][0] =  (A[0][1]*(A[1][2]*A[3][3]-A[1][3]*A[3][2]) - A[0][2]*(A[1][1]*A[3][3]-A[1][3]*A[3][1]) + A[0][3]*(A[1][1]*A[3][2]-A[1][2]*A[3][1]));
        cof[2][1] = -(A[0][0]*(A[1][2]*A[3][3]-A[1][3]*A[3][2]) - A[0][2]*(A[1][0]*A[3][3]-A[1][3]*A[3][0]) + A[0][3]*(A[1][0]*A[3][2]-A[1][2]*A[3][0]));
        cof[2][2] =  (A[0][0]*(A[1][1]*A[3][3]-A[1][3]*A[3][1]) - A[0][1]*(A[1][0]*A[3][3]-A[1][3]*A[3][0]) + A[0][3]*(A[1][0]*A[3][1]-A[1][1]*A[3][0]));
        cof[2][3] = -(A[0][0]*(A[1][1]*A[3][2]-A[1][2]*A[3][1]) - A[0][1]*(A[1][0]*A[3][2]-A[1][2]*A[3][0]) + A[0][2]*(A[1][0]*A[3][1]-A[1][1]*A[3][0]));

        cof[3][0] = -(A[0][1]*(A[1][2]*A[2][3]-A[1][3]*A[2][2]) - A[0][2]*(A[1][1]*A[2][3]-A[1][3]*A[2][1]) + A[0][3]*(A[1][1]*A[2][2]-A[1][2]*A[2][1]));
        cof[3][1] =  (A[0][0]*(A[1][2]*A[2][3]-A[1][3]*A[2][2]) - A[0][2]*(A[1][0]*A[2][3]-A[1][3]*A[2][0]) + A[0][3]*(A[1][0]*A[2][2]-A[1][2]*A[2][0]));
        cof[3][2] = -(A[0][0]*(A[1][1]*A[2][3]-A[1][3]*A[2][1]) - A[0][1]*(A[1][0]*A[2][3]-A[1][3]*A[2][0]) + A[0][3]*(A[1][0]*A[2][1]-A[1][1]*A[2][0]));
        cof[3][3] =  (A[0][0]*(A[1][1]*A[2][2]-A[1][2]*A[2][1]) - A[0][1]*(A[1][0]*A[2][2]-A[1][2]*A[2][0]) + A[0][2]*(A[1][0]*A[2][1]-A[1][1]*A[2][0]));

        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
            {
                adj[i][j] = cof[j][i];
                inv[i][j] = adj[i][j]/determinant4;
            }

        for(i=0;i<4;i++)
        {
            X[i][0] = 0;
            for(j=0;j<4;j++)
                X[i][0] += inv[i][j]*B[j][0];
        }
    }

    if(n<=4)
    {
        printf("\nResultant Matrix:");
        for(i=0;i<n;i++)
            printf("\n\t%f", X[i][0]);
    }
    if(n==2)
    {
    printf("\nValues of the variables:%d\t%d",
    (A[1][1]*B[0][0]-A[0][1]*B[1][0])/(A[1][1]*A[0][0]-A[1][0]*A[0][1]),
    (A[0][0]*B[1][0]-A[1][0]*B[0][0])/(A[0][0]*A[1][1]-A[1][0]*A[0][1])
    );
    }
    if(n==0)
    printf("\nSyntax Error");
    if(n==1)
    {
    printf("%d",A[0][0]);
    }
    printf("\n\n\nAbhinav Chaudhary\nShamit Garg\nRajvansh Singh Chauhan\nSarthak Sharma\nManit Chandla");
    return 0;
}
