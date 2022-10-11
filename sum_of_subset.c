#include<stdio.h>
int n,a[20],sum,flag=0,count=0,set[20];

void subset(int result,int i){
    if(result==sum){
        flag=1;
        for(int i=0;i<count;i++){
            printf("%d ",set[i]);
        }
        printf("= %d\n",sum);
        return;
    }
    if(result>sum || i>=n){
        return;
    }
    else{
        set[count]=a[i];
        count++;
        subset(result+a[i],i+1);
        count--;
        subset(result,i+1);
    }
}

void main(){
    printf("enter the number of values:");
    scanf("%d",&n);
    printf("enter the values:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("enter the sum to check:");
    scanf("%d",&sum);
    subset(0,0);
    if(flag==0)
    printf("No solution found..!");
}