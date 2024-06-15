#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int firstNonRepeatingElement(const vector<int>& arr) {
    unordered_map<int, int> frequency;

    // Populate the frequency map
    for (int num : arr) {
        frequency[num]++;
    }

    // Find the first element with frequency 1
    for (int num : arr) {
        if (frequency[num] == 1) {
            return num;
        }
    }

    // If no non-repeating element is found
    return -1;
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
    int result = firstNonRepeatingElement(arr);

    if (result != -1) {
        cout << "The first non-repeating element is: " << result << endl;
    } else {
        cout << "No non-repeating element found." << endl;
    }

    return 0;
}
