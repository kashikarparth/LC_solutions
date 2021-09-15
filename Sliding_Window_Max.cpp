class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        if(!nums.size() or k==1) return nums;
        
        vector<int> ans;
        
        priority_queue<pair<int,int>>pq;
        
        int i = 0; int j = k-1;
        
        for(int l = i; l <=j; l++){
            pq.push({nums[l], l});
        }
        
        ans.push_back(pq.top().first);
        
        while(j<nums.size()){
            
            i++; j++; //on next window
            
            if(j>=nums.size()) break;
            
            pq.push({nums[j], j});
            
            //if max crossed
            if(i>pq.top().second){
                int prev_ind = pq.top().second;
                while(!pq.empty() and pq.top().second<=prev_ind) pq.pop();
            }
            
            ans.push_back(pq.top().first);
        }
        
        return ans;
        
        
    }
};