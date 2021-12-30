class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, float>> arr;
        
        for(int i = 0; i < position.size(); i++)
        {
            arr.push_back({position[i], ((float)(target - position[i]) / (float)speed[i])});
        }
        
        sort(arr.begin(), arr.end(), greater<>());
       
        int cnt = 1;
        for(int i = 0; i < arr.size() - 1; i++)
        {
            if(arr[i].second < arr[i + 1].second)
                cnt++;
            else
                arr[i + 1] = max(arr[i], arr[i + 1]);
        }
        return cnt;
    }
};