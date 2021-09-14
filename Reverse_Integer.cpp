class Solution {
public:
    int reverse(int x) {
        
        long long int y = x, z = 0;
        bool flag = false;
        
        if(y<0){flag = true; y = -1*y;}
        
        while(y){
            z*=10;
            z+=y%10;
            y/=10;
        }
        
        if(z<INT_MIN or z>INT_MAX)z = 0;
        
        return flag?-1*z:z;
        
    }
};