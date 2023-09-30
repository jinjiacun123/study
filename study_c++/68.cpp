#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth)  {
      vector<string> retVector;
      int wordsLen = words.size();
      int beginPosition;
      int curPosition = 0;
      int maxSpitLength;
      int spaceLength;
      int isLastGroup = 0;

      while(curPosition < wordsLen){
	maxSpitLength = 0;
	spaceLength = 0;
	isLastGroup = 0;
      
	beginPosition = curPosition;
	while(curPosition + maxSpitLength < wordsLen
	&& spaceLength <= maxWidth){
	  spaceLength += words[curPosition+maxSpitLength].size() + 1;
	  maxSpitLength++;	  
	}
	
	//save string group
	if(maxSpitLength > 0){
	  //only one element
	  if(maxSpitLength == 1){
	    string str = words[curPosition+maxSpitLength -1];
	    str.append(maxWidth - str.size() , ' ');
	    retVector.push_back(str);
	    // cout<<"---->maxSpitLenth:1,str:["<<str<<"]"<<endl;
	    curPosition += maxSpitLength;	    
	    continue;
	  }
	  //cout<<"#####maxSpitLength:"<<maxSpitLength<<endl;
	  //is over
	  if(spaceLength > maxWidth + 1){
	    spaceLength -= words[curPosition+maxSpitLength -1].size() + 1;
	    maxSpitLength--;	   
	  }
	  spaceLength --;//clean end black
	  //cout<<"########-->:"<< wordsLen - curPosition - maxSpitLength<<endl;
	  if(wordsLen - curPosition - maxSpitLength == 0){isLastGroup = 1;}
	  int restBlackNum = maxWidth - spaceLength;
	  if(restBlackNum > 0){
	    //need fill with black
	    /*
	    cout<<"need fill:"<<restBlackNum
		<<",spaceLength:"<<spaceLength
	        <<",maxSpitLength:"<<maxSpitLength
	        <<",curPosition:"<<curPosition
		<<endl;
	    */
	  }
	  string str;
	  vector<int> fillLenVector = generalAnBySn(restBlackNum, maxSpitLength-1);
	  //cout<<"sequence:";
	  /*
	  for(int i = 0; i < fillLenVector.size(); i ++){
	    cout<<fillLenVector[i]<<",";
	  }
	  cout<<endl;
	  */
	  if(maxSpitLength > 1){
	    //int isLastGroup = 0;
	    //check is last group
	    cout<<"retVector count:"<<retVector.size()<<endl;
	    for(int i = 0; i < maxSpitLength - 1; i++){
	      string tmpStr =  words[curPosition + i];
	      if(isLastGroup == 0){
		int tmpLen = fillLenVector[i] + 1;
		//= (restBlackNum/(maxSpitLength -1)) + 1;
		tmpStr.append(tmpLen, ' ');
	      }else if(isLastGroup == 1){
		  tmpStr.append(1, ' ');
	      }
	      str += tmpStr;
	    }
	    if(isLastGroup == 0)
	      str += words[curPosition + maxSpitLength -1];
	    else{
	       str += words[curPosition + maxSpitLength -1];
	       str.append(maxWidth - str.size(), ' ');
	    }
	  }else if(maxSpitLength == 1){
	    string tmpStr =  words[curPosition + 0];
	    tmpStr.append(maxWidth - tmpStr.size(), ' ');
	    str += tmpStr;
	  }
	   retVector.push_back(str);
	}

	curPosition += maxSpitLength;
      //next group
      }
	

      
      return retVector;
    }

  //general spit black sequence
  vector<int> generalAnBySn(int sn, int n){//black of left may great or equal black of right 
    vector<int> sequence;
    
    if(n == 0){
      sequence.push_back(sn);
      return sequence;
    }
    
    for(int i = 0; i < n; i ++){
      sequence.push_back(sn/n);
    }

    int rest = sn - (sn/n)*n;
    if(rest > 0){
      for(int i = 0; i < n,rest > 0; i++,rest--){
	sequence[i] += 1;
      }
    }

    return sequence;
  }
};

void
test(Solution s,
     map<int,vector<string>> paramA,
     map<int, int> paramB,
     map<int,vector<string>> result){
  int i = 0;
  //---------------------------------------------------------
  paramA[i].push_back("This");
  paramA[i].push_back("is");
  paramA[i].push_back("an");
  paramA[i].push_back("example");
  paramA[i].push_back("of");
  paramA[i].push_back("text");
  paramA[i].push_back("justification.");
  
  paramB[i] = 16;
  
  result[i].push_back("This    is    an");
  result[i].push_back("example  of text");
  result[i].push_back("justification.  ");
  //---------------------------------------------------------
  i++;
  paramA[i].push_back("What");
  paramA[i].push_back("must");
  paramA[i].push_back("be");
  paramA[i].push_back("acknowledgment");
  paramA[i].push_back("shall");
  paramA[i].push_back("be");
  
  paramB[i] = 16;

  result[i].push_back("What   must   be");
  result[i].push_back("acknowledgment  ");
  result[i].push_back("shall be        ");
  //---------------------------------------------------------
  i++;
  paramA[i].push_back("Science");
  paramA[i].push_back("is");
  paramA[i].push_back("what");
  paramA[i].push_back("we");
  paramA[i].push_back("understand");
  paramA[i].push_back("well");
  paramA[i].push_back("enough");
  paramA[i].push_back("to");
  paramA[i].push_back("explain");
  paramA[i].push_back("to");
  paramA[i].push_back("a");
  paramA[i].push_back("computer.");
  paramA[i].push_back("Art");
  paramA[i].push_back("is");
  paramA[i].push_back("everything");
  paramA[i].push_back("else");
  paramA[i].push_back("we");
  paramA[i].push_back("do");

  paramB[i] = 20;

  result[i].push_back("Science  is  what we");
  result[i].push_back("understand      well");
  result[i].push_back("enough to explain to");
  result[i].push_back("a  computer.  Art is");
  result[i].push_back("everything  else  we");
  result[i].push_back("do                  ");
  
 
  for(auto [k,v]:paramA){
    cout<<"lab "<<k<<":"<<endl;
    vector<string> value = s.fullJustify(v, paramB[k]);
    if(value.size() <= 0){      
      cout<<k<<"-->fail"<<endl;
      continue;
    }

    for(int i = 0; i < value.size(); i++){
      cout<<"i:"<<i<<",value:["<<value[i]<<"]"<<endl;
    }
    cout<<"--------------------"<<endl;
    //    break;
    //continue;
    int resultLen = result[k].size();
    int okTime = 0;
    for(int i = 0; i < resultLen; i++){
      if(value[i] == result[k][i]){
	okTime++;
      }
    }
    if(okTime == resultLen){
       cout<<"-->success"<<endl;
    }else{
      cout<<"-->fail"<<endl;
    }
    //cout<<"|"<<value<<"|"<<endl;
    /*
    if(value == result[k]){
      cout<<"-->success"<<endl;
    }else{
      cout<<"-->fail"<<endl;
    }
    */
   }
  cout<<endl;
}

int
main(){
	Solution s;
	map<int, vector<string>> a;
	map<int, int> b;
	map<int, vector<string>> result;

		test(s, a, b, result);

	/*string ss = "foo";
	ss.append(20 - ss.length(), ' ');
	cout<<"ss:["<<ss<<"]"<<endl;
	*/

	return 0;	
}
