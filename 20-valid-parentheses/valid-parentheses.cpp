class Solution {
public:
    bool isValid(string s) {
        // Optimization: If the length is odd, it cannot be valid
        if (s.length() % 2 != 0) {
            return false;
        }

        stack<char> st;
        
        for (char c : s) {
            // Push open brackets onto the stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            // Handle closing brackets
            else {
                // If there's no matching open bracket, it's invalid
                if (st.empty()) {
                    return false;
                }
                
                char top = st.top();
                
                // If it matches the top of the stack, pop it
                if ((c == ')' && top == '(') || 
                    (c == '}' && top == '{') || 
                    (c == ']' && top == '[')) {
                    st.pop();
                } 
                // If it doesn't match, it's invalid
                else {
                    return false;
                }
            }
        }
        
        // If the stack is empty at the end, all brackets were matched properly
        return st.empty();
    }
};