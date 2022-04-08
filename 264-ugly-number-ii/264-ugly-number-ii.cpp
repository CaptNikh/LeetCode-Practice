class Solution {
public:
    long nthUglyNumber(int n) {
        
        priority_queue<long, vector<long>, greater<long>> pq;
        pq.push(1);
        
        unordered_set<long> s;
        s.insert(1);
        
        long ans = 1;
        
        while(n--)
        {
            ans = pq.top();
            // cout << ans << " ";
            pq.pop();
            
            if(s.find(ans * 2) == s.end()){
                pq.push(ans * 2);
                s.insert(ans * 2);
            }
            if(s.find(ans * 3) == s.end()){
                pq.push(ans * 3);
                s.insert(ans * 3);
            }
            if(s.find(ans * 5) == s.end()){
                pq.push(ans * 5);
                s.insert(ans * 5);
            }
        }
        
        return ans;
    }
};