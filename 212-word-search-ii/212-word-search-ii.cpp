class Solution {
public:
     vector<string> ans;
    
    struct node
    {
        bool end;
        string s;
        node *next[26];
    }*trie;
    
    void insert(string str)
    {
        node *t=trie;
        
        for(char ch:str)
        {
            int in=ch-'a';
            
            if(!t->next[in])
                t->next[in]=new node();
            
            t=t->next[in];
        }
        t->end=1;
        t->s=str;
    }
    
    void make_trie(vector<string>& w)
    {        
        for(string str:w)
            insert(str);
    }
    
    void search(vector<vector<char>>& b,int i,int j,int m,int n,node *t)
    {
        int in=b[i][j]-'a';
        
        if(!t->next[in])
            return;
        
        t=t->next[in];
        if(t->end)
        {
            ans.push_back(t->s);
            t->end=0;
        }
        
        char c=b[i][j];
        b[i][j]='.';
        
        if(i-1>=0 && b[i-1][j]!='.')
            search(b,i-1,j,m,n,t);
        
        if(j-1>=0 && b[i][j-1]!='.')
            search(b,i,j-1,m,n,t);
        
        if(i+1<m && b[i+1][j]!='.')
            search(b,i+1,j,m,n,t);
        
        if(j+1<n && b[i][j+1]!='.')
            search(b,i,j+1,m,n,t);
        
        b[i][j]=c;
    }
    
    vector<string> findWords(vector<vector<char>>& b, vector<string>& w) {
        
        int m=b.size(),n=b[0].size();
        int i,j;
        ans={};
        
        trie=new node();
        make_trie(w);
        
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                search(b,i,j,m,n,trie);
        
        return ans;
    }   
};