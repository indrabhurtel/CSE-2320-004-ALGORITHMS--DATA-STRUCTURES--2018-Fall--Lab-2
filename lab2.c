/*
*
*lab2
*
*Created by Indra Bhurtel on 10/05/18.
*
*
*Name:Indra Bhurtel
*I am senior at UTA. My major is software Engineering.
*UTA ID NO:1001542825
*
*lab 2 assignment
*
*Professor Bob Weems
*
*Code compilation in Omega as follows:
*    gcc lab2.c
*   ./a.out
*/

#include <stdio.h>
#include <stdlib.h>

void interleaveArrA(int *arrB,int *arrA, int arrAsize, int factor);  /// Interleaving function

int subsequenceTesting(int *InterleavedArrA, int sizeB, int *arrayA, int sizeA); ///Function for subsequence testing

int binary_search(int *arrC, int arrCSize, int *arA, int arASize, int maxValue); ///Function for binary search

int main()
{
    int sizeA;
    int sizeX;
    int a;
    int tempNum;
    int* arrayA;
    int* arrayX;

    scanf("%d %d", &sizeA, &sizeX);

   ///The dynamic arrays A and X being initialized
    arrayA = (int*)malloc(sizeA * sizeof(int));
    arrayX = (int*)malloc(sizeX * sizeof(int));

    for (a = 0; a < (sizeA + 1); a++) ///Take and store input value
    {
        scanf("%d", &tempNum);
        if (tempNum != -999999999)
            arrayA[a] = tempNum;
    }

    for (a = 0; a< (sizeX + 1); a++)
    {
        scanf("%d", &tempNum);
        if (tempNum != -999999999)
            arrayX[a] = tempNum;
    }

    int max_Interleaf_Factor;
    int maxInterleaf = sizeA/sizeX;
    max_Interleaf_Factor = binary_search(arrayA, sizeA, arrayX, sizeX, maxInterleaf);
    printf("Maximum repeats is  %d\n", max_Interleaf_Factor);

    free(arrayA);
    free(arrayX);
}

void interleaveArrA(int *arrB,int *arrA, int arrAsize, int factor)  /// Interleaving function
{
    int a;
    int b;
    int c = 0;
    for (a = 0; a < arrAsize; a++)
    {
        b=0;
        while(b < factor)
        {
            arrB[c] = arrA[a];
            c++;
            b++;
        }
    }
}


int subsequenceTesting(int *InterleavedArrA, int sizeB, int *arrayA, int sizeA) ///Function for subsequence testing
{
    int a=0;
    int b=0;

    while (a < sizeA)
    {
        if (InterleavedArrA[b] == arrayA[a]) /// Moving on to the next elements in arrayA interleaved, if it matches
            b++;

        if (b == sizeB) ///Break , if e reaches the size of array A
            break;

        else /// Moving on the next elements in arrayA, if the value are not equal
            a++;

    }
    if (b == sizeB)		///the interleaved array is a subsequence of A.
        return 1;
    else				///the interleaved array is not a subsequence of A.
        return 0;
}

int binary_search(int *arrC, int arrCSize, int *arA, int arASize, int maxValue) ///Function for binary search
{
    int low = 0;
    int mid;
    int high = maxValue;;
    int testPassCheck;
    int maximumRepeats = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;

        int* interleavedX; ///The dynamic interleaved array being initialized
        int sizeInterleavedX = arASize * mid;

        interleavedX = (int*)malloc(sizeInterleavedX * sizeof(int)); ///Memory allocated

        interleaveArrA(interleavedX, arA, arASize, mid);	/// interleaving the arrayA

        testPassCheck = subsequenceTesting(interleavedX, sizeInterleavedX, arrC, arrCSize);

        printf("low %d mid %d high %d", low, mid, high );

        if (testPassCheck == 1)
        {
            low = mid + 1;
            printf(" passed\n");
            maximumRepeats = mid;
        }

        else
        {
            high = mid - 1;
            printf(" failed\n");
        }

        free(interleavedX);
    }

    return maximumRepeats;
}
