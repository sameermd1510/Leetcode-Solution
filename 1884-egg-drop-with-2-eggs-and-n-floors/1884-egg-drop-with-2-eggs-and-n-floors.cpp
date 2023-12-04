class Solution {
public:
    int twoEggDrop(int n) {
        
        int i=1;
        for(i=1; (i*(i+1)/2 )<n  ;i++);
        return i;
    }
};