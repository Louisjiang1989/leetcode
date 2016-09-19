#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

/* 
 * Suppose a sotrted array is rotated at some pivot unknown to you beforehand.
 * (ie. 0 1 2 3 4 5 6 7 might become 4 5 6 7 0 1 2)
 * Find the minimum element.
 * You may assume no duplicate exists in the array.
 */
class FindMin
{
    public:
        int findMinOn1(vector<int> &vec)
        {
            int min;

            for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
                if ((iter != vec.end() -1) && (*iter > *(iter+1))) {
                    min = *(iter+1);
                }
            }
            return min;
        }

        /* in this case, we can use the binary-search to find the min element. */
        int findMinBinarySearch(vector<int> &vec)
        {
            int start = 0;
            int stop = vec.size() - 1;
            int mid = start + (stop - start) / 2;

            while (start < stop - 1) {     /* why it is "start < stop -1" not "start < stop" */
                if (vec[mid] > vec[start]) {
                    // min is in the [mid, stop]
                    start = mid;
                    mid = (start + stop) / 2;
                } else if (vec[mid] < vec[start]){
                    // min is in the [start, mid]
                    stop = mid;
                    mid = (start + stop) / 2;
                } else {
                    start++;
                }
            }
            return min(vec[start], vec[stop]);
        }
};

int main()
{
    int array[8] = {4, 5, 6, 7, -1, -1, 1, 2};
    vector<int> vec(array, array+8);
    FindMin test;
    int min;
    min = test.findMinBinarySearch(vec);
    printf("min: %d\n", min);
    return 0;
}
