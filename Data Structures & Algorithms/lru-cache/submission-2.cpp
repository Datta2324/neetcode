class LRUCache {
public:
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int,int>>::iterator> um;
    int cap;
    LRUCache(int capacity ) {
        cap = capacity;
    }
    
    int get(int key) {
        //if key doesnt exist
        if(um.contains(key) == false)
            return -1;
        // Key exists
        auto it = um[key];
        l.splice(l.end(),l,it);
        return it->second;
    }
    
    void put(int key, int value) {
        //if key exists
        if(um.contains(key))
        {
            // Get iterator
               auto it = um[key];
            // Update value
                it->second = value;
            // Move it to end
              l.splice(l.end(), l, it);
        }
        //Key doesnt exist
        else
        {
            // Capacity not full
            if(l.size() < cap)
            {
                // Insert
                    l.emplace_back(key,value);
                // Update map
                    um[key] = prev(l.end());
            }
            //Capacity full
            else
            {
                // Update the key val of the first
                    int oldKey = l.front().first;
                    l.front().first = key;
                    l.front().second = value;
                // Move it to the end
                    l.splice(l.end(),l,l.begin());
                // Update the map
                    um.erase(oldKey);
                    um[key] = prev(l.end());
            }
        }
        
    }
};
