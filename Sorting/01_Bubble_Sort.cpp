#include<iostream>
using namespace std;
 
/*
Best Time Complexity : O(n)
Average Time Complexity : O(n^2)
Worst Time Complexity : O(n^2)
Worst Space Complexity : O(1)
*/

//Swap Function
void swap(int *x, int *y){  
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

//Print Function
void printArray(int A[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<", ";
    }
    cout<<endl;
}

//Sort Function
void bubbleSort(int A[], int n){

    for (int i = 0; i < n-1; i++) 
    { 
        bool flag = true;         //Break if already Sorted
        for (int j = 0; j <n-1-i ; j++) 
        {
            if(A[j]>A[j+1]){
                flag = false;
                swap(A[j],A[j+1]); // Using Swap Function
            }
        }
        if(flag==true)
            break;  
    } 
}
 

 
int main(){
 
    int A[] = {1, 2, 5, 6, 12, 54, 625, 7, 23, 9, 987};
    
    int n = 11;
    printArray(A, n);
    bubbleSort(A, n); 
    printArray(A, n); 
    return 0;
}
