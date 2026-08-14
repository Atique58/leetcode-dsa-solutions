class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> st;
        int result;
        for(string t:tokens)
        {
            if(t == "+" || t == "-" || t == "*" || t == "/")
            {
                int n1=st.top();
                st.pop();
                int n2=st.top();
                st.pop();

                if(t=="+")
                {
                    result=n1+n2;
                }
                else if(t=="*")
                {
                    result=n1*n2;
                }
                else if(t=="-")
                {
                    result=n2-n1;
                }
                else 
                {
                    result=n2/n1;
                }
                st.push(result);
            }
            else
            {
                int num=stoi(t);
                st.push(num);
            }
        }  
        return st.top();              
    }
};