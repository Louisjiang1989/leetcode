#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

/* 
 * Merge Sorted Array
 * Given two sorted integer arrays A and B, merge B into A as one sorted array.
 *
 * Note: You may assume that A has enough space (size that is greater or equal to m+n) to hold
 * additional elements from B. The number of elements initialized in A and B are m and n respectively.
 */

class MergeSortedArray
{
    public:

        vector<int> mergeSortedArray(vector<int> &a, vector<int> &b)
        {
            int len_a = a.size();
            int len_b = b.size();
            bool flag = false;
            //a.resize(len_a + len_b, 0);
            //vector<int>::iterator iter_a = a.begin();
            for (vector<int>::iterator iter_b = b.begin(); iter_b != b.end(); iter_b++) {
                printf("b_%d ", *iter_b);
                flag = false;
                for (vector<int>::iterator iter_a = a.begin(); iter_a != a.end(); iter_a++) {
                    //printf("a_%d", *iter_a);
                    if (*iter_b <= *iter_a) {
                        printf("a: %d, b: %d\n", *iter_a, *iter_b);
                        //insert the b element in front of the a element, we assume a and b all sorted from small to big
                        a.insert(iter_a, *iter_b);
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    printf("flag: %d\n", *iter_b);
                    a.insert(a.end(), *iter_b);
                }
            }
            return a;
        }

        // do not use the vector 
        void mergeSortedArrayNotVector(int a[], int m, int b[], int n)
        {
            int i = m + n -1;
            int j = m - 1;    // array a index
            int k = n -1;     // array b index

            while (i >= 0) {
                if (j >= 0 && k >= 0) {
                    if (a[j] >= b[k]) {
                        a[i] = a[j];
                        j--;
                    } else {
                        a[i] = b[k];
                        k--;
                    }
                } else if (j >= 0) {
                    // put the leave element of a to the new a 
                    a[i] = a[j];
                    j--;
                } else if (k >= 0) {
                    // put the leave element of b to the new a
                    a[i] = b[k];
                    k--;
                }
                i--;
            }

        }
};

int main() 
{
    MergeSortedArray test;
    int array_a[11] = {1, 2, 2, 3, 4, 5, 6};
    int array_b[4] = {2, 4, 6, 7};
    vector<int> a(array_a, array_a+7);
    vector<int> b(array_b, array_b+4);
    a = test.mergeSortedArray(a, b);
    for (vector<int>::iterator iter = a.begin(); iter != a.end(); iter++) {
        printf("%d ", *iter);
    }
    printf("\n");
    test.mergeSortedArrayNotVector(array_a, 7, array_b, 4);
    for (int i = 0; i < 11; i++) {
        printf("%d\n", array_a[i]);
    }
    return 0;
}
