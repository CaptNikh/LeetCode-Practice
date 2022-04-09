class Solution {
public:
    long long nthSuperUglyNumber(int n, vector<int>& primes) {
        
        vector<long long> arr;
        auto cmp = [&arr](pair<long long, long long> &a, pair<long long, long long> &b){
            return a.first * arr[a.second] > b.first * arr[b.second];
        };
        
        priority_queue<pair<long long, long long> ,vector<pair<long long, long long>> , decltype(cmp)> pq(cmp);
        arr.push_back(1);
        for(int i = 0; i < primes.size(); i++)
        {
            pq.push({primes[i], 0});
        }
        
        
        
        while(arr.size() < n){
            
            pair<long long, long long> p = pq.top();
            pq.pop();
            
            if(arr[arr.size() - 1] < (p.first * arr[p.second]))
                arr.push_back(p.first * arr[p.second]);
            
            pq.push({p.first, p.second + 1});
        }
        
        return arr[arr.size() - 1];
    }
    
};