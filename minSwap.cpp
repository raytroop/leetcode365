//https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/

#include <vector>
#include <algorithm>
#include <climits>
using std::vector;

// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-801-minimum-swaps-to-make-sequences-increasing/
int minSwap(vector<int>& A, vector<int>& B) {
    const int n = A.size();
    vector<int> keep(n, INT_MAX);   // end without swap
    vector<int> swap(n, INT_MAX);   // end with swap
    keep[0] = 0;
    swap[0] = 1;

    for(int i = 1; i < n; ++i){
        if(A[i-1] < A[i] && B[i-1] < B[i]){
            keep[i] = keep[i-1];
            swap[i] = swap[i-1] + 1;
        }

        if(A[i-1] < B[i] && B[i-1] < A[i]){
            keep[i] = std::min(keep[i], swap[i-1]);
            swap[i] = std::min(swap[i], keep[i-1] + 1);
        }
    }

    return std::min(keep[n-1], swap[n-1]);
}