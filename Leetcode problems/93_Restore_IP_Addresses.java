import java.util.*;

class Solution {
    List<String> ans;
    private static final int RECURSION_COUNT = 0;
    private static final int START = 0;

    public List<String> restoreIpAddresses(String s) {
        ans = new ArrayList<String>();
        recurse(s, START, new StringBuilder(), RECURSION_COUNT);
        return ans;
    }

    private void recurse(String s, int i, StringBuilder sb, int recursionCount) {
        if (recursionCount == 4) {
            if (i == s.length()) {
                ans.add(sb.toString());
            }
            return;
        }

        int len = 0, number = 0;
        if (sb.length() > 0) {
            sb.append(".");
            ++len;
        }

        for (int j = i; j < s.length(); ++j) {
            if (!isValid(number, i, j))
                break;
            char c = s.charAt(j);
            number = number * 10 + (c - '0');
            if (!isValid(number, i, j))
                break;
            sb.append(c);
            ++len;

            recurse(s, j + 1, sb, recursionCount + 1);
        }

        sb.setLength(sb.length() - len);
    }

    private boolean isValid(int number, int i, int j) {
        if (number > 255)
            return false;
        if (number == 0 && j > i)
            return false;
        return true;
    }
}