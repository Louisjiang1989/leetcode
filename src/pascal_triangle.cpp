#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>

using namespace std;

/*
 * Pascal's Triangle
 *
 * (1) 第K行有K个元素
 * (2) 第K行第一个和最后一个元素为1
 * (3) 第K(k>2)行的第n个元素A[k][n] = A[k-1][n-1] + A[k-1][n]
 *
 * <1> Give row numbers and return the first numRows of Pascal's Triangle
 * <2> Give the kth row and return the row numbers of Kth row
 */
class PascalTriangle 
{
    public:
        vector<vector<int> > pascalTriangle(int rownumber)
        {
            vector<vector<int> > vec;
            vec.resize(rownumber);

            assert(rownumber > 0);
            
            /* i row */
            for (int i = 0; i < rownumber; i++) {
                vec[i].resize(i+1);
                vec[i][0] = 1;
                vec[i][vec[i].size()-1] = 1;
                for (int j = 1; j < vec[i].size() -1; j++) {
                    vec[i][j] = vec[i-1][j-1] + vec[i-1][j];
                }
            }
            return vec;
        }

        /*vector<int> kthPascalTriangle(int k)
        {
            vector<vector<int> > vec;
            vec.resize(k);

            assert(k > 0);

            for (int i = 0; i < k; i++) {
                vec[i].resize(i+1);
                vec[i][0] = 1;
                vec[i][vec[i].size() - 1] = 1;
                for (int j = 1; j < vec[i].size() -1; j++) {
                    vec[i][j] = vec[i-1][j-1] + vec[i-1][j];
                }
            }
            return vec[k-1];
        } */

        /* k: rowIndex, if k =4, then return the 5th row number */
        vector<int> kthPascalTriangle(int k)
        {
            vector<int> vec;
            vec.resize(k+1, 1);
            assert(k > 0);

            for (int i = 0; i < k+1; ++i) {
                for (int j = i-1; j >= 1; --j) {
                    vec[j] = vec[j] + vec[j-1];
                }
            }
            return vec;
        }
};

int main() {
    PascalTriangle test;
    vector<vector<int> > res = test.pascalTriangle(5);
    for (vector<vector<int> >::iterator iter = res.begin(); iter != res.end(); iter++) {
        for (vector<int>::iterator iter2 = (*iter).begin(); iter2 != (*iter).end(); iter2++) {
            printf("%d ", *iter2);
        }
    }
    printf("\n");
    vector<int> kth = test.kthPascalTriangle(5);
    for (vector<int>::iterator iter3 = kth.begin(); iter3 != kth.end(); iter3++) {
        printf("%d ", *iter3);
    }
    printf("\n");
    return 0;
}


