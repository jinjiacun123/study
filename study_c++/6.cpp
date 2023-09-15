#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
  /***
   *    0 0   0         2*n-2
   *    00 0 0 0        2*(n-1) -2
   *    0   0  0        2*n-2
   *
   *    0  0     0      2*n-2       2*n-2            direction(position,navigate)
   *    0 0 0   0       2*(n-1)-2   2*(n-2)-2
   *    00   0 0        2*(n-2)-2   2*(n-1)-2
   *    0     0         2*n-2       2*n-2
   */
    string convert(string s, int numRows) {
      string reStr;
      int sLen = s.size();
      int direction = 0;
      vector<int> skipVector = generalSequence(numRows);
      int skipLen = skipVector.size();
      vector<int> nSkipVector;
      for(int i = skipLen -1; i >= 0; i--)
	nSkipVector.push_back(skipVector[i]);
      map<int, vector<int>> mSkip;
      mSkip[0] = skipVector;
      mSkip[1] = nSkipVector;

      int position = 0;
      for(int level = 0; level < numRows; level++){
	position = level;
	direction = 0;
	while(position < sLen){
	  reStr.push_back(s[position]);
	  position += mSkip[direction][level];
	  direction = (++direction) % 2;
	}
      }
      
      return reStr;
    }

  //general jump sequence
  vector<int> generalSequence(int n){
    vector<int> seq;

    if(n > 1){
      for(int i=1; i < n; i++)
	seq.push_back(2*(n-i+1)-2);
      seq.push_back(2*n-2);
    }
    
    return seq;
  }
};


void
test(Solution s,
     map<int,string> a,
     vector<string> result){
  a[3] = "PAYPALISHIRING";
  a[4] = "PAYPALISHIRING";

  result.push_back("PAHNAPLSIIGYIR");
  result.push_back("PINALSIGYAHRPI");
  
  int len = a.size();
  int i = 0;
  for(auto [k,v]:a){
    string value = s.convert(v, k);
    cout<<"|"<<value<<"|"<<endl;
    if(value == result[i++]){
      cout<<"-->success"<<endl;
    }else{
      cout<<"-->fail"<<endl;
    }
   }
  cout<<endl;
}

int
main(){
	Solution s;
	map<int, string> a;
	vector<string> result;

	test(s, a, result);

	/*
	vector<int> r = s.generalSequence(3);
	int len = r.size();
	for(int i = 0; i < len; i++)
	  cout<<r[i]<<",";
	cout<<endl;
	*/

	return 0;	
}
