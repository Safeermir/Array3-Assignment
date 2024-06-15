#include <iostream>
#include <vector>
using namespace std;
// Function to multiply a number by an integer and store the result in a vector
void multiply(int num, vector<int>& result) {
    int carry = 0; // Initialize carry

    // Multiply each digit of the result by the number and add carry
    for (int i = 0; i < result.size(); i++) {
        int product = result[i] * num + carry;
        result[i] = product % 10; // Store the last digit of product in the result
        carry = product / 10; // Update carry
    }

    // Add remaining carry to the result
    while (carry) {
        result.push_back(carry % 10);
        carry /= 10;
    }
}

// Function to find factorial of a large number
void factorial(int n) {
    vector<int> result(1, 1); // Initialize result with 1

    // Multiply result by every number from 2 to n
    for (int i = 2; i <= n; i++) {
        multiply(i, result);
    }

    // Print the result in reverse order
    for (int i = result.size() - 1; i >= 0; i--) {
          cout << result[i];
    }
    cout << endl;
}

int main() {

    int number;
    cout<<"Enter the Number: ";
    cin>>number;  
    cout << "Factorial of " << number << " is: ";
    factorial(number);
    return 0;
}
