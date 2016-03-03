#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
using namespace std;

template<typename T>
T square(T x) {
   return x*x;
}

int main() {
unordered_map<int,string> mp;
mp[1] ="James";
mp[3] = "Justin";
mp[2] ="Xiao";
for (auto m : mp) {
	cout<<m.first<<" "<<m.second<<" ";
}
cout<<endl;
unordered_set<int> s = {3,1,5,4,8,7} ;
for (auto v: s) {
	cout<<v<<" ";
}
cout<<endl;
string str = "9,3,4,#,#,1,#,#,2,#,6,#,#";
istringstream in(str);
string val;
while(getline(in,val,',')) {
cout<<val<<endl;
}
vector<int> vec = {1,2,3,4,5,6,7};
for (auto i: vec) {
	cout<<i<<" ";
}
cout<<endl;
rotate(vec.begin(),vec.end()-3,vec.end());
for (auto i :vec) {
   cout<<i<<" ";
}
cout<<endl;
int n = count(vec.begin(),vec.end(),69);
cout<<n<<endl;
int m = count_if(vec.begin(),vec.end(),[](int x){return x<10;});
vector<int>::iterator itr;
itr = max_element(vec.begin(),vec.end());
cout<<*itr<<endl;
cout<<m<<endl;
cout<<square(5)<<endl;
cout<<square(5.5)<<endl;
string str1 ="abc";
string str11 = str1.substr(0,str1.size() -1);
string str12 = str1.substr(1,str1.size());
cout<<str11<<endl;
cout<<str12<<endl;
return 0;
}
