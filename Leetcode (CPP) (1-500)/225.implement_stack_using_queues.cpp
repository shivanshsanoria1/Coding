class MyStack {
private: 
    queue<int> q;
    
public:
    MyStack() {
        
    }
    
    void push(int x) { // T.C.=O(n)
        q.push(x); // push curr element in queue
        int n = q.size();
        // pop (n-1) elements from the front and push them into the rear of the queue
        for(int i=1; i<n; i++) 
        {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() { // T.C.=O(1)
        int popped = q.front();
        q.pop();
        return popped;
    }
    
    int top() { // T.C.=O(1)
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */