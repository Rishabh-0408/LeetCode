class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        //Step 1: Move all elements from s1 to s2
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }

        //Step 2: Push the new element into s1
        st1.push(x);

        //Step 3: Move all elements from s2 to s1
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        int top_val = st1.top();
        st1.pop();
        return top_val;
    }
    
    int peek() {
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