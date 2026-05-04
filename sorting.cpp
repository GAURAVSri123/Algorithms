#include <iostream>
#include <algorithm>
using namespace std;
// bubble is stable and inplace algo
void bubbleSort(int arr[],int n) {
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
// selection is unstable and inolace algo
void SelectionSort(int arr[], int n){
    for(int i =0;i<n-1;i++){
        int smallest = i;
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[smallest]){
                smallest = j;
            }
        }
        swap(arr[i],arr[smallest]);
    }
}

void printarr(int arr[],int n){
    for(int i=0;i<n;i++) {
        cout<< arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int arr[] = {4,1,5,2,3};
    int n = 5;

    bubbleSort(arr,n);
    printarr(arr,n);
    SelectionSort(arr,n);
    printarr(arr,n);

}