#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <iostream>
using std::vector;
using std::string;

int GetTranslationCount(const string& s);

int GetTranslationCount(int number) {
    if (number < 0)
        return 0;
    string numberInString = std::to_string(number);
    return GetTranslationCount(numberInString);
}

int GetTranslationCount(const string& s){
    const int sz = s.length();
    vector<int> dp(sz+1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= sz; ++i){
        dp[i] = dp[i-1];
        int tmp = 10 * (s[i-2] - '0') + (s[i-1] - '0');
        if(s[i-2] == '0' || tmp > 25)
            continue;
        else
            dp[i] += dp[i-2];
    }
    return dp[sz];
}

int main(){
    int ans = GetTranslationCount(12258);
    // assert(ans == 5);
    std::cout << ans << std::endl;
    return 0;
}
