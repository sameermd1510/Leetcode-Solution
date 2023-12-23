class Solution {
    public boolean isPathCrossing(String p) {
        
        Map<Character, int[]> m = new HashMap<>();
        m.put('N', new int[]{0, 1});
        m.put('S', new int[]{0, -1});
        m.put('E', new int[]{1, 0});
        m.put('W', new int[]{-1, 0});
        
        Set<String> s = new HashSet<>();
        int px = 0, py = 0;
        s.add("0-0");
        
        for (char ch : p.toCharArray()) {
            int[] t = m.get(ch);
            int x = px + t[0], y = py + t[1];
            String str = x + "-" + y;
            
            if (!s.contains(str)) {
                s.add(str);
                px = x;
                py = y;
            } else {
                return true;
            }
        }
        return false;
    }
}