/*
 * Complete the 'divisibleSumPairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER_ARRAY ar
 */

int divisibleSumPairs(int n, int k, vector<int> ar) {
    int c=0;
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if((ar[i]+ar[j])%k==0)
                c++;
    return c;
}