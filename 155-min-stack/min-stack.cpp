class MinStack {
    stack<long long> st;
    long long min;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        long long val = value;
        if(st.empty()){
            st.push(val);
            min = val;
        }
        else{
            if(val > min){
                st.push(val);
            }
            else{
                st.push(2*val-min);
                min = val;
            }
        }
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        long long top_val = st.top();
        st.pop();
        if (top_val < min) {
            min = 2 * min - top_val; 
        }
    }
    
    int top() {
        if(st.empty()){
            return 0;
        }
        long long top = st.top();
        if(top < min) return min;
        else return top;
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */