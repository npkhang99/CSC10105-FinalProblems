/*
Reference:
https://www.geeksforgeeks.org/find-a-triplet-that-sum-to-a-given-value/

Best method: O(n^2)
*/

// C++ program to find a triplet using Hashing 
#include <bits/stdc++.h> 
using namespace std; 
  
// returns true if there is triplet with X equal 
// to 'X' present in A[]. Also, prints the triplet 
bool find3Numbers(int A[], int arr_size, long long X) 
{ 
    // Fix the first element as A[i] 
    for (int i = 0; i < arr_size - 2; i++) { 
  
        // Find pair in subarray A[i+1..n-1] 
        // with sum equal to X - A[i] 
        unordered_set<int> s; 
        long long curr_sum = X - A[i]; 
        for (int j = i + 1; j < arr_size; j++) { 
            if (s.find(curr_sum - A[j]) != s.end()) { 
                printf("Triplet is %d, %d, %d", A[i], 
                       A[j], curr_sum - A[j]); 
                return true; 
            } 
            s.insert(A[j]); 
        } 
    } 
  
    // If we reach here, then no triplet was found 
    return false; 
} 
  
/* Driver program to test above function */
int main() 
{ 
    int A[5000];
    int arr_size;
    long long X;

    cin >> arr_size;
    for (int i = 0; i < arr_size; ++i)
    {
        cin >> A[i];
    }
    cin >> X;

    find3Numbers(A, arr_size, X); 
  
    return 0; 
} 