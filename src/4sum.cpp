#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

/* 
 * Given an array of S of n integers, are there elements a, b, c and d in S such that a+b+c+d = target?
 * Find all unique quadruplets in the array which gives the sume of target 
 */
class FourSum
{
    public:
        vector<vector<int> > fourSum(vector<int> &vec, int value)
        {
            int sum = 0;
            vector<vector<int> > res;
            vector<int> cur(4, 0);

            if (vec.size() < 4) {
                return res;
            }
            sort(vec.begin(), vec.end());

            for (int i=0; i < vec.size()-3; i++) {
                for (int j=i+1; j < vec.size()-2; j++) {
                    int k = j + 1;
                    int l = vec.size() - 1;

                    while(k < l) {
                        sum = vec[i] + vec[j] + vec[k] + vec[l];
                        if (sum == value) {
                            cur[0] = vec[i];
                            cur[1] = vec[j];
                            cur[2] = vec[k];
                            cur[3] = vec[l];
                            res.push_back(cur);
                            ++k;
                            --l;
                            /* skip the duplication solution */
                            while (k < l && vec[k-1] == vec[k]) {
                                ++k;
                            }
                            while (k < l && vec[l] == vec[l+1]) {
                                --l;
                            }
                        } else if (sum < value) {
                            ++k;
                            /* skip the duplication solution */
                            while (k < l && vec[k-1] == vec[k]) {
                                ++k;
                            }
                        } else {
                            --l;
                            /* skip the duplication solution */
                            while (k < l && vec[l] == vec[l+1]) {
                                --l;
                            }
                        }
                    }
                    if (j < vec.size()-2 && vec[j] == vec[j+1]) {
                        ++j;
                    }
                }
                if (i < vec.size()-3 && vec[i] == vec[i+1]) {
                    ++i;
                }
            }
            return res;
        }
};


int main() 
{
    FourSum test;
    int array[5] = {1, -1, 5, -2, 7};
    vector<int> vec(array, array+5);
    vector<vector<int> > result = test.fourSum(vec, 9);
    for (vector<vector<int> >::iterator iter_out = result.begin(); iter_out != result.end(); iter_out++) {
        for (vector<int>::iterator iter_inner = (*iter_out).begin(); iter_inner != (*iter_out).end(); iter_inner++) {
            printf("%d ", *iter_inner);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
