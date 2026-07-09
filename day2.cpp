#include <iostream>
#include <vector>
using namespace std;

// 1. Calculate Mid
int calculateMid(int low, int high) {
    return low + (high - low) / 2;
}

// 2. Complex Target with Mid (Binary Search)
int binarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

// 3. Print N Natural Numbers Using Recursion
void printNatural(int n) {
    if (n == 0)
        return;

    printNatural(n - 1);
    cout << n << " ";
}

// 4. Sum of First N Natural Numbers Using Recursion
int sumNatural(int n) {
    if (n == 0)
        return 0;

    return n + sumNatural(n - 1);
}

// 5. Nth Fibonacci Using Recursion (Optimized)
long long fibonacci(int n, vector<long long>& dp) {
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
}

// 6. Array of Squares
vector<int> squareArray(vector<int>& arr) {
    vector<int> result;

    for (int num : arr)
        result.push_back(num * num);

    return result;
}

// 7. Count Factors
int countFactors(int n) {
    int count = 0;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i == n / i)
                count++;
            else
                count += 2;
        }
    }

    return count;
}

// 8. Prime Check
bool isPrime(int n) {
    if (n <= 1)
        return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main() {

    // 1. Mid Calculation
    int low = 10, high = 20;
    cout << "Mid = " << calculateMid(low, high) << "\n\n";

    // 2. Binary Search
    vector<int> arr = {2, 4, 6, 8, 10, 12, 14};
    int target = 10;

    int index = binarySearch(arr, target);

    if (index != -1)
        cout << "Target found at index: " << index << "\n\n";
    else
        cout << "Target not found\n\n";

    // 3. Print N Natural Numbers
    int n = 10;
    cout << "Natural Numbers: ";
    printNatural(n);
    cout << "\n\n";

    // 4. Sum of First N Natural Numbers
    cout << "Sum of first " << n << " natural numbers = "
         << sumNatural(n) << "\n\n";

    // 5. Nth Fibonacci
    int fibN = 10;
    vector<long long> dp(fibN + 1, -1);

    cout << fibN << "th Fibonacci Number = "
         << fibonacci(fibN, dp) << "\n\n";

    // 6. Array of Squares
    vector<int> nums = {1, 2, 3, 4, 5};

    vector<int> squares = squareArray(nums);

    cout << "Squares Array: ";
    for (int x : squares)
        cout << x << " ";
    cout << "\n\n";

    // 7. Count Factors
    int num = 36;
    cout << "Number of factors of " << num << " = "
         << countFactors(num) << "\n\n";

    // 8. Prime Check
    int primeNum = 29;

    if (isPrime(primeNum))
        cout << primeNum << " is Prime\n";
    else
        cout << primeNum << " is Not Prime\n";

    return 0;
}