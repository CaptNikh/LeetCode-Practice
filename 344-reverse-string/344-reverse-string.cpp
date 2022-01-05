class Solution {
public:
    void reverseS(vector<char> &s, int i, int j)
    {
        if(i >= j)
            return;
        
        swap(s[i], s[j]);
        
        reverseS(s, i + 1, j - 1);
    }
    void reverseString(vector<char>& s) {
        reverseS(s, 0, s.size() - 1);
        return;
    }
};