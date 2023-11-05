#include<vector>
#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
#include<set>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<list>
#include<numeric>
#include<string>
#include<sstream>
#define ll long long


using namespace std;

void printFFF(int index, vector<int> a, vector<int>& values, int n){
    if(index >= n){
        for(int i = 0; i < a.size(); i++){
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    a.push_back(values[index]);
    printFFF(index + 1, a, values, n);
    a.pop_back();
    printFFF(index + 1, a, values, n);
    
}


#include<iostream>


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int val[] = {3, 1, 2};
    int n = sizeof(val)/sizeof(int);
    vector<int> a, values(val, val + n);

    printFFF(0, a, values, n);
    return 0;
}