public class Solution {
	public ArrayList<Integer> maxone(ArrayList<Integer> a, int b) {
        ArrayList<Integer> result = new ArrayList<>();
        if (a.size() == 0 || b < 0) {
            return result;
        }
        int start = 0; // start index of current window
        int count = 0; // number of zeros in current window
        int globalStart = -1;
        int globalEnd = -1;
        int len = 0; // global longest
        for (int i = 0; i < a.size(); i++) {
            if (a.get(i) == 0) {
                count++;
            }
            if (count > b) {
                // current 0 breaks current window ([start : i] has b + 1 0s)
                // until current window has only b times 0
                // find the new start position s.t. [start:i] has only b 0s
                for (int j = start; j <= i; j++) {
                    if (a.get(j) == 0) {
                        count--;
                        // start from position after current 0
                        start = j + 1;
                        break;
                    }
                }
            } else {
                // update global result
                if (i - start + 1 > len) {
                    len = i - start + 1;
                    globalStart = start;
                    globalEnd = i;
                }
            }
        }
        if (globalStart != -1) {
            for (int i = globalStart; i <= globalEnd; i++) {
                result.add(i);
            }
        }
        return result;
	}
}
