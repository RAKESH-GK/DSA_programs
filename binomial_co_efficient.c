#include<stdio.h>
int min(int a,int b){
    return a<b?a:b;
}
void main(){
    int row,col;
    printf("enter value for row and column:");
    scanf("%d%d",&row,&col);
    int c[row+1][col+1];
    for(int i=0;i<=row;i++){
        for(int j=0;j<=min(i,col);j++){
            if(i==j || j==0){
                c[i][j]=1;
                printf("%d  ",c[i][j]);
            }
            else{
                c[i][j]=c[i-1][j-1]+c[i-1][j];
                printf("%d  ",c[i][j]);
            }
        }
        printf("\n");
    }
}