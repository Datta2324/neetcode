class LRUCache {
public:
    
    int size = 0;
    unordered_map<int,list<pair<int,int>>::iterator> mpp;
    std::list<pair<int,int>> l;
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(l.size())
        {
            if(mpp.find(key) == mpp.end())
                return -1;
            auto it = mpp[key];
            l.splice(l.end(), l, it);
            return it->second;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end())
        {
            auto it = mpp[key];
            it->second = value;
            l.splice(l.end(), l, it);
        }
        else if(l.size() < size)
        {
            l.push_back({key,value});
            auto it = prev(l.end());
            mpp[key] = it;
        }
        else
        {
            int oldKey = l.front().first;
            mpp.erase(oldKey);
            l.pop_front();   
            l.push_back({key,value});
            auto it = prev(l.end());
            mpp[key] = it;
        }
    }
};
