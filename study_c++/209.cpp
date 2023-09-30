#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
      int minNumsSub(vector<int>& nums, int target) {
     	int minLen = 0;
	int sum = 0;
	int numsLen = nums.size();

	//calculation sum
	for (int i = 0; i < numsLen; i++){
		sum += nums[i];
	}

	//sum is less target
	if(sum < target) return 0;

	//sum is equal target
	if(sum == target) return numsLen;

	//sort
	for(int i = 0; i < nums.size(); i ++){
		for(int j = i; j < nums.size(); j++){
			if(nums[i] > nums[j]){
				int tmp = nums[i]; nums[i] = nums[j]; nums[j] = tmp;
			}
		}
	}
	
	//sum is greate target
	minLen = 1;	
	if(nums[numsLen -1] >= target) return minLen;

	while(numsLen >= 0){
		target -= nums[numsLen -1];	
		minLen++;numsLen--;
		for(int i = 0; i < numsLen; i++){
			if(nums[i] >= target) return minLen;
		}
	}
		
      
      	return minLen;
    }

};


void
test(Solution s,
     map<int, vector<int>> a,
     map<int, int> result){

	int i = 7;
	//key:7
	a[i].push_back(2);
	a[i].push_back(3);
	a[i].push_back(1);
	a[i].push_back(2);
	a[i].push_back(4);
	a[i].push_back(3);
	result[i] = 2;

	//key:4
	i = 4;
	a[i].push_back(1);
	a[i].push_back(4);
	a[i].push_back(4);
	result[i] = 1;

	//key:11
	i = 11;
	a[i].push_back(1);
	a[i].push_back(1);
	a[i].push_back(1);
	a[i].push_back(1);
	a[i].push_back(1);
	a[i].push_back(1);
	a[i].push_back(1);
	a[i].push_back(1);
	result[i] = 0;	

	//invoke and test
	map<int, vector<int>>::iterator it;
	for(it = a.begin(); it != a.end(); ++it){
		int key = (int)it->first;
		cout<<"key:"<<key<<endl;
		int value = s.minNumsSub(it->second, key);
		cout<<"value:"<<value<<endl;
		if(value == result[key]){
			cout<<"key:"<<key<<" is success"<<endl;
		} else {
			cout<<"key:"<<key<<" is failt"<<endl;
		}
		cout<<"-------------------------------"<<endl;
	}	


    cout<<endl;
}

int
main(){
	Solution s;
	map<int, vector<int>> a;
	map<int, int> result;

	test(s, a, result);
	
	return 0;	
}
