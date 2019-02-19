// https://leetcode.com/problems/median-of-two-sorted-arrays/
/* There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)). */

/*
Binary Search Template
[l, r]
def binary_search(l, r):
    while l < r:
        m = l + (r - l) // 2
        if f(m): return m # optional
        if g(m):
            r = m   # new range [l, m)
        else:
            l = m + 1   # new range [m+1, r]
    return l # or not found

find the smallest index to satisfy `g(index)`
*/
#include <vector>
#include <climits>
#include <algorithm>
using std::vector;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    const int n1 = nums1.size();
    const int n2 = nums2.size();
    // Make sure n1 <= n2
    if (n1 > n2)
        return findMedianSortedArrays(nums2, nums1);

    const int k = (n1 + n2 + 1) / 2;

    int l = 0;
    int r = n1;
    // binary search in nums1
    while (l < r)
    {
        // fetch `mid` numbers from nums1, `k - mid` numbers from nums2
        // nums1[0, 1, 2, ...       mid-1 | mid, ...]
        // nums2[0, 1, 2, ... k - mid - 1       ...     ]

        const int mid = l + (r - l) / 2;
        if (nums1[mid] >= nums2[k - mid - 1]) // `mid` worked as index
            r = mid;
        else
            l = mid + 1;
    }

    const int m1 = l;   // `l` is the smallest index so that  `nums1[index] >= nums2[k - index - 1]`
    const int m2 = k - l;

    const int c1 = std::max(m1 == 0 ? INT_MIN : nums1[m1 - 1],
                       m2 == 0 ? INT_MIN : nums2[m2 - 1]);

    if ((n1 + n2) % 2 == 1)
        return c1;

    const int c2 = std::min(m1 == n1 ? INT_MAX : nums1[m1],
                       m2 == n2 ? INT_MAX : nums2[m2]);

    return (c1 + c2) * 0.5;
}