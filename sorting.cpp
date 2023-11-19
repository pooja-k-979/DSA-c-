#include<bits/stdc++.h>
using namespace std;

#include <vector>
void merge(vector<int> &arr, int l, int mid, int r) {
    int a=l, b=mid+1;
    std::vector<int> temp;
    while(a<=mid && b<=r) {
        if(arr[a] <= arr[b]) {
            temp.push_back(arr[a]);
            a++;
        } else {
            temp.push_back(arr[b]);
            b++;
        }
    }
    while(a<=mid) {
        temp.push_back(arr[a]);
        a++;
    }
    while(b<=r) {
        temp.push_back(arr[b]);
        b++;
    }
    for(int i=l; i<=r; i++) {
        arr[i] = temp[i-l];
    }
    return;
}


void mergeSort(vector<int> &arr, int l, int r) {
    if(l==r) return;
    int mid = (l+r)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, mid, r);
}

int main() {
    vector<int> arr={3, 1, 2, 4, 1, 5, 2, 6, 4};
    mergeSort(arr, 0, arr.size());
    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] <<" ";
    }
}