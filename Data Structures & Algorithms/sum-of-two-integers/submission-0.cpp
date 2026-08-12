class Solution {
public:
    int getSum(int a, int b) {
        int andey = (a&b) *2;
        return (andey + (a^b));
    }
};
