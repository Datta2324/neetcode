class Solution {
public:
    int getSum(int a, int b) {

int sum=0, carry=0;
        do
        {
            sum = a ^ b;
            carry = a & b;
            carry <<= 1;

            a = sum;
            b = carry;

        }while(carry);
        return sum;
    }
};
