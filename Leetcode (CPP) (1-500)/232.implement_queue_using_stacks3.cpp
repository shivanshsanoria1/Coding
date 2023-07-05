class MyQueue {
private:
    stack<int> in; //acts as 'rear' of the queue for pushing the elements
    stack<int> out; //acts as 'front' of the queue for popping the elements

public:
    MyQueue() {
        
    }
    
    void push(int x) { //T.C.=O(1)
        in.push(x);
    }
    
    int pop() { //T.C.=O(1)
        if(out.empty()) //out stack is empty
            while(!in.empty()) //empty the 'in' stack into the 'out' stack
            {
                out.push(in.top());
                in.pop();
            }
        int popped=out.top();
        out.pop();
        return popped;
    }
    
    int peek() { //T.C.=O(1)
        if(out.empty()) //out stack is empty
            while(!in.empty()) //empty the 'in' stack into the 'out' stack
            {
                out.push(in.top());
                in.pop();
            }
        return out.top();
    }
    
    bool empty() {
        return out.empty() && in.empty();
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