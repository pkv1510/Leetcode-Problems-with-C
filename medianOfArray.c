#include<stdio.h>
#include<stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int totalSize = nums1Size + nums2Size;
    int j = 0, k = 0;
    int* ret = (int*)malloc(totalSize * sizeof(int));

    for(int i = 0;i < totalSize;i++) {
        if(k < nums1Size && (j >= nums2Size || nums1[k] < nums2[j]) ) {
            ret[i] = nums1[k];
            k++;
        }
        else {
            ret[i] = nums2[j];
            j++;
        }
    }
    double retVal;
    if(totalSize % 2) {
        retVal = ret[totalSize / 2];
    }
    else {
        retVal = (double)(ret[totalSize / 2] + ret[(totalSize / 2) - 1]) / 2;
    }
    free(ret);
    
    return retVal; 
}

double findMedianSortedArrays1(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i, j,temp;
    int totalSize = nums1Size + nums2Size;
    int* mergedArray = (int*)malloc(totalSize * sizeof(int));
    for (i = 0; i < nums1Size; ++i) {
        mergedArray[i] = nums1[i];
    }
    for (j = 0; j < nums2Size; ++j) {
        mergedArray[i + j] = nums2[j];
    }
    for(i=0;i<totalSize;i++)
    {
        for(j=i+1;j<totalSize;j++)
        {
           if (mergedArray[i] > mergedArray[j]) 
           {
           temp = mergedArray[i];
           mergedArray[i] = mergedArray[j];
           mergedArray[j] = temp;
           }
        }
    }
    double median;
    if (totalSize % 2 == 0) {
        median = (mergedArray[totalSize / 2 - 1] + mergedArray[totalSize / 2]) / 2.0;
    } else {
        median = mergedArray[totalSize / 2];
    }
    free(mergedArray);
    return median;
}

int main() {
    int arr1[] = {1, 3};
    int arr2[] = {2};

    double med = findMedianSortedArrays(arr1, 2, arr2, 1);

    printf("The median is %lf\n", med);

    return 0;
}