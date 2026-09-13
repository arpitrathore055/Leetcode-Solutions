class RandomizedSet {

    unordered_map<int,int> indexMap;
    vector<int> setElements;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {

        if(indexMap.find(val) != indexMap.end()){
            return false;
        }
        setElements.push_back(val);
        indexMap[val]=setElements.size()-1;
        return true;
        
    }
    
    bool remove(int val) {
        
        if(indexMap.find(val) == indexMap.end()){
            return false;
        }
        int swappedValue=setElements.back();
        int swappedIndex=indexMap[val];
        swap(setElements[indexMap[val]],setElements.back());
        setElements.pop_back();
        indexMap[swappedValue]=swappedIndex;
        indexMap.erase(val);

        return true;

    }
    
    int getRandom() {

        return setElements[rand() % setElements.size()];

    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */