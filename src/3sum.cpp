#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

/* 
 * Given an array of S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all
 * unique triplets in the array which gives the sum of zero.
 *
 * Note: Elements in a triplet (a,b,c) must be in non-descending order. (ie. a <= b <= c) The solution set must 
 * not contain duplicate triplets.
 */
class ThreeSum
{
    public:
        vector<vector<int> > threeSum(vector<int> &vec, int value)
        {
            vector<int> cur(3, 0);    /* save the current triple answer */
            vector<vector<int> > res;  /* answers */

            if (vec.size() <= 2) {
                return res;
            }

            /* sort the array first */
            sort(vec.begin(), vec.end());

            for (int i=0; i < vec.size()-2; ++i) {
                int j = i + 1;
                int k = vec.size() - 1;
                while (j < k) {
                    if (vec[i] + vec[j] + vec[k] == value) {
                        /* Note: you must allocate the memory for the cur vector first, or it will occur segment fault */
                        cur[0] = vec[i];
                        cur[1] = vec[j];
                        cur[2] = vec[k];
                        res.insert(res.begin(), cur);
                        ++j;
                        --k;

                        /* skip the duplication solution */
                        while (j < k && vec[j-1] == vec[j]) {
                            ++j;
                        }
                        while (j < k && vec[k] == vec[k+1]) {
                            --k;
                        }
                    } else if (vec[i] + vec[j ] + vec[k] < value) {
                        ++j;
                    } else {
                        --k;
                    }
                }
                while (i < vec.size()-1 && vec[i] == vec[i+1]) {
                    ++i;
                }
            }
            
            return res;
        }
};

int main() 
{
    ThreeSum test;
    int array[5] = {1, -1, 0, 6, -5};
    vector<int> vec(array, array+5);
    vector<vector<int> > res = test.threeSum(vec, 0);
    for (vector<vector<int> >::iterator iter = res.begin(); iter != res.end(); iter++) {
        for (vector<int>::iterator iter2 = (*iter).begin(); iter2 != (*iter).end(); iter2++) {
            printf("%d ", *iter2);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
