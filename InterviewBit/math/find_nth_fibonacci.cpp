#define MOD 1000000007;
long long int a,b,c,d;

void fast_fib(int n, long long int ans[])
{
    if(n==0)
    {
        ans[0]=0;
        ans[1]=1;
        return;
    }
    fast_fib(n/2,ans);
    a= ans[0]; //F(n)
    b= ans[1]; //F(n+1)
    c= 2*b-a; //2*F(n+1)-F(n)
    if(c < 0)
        c+=MOD;
    c= (a*c) % MOD; //F(2n)= F(n)*(2*F(n+1)-F(n))
    d= (a*a+b*b) % MOD; //F(2n+1)= F(n)^2 + F(n+1)^2
    if(n%2 == 0)
    {
        ans[0]= c;
        ans[1]= d;
    }
    else
    {
        ans[0]= d;
        ans[1]= c+d;
    }
}

int Solution::solve(int n) {
    long long int ans[2]={0};
    fast_fib(n,ans);
    return ans[0];
}

