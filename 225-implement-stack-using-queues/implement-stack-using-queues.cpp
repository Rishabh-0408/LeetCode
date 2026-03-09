class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        // Step 1: Push new element to helper queue q2
        q2.push(x);
        while(!q1.empty()){
            //transfering the element
            q2.push(q1.front());
            q1.pop();
        }
        //swapping the values
        swap(q1,q2);
    }
    
    int pop() {
        int topelement = q1.front();
        q1.pop();
        return topelement;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
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