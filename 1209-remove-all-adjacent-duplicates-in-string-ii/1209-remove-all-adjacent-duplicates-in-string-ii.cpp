class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int i = 0; i < s.size(); i++){
            if(st.empty())
            {
                st.push({s[i], 1});
            }
            else {
                if(s[i] == st.top().first){
                    st.push({s[i], st.top().second + 1});
                }
                else {
                    st.push({s[i], 1});
                }
                if(st.top().second == k)
                {
                    int x = k;
                    while(x--) {
                        st.pop();
                    }
                }
            }
        }
                        
        string ans;
        while(!st.empty()) {
            ans += st.top().first;
            st.pop();
        }
                        
        reverse(ans.begin(), ans.end());
                        
        return ans;
    }
};