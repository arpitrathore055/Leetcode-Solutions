class MinStack {

    stack<int> mainStack;
    stack<int> minStack;

public:
    MinStack() {
    }
    
    void push(int val) {
        mainStack.push(val);
        int prevMin=(!minStack.empty())?minStack.top():INT_MAX;
        if(prevMin == INT_MAX){
            minStack.push(val);
            return;
        }
        minStack.push(min(prevMin,val));
    }
    
    void pop() {
        mainStack.pop();
        minStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
