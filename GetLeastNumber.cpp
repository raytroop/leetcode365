#include <iostream>
#include <vector>
#include <queue>
using std::vector;
using std::priority_queue;

vector<int> LeastTopK(vector<int>& numbers, int k){
    if(k > numbers.size())
        return {};
    priority_queue<int> q;  // max-heap
    for(auto c: numbers){
        q.push(c);
        if(q.size() > k)
            q.pop();
    }

    vector<int> ans;
    while(! q.empty()){
        ans.push_back(q.top());
        q.pop();
    }

    return ans;
}

int main(){
    vector<int> numbers{4, 5, 1, 6, 2, 7, 3, 8};
    vector<int> ans = LeastTopK(numbers, 4);
    for(auto x: ans)
        std::cout << x << " ";
    std::cout << '\n';
}