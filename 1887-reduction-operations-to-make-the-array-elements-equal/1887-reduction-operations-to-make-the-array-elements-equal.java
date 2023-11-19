import java.util.*;
class Solution {
    Comparator<Integer> Desc = new Comparator<Integer>() {
        @Override 
        public int compare(Integer a, Integer b) {
            return b - a;
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
