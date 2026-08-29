class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> myStack;

        for (string token : tokens) {
            if (token == "+" || token == "-" || token == "/" || token == "*") {
                int b = myStack.top();
                myStack.pop();
                int a = myStack.top();
                myStack.pop();

                if (token == "+") {
                    myStack.push(a + b);
                }
                else if (token == "-") {
                    myStack.push(a - b);
                }
                else if (token == "*") {
                    myStack.push(a * b);
                }
                else {
                    myStack.push(a / b);
                }
            }
            else {
                myStack.push(stoi(token));
            }
        }
        return myStack.top();
    }
};