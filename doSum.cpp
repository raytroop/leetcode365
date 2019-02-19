#include <string>
#include <algorithm>
#include <iostream>

using std::string;

string doSum(string a, string b){
    string s1, s2;
    if(a.length() < b.length()){
        s1 = b;
        s2 = a;
    }
    else{
        s1 = a;
        s2 = b;
    }
    const int sz1 = s1.length();
    const int sz2 = s2.length();
    int c = 0;
    for(int i = sz2 - 1 ; i >= 0; --i){
        int num = s1[sz1 - sz2 + i] + s2[i] + c  - '0' - '0';
        c = num / 10;
        s1[sz1 - sz2 + i] = '0' + num % 10 ;
    }

    for(int i = sz1 - sz2 - 1; i >= 0; --i){
        int num = s1[i] + c - '0';
        c = num / 10;
        s1[i] = '0' + num % 10;
    }

    if(c > 0){
        string k("0");
        k[0] += c;
        return k + s1;
    }
    else
        return s1;
}

int main(){
    string s1("123");
    string s2("91");
    string ans = doSum(s1, s2);
    std::cout << ans << std::endl;
    return 0;
}