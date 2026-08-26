class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long>st;
        unordered_set<string>ops = {"+", "-", "*", "/"};

        for(const string& i : tokens){
            if(ops.count(i)){
                int b = st.top();
                st.pop();
                
                int a = st.top();
                st.pop();

                if(i == "+") st.push(a+b);
                else if(i == "-") st.push(a-b);
                else if(i == "*") st.push(a*b);
                else if(i == "/") st.push(a/b);
            }else{
                st.push(std :: stoi(i));
            }
        }
        return st.top();
    }
};
