class WordDictionary {
public:
    
    unordered_map< string, bool> m;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        m[word]=1;
    }
    
    bool search(string word) {
        
        if(m.find(word)!=m.end()) return true;  
        string s=word;
        for( int i=0;i<s.size();i++){
            if(s[i]=='.'){
                for( char ch='a' ;ch<='z';ch++){
                    s[i]=ch;
                    if(m.find(s)!=m.end()) return true;
                    
                    for(int j=i+1;j<s.size();j++){
                        if(s[j]=='.'){
                            for( char c='a' ;c<='z';c++){
                                s[j]=c;
                                
                                if(m.find(s)!=m.end()) return true;
                            }
                            s[j]='.';
                            break;
                        }
                    }
                }
                break;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */