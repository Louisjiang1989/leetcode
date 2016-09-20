#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

/* 
 * Largest Rectangle in Histogram
 * Given n non-negative integers representing the histogram's bar height where width of each bar
 * is 1, find the area of largest rectangle in the histogram.
 */
class LargestRectangleArea
{
    public:

        /* 
        * start from a bar, and find the smaller height of the bar, then caculate the bar area.
        * at last, we can find the largest bar.
        */
        int largestRectangleAreaOn2(vector<int> &vec) 
        {
            int result_right = 0;
            int result_left = 0;
            int result = 0;

            for (int i=0; i < vec.size(); i++) {
                for (int j=i+1; j < vec.size(); j++) {
                    int tmp;
                    if (vec[i] > vec[j]) {
                        tmp = j * vec[j];
                        if (tmp > result_right) {
                        result_right = tmp;
                        }
                    } 
                }

            }

            for (int i=vec.size()-1; i >= 0; i--) {
                for (int j=i-1; j >= 0; j--) {
                    int tmp;
                    if (vec[i] > vec[j]) {
                        tmp = j * vec[j];
                        if (tmp > result_left) {
                            result_left = tmp;
                        }
                    } 
                }
            } 

            if (result_left >= result_right) {
                result = result_left;
            } else {
                result = result_right;
            }
            return result;
        }

        /* 
         * leetcode has time limited, so we must decrease the time cost for huge input datai
         * 我们可以从左到右遍历所有bar，并将其push到一个stack中，如果当前bar的高度小于栈顶bar, 我们pop出栈顶的bar，
         * 同时以该bar计算矩形面积。那么我们如何知道该bar的ln和rn？ rn铁定就是当前遍历到的bar的索引，而ln则是当前的
         * 栈顶bar的索引，因为此时栈顶bar的高度一定小于pop出来的bar的高度。
         *
         * 为了更好的处理最后一个bar的情况，我们在实际中会插入一个高度为0的bar，这样就能pop出最后一个bar并计算了。
         * 这个在理解上有一定的难度!
         */
        int largestRectangleAreaOn1(vector<int> &vec)
        {
            vector<int> s;
            int sum = 0;
            int i = 0;
            vec.push_back(0);

            while (i < vec.size()) {
                if (s.empty() || vec[i] > vec[s.back()]) {
                    s.push_back(i);
                    i++;
                } else {
                    int t = s.back();
                    s.pop_back();
                    printf("t: %d\n", t);
                    sum = max(sum, vec[t] * (s.empty() ? i : (i - s.back() - 1)));
                    printf("sum: %d\n", sum);
                }
            }
            return sum;
        }
};

int main()
{
    LargestRectangleArea test;
    int array[5] = {2, 1, 5, 6, 2};
    vector<int> vec(array, array+5);
    int result = test.largestRectangleAreaOn1(vec);
    printf("result: %d\n", result);
    return 0;
}
