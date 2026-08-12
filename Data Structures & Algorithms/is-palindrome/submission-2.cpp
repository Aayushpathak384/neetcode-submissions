class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0 ; 
        int end = s.length();
        end = end - 1;
        while(start<=end)
        {
            if(s[start]>=65 && s[start]<=90 || s[start]>= 97 && s[start]<= 122 || s[start]>= '0' && s[start]<= '9' ) 
            {
                if(s[end]>=65 && s[end]<=90 || s[end]>= 97 && s[end]<= 122 || s[end]>= '0' && s[end]<= '9') 
                {
                    if(tolower(s[start])!=tolower(s[end]))
                    return false;
                    else
                    {
                        start++;
                        end--;
                    }
                }
                else
                end--;
            }
            else 
            start++;
        }
        return true;
    }
};
