#include<stdio.h>

int a[10][10],n;

void main(){
printf("enter the number of vertices:");
scanf("%d",&n);
printf("enter the adjuacency matrix:\n");
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        scanf("%d",&a[i][j]);
    }
}
for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=a[i][j] || a[i][k] && a[k][j];
        }
    }
}
printf("The transitive clousure is:\n");
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        printf("%d ",a[i][j]);
    }
    printf("\n");
}
}