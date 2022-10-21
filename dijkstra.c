#include<stdio.h>
void main(){
    int cost[20][20],n,source,visited[20],dist[20],min,u;
    printf("enter the number of vertices:");
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
    printf("enter the source vertex:");
    scanf("%d",&source);
    for(int i=1;i<=n;i++){
        visited[i]=0;
        dist[i]=cost[source][i];
    }
    visited[source]=1;
    dist[source]=0;
    for(int i=1;i<n;i++){
        min=999;
        for(int j=1;j<=n;j++){
            if(visited[j]==0 && dist[j]<min){
                min=dist[j];
                u=j;
            }
        }
        visited[u]=1;
        for(int j=1;j<=n;j++){
            if(visited[j]==0 && dist[u]+cost[u][j]<dist[j]){
                dist[j]=dist[u]+cost[u][j];
            }
           
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d to %d is: %d\n",source,i,dist[i]);
    }
}