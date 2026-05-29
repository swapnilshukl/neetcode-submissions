class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long>st;
        unordered_set<string>ops = {"+", "-", "*", "/"};

        for(const string& token: tokens){
            if(ops.count(token)){
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                if(token == "+") st.push(a+b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(a / b); 
            }else{
                st.push(std::stoi(token));
            }
        }
        return st.top();
    }
};
