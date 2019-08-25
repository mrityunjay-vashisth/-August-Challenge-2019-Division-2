#include "iostream"

using namespace std;

void DistributeApple(long long n, long long k);

int 
main() {
	long long t = 0, n, k;
	cin>>t;
	while(t) {
		cin>>n;
		cin>>k;
		DistributeApple(n, k);
		t--;
	}
}


void
DistributeApple(long long n, long long k) {
	long long tmp = 0;
	tmp = n/k;
	if (tmp%k == 0)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
}