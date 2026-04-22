class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.size() - 1;  // Pointer for a (right to left)
        int j = b.size() - 1;  // Pointer for b (right to left)
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) { sum += (a[i--] - '0'); }  // Add bit from a
            if (j >= 0) { sum += (b[j--] - '0'); }  // Add bit from b

            carry = sum / 2;         // Carry for next position
            result += (sum % 2 + '0');  // Current bit
        }

        reverse(result.begin(), result.end());  // Reverse to get correct order
        return result;
    }
};