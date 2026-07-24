class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> evaluationStack;

        for(auto operand:tokens){
            if(operand == "+" || operand == "-" || operand == "*" || operand == "/"){
                int operand2=evaluationStack.top();
                evaluationStack.pop();
                int operand1=evaluationStack.top();
                evaluationStack.pop();
                
                if(operand == "+"){
                    evaluationStack.push(operand1 + operand2);
                }
                else if(operand == "-"){
                    evaluationStack.push(operand1 - operand2);
                }
                else if(operand == "*"){
                    evaluationStack.push(operand1 * operand2);
                }
                else{
                    evaluationStack.push(operand1 / operand2);
                }

            }
            else{
                evaluationStack.push(stoi(operand));
            }
        }

        return (!evaluationStack.empty())?evaluationStack.top():-1;

    }
};
