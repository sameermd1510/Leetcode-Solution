class Solution {
    public int[] findDiagonalOrder(List<List<Integer>> a) {
       Map<Integer, List<Integer>> diagonalMap = new HashMap<>();

        // Traverse the matrix and store elements in the diagonal map
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < a.get(i).size(); j++) {
                int sum = i + j;
                diagonalMap.putIfAbsent(sum, new ArrayList<>());
                diagonalMap.get(sum).add(a.get(i).get(j));
            }
        }

        List<Integer> result = new ArrayList<>();

        // Construct the result array by reading diagonals from the map
        for (int key = 0; key < diagonalMap.size(); key++) {
            List<Integer> diagonalElements = diagonalMap.get(key);
            Collections.reverse(diagonalElements); // Reverse the elements for alternate direction
            result.addAll(diagonalElements);
        }

        // Convert the list to an array
        int[] ansArray = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            ansArray[i] = result.get(i);
        }

        return ansArray;
        
    }
}