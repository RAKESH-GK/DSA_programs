#include<stdio.h>
#include<time.h>
int partition(int a[],int low,int high){
    int pivote=a[low];
    int i=low+1;
    int j=high;
    while(i<=j){
        while(i<=high && pivote>=a[j]){
            i++;
        }
        while(pivote<a[j]){
            j--;
        }
        if(i<j){
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        else{
            int temp=a[j];
            a[j]=a[low];
            a[low]=temp;
            
        }
    }
   return j;  
}
void quicksort(int a[],int low,int high){
    if(low<high){
        int mid=partition(a,low,high);
        quicksort(a,low,mid-1);
        quicksort(a,mid+1,high);
    }
}



void main(){
    int ch,n,a[10];
    clock_t time;
    while(1){
    printf("\nMENU:\n1.wort case analysis\n2.best case analysis\nenter your choice:");
    scanf("%d",&ch);
    printf("enter the number of inputs:");
    scanf("%d",&n);
    switch(ch){
    case 1:
        for(int i=0;i<n;i++){
            a[i]=i+1;
        }
        printf("worst case already soterd elemets are:\n");
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        time=clock();
        quicksort(a,0,n-1);
        time=clock()-time;

        printf("\narray after sort:\n");
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\ntime taken is %f secs",time/CLK_TCK);
        break;
    case 2:
        for(int i=0;i<n;i++){
            a[i]=rand()%100;
        }
        printf("array before sort:\n");
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        time=clock();
        quicksort(a,0,n-1);
        time=clock()-time;

        printf("\narray after sort:\n");
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        double t=time;
        printf("\ntime taken is %lf secs",t/CLK_TCK);
        break;
    default:printf("invalid input..!\n");
        break;
    }
    }
}