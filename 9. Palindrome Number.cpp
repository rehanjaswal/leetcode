// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if (x < 0) return false;
//         long long rev = 0, temp = x;
//         while (x > 0) {
//             int lastDigit = x % 10;
//             rev = (rev * 10) + lastDigit;
//             x /= 10;
//         }
//         return (rev == temp);
//     }
// };

/// optimal solution

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int revHalf = 0;
        
        while (x > revHalf) {
            revHalf = (revHalf * 10) + (x % 10);
            x /= 10;
        }
        return (x == revHalf || x == revHalf / 10);
    }
};