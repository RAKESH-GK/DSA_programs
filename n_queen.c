#include<stdio.h>
#include<math.h>
int x[20],count=1;
int place(int k,int j){
    for(int i=1;i<k;i++){
        if((x[i]==j) || abs(x[i]-j)==abs(i-k)){
            return 0;
        }
    }
    return 1;
}
void queens(int n,int k){
    for(int j=1;j<=n;j++){
        if(place(k,j)){
            x[k]=j;
            if(k==n){
                printf("%d solution:\n",count);
                count++;
                for(int i=1;i<=n;i++){
                    printf("%d row-->%d column\n",i,x[i]);
                } 
                printf("\n");
            }
            else{
                queens(n,k+1);
            }
        }
    }
}
void main(){
    int n,k=1;
    printf("enter the number of queens:");
    scanf("%d",&n);
    queens(n,k);
}