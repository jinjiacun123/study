#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstring>
/*
11. 盛最多水的容器
提示
中等
4.6K
相关企业

给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

说明：你不能倾斜容器。
输入：[1,8,6,2,5,4,8,3,7]
输出：49 
解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

示例 2：

输入：height = [1,1]
输出：1
*/
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height)  {
      int reValue;
      
      
      return reValue;
  }
};

void
test(Solution s,
     map<int,vector<int>> paramA,
     map<int,int> paramB,
     map<int,vector<int>> result){
  int i = 0;
  //---------------------------------------------------------
  paramA[i].push_back(2);
  paramA[i].push_back(3);
  paramA[i].push_back(4);
  paramB[i] = 6;
  result[i].push_back(1);
  result[i].push_back(3);
  //---------------------------------------------------------
  i++;
  paramA[i].push_back(-1);
  paramA[i].push_back(0);
  paramB[i] = -1;
  result[i].push_back(1);
  result[i].push_back(2);
  //---------------------------------------------------------

  //map<int, bool> reValue;
  for(auto [k,v]:paramA){
    cout<<"lab "<<k<<":"<<endl;
    vector<int> value = s.twoSum(v, paramB[k]);
    
    //cout<<"|"<<value<<"|"<<endl;
    int matchTimes = 0;
    int len = result[k].size();
    for(int i = 0; i < len; i++){
      if(result[k][i] == value[i])
	matchTimes++;
    }
    if(matchTimes == len){
      cout<<"-->success"<<endl;
    }else{
      cout<<"-->fail"<<endl;
    }
    cout<<"--------------------"<<endl;    
   }
  cout<<endl;
}

int
main(){
	Solution s;
	map<int, vector<int>> a;
	map<int, int> b;
	map<int, vector<int>> result;

	test(s, a, b, result);

	/*string ss = "foo";
	ss.append(20 - ss.length(), ' ');
	cout<<"ss:["<<ss<<"]"<<endl;
	*/

	return 0;	
}
