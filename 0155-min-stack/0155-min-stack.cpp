class MinStack {

    stack<pair<int,int>> mainStack;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        int prevMin=(mainStack.empty())?INT_MAX:mainStack.top().second;
        mainStack.push({val,min(prevMin,val)});
    }
    
    void pop() {
        mainStack.pop();
    }
    
    int top() {
        return mainStack.top().first;
    }
    
    int getMin() {
        return mainStack.top().second;
    }
};
