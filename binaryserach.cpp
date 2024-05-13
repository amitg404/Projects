#include <iostream>
using namespace std;

int binarySearch(int arr[], int target, int size) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == target) return mid;
        if(arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int target = 3;
    int size = sizeof(arr) / sizeof(arr[0]);
    int index = binarySearch(arr, target, size);
    if(index != -1) cout << "Element found at index " << index << endl;
    else cout << "Element not found" << endl;
    return 0;
}
