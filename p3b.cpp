


#include <iostream>
#include<stack>
using namespace std;

const int MAX_N = 50;  // Maximum number of stopping points
const int INF = 1e9;    // A large constant representing infinity


void compute_optimal_cost_and_path(int dp[], int n, int c[][MAX_N], int parent[]) {
    // Initialize the minimum cost to reach the starting point as 0
    dp[0] = 0;

    // Compute the minimum cost to reach each stopping point
    for (int j = 1; j < n; j++) {
        dp[j] = INF;
        for (int i = 0; i < j; i++) {
            if (dp[i] + c[i][j] < dp[j]) {
                dp[j] = dp[i] + c[i][j];
                parent[j] = i;
            }
        }
    }
    // Push the path into a stack to print it in ascending order
    stack<int> path;
    int curr = n - 1;
    int total_cost = dp[n - 1];
    while (curr != 0) {
        path.push(curr + 1);
        curr = parent[curr];
    }
    path.push(1); // The starting point is 1


    // Print the optimal path in ascending order
    cout << "The optimal path is: ";
    while (!path.empty()) {
        cout << path.top();
        path.pop();
        if (!path.empty()) {
            cout << "->";
        }
    }
    cout << "\n";

    cout << "The total optimal cost is: " << total_cost << endl;
}


int main() {


    /*
    int n = 10;               // Number of stopping points
    int c[MAX_N][MAX_N] = { {0, 100, 200, 40, 250, 300, 400, 500, 600, 700},
            { -1,0,50,10,100,200,300,400,500,600 },
            { -1,-1,0,30,10,90,10,150,200,250 },
            { -1,-1,-1,0,80,160,240,320,400,430 },
            { -1,-1,-1,-1,0,120,240,600,650,700 },
            { -1,-1,-1,-1,-1,0,120,240,300,350 },
            { -1,-1,-1,-1,-1,-1,0,120,140,160 },
            { -1,-1,-1,-1,-1,-1,-1,0,200,400 },
            { -1,-1,-1,-1,-1,-1,-1,-1,0,400 },
            { -1,-1,-1,-1,-1,-1,-1,-1,-1,0 } };*/

    int n = 8;
    int c[MAX_N][MAX_N] = { {0, 100, 20, 300, 400, 500, 600, 700},
    { -1,0,50,10,100,200,300,400 },
    { -1,-1,0,30,10,90,10,150 },
    { -1,-1,-1,0,80,160,240,320 },
    { -1,-1,-1,-1,0,120,240,600 },
    { -1,-1,-1,-1,-1,0,120,240 },
    { -1,-1,-1,-1,-1,-1,0,120 },
    { -1,-1,-1,-1,-1,-1,-1,0 } };

    int dp[MAX_N];       // Array to store the minimum cost to reach each stopping point
    int parent[MAX_N];   // Array to store the optimal path
    compute_optimal_cost_and_path(dp, n, c, parent);
    return 0;
}

