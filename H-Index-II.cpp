class Solution {
public:
    int hIndex(vector<int>& c) {
        int n=c.size();
        int start=0 , end = c.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(c[mid]==n-mid)
              return n-mid;
            else if (c[mid] > n-mid)
                end=mid-1;
            else
                start=mid+1;
        }
        return n-start;
    }
};