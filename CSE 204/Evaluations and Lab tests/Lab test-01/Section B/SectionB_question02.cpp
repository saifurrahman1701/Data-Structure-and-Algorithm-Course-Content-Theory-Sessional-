/*
* author: brownFalcon
*/

//nter  this is the solution we wanted in the online
// Time complexity O(N^2 * log N)

// there is a better solution possible using two pointers
// https://www.geeksforgeeks.org/find-number-of-triangles-possible/

#include<iostream>
using namespace std;

void sort(int arr[], int n) {
  for(int i=0;i<n;i++) {
    for(int j=i+1;j<n;j++) {
      if(arr[i] > arr[j]) swap(arr[i], arr[j]);
    }
  }
}

int main() {
  int n;cin>>n;
  int arr[n];
  for(int i=0;i<n;i++) cin>>arr[i];
  sort(arr, n);
  int ans = 0;
  for(int i=0;i<n;i++) {
    for(int j=i+1;j<n;j++) {
      int low = j+1, high = n-1;
      int sum = arr[i] + arr[j];
      int idx = -1;
      while(low <= high) {
        int mid = (low + high)/2;
        if(sum <= arr[mid]) {
          high = mid-1;
        }
        else {
          idx = mid;
          low = mid+1;
        }
      }
      if(idx != -1) {
        ans += (idx - j);
      }
    }
  }
  cout<<ans<<endl;
}