class MyQueue {
private:
    stack<int> st1; //primary stack
    stack<int> st2; //secondary stack

public:
    MyQueue() {
        
    }
    
    void push(int x) { //T.C.=O(n)
        while(!st1.empty()) //empty stack1 into stack2
        {
            st2.push(st1.top());
            st1.pop();
        }
        st2.push(x); //push curr into stack2
        while(!st2.empty()) //empty stack2 into stack1
        {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() { //T.C.=O(1)
        int popped= st1.top();
        st1.pop();
        return popped;
    }
    
    int peek() { //T.C.=O(1)
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */