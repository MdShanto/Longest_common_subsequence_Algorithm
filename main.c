#include <stdio.h>
#include <string.h>
#define MAX 100


int i,j,m,n,LCS[MAX][MAX];
char A[MAX],B[MAX],b[MAX][MAX];

void PRINT_LCS(int i,int j)
{
                if(i==0 || j==0)
                {
                  return;
                }
                if(b[i][j]=='a')
                {
                   PRINT_LCS(i-1,j-1);
                   printf("%c",A[i-1]);
                }
                else if(b[i][j]=='b')
                {
                    PRINT_LCS(i-1,j);
                }
                else
                {
                    PRINT_LCS(i,j-1);
                }

}

void LCS_LENGTH()
{
    m=strlen(A);
    n=strlen(B);
    int LCS[m+1][n+1];
    for(i=0;i<=m;i++)
    {
        LCS[i][0]=0;
    }

    for(j=0;j<=n;j++)
    {
        LCS[0][j]=0;
    }

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(A[i-1]==B[j-1])
            {
                LCS[i][j]=1+LCS[i-1][j-1];
                b[i][j]='a';
            }

            else if(LCS[i-1][j]>=LCS[i][j-1])
            {
                LCS[i][j]=LCS[i-1][j];
                b[i][j]='b';
            }

            else
            {
                LCS[i][j]=LCS[i][j-1];
                b[i][j]='c';
            }
        }
    }

    printf("Length of the longest common subsequence is: ");
    printf("%d\n",LCS[m][n]);
    printf("The Longest Common Subsequence is: ");
    PRINT_LCS(m,n);
}



int main()
{
     printf("enter the first string:\n");
     scanf("%s",A);
     printf("enter the second string:\n");
     scanf("%s",B);

     LCS_LENGTH();

     return 0;
}
