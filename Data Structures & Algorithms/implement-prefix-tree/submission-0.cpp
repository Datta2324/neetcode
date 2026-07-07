struct Node{
    Node* links[26];
    bool flag = false;

    bool containsKey(char c)
    {
        return(links[c -'a'] != nullptr);
    }
    void put(char c, Node* node)
    {
        links[c-'a'] = node;
    }
    Node* moveToNext(char c)
    {
        return links[c - 'a'];
    }
    void setFlag()
    {
        flag = true;
    }
};
class PrefixTree {
private:
    Node* root;
public:
    PrefixTree() {
        root = new Node(); 
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->moveToNext(word[i]);
        }
        node->setFlag();
        
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i ++)
        {
            if(!node->containsKey(word[i]))
                return false;
            node = node->moveToNext(word[i]);
        }
        return node->flag;
        
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0; i < prefix.size(); i++)
        {
            if(!node->containsKey(prefix[i]))
                return false;
            
            node = node->moveToNext(prefix[i]);  
        }
        return true;
        
    }
};
