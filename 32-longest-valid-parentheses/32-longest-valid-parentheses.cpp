class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<int> st;
        
        int n = s.size();
        
        for(int i = 0; i < n; i++){
            if(s[i] == '(')
                st.push(i);
            
            else {
                if(!st.empty() && s[st.top()] == '(')
                    st.pop();
                else
                    st.push(i);
            }
        }
        
        int ans = 0;
        
        if(st.empty())
            ans = n;
        else {
            int res = n;
            
            while(!st.empty()) {
                ans = max(res - st.top() - 1, ans);
                res = st.top();
                st.pop();
            }
            ans = max(ans, res);    
    }
        return ans;
    }
};