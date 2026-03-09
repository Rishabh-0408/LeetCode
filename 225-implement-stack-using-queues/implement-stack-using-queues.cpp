class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        int size = q.size();
        //pushing the value
        q.push(x);
        //rotating the value
        for(int i = 0; i < size; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int topele = q.front();
        q.pop();
        return topele;
    }
    
    int top() {
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