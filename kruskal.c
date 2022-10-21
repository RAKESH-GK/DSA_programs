#include<stdio.h>
int cost[10][10],parent[10],u,v,a,b,n,flag=0,count=0,min,mincost=0;
void find_min(){
    min=999;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(cost[i][j]<min){
                min=cost[i][j];
                a=u=i;
                b=v=j;
            }
        }
    }
}
void cycle(){
    if(parent[u]==parent[v] && parent[u]!=0){
        flag=0;
    }
    else{
        flag=1;
    }
}
void update(){
    if(parent[v]==0 && parent[u]==0){
        parent[u]=parent[v]=u;
    }
    else if(parent[u]==0){
        parent[u]=parent[v];
    }
    else if(parent[v]==0){
        parent[v]=parent[u];
    }
    else{
        for(int i=1;i<=n;i++){
            if(parent[i]==parent[v]){
                parent[i]=parent[u];
            }
        }
    }
}

void main(){
printf("enter the number of vertices:");
scanf("%d",&n);
printf("enter the number cost matrix:\n");
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        scanf("%d",&cost[i][j]);
        if(cost[i][j]==0){
            cost[i][j]=999;
        }
    }
}
find_min();
while(count!=n-1 && min!=999){
    cycle();
    if(flag){
        printf("%d --> %d is: %d\n",a,b,min);
        count++;
        mincost=mincost+min;
        update();
    }
    cost[a][b]=cost[b][a]=999;
    find_min();
}
}