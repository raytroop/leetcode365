//https://leetcode.com/problems/longest-mountain-in-array/

#include <vector>
#include <algorithm>
using std::vector;

int longestMountain(vector<int>& A) {
    const int n = A.size();
    if(n < 3)
        return 0;

    vector<int> leftRise(n);    // left side of mountain
    vector<int> rightRise(n);   // right side of mountain

    leftRise[0] = 0;
    for(int i = 1; i < n; ++i){
        if(A[i] > A[i-1])
            leftRise[i] = leftRise[i-1] + 1;
        else
            leftRise[i] = 0;
    }

    rightRise[n-1] = 0;
    for(int i = n-2; i >= 0; --i){
        if(A[i] > A[i+1])
            rightRise[i] = rightRise[i+1] + 1;
        else
            rightRise[i] = 0;
    }

    int ans = 0;
    for(int i = 1; i < n-1; ++i){
        if(leftRise[i] > 0 && rightRise[i] > 0)
            ans = std::max(ans, leftRise[i] + rightRise[i] + 1);
    }

    return ans;
}
