#include<stdio.h>
#include<stdlib.h>

void dfs(int,int[20][20],int,int[]);

void main(){
    int n,cost[20][20],s[10];
    printf("enter the number of vertices:");
    scanf("%d",&n);
    printf("enter the adjacent matrix:");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            s[j]=0;
        }
        dfs(n,cost,i,s);
        for(int i=0;i<n;i++){
            if(s[i]==0){
                printf("graph is not connected..!");
                exit(0);
            }
        }
    }
    printf("graph is connected..!");
}

void dfs(int n,int cost[20][20],int j,int s[]){
    s[j]=1;
    for(int i=0;i<n;i++){
        if(cost[j][i]==1 && s[i]==0){
            dfs(n,cost,i,s);
        }
    }
}