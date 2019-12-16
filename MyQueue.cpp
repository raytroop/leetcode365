//https://leetcode.com/problems/implement-queue-using-stacks/

#include <stack>
using std::stack;

//https://zxi.mytechroad.com/blog/stack/leetcode-232-implement-queue-using-stacks/
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) {
        s1_.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (s2_.empty()) move();
        int top = s2_.top();
        s2_.pop();
        return top;
    }

    /** Get the front element. */
    int peek() {
        if (s2_.empty()) move();
        return s2_.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s1_.empty() && s2_.empty();
    }
private:
    stack<int> s1_;
    stack<int> s2_;

    void move() {
        while (!s1_.empty()) {
            s2_.push(s1_.top());
            s1_.pop();
        }
    }
};
