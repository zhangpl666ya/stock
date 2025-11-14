/*给你一个非负整数数组 `nums` ，你最初位于数组的 **第一个下标** 。数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标，如果可以，返回 `true` ；否则，返回 `false` 。*/

//如果是零的元素，要保证其前面的能跳过去 基本想法，先找到0的位置，再遍历前面的元素
//这个算法太差劲了
bool canJump(int* nums, int numsSize) {
	if(numsSize==1)return 1;
	if(nums[numsSize-1]==0){
			int j = numsSize -1;
			for(; j >=0;j--){
				if(nums[j]>=numsSize-1-j){
					break;
				}				
			}
			if(j<0)return 0;
			
		}
	for(int i = numsSize-2; i>=0; i--){
		if(nums[i]==0){
			int j = i -1;
			for(; j >=0;j--){
				if(nums[j]>i-j){
					break;
				}				
			}
			if(j<0)return 0;
			
		}
	}
		
	return 1;
}

//贪心算法 太优雅了
bool canJump(int* nums, int numsSize) {
	int max = 0;
	for(int i = 0; i<numsSize;i++){
		if(max<i)return 0;
		max=max>i+nums[i]?max:i+nums[i];
	}
	return 1;
}