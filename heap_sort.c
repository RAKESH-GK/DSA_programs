#include<stdio.h>
#include<stdlib.h>
void hepify(int a[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n && a[left]>a[largest]){
        largest=left;
    }
    if(right<=n && a[right]>a[largest]){
        largest=right;
    }
    if(largest!=i){
        int temp=a[largest];
        a[largest]=a[i];
        a[i]=temp;
        hepify(a,n,largest);
    }
}
void heapsort(int a[],int n){
    for(int i=n/2;i>=1;i--){
        hepify(a,n,i);
    }
    for(int i=n;i>=1;i--){
        int temp=a[i];
        a[i]=a[1];
        a[1]=temp;
        hepify(a,i-1,1);
    }
}
void main(){
    int n,a[20];
    printf("enter the size of the array:");
    scanf("%d",&n);
    printf("inserting random elements....");
    for(int i=1;i<=n;i++){
        a[i]=rand()%2000;
    }
    printf("\narray before sort:\n");
    for(int i=1;i<=n;i++){
        printf("%d ",a[i]);
    }
    heapsort(a,n);
    printf("\narray after sort:\n");
    for(int i=1;i<=n;i++){
        printf("%d ",a[i]);
    }
}