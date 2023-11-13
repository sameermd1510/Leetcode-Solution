class Solution {
public:
    
    bool vsmall(char ch){
        return ( ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }   
    bool vcap(char ch){
        return ( ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U');
    }
    string sortVowels(string s) {
        
        multiset< char> v;
        
        for( int i=0;i<s.size();i++) {
            if(vsmall(s[i]) || vcap(s[i]) ) {
                v.insert(s[i]);
            }
        }
        
        for( int i=0;i<s.size();i++){
            
            if(vsmall(s[i]) || vcap(s[i]) ){
                auto t=v.begin();
                s[i]=*t;
                v.erase(t);
            }
        }
        return s;
        
    }
};