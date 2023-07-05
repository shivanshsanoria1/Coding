class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto it: tokens)
        {
            if(it !="+" && it !="-" && it !="*" && it !="/") //curr string is not an operator, ie,
                st.push(stoi(it)); //it is a number so push it in stack
            else
            {
                int b=st.top(); //pop 2 elements from stack- B and A
                st.pop();
                int a=st.top();
                st.pop();
                int res; //find the result of A operator B and push it in stack
                if(it == "+")
                    res=a+b;
                else if(it == "-")
                    res=a-b;
                else if(it == "*")
                    res=a*b;
                else if(it == "/")
                    res=a/b;
                st.push(res);
            }
        }
        return st.top();
    }
};