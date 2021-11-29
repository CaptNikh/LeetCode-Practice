class Solution {
public: 
    // using compartor function
    /*
    static string t;
    static bool comp(char a, char b)
    {
        return (t.find(a)) < (t.find(b));
    } */
    
    
    string customSortString(string order, string s) {
        
        // t = order;
//      using lambda function 
        unordered_map<char, int> m;
    
        for(int i = 0 ; i < order.size(); i++)
        {
            m[order[i]] = i + 1;
        }
            
        sort(s.begin(), s.end(),[&](char a, char b){
            return m[a] < m[b];
        });
        
        return s;
    }
};
// static variables to be declared outside class
// string Solution :: t;