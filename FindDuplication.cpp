#include <vector>
#include <algorithm>
#include <cassert>
using std::vector;

int FindDuplication(vector<int>& numbers){
    const int sz = numbers.size();
    if(sz == 0)
        return -1;
    for(int i = 0; i < sz; ++i){
        while(numbers[i] != i){
            if(numbers[i] == numbers[numbers[i]])
                return numbers[i];
            else
                std::swap(numbers[i], numbers[numbers[i]]);
        }
    }

    return -1;
}

int main(){
    vector<int> numbers{2, 3, 1, 0, 2, 5, 3};
    int ans = FindDuplication(numbers);
    assert(ans == 2 || ans == 3);
    return 0;
}