class RandomizedSet {
public:
    template<typename S>
        auto select_random(const S &s, size_t n) {
            auto it = std::begin(s);
            // 'advance' the iterator n times
            std::advance(it,n);
            return it;
        }   
    unordered_set<int> s;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        auto toBeInserted = s.find(val) == s.end();
        s.insert(val);
        return toBeInserted;
    }
    
    bool remove(int val) {
        auto toBeRemoved = s.find(val) != s.end();
        s.erase(val);
        return toBeRemoved;
    }
    
    int getRandom() {
        auto r = rand() % s.size(); 
        return *select_random(s, r);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */