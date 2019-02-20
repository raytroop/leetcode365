// https://leetcode.com/problems/flip-string-to-monotone-increasing/

#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using std::vector;
using std::string;

// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-926-flip-string-to-monotone-increasing/

// DP - prefix + suffix
int minFlipsMonoIncr(string S) {
    const int n = S.length();
    vector<int> leftZeros(n);   // leftZeros[ix] =>  minimum number of flips to make S[0, 1, 2, ..., ix-1] all `0`
    vector<int> rightOnes(n);   // rightOnes[ix] =>  minimum number of flips to make S[ix-1, ix, ..., n-1] all `1`

    leftZeros[0] = static_cast<int>(S[0] == '1');
    for(int i = 1; i < n; ++i)
        leftZeros[i] = leftZeros[i-1] + static_cast<int>(S[i] == '1');

    rightOnes[n-1] = static_cast<int>(S[n-1] == '0');
    for(int i = n-2; i >= 0; --i)
        rightOnes[i] = rightOnes[i+1] + static_cast<int>(S[i] == '0');

    int ans = INT_MAX;
    for(int i = 0; i <= n-2; ++i)
        ans = std::min(ans, leftZeros[i] + rightOnes[i+1]);

    return std::min(ans, std::min(leftZeros[n-1], rightOnes[0]));
}

// DP
int minFlipsMonoIncr_sol(string S) {
    const int n = S.length();
    vector<int> tailZero(n);    // tailZero[ix] => S[0, 1, 2, ..., ix-1] all zeros
    vector<int> tailOne(n);     // tailOne[ix] => S[0, 1, 2, ..., ix-1] is monotone increasing and S[ix-1] is '1'

    tailZero[0] = static_cast<int>(S[0] == '1');
    tailOne[0] = static_cast<int>(S[0] == '0');

    for(int i = 1; i < n; ++i){
        if(S[i] == '0'){
            tailZero[i] = tailZero[i-1];
            tailOne[i] = std::min(tailZero[i-1], tailOne[i-1]) + 1; // flip '0'
        }
        else{
            tailZero[i] = tailZero[i-1] + 1;    // flip '1'
            tailOne[i] = std::min(tailZero[i-1], tailOne[i-1]);
        }
    }

    return std::min(tailOne[n-1], tailZero[n-1]);
}