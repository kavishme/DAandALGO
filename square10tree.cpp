#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>
#include<bitset>
#include<fstream>
#include<queue>
#include<stack>
#include <unordered_map>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define R(i,n)			REP(i,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

const int LIM = 2000000;
struct BigInt{
	int a[LIM+1];
	BigInt(){
		CL(a,0);
	}
};

vi res_level;
vector<string> res_number; 


string l,r;


string sub(string t1,string t2){
	REP(i,t1.size()) {
		t1[i]-=(t2[i]-'0');
		if(t1[i]<'0'){
			t1[i]+=10;
			t1[i+1]--;
		}
	}
	return t1;
}
void sub1(string& s){
	s[0]--;
	REP(i,s.size()){
		if(s[i]<'0'){
			s[i]+=10;
			s[i+1]--;
		}else break;
	}
	while(s.size()>1 && s.back()=='0')s.pop_back();
}

void add1(string& t){
	t.pb('0');
	t[0]++;
	REP(i,t.size()){
		if(t[i]>'9'){
			t[i]-=10;
			t[i+1]++;
		}else break;
	}
	while(t.back()=='0')t.pop_back();
}

void solve(string l, string r, int level){
	if(l.empty()) return;
	while(l.size() > 1 && r.size() > 0 && l.back()=='0' && r.back()=='0')l.pop_back(),r.pop_back();
	int len = level == 0 ? 1 : ((1<<(level-1))+1);
	//cout<<level<<' '<<len<<' '<<l.size()<<' '<<r.size()<<' '<<l<<' '<<r<<endl;
	
	if(l == string(len-1,'0') && r==string(len-1,'9')){
		res_level.pb(level);
		res_number.pb("1");
		return;
	}

	if (l.size() < len) {
		solve(l,r,level-1);
		return;
	}


	string s1 = l.substr(len-1);
	string s2 = r.substr(len-1);
	l=l.substr(0,len-1);
	r=r.substr(0,len-1);
			
	if (s1 == s2) {
		if (level==0){
			//cout<<s1<<' '<<s2<<' '<<l<<' '<<r<<endl;
			res_level.pb(0);
			res_number.pb("1");
		}else{
			solve(l,r,level-1);
		}
		return;
	}else{
		string t = sub(s2,s1);
		sub1(t);

		if (l == string(len-1,'0')) {
			add1(t);
		} else solve(l,string(len-1,'9'),level-1);

		if (r == string(len-1,'9')) add1(t);


		if(t==string(t.size(),'0')){
		}else{
			res_level.pb(level);
			res_number.pb(t);
		}

		if(r==string(len-1,'9'));
		else solve(string(len-1,'0'),r,level-1);
	}
}


int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//1freopen("output.txt","w",stdout);
#endif
	
	getline(cin,l);
	getline(cin,r);

	reverse(l.begin(),l.end());
	reverse(r.begin(),r.end());

	sub1(l);
	sub1(r);

	l = l+string(r.size()-l.size(),'0');
	solve(l,r,20);


	cout<<res_level.size()<<endl;
	REP(i,res_level.size()){
		string t = res_number[i];
		while(t.size()>0 && t.back()=='0')t.pop_back();
		reverse(t.begin(),t.end());
		printf("%d %s\n",res_level[i],t.c_str());
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}