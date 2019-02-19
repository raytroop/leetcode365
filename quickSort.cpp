/*
快速排序通常明显比同为Ο(n log n)的其他算法更快，因此常被采用，而且快排采用了分治法的思想，所以在很多笔试面试中能经常看到快排的影子。可见掌握快排的重要性。

步骤：
    1. 从数列中挑出一个元素作为基准数。
    2. 分区过程，将比基准数大的放到右边，小于或等于它的数都放到左边。
    3. 再对左右区间递归执行第二步，直至各区间只有一个数。
*/

#include <vector>
#include <random>
using std::vector;

// lo, hi inclusive
int partion(vector<int>& nums, int lo, int hi){
    std::swap(nums[lo], nums[lo + std::rand() % (hi - lo + 1)]);
    int pivot = nums[lo];
    while(lo < hi){
        while(lo < hi && pivot <= nums[hi])
            --hi;
        nums[lo] = nums[hi];

        while(lo < hi && pivot >= nums[lo])
            ++lo;
        nums[hi] = nums[lo];
    }

    nums[lo] = pivot;
    return lo;
}

void quicksort(vector<int>& nums, int lo, int hi){
    if(hi - lo + 1 < 2)
        return; // already ordinal
    int mid = partion(nums, lo, hi);
    partion(nums, lo, mid - 1);
    partion(nums, mid + 1, hi);
}