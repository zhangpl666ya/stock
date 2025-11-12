#include<stdio.h>
//删除重复数，按顺序重新整合数组，输出整合后的数组内元素的个数

//我的解法 11.95MB 时间复杂度n 空间复杂度1 栈
int removeDuplicates(int* nums, int numsSize) {
	if (numsSize == 0)return 0;
	int top = 0;
	int i = 1, mem = 0;
	for (; i < numsSize;i++) {
		if (nums[i] != nums[mem]) {
			mem = i;
			nums[++top] = nums[mem];
		}
		else;
	}

	return top+1;
}
//设置mem的意义在哪呢？？？

//更好解法
int removeDuplicates1(int* nums, int numsSize) {
	if (numsSize == 0)return 0;
	int fast = 1, slow = 1;
	while (fast < numsSize) {
		if (nums[fast] != nums[fast - 1]) {
			nums[slow++] = nums[fast];
		}
		fast++;
	}
	return slow;
}
