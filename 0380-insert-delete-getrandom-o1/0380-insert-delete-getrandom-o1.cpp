class RandomizedSet {
    
    vector<int>vect;
    unordered_map<int,int>mp;
    int vectSize,mpSize;

public:
    RandomizedSet() {
        vectSize=0;
        mpSize=0;
    }
    
    bool insert(int val) {
        if(mp.find(val)==mp.end()){
            mp[val]=vectSize;
            vect.push_back(val);
            ++vectSize;
            ++mpSize;
            return true;
        }
        else{
            return false;
        }
    }
    
    bool remove(int val) {
        if(mp.find(val)!=mp.end()){
            int targetInd=mp[val];
            vect[targetInd]=vect[vectSize-1];
            vect.pop_back();
            --vectSize;
            mp[vect[targetInd]]=targetInd;
            mp.erase(val);
            --mpSize;
            return true;
        }
        else{
            return false;
        }
    }
    
    int getRandom() {
        int randInd=rand()%mpSize;
        return vect[randInd];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */