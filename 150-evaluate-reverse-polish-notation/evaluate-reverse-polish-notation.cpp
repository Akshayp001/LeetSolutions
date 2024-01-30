class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        unordered_set<string> expr({"+", "-", "*", "/"});

        for (string& element : tokens) {
            if (expr.find(element) == expr.end()) {
                s.push(stoi(element));
            } else {
                int num2 = s.top();
                s.pop();
                int num1 = s.top();
                s.pop();

                if (element == "+") {
                    s.push(num1 + num2);
                } else if (element == "-") {
                    s.push(num1 - num2);
                } else if (element == "*") {
                    s.push(num1 * num2);
                } else {
                    s.push(num1 / num2);
                }
            }
        }

        return s.top();
    }
};