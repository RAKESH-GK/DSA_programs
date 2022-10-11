#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int size;
void merge(int a[],int low,int mid,int high){
    int i,j,k,b[size];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            b[k++]=a[i++];
        }
        else{
            b[k++]=a[j++];
        }
    }
    while(i<=mid){
        b[k++]=a[i++];
    }
     while(j<=high){
        b[k++]=a[j++];
    }
    for(int i=low;i<=high;i++){
        a[i]=b[i];
    }
}

void merge_sort(int a[],int low, int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

void main(){
    int ch=1;
    while(ch){
        printf("\nenter the size of the array:");
        scanf("%d",&size);
        int a[size];
        printf("inserting element into array...\n");
        for(int i=0;i<size;i++){
            a[i]=rand()%2000;
        }
        printf("array before sort:\n");
        for(int i=0;i<size;i++){
            printf("%d ",a[i]);
        }
        double time=clock();
        merge_sort(a,0,size-1);
        time=clock()-time;
        printf("\narray after sort:");
        for(int i=0;i<size;i++){
            printf("%d ",a[i]);
        }
        printf("\ntime taken is %f ",time/CLK_TCK);
        printf("\nwant to run again(1/0):");
        scanf("%d",&ch);
    }
   
}