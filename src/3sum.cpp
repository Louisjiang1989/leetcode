#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>

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

        /* 
         * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
         * Return the sum of the three integers. You can assume that each input would have exactly one solution.
         */
        int threeSumClosestOn3(vector<int> &vec, int value)
        {
            int sum = 0;
            int result = 0;
            int distance = abs(vec[0]+vec[1]+vec[2]-value);
            for(int p=0; p < vec.size(); p++) {
                printf("%d ", vec[p]);
            }
            printf("\n");
            for (int i=0; i < vec.size()-2; i++) {
                for (int j=i+1; j < vec.size(); j++) {
                    for (int k=j+1; k < vec.size(); k++) {
                        sum = vec[i] + vec[j] + vec[k];
                        printf("sum(%d, %d, %d): %d, abs: %d\n", i, j, k, sum, abs(sum-value));
                        if (abs(sum - value) < distance) {
                            distance = abs(sum - value);
                            result = sum;
                        }
                    }   
                }
            }
            return result;
        }

        int threeSumClosestOn2(vector<int> &vec, int value)
        {
            int distance = INT_MAX;
            int ret = 0;
            for (int i=0; i < vec.size()-2; i++) {
                int j = i + 1;
                int k = vec.size() - 1;
                sort(vec.begin(), vec.end());

                while(j < k) {
                    int sum = vec[i] + vec[j] + vec[k];
                    int tmp_distance;
                    if (sum < value) {
                        tmp_distance = value - sum;
                        if (tmp_distance < distance) {
                            distance = tmp_distance;
                            ret = sum;
                        }
                        ++j;  /* sum < value, move j backward because NewSum > Sum */
                    } else if (sum > value) {
                        tmp_distance = sum - value;
                        if (tmp_distance < distance) {
                            distance = tmp_distance;
                            ret = sum;
                        }
                        --k;   /* sum > value, move k forward because NewSum < sum */
                    } else {   /* in this case, the distance is 0, it must be closest distance, so we just return. */
                        ret = sum;
                        return ret;
                    }
                }   
            }
            return ret;
        }
};

int main() 
{
    ThreeSum test;
    int array[5] = {1, -1, 0, 6, -5};
    vector<int> vec(array, array+5);
    vector<vector<int> > res = test.threeSum(vec, 6);
    for (vector<vector<int> >::iterator iter = res.begin(); iter != res.end(); iter++) {
        for (vector<int>::iterator iter2 = (*iter).begin(); iter2 != (*iter).end(); iter2++) {
            printf("%d ", *iter2);
        }
        printf("\n");
    }
    printf("\n");
    int result = test.threeSumClosestOn2(vec, -5);
    printf("result: %d\n", result);
    return 0;
}
