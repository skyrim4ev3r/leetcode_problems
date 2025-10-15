// class Solution {
// public:
//     int minOperations(int n) {
//         int i = 0;
//         int count = 0;
//         while (true) {
//             int num = 1 + 2 * i;
//             if (num >= n) {
//                 break;
//             }
//             count += n - num;
//             i += 1;
//         }
//         return count;
//     }
// };


class Solution {
public:
    int minOperations(int n) {
        return n * n / 4;
    }
};
