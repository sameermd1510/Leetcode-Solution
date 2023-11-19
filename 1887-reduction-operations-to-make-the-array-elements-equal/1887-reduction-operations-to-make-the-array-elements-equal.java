
// class Solution {
//     Comparator<Integer> Desc = new Comparator<Integer>() {
//         @Override 
//         public int compare(Integer s1, Integer s2) {
//             return s2-s1;
//         }           
//     };
//     public int reductionOperations(int[] a) {
        
        
//          // SortedMap<Integer , Integer> m=new TreeMap<>(Sort); 
//          //    = new TreeMap<String, String>(new Comparator<String>() { 
//          //          public int compare(String a, String b) 
//          //          { 
//          //              return b.compareTo(a); 
//          //          } 
//          //      }); 
//         //map< int, int,greater<int>> m;
//         SortedMap<Integer, Integer> m= new TreeMap<>(Desc);
//         for (int x : a) {
//             m.put(x, m.getOrDefault(x, 0) + 1);
//         }
        
// //         for( int x:a) m[x]++;
    
// //         int prev=0, ans=0 , n=m.size() ;
        
// //         for( auto& t:m){
// //             if(n==1) break;
// //             ans=ans+ (t.second+prev);
// //             prev+=t.second;
// //             n--;
// //         }
//         int ans=0;
//         return ans;
//     }
// }
import java.util.*;

class Solution {
    Comparator<Integer> Desc = new Comparator<Integer>() {
        @Override 
        public int compare(Integer s1, Integer s2) { // Change int to Integer
            return s2 - s1;
        }           
    };
    
    public int reductionOperations(int[] a) {
        SortedMap<Integer, Integer> m = new TreeMap<>(Desc);
        for (int x : a) {
            m.put(x, m.getOrDefault(x, 0) + 1);
        }

        int prev = 0, ans = 0;
        for (Map.Entry<Integer, Integer> entry : m.entrySet()) {
            int freq = entry.getValue();
            ans += (freq + prev);
            prev += freq;
        }

        // Subtract the last added frequency (to exclude the largest element)
        ans -= prev;

        return ans;
    }
}
