/*
写一个算法将栈里的元素升序排列。栈的实现未知，算法只能借助栈完成， 可使用的操作包括push pop top empty
 等。
*/

/*
 可借助另外一个栈来完成排序，思想是从原始栈里依次弹出元素放入辅助栈，每当将要压入的元素使得辅助栈不是升序排列，
 就将辅助栈里的元素重新压入原始栈，直到辅助栈里的元素都小于当前要压入的元素，然后再压入当前的元素。
 */

#include <stack>
using std::stack;

void stackSort(stack<int>& s){
    stack<int> aid;

    // push all in aid stack
    while(!s.empty()){
        aid.push(s.top());
        s.pop();
    }

    while(!aid.empty()){
        int cur = aid.top();
        aid.pop();
        while(!s.empty() && s.top() > cur){
            aid.push(s.top());
            s.pop();
        }
        s.push(cur);
    }
}