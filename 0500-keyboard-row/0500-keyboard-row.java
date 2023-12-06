class Solution {
     Map<Integer, Set<Character>> m = new HashMap<>();

    void put(int k, String s) {
        Set<Character> charSet = new HashSet<>();
        for (char ch : s.toCharArray()) {
            charSet.add(ch);
        }
        m.put(k, charSet);
    }

    public String[] findWords(String[] w) {
        String s1 = "qwertyuiop", s2 = "asdfghjkl", s3 = "zxcvbnm";
        put(1, s1);
        put(2, s2);
        put(3, s3);

        List<String> ans = new ArrayList<>();
        for (String x : w) {
            boolean found = false;
            for (int i = 1; i <= 3; i++) {
                int fl = 1;
                for (char ch : x.toCharArray()) {
                    ch = Character.toLowerCase(ch); // Convert char to lowercase
                    if (!m.get(i).contains(ch)) {
                        fl = 0;
                        break;
                    }
                }
                if (fl == 1) {
                    ans.add(x);
                    found = true;
                    break;
                }
            }
        }
        return ans.toArray(new String[0]);
    }
}