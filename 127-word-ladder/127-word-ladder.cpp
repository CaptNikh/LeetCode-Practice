class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool> visited;
        
        queue<pair<string, int>> q;
        
        set<string> s(wordList.begin(), wordList.end());
        
        visited[beginWord] = true;
        
        q.push({beginWord, 0});
        
        while(!q.empty())
        {
            pair<string, int> x = q.front();
            q.pop();
            
            string temp = x.first;
            
            if(temp == endWord)
                return x.second + 1;
            
            for(int i = 0; i < temp.size(); i++)
            {
                char ch = temp[i];
                
                for(int j = 0; j < 26; j++)
                {
                    temp[i] = j +  'a';
                    
                    if(s.find(temp) != s.end() && !visited[temp])
                    {
                        visited[temp] = true;
                        q.push({temp, x.second + 1});
                    }
                }
                
                temp[i] = ch;
            }
        }
        
        return 0;
        
    }
};