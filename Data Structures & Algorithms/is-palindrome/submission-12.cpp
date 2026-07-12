class Solution {
public:
    bool isPalin(string& s, int l , int r)
    {
        if(l >= r)
            return true;
        if(!isalnum(s[l]))
            return isPalin(s,l+1,r);
    
        else if(!isalnum(s[r]))
            return isPalin(s,l,r-1);
        
        else if(tolower(s[l]) != tolower(s[r]))
            return false;
        
        return isPalin(s,l+1,r-1);

    }
    bool isPalindrome(string s) {
        return isPalin(s,0,s.size()-1);
        
    }
};
