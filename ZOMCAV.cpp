#include "iostream"
#include "stdlib.h"

using namespace std;

void ComputeDifferenceArray(long long *cave, long long *D, long long n);
void ComputeRadiation(long long *cave, long long *zombie, long long n);
long long LongMax(long long a, long long b);
long long LongMin(long long a, long long b);

int 
main() {
	long long t, n, *cave, *zombie, i;
	cin>>t;
	while (t) {
		cin>>n;
		cave = (long long*) malloc(n * sizeof(long long));
		zombie = (long long*) malloc(n * sizeof(long long));
		for (i = 0; i < n; i++)
			cin>>cave[i];
		for (i = 0; i < n; i++)
			cin>>zombie[i];
		ComputeRadiation(cave, zombie, n);
		t--;
	}
}

long long 
LongMax(long long a, long long b) {
	if (a > b)
		return a;
	return b;
}

long long 
LongMin(long long a, long long b) {
	if (a >= b)
		return b;
	return a;
}

void 
ComputeDifferenceArray(long long *cave, long long *D, long long n) {
	long long i = 0, l = 0, r = 0;
	for (i = 1; i <=n; i++) {
		l = i - (cave[i - 1]);
		if (l <= 0) l = 1;
		r = i + (cave[i - 1]);
		D[l] += 1;
		if ( r < n) D[r + 1] -= 1;
	}
}

void
ComputeRadiation(long long *cave, long long *zombie, long long n) {
	long long i = 0, j = 0, k = 0, l = 0, *caveRad;
	long long *D = (long long*) calloc(n + 1, sizeof(long long)); 
	ComputeDifferenceArray(cave, D, n);
	caveRad = (long long*) calloc(n, sizeof(long long));
	caveRad[0] = D[1];
	for (i = 2; i <= n; i++)
		caveRad[i - 1] = caveRad[i - 2] + D[i];
	long long xo = caveRad[0];
	for (i = 1; i < n; i++)
		xo ^= caveRad[i];
	for (i = 0; i < n; i++)
		xo ^= zombie[i];
	if (xo)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
}
