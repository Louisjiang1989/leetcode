#include <stdio.h>

/* 
 * 1. remove the replicated elements of the specified array and return the new length of the new array, do not malloc new memory.
 * 2. remove the replicated elements of the specified-sorted array and return the new length of the new array, do not malloc new memory.
 * 3. remove the replicated elements (more than 2) of the specified array and return the length of the new array, do not malloc new memory.
 */
class Array {
    public:
        int removeElement(int a[], int n, int elem)
        {
            // condition 1
            int i=0;
            int j = 0;
            for (i = 0; i < n; i++) {
                if (a[i] == elem) {
                    continue;
                }
                // a[j] != a[i], then move forword of i and put the value a[i] = a[j]
                a[j] = a[i];
                j++;
            }
            return j;
        }

        // condition 2
        int removeElementSorted(int a[], int n) 
        {
            int i = 1;    /* traverse the array index */
            int j = 0;    /* non replicated element index */
            for (i; i < n; i++) {
                if (a[i] != a[j]) {
                    a[++j] = a[i];
                }
            }
            return j+1;
        }

        // condition 3
        int removeElementMoreThan2(int a[], int n)
        {
            int i = 1;
            int j = 0;
            int num = 0;
            for (i; i < n; i++) {
                if (a[i] == a[j]) {
                    num++;
                    if (num < 2) {
                        // handler it as the condition 2, we just as the 3rd one and .... as the replicated one 
                        a[++j] = a[i];
                    }
                } else {
                    a[++j] = a[i];
                    num = 0;
                }
            }
            return j+1;
        }
};


int main() 
{
    int a[10] = {1, 2, 2, 3, 4, 4, 4, 5, 5, 6};
    Array test;
    int len = test.removeElementMoreThan2(a, 10);
    for (int i=0; i<len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
