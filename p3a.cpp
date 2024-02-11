


#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using boost::multiprecision::cpp_int;

cpp_int computeTotalNumberOfWays(int n) {
    cpp_int* dp = new cpp_int[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cpp_int totalWays = dp[n];
    delete[] dp;   // free the memory allocated for the array
    return totalWays;
}

int main() {
    int n;
    cout << "Enter The Total Number Of Ways : ";
    cin >> n;
    cpp_int totalWays = computeTotalNumberOfWays(n);
    cout << "Total Number Of Ways : " << totalWays << endl;
    return 0;
}
