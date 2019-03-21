#include <stdio.h>
#include <stdlib.h>

void paint(int A[14][14], int row, int col)
{
    if (col>=14 || col<=0)
        return;
    if (row>=14 ||row<=0)
        return;

    if (A[row][col]==0){
        A[row][col]=1;
        //paint horizontally
        paint(A,row,col+1);
        paint(A,row,col-1);
        paint(A,row+1,col);
        paint(A,row-1,col);
    }
    else if (A[row][col]==1)
    {
        return;
        //paint(A,row+1,col);
        //paint(A,row-1,col);
    }
    //printarr(A);
}

void printarr(int A[14][14])
{
    for (int i=0; i<14; i++)
    {
        for (int j=0;j<14;j++){
            printf("[%d]",A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int a,b,x, mat[14][14]={0,};
    FILE* fp=fopen("input.txt","r");
    fscanf(fp,"%d %d",&a,&b);
    for (int i=0;i<14;i++)
    {
        for (int j=0; j<14;j++)
        {
            fscanf(fp,"%d",&x);
            mat[i][j]=x;
        }
    }
    printf("Original\n");
    printarr(mat);
    printf("Starting from [%d %d]\n",a,b);
    //printf("painting\n");
    paint(mat,a,b);
    printf("After painting\n");
    printarr(mat);


    FILE* fp_new=fopen("output.txt","w");
    for (int i=0; i<14; i++)
    {
        for (int j=0;j<14;j++){
            fprintf(fp_new,"%d ",mat[i][j]);
        }
        fprintf(fp_new,"\n");
    }
    fclose(fp_new);
    return 0;
}
