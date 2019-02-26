//https://leetcode.com/problems/student-attendance-record-i/

#include <string>
using std::string;

bool checkRecord(string s) {
    int absent = 0;
    const int n = s.length();
    for(int i = 0; i < n; ++i){
        if(s[i] == 'A' && ++absent > 1)
            return false;
        if(s[i] == 'L' && i > 1 && s[i-1] == 'L' && s[i-2] == 'L')
            return false;
    }

    return true;
}
