#include<stdio.h>
int a[20][20],n,queue[10],visited[10],dist[10],front=0,rear=0,i;
void dfs(int v){
    for(int i=1;i<=n;i++){
        visited[i]=0;
        dist[i]=0;
    }
    visited[v]=1;
    queue[rear++]=v;
    do{
        i=queue[front++];
        for(int j=1;j<=n;j++){
            if(a[i][j] && !visited[j]){
                visited[j]=1;
                dist[j]=dist[i]+1;
                queue[rear++]=j;
                printf("%d to %d is: %d\n",v,j,dist[j]);
            }
        }
    }while(front<rear);
}
void main(){
    printf("enter the number of vertices:");
    scanf("%d",&n);
    printf("enter the adjacency matrix:\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        printf("\nthe starting vertex is: %d\n",i);
        dfs(i);
    }
}