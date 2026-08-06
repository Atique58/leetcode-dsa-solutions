class Solution {
public:
    int smallestNumber(int n, int t) 
    {
        int current=n;
        while(1)
        {
           int product=1;
           int number=current;
           while(number>0)
           {
                int digit = number % 10;
                product *= digit;
                number /= 10;
           }
           if(product%t==0)
           {
            return current;
           }
        current++; 
        }   
                
    }
};