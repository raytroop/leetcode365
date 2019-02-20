// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
// https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-378-kth-smallest-element-in-a-sorted-matrix/

#include <vector>
#include <algorithm>
using std::vector;

// binary search
int kthSmallest(vector<vector<int>>& matrix, int k) {
    const int n = matrix.size();
    int l = matrix[0][0];
    int r = matrix[n-1][n-1] + 1;
    while(l < r){
        int mid = l + (r - l) / 2;
        int len = n;
        int total = 0;  // store total number that `less than / equal` mid
        for(auto& row: matrix)
            total += (len = std::distance(row.cbegin(), std::upper_bound(row.cbegin(), row.cbegin() + len, mid)));

        if(total >= k)
            r = mid;
        else
            l = mid + 1;
    }

    return l;
}

/* std::upper_bound
Returns an iterator pointing to the first element in the range [first, last) that is greater than value, or last if no such element is found. */