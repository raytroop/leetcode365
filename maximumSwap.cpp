// https://leetcode.com/problems/maximum-swap/

// https://leetcode.com/problems/maximum-swap/solution/
// Approach #2: Greedy [Accepted]

#include <string>
#include <vector>
using std::string;
using std::vector;


int maximumSwap(int num) {
    string s = std::to_string(num);
    vector<int> dict(10, -1);
    for (int i = 0; i < s.length(); ++i)
        dict[s[i] - '0'] = i;

    for (int i = 0; i < s.length(); ++i)
        for (int j = 9; j > s[i] - '0'; --j) {
            if (dict[j] > i) {
                char temp = s[i];
                s[i] = '0' + j;
                s[dict[j]] = temp;

                return std::stoi(s);
            }
        }

    return num;
}