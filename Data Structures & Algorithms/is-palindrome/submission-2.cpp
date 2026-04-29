class Solution {
public:
    bool isPalindrome(string s) {

        int l = 0;
        int r = s.size() - 1;
        while(l < r)
        {
            if( !(s[l] >= 48 && s[l] <= 57 ) && !(s[l] >= 65 && s[l] <= 90 ) && !(s[l] >= 97 && s[l] <= 122 ))
                l++;
            else if( !(s[r] >= 48 && s[r] <= 57 ) && !(s[r] >= 65 && s[r] <= 90 ) && !(s[r] >= 97 && s[r] <= 122 ))
                r--;
            else if(tolower(s[l]) == tolower(s[r]))
            {
                l++;
                r--;
            }
            else
                return false;
        }       
        return true;
    }
};
