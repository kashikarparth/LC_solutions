class Solution {
public:
    
    int strDiff(string s1, string s2){
        int diff = 0; 
        if(s1.size() == s2.size()){
            for(int i = 0; i < s1.size(); i++){
                if(s1[i]!=s2[i]) diff++;
            }
        }
        return diff;
    }
    
    void make_graph (vector<vector<int>> &g, vector<string>& wordList, string beginWord){
        for(int i = 0; i < wordList.size(); i++){
            for(int j = i+1; j < wordList.size(); j++){
                if(strDiff(wordList[i], wordList[j]) == 1){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        for(int i = 0; i < wordList.size(); i++){
            if(strDiff(beginWord,wordList[i]) == 1){
                g[g.size()-1].push_back(i);
            }
        }
    }
    
    int bfs(vector<vector<int>> &g, int target){
        
        vector<bool> vis(g.size(), false);
        queue<pair<int,int>> q;
        q.push({vis.size()-1, 0});
        
        while(!q.empty()){
            
            int node = q.front().first;
            int dist = q.front().second;
            
            q.pop();
            
            vis[node] = true;
            if(node == target) return dist;
            
            for(auto x: g[node]){
                if(!vis[x]) q.push({x, dist+1});
            }
        }
        
        return -1;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        vector<vector<int>> g(wordList.size()+1, vector<int>());
        int target = -1;
        
        for(int i = 0; i < wordList.size(); i++) if(wordList[i] == endWord) target = i;
        if(target == -1) return 0;
        
        make_graph(g, wordList, beginWord);
        
        return bfs(g, target)+1;

    }
};