#include<iostream>
#include<vector>
#include<map>
#include<stack>

using namespace std;

class RandomizedSet {
private:
    vector<int> collect;
    map<int,int> m;
public:
    RandomizedSet() {

    }

    bool insert(int val) {
        bool status = false;

        if(m[val] == 0){
            m[val] = 1;
            collect.push_back(val);
            status = true;
        }

        return status;
    }

    bool remove(int val) {
        bool status = false;

        if(m[val] == 1){
            m[val] = 0;
            int len = collect.size();
            for(int i = 0; i < len; i++){
                if(collect[i] == val){
                    collect.erase(collect.begin()+i);
                    status = true;
                }
            }
        }

        return status;
    }

    int getRandom() {
        int value = 0;
        int len = collect.size();
        int index = 0;

        if(len > 0){
            index = (rand()/(RAND_MAX + 1u)) * (len -1);
            value = collect[index];
        }


        return value;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
void test1(RandomizedSet s, vector<int> a){
    a.push_back(3);
    a.push_back(0);
    a.push_back(6);
    a.push_back(1);
    a.push_back(5);

    int value= s.getRandom();
    cout<<value;
    cout<<endl;
}


int
main(){
    RandomizedSet s;
    vector<int> a;

    test1(s, a);

    return 0;
}
