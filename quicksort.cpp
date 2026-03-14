#include <iostream>
#include <algorithm>
using namespace std;

    int partition(int arr[],int p,int r){
        int pivot = arr[r-1];
        int i = p-1;
        for(int j=p;j<r-1;j++){
            if(arr[j]<=pivot){
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[r-1]);
        return i+1;
    }

 void quickSort(int arr[], int p, int r) {
        if(p<r){
            int q = partition(arr,p,r);
            quickSort(arr,p,q-1);
            quickSort(arr,q+1,r);
        }
 }

int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int r = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0,r);

    for(int i = 0; i < r; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
        
}