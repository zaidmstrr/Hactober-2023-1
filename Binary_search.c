#include <stdio.h>

int binary_norecursion(int arr[], int N, int element) {
    int low = 0;
    int high = N - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == element) {
            return mid; // Element found, return the index
        } else if (arr[mid] < element) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // Element not found
}

int binary_recursion(int arr[], int element, int low, int high) {
    if (low <= high) {
        int mid = (low + high) / 2;
        
        if (arr[mid] == element) {
            return mid; // Element found, return the index
        } else if (arr[mid] < element) {
            return binary_recursion(arr, element, mid + 1, high);
        } else {
            return binary_recursion(arr, element, low, mid - 1);
        }
    }
    
    return -1; // Element not found
}

int main() {
    printf("\n");
    printf("\t\t\t BINARY SEARCH PROBLEM\n");
    int N;
    printf("\n");
    printf("Enter the size of array you want : ");
    scanf("%d",&N);
    int arr[N];
    for(int i=0;i<N;i++){
        printf("Enter the %d element :",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\n");
    int element;
    printf("Enter the element you want to search :");
    scanf("%d",&element);
    printf("\n");
    printf("1. Use Recursion\n");
    printf("2. Without Recursion\n");
    printf("\n");
    int low=0;
    int high=N-1;
    int choice;
    printf("Enter the choice out of two :");
    scanf("%d",&choice);
    if(choice==1){
        int index2=binary_recursion(arr, element, low, high);
        if(index2!=-1){
            printf("Element found at %d position",index2+1);
        }
        else{
            printf("Element not Found");
        }
    }
    else{
        int index=binary_norecursion(arr, N, element);
        if(index!=-1){
            printf("Element found at %d position",index+1);
        }
        else{
            printf("Element not Found");
        }
    }

    return 0;
}
