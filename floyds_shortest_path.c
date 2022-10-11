#include<stdio.h>
int a[10][10],n;

int min(int a,int b){
    return (a<b)?a:b;
}

void main(){
    printf("enter the number of vertices:");
    scanf("%d",&n);
    printf("enter the adjacency matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
    
    printf("all pairs shortes path is:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",a[i][j]);
            if(a[i][j]<10){
                printf(" ");
            }
        }
        printf("\n");
    }
}