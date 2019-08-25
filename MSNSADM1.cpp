#include "iostream"

using namespace std;

void CountScore(long long *goal, long long *foul, long long n);

int 
main() {
	long long t = 0, n = 0, *goal, *foul, i;
	cin>>t;
	while(t) {
		cin>>n;
		goal = (long long*) malloc(n *sizeof(long long));
		foul = (long long*) malloc(n *sizeof(long long));
		for (i = 0; i < n; i++)
			cin>>goal[i];
		for (i = 0; i < n; i++)
			cin>>foul[i];
		CountScore(goal, foul, n);
		t--;
	}
}


void
CountScore(long long *goal, long long *foul, long long n) {
	long long i = 0, maxp = 0, tmp = 0;
	for (i = 0; i < n; i++) {
		tmp = (20 *goal[i]) - (10 * foul[i]);
		if (tmp > maxp)
			maxp = tmp; 
	}
	cout<<maxp<<endl;
}