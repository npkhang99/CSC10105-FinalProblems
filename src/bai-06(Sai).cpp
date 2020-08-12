/*
Reference:
https://www.geeksforgeeks.org/construction-of-longest-monotonically-increasing-subsequence-n-log-n/

best method: O(n^2)
*/

// CPP program to find the length of the 
// longest decreasing subsequence 
//#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

// Function that returns the length 
// of the longest decreasing subsequence 
int longest_decreasing_subsequence(int arr[], int n, int lds[])
{
    int i, j;

    // Initialize LDS with 1 for all index 
    // The minimum LDS starting with any 
    // element is always 1 
    for (i = 0; i < n; i++)
        lds[i] = 1;

    // Compute LDS from every index 
    // in bottom up manner 
    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (arr[i] < arr[j] && lds[i] < lds[j] + 1)
                lds[i] = lds[j] + 1;

    // Select the maximum  
    // of all the LDS values 
    int count_max = 0, max = 0;
    for (i = 0; i < n; i++)
    {
        if (max == lds[i])
            ++count_max;

        if (max < lds[i])
        {
            max = lds[i];
            count_max = 1;
        }
    }

    // returns the count max of the LDS 
    return count_max;
}
// Driver Code 
int main()
{
    int arr[100000], lds[100000];
    int n;

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    
    cout << longest_decreasing_subsequence(arr, n, lds);
    return 0;
}
