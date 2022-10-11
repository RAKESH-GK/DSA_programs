#include<stdio.h>
int max(int a,int b){
    return a>b?a:b;
}
void main(){
    int n,m;
    printf("enter the number of items:");
    scanf("%d",&n);
    printf("enter the capacity of knapsack:");
    scanf("%d",&m);
    int w[n+1],p[n+1],v[n+1][m+1];
    printf("enter the weight and profit of items:\n");
    for(int i=1;i<=n;i++){
        printf("\nitem %d weight:",i);
        scanf("%d",&w[i]);
        printf("item %d profit:",i);
        scanf("%d",&p[i]);
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(j==0 || i==0){
                v[i][j]=0;
                printf("%d   ",v[i][j]);
            }  
            else if(w[i]>j){
                v[i][j]=v[i-1][j];
                printf("%d  ",v[i][j]);
            }  
            else{
                v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
                printf("%d  ",v[i][j]);
            }
        }
        printf("\n");
    }
    printf("maximum profit is:%d",v[n][m]);
    printf("\nmost valuable items are:");
    for(int i=n;i>=1;i--){
        if(v[i][m]!=v[i-1][m]){
            printf("item: %d ",i);
            m=m-w[i];
        }
    }
}