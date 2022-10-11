#include<stdio.h>
int k=0,res[20],n,cost[20][20],s[10];

void dfs(int j){
    s[j]=1;
    int i;
    for(i=0;i<n;i++){
        if(cost[j][i]==1 && s[i]==0){
            dfs(i);
        }
    }
    res[k++]=j; 
}

void main(){
    printf("enter number of vertices:");
    scanf("%d",&n);
    printf("enter the adjacency matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        scanf("%d",&cost[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        s[i]=0;
    }
    for(int i=0;i<n;i++){
        if(s[i]==0){
            dfs(i);
        }
    }
    printf("topological order is:\n");
    for(int i=n-1;i>=0;i--){
        printf("%d ",res[i]);
    }
}