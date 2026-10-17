class MedianFinder {
private:
    priority_queue<int> left;//max queue
    priority_queue<int,vector<int>,greater<int>> right;//min queue

public:
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        //inserting element
        if(left.empty() || left.top() >= num){
            left.push(num);
        }
        else{
            right.push(num);
        }
        
        //balancing the queues
        if(left.size() > right.size() + 1){
            right.push(left.top());
            left.pop();
        }
        else if(right.size() > left.size()){
            left.push(right.top());
            right.pop();
        }
        else{
            
        }
        
    }
    
    double findMedian() {
        
        if(left.size() > right.size()){
            return left.top();
        }
        
        return ((double)left.top()+right.top())/2.0;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */