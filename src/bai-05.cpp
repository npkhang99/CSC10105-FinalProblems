/*
Reference:
https://www.geeksforgeeks.org/find-subarray-with-given-sum-in-array-of-integers/

Best method: O(n)
*/

// C++ program to print subarray with sum as given sum 

//#include<bits/stdc++.h> 
#include <iostream>
#include <unordered_map>

using namespace std;

// Function to print subarray with sum as given sum 
int subArraySum(int arr[], int n, long long sum)
{
    int count = 0;

    // create an empty map 
    unordered_map<long long, int> map;

    // Maintains sum of elements so far 
    long long curr_sum = 0;

    for (int i = 0; i < n; i++)
    {
        // add current element to curr_sum 
        curr_sum = curr_sum + arr[i];

        // if curr_sum is equal to target sum 
        // we found a subarray starting from index 0 
        // and ending at index i 
        // or
        // If curr_sum - sum already exists in map 
        // we have found a subarray with target sum 
        if (curr_sum == sum || map.find(curr_sum - sum) != map.end())
        {
            ++count;
        }

        map[curr_sum] = i;
    }

    return count;
}

// Driver program to test above function 
int main()
{
    int arr[100000];
    int n;
    long long sum;

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cin >> sum;

    cout << subArraySum(arr, n, sum);

    return 0;
}
