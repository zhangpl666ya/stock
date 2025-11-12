//轮转数组 给定一个整数数组，将元素向右轮转k个位置，k是非负数
#include<stdio.h>
#include<stdlib.h>
//最简单的想法，先写一个轮转，执行k次
//第一次写犯了这种错误！！不删掉应以为戒
/*void singlerotate(int* nums,int numsSize){
	int temp = nums[numsSize-1];
	for(int i = 0; i<numsSize-1;i++){
		nums[i+1]=nums[i];//这里把后面的元素覆盖了
	}
	nums[0]=temp;
	return;
}*/
//但这时间复杂度为N*K 很差的算法
void singlerotate(int* nums,int numsSize){
	int temp = nums[numsSize-1];
	for(int i = numsSize-1; i>0;i--){
		nums[i]=nums[i-1];
	}
	nums[0]=temp;
	return;
}


void rotate(int* nums, int numsSize, int k){
	for(int i = 0; i<k; i++){
		singlerotate(nums, numsSize);
	}
	return;
}


//这个也不错，就是长了点
void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize; // 处理k大于数组长度的情况
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}

//可以申请一个同等大小的数组，但不知道什么问题官方答案用numsSize做常数申请数组？？
//C99以上好像可以？
void rotate(int* nums, int numsSize, int k) {
    int newArr[numsSize];
    for (int i = 0; i < numsSize; ++i) {
        newArr[(i + k) % numsSize] = nums[i];
    }
    for (int i = 0; i < numsSize; ++i) {
        nums[i] = newArr[i];
    }
}

//作者：力扣官方题解
//链接：https://leetcode.cn/problems/rotate-array/solutions/551039/xuan-zhuan-shu-zu-by-leetcode-solution-nipk/
//可以申请动态数组啊！
void rotate(int* nums, int numsSize, int k) {
    int* newArr = (int*)malloc(sizeof(int)*numsSize);
    if(newArr==NULL){
        return;
    }
    for (int i = 0; i < numsSize; ++i) {
        newArr[(i + k) % numsSize] = nums[i];
    }
    for (int i = 0; i < numsSize; ++i) {
        nums[i] = newArr[i];
    }
    free(newArr);
    return;
}