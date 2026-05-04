#include <iostream>
#include <algorithm>
using namespace std;

void merge(int arr[],int p, int q,int r){
    int l1  = q-p+1;
    int l2 = r-q;
    int left[l1] = {0};
    int right[l2] = {0};

    for(int i =0;i<l1;i++){
        left[i] = arr[p+i];
    }
     for(int i =0;i<l2;i++){
        right[i] = arr[q+1+i];
    }

    int i=0 ,j=0,k =p;
    while(i<l1&&j<l2){
        if(left[i]<right[j]){
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while(i<l1){
        arr[k++] = left[i++];
    }
    while(j<l2){
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[], int p, int r) {
        if(p<r){
            int q = p +(r-p)/2;
            mergeSort(arr,p,q);
            mergeSort(arr,q+1,r);
            merge(arr,p,q,r);
        }
}

int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int r = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0,r-1);

    for(int i = 0; i < r; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
        
}