// Program to find the one array is the subset of another array
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
bool isSubset(const vector<int>& larger, const vector<int>& smaller) {
    unordered_set<int> elements;
    // Insert all elements of the larger array into the set
    for (int num : larger) {
        elements.insert(num);
    }
    // Check if all elements of the smaller array are present in the set
    for (int num : smaller) {
        if (elements.find(num) == elements.end()) {
            return false; // Element not found, so smaller is not a subset of larger
        }
    }
    return true; // All elements found, so smaller is a subset of larger
}
int main() {
    int n;
    cout<<"Enter the size of first array:";
    cin>>n;
    vector<int> larger;
    cout<<"Enter the Elements of first array: ";
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        larger.push_back(a);
    }
    int m;
    cout<<"Enter the size of second array:";
    cin>>m;
    vector<int> smaller;
    cout<<"Enter the Elements of second array: ";
    for(int i=0;i<m;i++){
        int b;
        cin>>b;
        smaller.push_back(b);
    }
    if (isSubset(larger, smaller)) {
          cout << "The second array is a subset of the first array." << endl;
    } else {
          cout << "The second array is not a subset of the first array." << endl;
    }
    return 0;
}
