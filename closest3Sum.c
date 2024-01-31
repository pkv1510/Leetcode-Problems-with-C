#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compare);
    int minDiff = __INT_MAX__, closest = 0;

    for(int i = 0;i < numsSize - 2;i++) {
        int left = i + 1;
        int right = numsSize - 1;
        
        while(left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            int temp;
            if(sum == target)
                return sum;
            if(target < 0) {
                if(sum > target)
                    temp = sum - target;
                else
                    temp = target - sum;
            } else {
                if(sum > target)
                    temp = sum - target;
                else
                    temp = target - sum;
            }

            if(temp < minDiff) {
                minDiff = temp;
                closest = sum;
            }

            if(sum < target)
                left++;
            else
                right--;
        }
    }

    return closest;
}

int main()
{
    //int arr[] = {-1, 0, 1, 2, -1, -4};
    //int arr[] = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
    //int arr[] = {833,736,953,-584,-448,207,128,-445,126,248,871,860,333,-899,463,488,-50,-331,903,575,265,162,-733,648,678,549,579,-172,-897,562,-503,-508,858,259,-347,-162,-505,-694,300,-40,-147,383,-221,-28,-699,36,-229,960,317,-585,879,406,2,409,-393,-934,67,71,-312,787,161,514,865,60,555,843,-725,-966,-352,862,821,803,-835,-635,476,-704,-78,393,212,767,-833,543,923,-993,274,-839,389,447,741,999,-87,599,-349,-515,-553,-14,-421,-294,-204,-713,497,168,337,-345,-948,145,625,901,34,-306,-546,-536,332,-467,-729,229,-170,-915,407,450,159,-385,163,-420,58,869,308,-494,367,-33,205,-823,-869,478,-238,-375,352,113,-741,-970,-990,802,-173,-977,464,-801,-408,-77,694,-58,-796,-599,-918,643,-651,-555,864,-274,534,211,-910,815,-102,24,-461,-14};
    int arr[] = {4, 0, 5, -5, 3, 3, 0, -4, -5};
    int size = sizeof(arr) / sizeof(int);
    int target = -2;
    
    printf("The closest sum of three elements in the array to the target %d is %d\n", target, threeSumClosest(arr, size, target));

    return 0;
}