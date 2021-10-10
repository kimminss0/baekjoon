#include <stdio.h>
#include <stdlib.h>
void myqsort(int *, int *);
void exchange(int *, int *, int *);
void _quicksort(int *const pbase, size_t total_elems);

int main(void)
{
    int N;
    scanf("%d", &N);
    int *arr = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        scanf("%d", &(arr[i]));
    _quicksort(arr, N);
    for (int i = 0; i < N; i++)
        printf("%d\n", arr[i]);
}

// void myqsort(int* left, int* right) {
//     int len = right-left+1;
//     if (len == 0 || len == 1)
//         return;
//     int temp;
//     int* low = left + 1;
//     int* high = right;
//     while (1) {
//         while (*low < *left && low < right) low++;
//         while (*high > *left && high > left) high--;
//         if (low < high) {
//             exchange(low, high, &temp);
//         }
//         else {
//             exchange(left, high, &temp);
//             break;
//         }
//     }
//     myqsort(left, high-1);
//     myqsort(high+1, right);
// }

// void exchange(int* a, int* b, int* tmp) {
//     *tmp = *a;
//     *a = *b;
//     *b = *tmp;
// }

#include <alloca.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(a, b)            \
    do                        \
    {                         \
        do                    \
        {                     \
            int __tmp = *(a); \
            *(a) = *(b);      \
            *(b) = __tmp;     \
        } while (0);          \
    } while (0)

#define MAX_THRESH 4

typedef struct
{
    int *lo;
    int *hi;
} stack_node;

#define STACK_SIZE (CHAR_BIT * sizeof(size_t))
#define PUSH(low, high) ((void)((top->lo = (low)), (top->hi = (high)), ++top))
#define POP(low, high) ((void)(--top, (low = top->lo), (high = top->hi)))
#define STACK_NOT_EMPTY (stack < top)

void _quicksort(int *const pbase, size_t total_elems)
{
    int *base_ptr = pbase;
    if (total_elems == 0)
        return;

    int *lo = base_ptr;
    int *hi = &lo[total_elems - 1];
    stack_node stack[STACK_SIZE];
    stack_node *top = stack;
    PUSH(NULL, NULL);
    while (STACK_NOT_EMPTY)
    {
        int *left_ptr;
        int *right_ptr;

        left_ptr = lo + 1;
        right_ptr = hi - 1;

        do
        {
            while (*left_ptr > *lo)
                left_ptr++;
            while (*right_ptr < *hi)
                right_ptr--;
            if (left_ptr < right_ptr)
            {
                SWAP(left_ptr, right_ptr);
                left_ptr++;
                right_ptr--;
            }
            else if (left_ptr == right_ptr)
            {
                left_ptr++;
                right_ptr--;
                break;
            }
        } while (left_ptr <= right_ptr);
        /* Set up pointers for next iteration.  First determine whether
            left and right partitions are below the threshold size.  If so,
            ignore one or both.  Otherwise, push the larger partition's
            bounds on the stack and continue sorting the smaller one. */
        if ((size_t)(right_ptr - lo) <= sizeof(int))
        {
            if ((size_t)(hi - left_ptr) <= sizeof(int))
                /* Ignore both small partitions. */
                POP(lo, hi);
            else
                /* Ignore small left partition. */
                lo = left_ptr;
        }
        else if ((size_t)(hi - left_ptr) <= sizeof(int))
            /* Ignore small right partition. */
            hi = right_ptr;
        else if ((right_ptr - lo) > (hi - left_ptr))
        {
            /* Push larger left partition indices. */
            PUSH(lo, right_ptr);
            lo = left_ptr;
        }
        else
        {
            /* Push larger right partition indices. */
            PUSH(left_ptr, hi);
            hi = right_ptr;
        }
    }

}