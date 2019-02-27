// https://leetcode.com/problems/first-bad-version/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long l = 1;
        long r = static_cast<long>(n) + 1;
        while(l < r){
            long mid = l + (r - l) / 2;
            if(isBadVersion(mid))
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};