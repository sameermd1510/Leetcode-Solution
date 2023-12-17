class FoodRatings {
public:
    unordered_map< string, int > fr;
    unordered_map< string, string> fc;
    unordered_map< string, set<pair< int,string>> > cm;
    
    FoodRatings(vector<string>& f, vector<string>& c, vector<int>& r) {
        for( int i=0;i<f.size();i++ ){
            fr[ f[i] ]=r[i];
            fc[ f[i] ]=c[i];
            cm[ c[i] ].insert({-r[i],f[i]});
        }
    }
    
    void changeRating(string f, int nr) {
        
        string cu=fc[f];
        auto t= cm[cu].find({ -fr[f],f});
        cm[cu].erase(t);
        
        fr[f]=nr;
        cm[cu].insert({-nr,f});
    }
    
    string highestRated(string c) {
        return cm[c].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */