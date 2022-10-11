#include<stdio.h>
int min(int a,int b){
    return a<b?a:b;
}
void main(){
    int n,cost[10][10],source,visited[10],dist[10],u;
    printf("enter the number of nodes:");
    scanf("%d",&n);
    printf("enter the cost of edges:\n");
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0){
                cost[i][j]=999;
            }
        }
    }
    printf("enter the source vertex:");
    scanf("%d",&source);
    for(int i=1;i<=n;i++){
        visited[i]=0;
        dist[i]=cost[source][i];
    }
    visited[source]=1;
    dist[source]=0;
    for(int i=2;i<n;i++){
        int mini=999;
        for(int j=1;j<=n;j++){
            if(visited[i]==0 && dist[i]<mini){
                mini=dist[i];
                u=i;
            }
            visited[u]=1;
            for(int j=1;j<=n;j++){
                if(visited[j]==0){
                    dist[j]=min(dist[j],cost[u][j]);
                }
            }
        }
    }
    printf("shortest from vertex %d to all vertices are:\n",source);
    for(int i=1;i<=n;i++){
        printf("%d to %d is: %d\n",source,i,dist[i]);
    }
}