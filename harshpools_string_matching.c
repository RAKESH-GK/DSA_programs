#include<stdio.h>
#include<string.h>

void main(){
    int table[128],flag=0,k;
    char t[100]="im in barber shop",p[20]="shop";
    // printf("enter the text:");
    // gets(t);
    // printf("enter the pattern:");
    // gets(p);
    int n=strlen(t);
    int m=strlen(p);
    for(int i=0;i<128;i++){
        table[i]=m;
    }
    for(int j=0;j<m-1;j++){
        table[p[j]]=m-1-j;
    }
    int i=m-1;
    while(i<=n-1){
        k=0;
        while(k<=m-1 && p[m-1-k]==t[i-k]){
            k++;
        }
        if(k==m){
            printf("pattern found at position %d",i-m+2);
            flag=1;
            break;
        }
        else{
            i=i+table[t[i]];
        }
    }
if(!flag){
    printf("pattern not found..!");
}
}