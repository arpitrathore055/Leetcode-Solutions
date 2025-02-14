import java.util.HashMap;

class Solution {
    public int romanToInt(String s) {
        int len = s.length();
        int low = 0, high = 0;
        int result = 0;
        HashMap<Character, Integer> romanMap = new HashMap<>();
        romanMap.put('I', 1);
        romanMap.put('V', 5);
        romanMap.put('X', 10);
        romanMap.put('L', 50);
        romanMap.put('C', 100);
        romanMap.put('D', 500);
        romanMap.put('M', 1000);

        while (high < len) {
            if (s.charAt(low) == s.charAt(high)) {
                ++high;
            } else {
                // Checking subtraction instances
                char lastCh = s.charAt(high);
                char sLastCh = s.charAt(high - 1);
                char firstCh = s.charAt(low);

                if ((lastCh == 'V' || lastCh == 'X') && sLastCh == 'I') {
                    result += (lastCh == 'V') ? romanMap.get('V') - 1 : romanMap.get('X') - 1;
                    low = high + 1;
                    ++high;
                } else if ((lastCh == 'L' || lastCh == 'C') && sLastCh == 'X') {
                    result += (lastCh == 'L') ? romanMap.get('L') - 10 : romanMap.get('C') - 10;
                    low = high + 1;
                    ++high;
                } else if ((lastCh == 'D' || lastCh == 'M') && sLastCh == 'C') {
                    result += (lastCh == 'D') ? romanMap.get('D') - 100 : romanMap.get('M') - 100;
                    low = high + 1;
                    ++high;
                } else {
                    result += romanMap.get(firstCh) * (high - low);
                    low = high;
                    ++high;
                }
            }
        }

        // Final calculations
        if (low < len) {
            result += romanMap.get(s.charAt(low)) * (high - low);
        }

        return result;
    }
}
