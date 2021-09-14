class Solution {
public:
    double myPow(double x, int n) {
        if(x==1) return 1;
        
        if(n==1) return x;
        if(n==0) return 1;
        
        if(n>0){
            if(n%2==0) return pow(x,n/2)*pow(x,n/2);
            else return pow(x,n/2)*pow(x,n/2)*x;
        }
        else{
            if(n!=INT_MIN) return 1/pow(x,-1*n);
            else return 1/pow(x,-1*(n+1))*(1/x);
        }
       
    }
};