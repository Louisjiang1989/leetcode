#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;
/*
 * Given an array of intergers, find two numbers such that they add up to a specific target number. The
 * function twoSum should return indices of the two numbers such that they add up to the target,
 * where index1 must be less than index2. Please note that your returned answers(both index1 and index2)
 * are not zero-based.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers = {2, 7, 11, 15}, target = 9, Output: index1=1, index2=2
 */

class TwoSum 
{
    public:
        vector<int> twoSumOn2(vector<int> &vec, int value)
        {
            vector<int> indexes(2, 0);
            /* boundary condition */
            if (vec.size() <= 1) {
                return indexes;
            }

            for (int i = 0; i < vec.size(); i++) {
                for (int j = i + 1; j < vec.size(); j++) {
                    if (value == vec[i] + vec[j]) {
                        printf("vec[i]: %d, vec[j]: %d\n", vec[i], vec[j]);
                        indexes[0] = i+1;
                        indexes[1] = j+1;
                        return indexes;
                    }
                }
            }
            indexes[0] = -2;
            indexes[1] = -1;
            return indexes;
        }

        vector<int> twoSumOn1(vector<int> &vec, int value) 
        {
            vector<int> indexes(2, 0);
            unordered_map<int, int> hash_map;

            // init the hash_map
            for (int i = 0; i < vec.size(); i++) {
                hash_map[vec[i]] = i;
            }

            // find the target-vec[i]
            for (int i = 0; i < vec.size(); i++) {
                int diff = value - vec[i];
                if (hash_map.find(diff) != hash_map.end()) {
                    if (i == hash_map[diff]) {
                        continue;
                    } else if (i < hash_map[diff]) {
                        indexes[0] = i + 1;
                        indexes[1] = hash_map[diff] + 1;
                    } else {
                        indexes[0] = hash_map[diff] + 1;
                        indexes[1] = i + 1;
                    }
                    
                    return indexes;
                }
            }
            indexes[0] = -2;
            indexes[1] = -1;
            return indexes;
        }

};

int main() 
{
    TwoSum test;
    int array_a[4] = {2, 7, 11, 15};
    vector<int> data(array_a, array_a+4);
    vector<int> vec = test.twoSumOn1(data, 9);
    for (int i = 0; i < 2; i++) {
        printf("%d\n", vec[i]);
    }
    return 0;
}
