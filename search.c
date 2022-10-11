#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int size;

void linear_search(){
    int ele,flag=0;
    double time;
    printf("enter the size of array:");
    scanf("%d",&size);
    int a[size];
    printf("inserting random element into array....\n");
    for(int i=0;i<size;i++){
        a[i]=rand()%2000;
    }
    printf("elements in array are:\n");
    for(int i=0;i<size;i++){
        printf("%d ",a[i]);
    }
    printf("\nenter the search element:");
    scanf("%d",&ele);
    time=clock();
    for(int i=0;i<size;i++){
        if(a[i]==ele){
            printf("\nsearch is succesfull at position %d ",i);
            flag=1;
            break;
        }
    }
    time=clock()-time;
    if(flag==0){
        printf("\nsearch unsuccesfull\n");
    }
    else{
        printf("\nTime taken is %f \n",time/CLOCKS_PER_SEC);
    }
    

}
void merge(int a[],int low,int mid, int high){
    int i,j,k;
    i=low;
    j=mid+1;
    k=low;
    int b[size];
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

void merge_sort(int a[],int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

void binary_search(){
    int flag=0,ele;
    double time;
    printf("enter the size of the array:");
    scanf("%d",&size);
    int a[size];
    printf("inserting ramdom elements into array....");
    for(int i=0;i<size;i++){
        a[i]=rand()%2000;
    }
    printf("\narray before sort:\n");
    for(int i=0;i<size;i++){
        printf("%d ",a[i]);
    }
    int low=0,high=size-1,mid;

    merge_sort(a,low,high);

    printf("\narray after sort:\n");
    for(int i=0;i<size;i++){
        printf("%d ",a[i]);
    }
    printf("\nenter the search element:");
    scanf("%d",&ele);
    time=clock();
    while(low<=high){
        mid=(low+high)/2;
        if(a[mid]==ele){
            printf("search succesfull at position %d ",mid);
            flag=1;
            break;
        }
        else if(ele>a[mid]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    time=clock()-time;
    if(flag==0){
        printf("\nsearch is unsuccesfull\n");
    }
    else{
        printf("\ntime taken is %f",time/CLK_TCK);
    }

}

void main(){
    int choice;
    while(1){
        printf("\nMENU\n1.Binary search\n2.Linear search\n3.Exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:binary_search();
            break;
            case 2:linear_search();
            break;
            case 3:exit(0);
            default:printf("invalid choice..!");
            break;
        }
    }

}