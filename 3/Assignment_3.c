#include <stdio.h>
#include <stdlib.h>
#define num 10
int main()
{
    int newarr[num][num]={0,};
    int N, x,y,i,j,count=0;
    int arr[num][num]={0,};
    FILE* fp=fopen("index.txt","r");

    fscanf(fp,"%d",&N);
    //printf("%d\n",N);
    for (i=0;i<N;i++)
    {
        fscanf(fp,"%d%d",&x,&y);
        printf("%d %d\n",x,y);
        arr[x][y]=-1;
    }
    printf("\n");
    //original
    for (i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            printf("[");
            if (arr[i][j]==0)
            {
                printf(" %d",arr[i][j]);
            }
            else if (arr[i][j]==-1)
            {
                printf("%d",arr[i][j]);
            }
            printf("]");
        }
        printf("\n");
    }
    printf("\n");

    //°¡¿îµ¥
    for (i=1;i<9;i++)
    {
        for(j=1;j<9;j++)
        {
            if (arr[i][j]==-1)
            {
                newarr[i][j]=-1;
                continue;
            }
            newarr[i][j]=abs(arr[i-1][j-1]+arr[i-1][j]+arr[i-1][j+1]+arr[i][j-1]+arr[i][j+1]+arr[i+1][j-1]+arr[i+1][j]+arr[i+1][j+1]);
        }
    }

    //À­ÁÙ
    for (j=1;j<num-1;j++)
    {
        if (arr[0][j]==-1)
        {
            newarr[0][j]=-1;
            continue;
        }
        newarr[0][j]=abs(arr[0][j-1]+arr[0][j+1]+arr[1][j-1]+arr[1][j]+arr[1][j+1]);
    }

    //¾Æ·§ÁÙ
    for (j=1;j<num-1;j++)
    {
        if (arr[num-1][j]==-1)
        {
            newarr[num-1][j]=-1;
            continue;
        }
        newarr[num-1][j]=abs(arr[num-1][j-1]+arr[num-1][j+1]+arr[num-2][j-1]+arr[num-2][j]+arr[num-2][j+1]);
    }

    //¿ÞÂÊ
    for (i=1;i<num-1;i++)
    {
        if (arr[i][0]==-1)
        {
            newarr[i][0]=-1;
            continue;
        }
        newarr[i][0]=abs(arr[i-1][0]+arr[i-1][1]+arr[i][1]+arr[i+1][0]+arr[i+1][1]);
        //printf("newarr[%d][0]: %d\n",i,newarr[i][0]);
    }
    printf("\n");
    //¿À¸¥ÂÊ
    for (i=1;i<num-1;i++)
    {
        if (arr[i][num-1]==-1)
        {
            newarr[i][num-1]=-1;
            continue;
        }
        newarr[i][num-1]=abs(arr[i-1][num-2]+arr[i-1][num-1]+arr[i][num-2]+arr[i+1][num-2]+arr[i+1][num-1]);
        //printf("newarr[0][%d]: %d\n",i,newarr[0][i]);
    }

    //¸ðÅüÀÌ
    //¿ÞÂÊ À§
    if (arr[0][0]==-1)
    {
        newarr[0][0]=-1;
    }
    else
    {
        newarr[0][0]=abs(arr[0][1]+arr[1][1]+arr[1][0]);
    }
    //¿ÞÂÊ ¾Æ·¡
    if (arr[num-1][0]==-1)
    {
        newarr[num-1][0]=-1;
    }
    else
    {
        newarr[num-1][0]=abs(arr[num-1][1]+arr[num-2][1]+arr[num-2][0]);
    }
    //¿À¸¥ÂÊ À§
    if (arr[0][num-1]==-1)
    {
        newarr[0][num-1]=-1;
    }
    else
    {
        newarr[0][num-1]=abs(arr[0][num-2]+arr[1][num-2]+arr[1][num-1]);
    }
    //¿À¸¥ÂÊ ¾Æ·¡
    if (arr[num-1][num-1]==-1)
    {
        newarr[num-1][num-1]=-1;
    }
    else
    {
        newarr[num-1][num-1]=abs(arr[num-1][num-2]+arr[num-2][num-2]+arr[num-2][num-1]);
    }

    //print new array
    printf("New array:\n");
    for (i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            printf("[");
            if (newarr[i][j]>=0)
            {
                printf(" %d",newarr[i][j]);
            }
            else if (newarr[i][j]==-1)
            {
                printf("%d",newarr[i][j]);
            }
            printf("]");
        }
        printf("\n");
    }

    return 0;
}
