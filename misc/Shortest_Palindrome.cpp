class Solution {
public:
    int fun(string& s)
    {
        int n=s.length();
        vector<int> lps(n);
        int len=0;
        lps[0]=0;
        int i=1;
        while(i<n)
        {
            if(s[len]==s[i])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len!=0)len=lps[len-1];
                else
                {
                    lps[i]=0;
                    i++;
                }
            }
        }
        return lps[n-1];
    }
    string shortestPalindrome(string s) {
        string s1=s;
        int n=s.length();
        reverse(s1.begin(),s1.end());
        string res=s+"#"+s1;
        int x=fun(res);
        string ans;
        // cout<<n-x<<endl;
        for(int i=0;i<n-x;i++)
        {
            ans.push_back(s1[i]);
        }
        ans+=s;
        return ans;
    }
};