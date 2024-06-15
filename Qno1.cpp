// Program to find the number triplets in an array whose sum is equal to given value X.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int countTriplets(vector<int>& arr, int x) {
    int n = arr.size();
    int count = 0;

    // Sort the array
    sort(arr.begin(), arr.end());

    // Iterate through each element and use two-pointer technique for the rest of the elements
    for (int i = 0; i < n - 2; i++) {
        // Use two pointers to find pairs that sum up to (x - arr[i])
        int left = i + 1;
        int right = n - 1;
        while (left < right) {
            int current_sum = arr[i] + arr[left] + arr[right];
            if (current_sum == x) {
                count++;
                left++;
                right--;
                // To avoid counting duplicates, skip the same elements
                while (left < right && arr[left] == arr[left - 1]) left++;
                while (left < right && arr[right] == arr[right + 1]) right--;
            } else if (current_sum < x) {
                left++;
            } else {
                right--;
            }
        }
    }

    return count;
}

int main() {
    int n;
    cout<<"Enter the size of the vector:";
    cin>>n;
    vector<int> arr;
    cout<<"Enter the array: ";
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    int x;
    cout<<"Enter the value of X = ";
    cin>>x;
    int result = countTriplets(arr, x);
    cout<<"Number of triplets with sum "<<x<<" is: "<<result<<endl;
    return 0;
    
}
