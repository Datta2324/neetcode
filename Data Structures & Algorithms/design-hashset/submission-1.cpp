class MyHashSet {
public:
    list<int> hs;
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(this->contains(key) == false)
            hs.push_back(key);
    }
    
    void remove(int key) {
         if(this->contains(key) == true)
             hs.remove(key);  
    }
    
    bool contains(int key) {
        for(auto &i : hs)
        {
            if(i == key)
                return true;
        }
        return false;
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */