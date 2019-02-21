// https://leetcode.com/problems/4sum-ii/
#include <vector>
#include <unordered_map>
#include <algorithm>
using std::unordered_map;
using std::vector;

// https://zxi.mytechroad.com/blog/hashtable/leetcode-454-4sum-ii/
/*
Split the arrays into two groups: (A, B), (C, D)

Create the Minkowski sum of two groups and count the occurrence of each element.

e.g. A = [1, 2, 3], B = [0, -1, 1]

Minkowski sum(A, B) SAB= [0, 1, 2, 3, 4] => [0:1, 1:2, 2:3, 3:2, 4:1]

for each element s in SAB, check whether -s is in Minkowski sum(C, D) SCD

ans = sum(SAB[s] * SCD[-s]), for all s, that s in SAB and -s in SCD

Time complexity: O(n^2)

Space complexity: O(n^2)
*/
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    unordered_map<int, int> SAB;
    for(auto a: A)
        for(auto b: B)
            ++SAB[a+b];

    unordered_map<int, int> SCD;
    for(auto c: C)
        for(auto d: D)
            ++SCD[c + d];

    int ans = 0;
    for(auto& pair: SAB){
        int t = -pair.first;
        if(SCD.count(t))
            ans += pair.second * SCD[t];
    }

    return ans;
}


/* class Solution {
public:
  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    unordered_map<int, int> sums;
    for (int a : A)
      for (int b : B)
        ++sums[a + b];
    int ans = 0;
    for (int c : C)
      for (int d : D) {
        auto it = sums.find(- c - d);
        if (it != sums.end()) ans += it->second;
      }
    return ans;
  }
}; */