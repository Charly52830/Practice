//https://codeforces.com/contest/1270/problem/D
#include<string.h>
#include<set>
#include<iostream>
#define N 510
#define mp make_pair
#define oo 1000000010
using namespace std;
 
typedef pair<int,int> pii;
 
int n,k,k1;
set<int> s;
int A[N];
 
/* TEST */
int test_A[N],m_ans;
int test_cnt;
 
pii test_query() {
	test_cnt++;
	set<int> tmp;
	for(auto i:s) 
		tmp.insert(test_A[i-1]);
	int c=1,res,index;
	for(auto i:tmp) {
		if(c==m_ans)
			res=i;
		c++;
	}
	for(int x=0;x<n;x++) {
		if(test_A[x] == res)
			return mp(x+1,res);
	}
}
 
/* FINISH TEST */
 
pii query() {
	cout<<"? ";
	for(auto i:s)
		cout<<i<<" ";
	cout<<endl;
	cout.flush();
	int index,val;
	cin>>index>>val;
	return mp(index,val);
}
 
void answer(int m) {
	cout<<"! "<<m<<endl;
	//cout<<"! "<<m<<" "<<test_cnt<<endl;	// TEST
	cout.flush();
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int x;
	memset(A,-1,sizeof(A));
	/* TEST */
	/*
	cin>>n>>k>>m_ans;
	for(x=0;x<n;x++)
		cin>>test_A[x];
	*/
	/* FINISH TEST */
	cin>>n>>k;
	if(k==1) {
		answer(1);
		return 0;
	}
	for(x=0;x<k-1;x++) 
		s.insert(x+1);
	int last=k;
	for(x=0;x<n-k+1;x++) {
		s.insert(last++);
		pii p=query();
		//pii p=test_query();	// TEST
		A[p.first]=p.second;
		s.erase(p.first);
	}
	if(k*2-1 <=n) {
		set<int> s2,s3;
		swap(s,s2);
		for(x=1;x<=n && s.size() < k;x++) {
			if(A[x]!=-1)
				s.insert(x),s3.insert(A[x]);
		}
		pii p=query();
		//pii p=test_query();	// TEST
		int m=1;
		for(auto i:s3) {
			if(i == p.second) {
				answer(m);
				break;
			}
			m++;
		}
	}
	else {
		int m=oo,M=-1,m_index=0,M_index=0,m_cnt=0,M_cnt=0;
		for(x=1;x<=n;x++) {
			if(A[x]!=-1) {
				if(A[x] < m)
					m=A[x],m_index=x;
				if(A[x] > M)
					M=A[x],M_index=x;
			}
		}
		set<int> s2;
		swap(s,s2);
		s.insert(m_index);
		s.insert(M_index);
		for(auto i:s2)
			s.insert(i);
		for(auto i:s2) {
			s.erase(i);
			pii p=query();
			//pii p=test_query();	// TEST
			s.insert(i);
			if(p.second == m)
				m_cnt++;
			else
				M_cnt++;
		}
		m=k-1,M=0;
		for(x=1;x<=k;x++) {
			if(m == m_cnt && M==M_cnt) {
				answer(x);
				break;
			}
			m--,M++;
		}
	}	
	return 0;
}
