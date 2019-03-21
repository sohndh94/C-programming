#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num=100, boolnum,id,i,first=0;
    int count=0;
    int out_count=0;

    int *arr=(int*)malloc(sizeof(int) * num);

    FILE* fp1=fopen("user_ID_list.txt","r");
    FILE* log=fopen("log.txt","w");

    while(!feof(fp1))
    {
        fscanf(fp1,"%d %d",&boolnum,&id);

        if (boolnum==1){
            arr[count]=id;
            count++;
        }
        else if (boolnum==-1){
            deleteArray(arr,&count,&num,&id);
            out_count++;
        }

        float rate = (float) count / num;
        if (rate>= (float) 0.95) //has to be expanded
        {
            first=1;
            fprintf(log,"%d ",num); // num before changed
            num = 1.5 * num ;
            arr = (int *)realloc(arr, sizeof(int) * num);
            fprintf(log,"%d [%d]\n",num, count); // size and saved members when changed
        }
        else if (rate<=0.5) //has to be shorten
        {
            if (first!=0)
                fprintf(log,"%d ",num);
            num = 0.8*num;
            if (0.8*num <100) //upper than 100
                num=100;
            arr = (int *)realloc(arr, sizeof(int) * num);
            if (first!=0)
                fprintf(log,"%d [%d]\n",num, count); // size and saved members when changed
        }
    }

    printf("registered member: %d\n", count);
    printf("withdrawal member: %d\n", out_count);


    fclose(log);//log close
    fclose(fp1);//user_ID close

    //write in members
    FILE* mem_list=fopen("in_member.txt","w");
    for (i=0;i<count;i++)
        fprintf(mem_list,"%d\n",arr[i]);
    fclose(mem_list);//in_member close


    return 0;
}


void deleteArray(int *arr, int *count, int *size, int *id){
    //count is length of arr
    //size criteria of arr length
    int i, temp;
    for(i = 0; i < *count; i++)
        if(arr[i] == *id) break;
    temp = arr[*count-1];
    arr[*count-1] = arr[i];
    arr[i] = temp;
    (*count)--;
    //length is count
}
