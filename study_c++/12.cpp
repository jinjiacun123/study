#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
private:
  map<int, string> mCommon = {
    {1, "I"},
    {5,"V"},
    {10,"X"},
    {50,"L"},
    {100,"C"},
    {500,"D"},
    {1000,"M"}	
  };
  map<int,string> mSpecial = {
    {4,"IV"},
    {9,"IX"},
    {40,"XL"},
    {90,"XC"},
    {400,"CD"},
    {900,"CM"}
  };
  vector<int> v = {
    1,4,5,9,10,40,50,90,100,400,500,900,1000
  };
public:
    string intToRoman(int num) {
	string reStr;
	int vLen = v.size();
	int i;
	
	//find step value
	i = vLen - 1;
	while(num < v[i])i--;

	while(num >= 0
	&& i >= 0){
	  while(num >= v[i] && num >= 0){
	    //if common
	    if(mCommon.find(v[i]) != mCommon.end()){
	      num -= v[i];
	      reStr += mCommon[v[i]];
	      cout<<"reStr:"<<reStr<<endl;
	      continue;
	    }
	  
	    //if special
	    if(mSpecial.find(v[i]) != mSpecial.end()){
	      num -= v[i];
	      reStr += mSpecial[v[i]];
	      cout<<"reStr:"<<reStr<<endl;
	      continue;
	    }
	  }

	  if(num >= 0
	  && i >= 0) i--;
	  else break;
	}
	

	return reStr;	
    }
};


void
test(Solution s,
     vector<int> a){
  a.push_back(3);
  a.push_back(4);
  a.push_back(9);
  a.push_back(58);
  a.push_back(1994);
  
  int len = a.size();
  for(int i = 0; i < len; i++){
    string value = s.intToRoman(a[i]);
    cout<<value<<"\t"<<endl;
  }
  cout<<endl;
  
}

int
main(){
	Solution s;
	vector<int> a;

	test(s, a);

	return 0;	
}
