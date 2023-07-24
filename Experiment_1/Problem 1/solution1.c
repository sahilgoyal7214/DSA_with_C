// Online C compiler to run C program online
#include <stdio.h>
int search(int arr[],int f,int n){ 
    int i;
    for(i=0;i<n;i++){
        if(f==arr[i]){
            return -1 ;
        }
    }
    return f ;
}
int max(int arr[], int n) {
    int i;
    int max_val = arr[0];
    for (i = 1; i < n; ++i) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}


int main() {
    // Write C code here
    int size,i;
    printf("enter the size of array\n");
    scanf("%d",&size);
    
    int arr[size];
    printf("enter the array\n");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    int maxi = max(arr,size);
    
    for(i = 1;i <= maxi;i++){
        if (search(arr,i,size)==i){
           
            printf("the smallest missing integer is %d",i);
            break;
        
        }
    }

    return 0;
}
