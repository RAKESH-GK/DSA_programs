#include<stdio.h>
int cost[20][20],n,min,s,visited[10],dist[10],p[10],u,t[20][20],k=0,sum=0;
void main(){
    printf("enter the number:");
    scanf("%d",&n);
    printf("enter the cost matrix:\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0){
                cost[i][j]=999;
            }
        }
    }
    min=999;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(cost[i][j]<min){
                min=cost[i][j];
                s=i;
            }
        }
    }

    for(int i=1;i<=n;i++){
        visited[i]=0;
        dist[i]=cost[s][i];
        p[i]=s;
    }

    visited[s]=1;
    for(int it=1;it<n;it++){
    min=999;
    for(int i=1;i<=n;i++){
        if(visited[i]==0 && dist[i]<min){
            min=dist[i];
            u=i;
        }
    }
    visited[u]=1;
    sum=sum+cost[u][p[u]];
    for(int i=1;i<=n;i++){
        if(visited[i]==0 && cost[u][i]<dist[i]){
            dist[i]=cost[u][i];
            p[i]=u;
        }
    }
}
    printf("\nsum of minimum spanning tree is:%d",sum);
}
