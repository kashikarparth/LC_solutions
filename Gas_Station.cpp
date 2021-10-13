class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        if(gas.size()==1) return gas[0]>=cost[0]?0:-1;
        
        int start = 0;
        int curr = start;
        int trips = 0;
        int fuel = 0;
        
        while(trips< gas.size() and start < gas.size()){
            
            fuel+=(gas[curr]);
            
            if(cost[curr]>fuel){
                start++;
                fuel = 0;
                curr = start;
                trips = 0;
                
            }
            
            else{
                fuel-=cost[curr];
                curr++;
                if(curr==gas.size()) curr = 0;
                trips++;
            }
            
        }
        
        if(start>=gas.size()) return -1;
        return start;
        
        
    }
};