// uva1101
#include <iostream>
#include<string.h>
#include <math.h> 
#include<algorithm>
#define INF 0x3f3f3f3f
#define MAXN 110
using namespace std;

typedef long long LL;
int A, M, P, Q, R, S;

struct Solution
{
    int s;
	int n; 
	int count[MAXN];
    bool A[MAXN];
    
	bool operator < (const Solution &t) const
    {
		if(s != t.s) return s < t.s;
        
		for(int i=0; i<n; i++){
			if(A[i]&&!t.A[i]) return true;
			if(!A[i]&&t.A[i]) return false;
			if(count[i]!=t.count[i]) 
			    return ((count[i]>t.count[i])&&A[i])||(count[i]<t.count[i]&&!A[i]);       
		}
	}
}optimal_solution;


Solution generate_new_soluiton(int a[], int mn)
{
    Solution new_soluiton;
    new_soluiton.s = mn, new_soluiton.n = 0;
    for(int i = 0, &n = new_soluiton.n; i <= mn; i ++)
    {
        new_soluiton.s += a[i];
        if(a[i] > 0)
        {
            new_soluiton.count[n] = a[i], new_soluiton.A[n] = true;
            ++ n;
        }
        if(i < mn)
        {
            if(n == 0 || new_soluiton.A[n - 1])
            {
                new_soluiton.count[n] = 1, new_soluiton.A[n] = false;
                ++ n;
            }
            else ++ new_soluiton.count[n - 1];
        }
    }
   
 return new_soluiton;
}

void generate_soluiton_with_i_Ms(int mn, int p, int px, int py)
{
    if(p > px) px = p;
    LL sum = ((p - px) % A + A) % A + px;
    if(sum > py) return;
    sum = (sum - p) / A;
    int t = sum, max = (py - p) / A, a[MAXN];
    for(int i = mn; i > 0; i --) a[i] = t % M, t /= M;
    a[0] = t;

    Solution new_solution;
    for(int i = mn, fac = 1; i >= 0; i --, fac *= M)
    {
        new_solution = generate_new_soluiton(a, mn);
        
        if(new_solution < optimal_solution) optimal_solution = new_solution;
       
	   
	    if(i > 0 && a[i] != 0)
        {
            sum += (LL)(M - a[i]) * fac, a[i] = M;
            if(sum > max) break;
            for(int j = i; j > 0 && a[j] == M; j --)
                ++ a[j - 1], a[j] = 0;
        }
    }
}


int main()
{
    int rd = 0;

    cin >> A >> M >> P >> Q >> R >> S;
    
	while(!(A==0&&M==0&&P==0&&Q==0&&R==0&&S==0))
	{
    	rd++;
        optimal_solution.s = INF;
        
        LL l = Q - P, p = P;
        for(int i = 0; p <= S - l && l <= S - R; i++)
        {
            generate_soluiton_with_i_Ms(i, p, R, S - l);
            l *= M;
			p *= M;
			if(M == 1) break;
        }
        
        cout <<"Case "<<rd<<":";
        
		if(optimal_solution.s == 0) cout<<" empty"<<endl;  
        else if(optimal_solution.s == INF) cout<<" impossible"<<endl;
        		else
        		{
            		for(int i = 0; i < optimal_solution.n; i ++){
            			cout << " " << optimal_solution.count[i];
						if(optimal_solution.A[i]) 
							cout <<'A';
						else
							cout <<'M';		
					}
            		cout<<endl;
       			}
        cin >> A >> M >> P >> Q >> R >> S;
    }
    return 0;
}