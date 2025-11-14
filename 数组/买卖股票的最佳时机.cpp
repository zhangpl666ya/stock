//买卖股票的最佳时机？
//给定一个数组 `prices` ，它的第 `i` 个元素 `prices[i]` 表示一支给定股票第 `i` 天的价格。
//你只能选择 **某一天** 买入这只股票，并选择在 **未来的某一个不同的日子** 卖出该股票。设计一个算法来计算你所能获取的最大利润。
//返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 `0` 。

//最开始想是不是用栈会好一点，但没招 用in和out和max记录 时间复杂度n 空间复杂度1
int maxProfit(int* prices, int pricesSize) {
	int in = 0, out = 0, max = 0;
	for(int i = 1; i<pricesSize; i++){
		
		if(prices[i]>prices[out]){
			out = i;
		}
		if(prices[i]<prices[in]){
			in = i;
		}
		if(in>out){
			
			out = i;
		}
		else{
			if(prices[out]-prices[in]>max){
				max=prices[out]-prices[in];
			}
		}
	}
	return max;
}

//还是有大佬用单调栈的 哨兵 维护单调栈 时间复杂度n 空间复杂度1
int maxProfit(int* prices, int pricesSize) {
	int max = 0;
	int top = 1;
	for(int i = 1; i<pricesSize; i++){
		if(prices[i]>prices[top - 1]){
			prices[top++]=prices[i];
		}
		else if(prices[i]<prices[top - 1]){
			if(prices[top - 1]-prices[0]>max)max = prices[top-1]-prices[0];
			while(top>0&&prices[top-1]>prices[i]){
				top--;
			}
			prices[top++]=prices[i];
		}
		else;
	}
	return prices[top - 1]-prices[0]>max?prices[top - 1]-prices[0]:max;
}