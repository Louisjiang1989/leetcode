#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;
/* 
 * Give a non-negative number represented as an array of digits, plus one to the number.
 * The digits are stored such that the most significant digit is at the head of the list.
 */
class PlusOne
{
    public:
        vector<int> plusOne(vector<int> &digits)
        {
            vector<int> vec(digits.size(), 0);
            int sum = 0;
            int one = 1;
            for (int i = digits.size()-1; i >= 0; i--) {
                sum = one + digits[i];
                one = sum / 10;
                vec[i] = sum % 10;
            }

            if (one > 0) {
                vec.insert(vec.begin(), one);
            }
            return vec;
        }
};

int main() 
{
    PlusOne test;
    int iarray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> digits(iarray, iarray+10);
    vector<int> res = test.plusOne(digits);
    for (vector<int>::iterator iter = res.begin(); iter != res.end(); iter++) {
        printf("%d", *iter);
    }
    printf("\n");
    return 0;
}
