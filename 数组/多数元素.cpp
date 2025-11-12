//n个元素的数组中出现次数大于n/2的为多数元素，假定一定存在多数元素且n不为零，返回这个多数元素
//这是我的做法，比较巧，空间复杂度1，时间复杂度n，但不适合迁移 栈
int majorityElement(int* nums, int numsSize){
	int top = 1;
	for(int i =1; i<numsSize; i++){
		if(top==0){
			nums[top++]=nums[i];
		}
		else{
			if(nums[top-1]==nums[i]){
				nums[top++]=nums[i];
			}
			else{
				top--;
			}
		}
	}
	return nums[top-1];
}

//大佬算法：摩尔投票 虽然差不多 但看起来牛逼
//思想：众数记+1，非多数元素记为-1

int majorityElement(int* nums, int numsSize){
	int votes = 0;
	int majority = nums[0];
	for(int i = 0; i<numsSize; i++){
	if(nums[i]==majority){
		votes++;
	}
	else{
		votes--;
	}
	if(votes==0){
		majority = nums[i+1];
	}
	}
	return majority;
	
	}