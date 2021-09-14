class Solution {
public:
    int candy(vector<int>& ratings) {
        
        vector<int> candies(ratings.size(),1);
        
        for(int i = 0; i < ratings.size()-1; i++){
            if(ratings[i]>ratings[i+1] and candies[i]<=candies[i+1]){
                candies[i] = candies[i+1]+1;
            }
            else if(ratings[i]<ratings[i+1] and candies[i]>=candies[i+1]){
                candies[i+1] = candies[i]+1;
            }
        }
        
        for(int i = ratings.size()-1; i>0;i--){
            
            if(ratings[i]<ratings[i-1] and candies[i]>=candies[i-1]){
                candies[i-1] = candies[i]+1;
            }
            if(ratings[i]>ratings[i-1] and candies[i]<=candies[i-1]){
                candies[i] = candies[i-1]+1;
            }
            
        }
        
        return accumulate(candies.begin(),candies.end(), 0);
        
    }
};