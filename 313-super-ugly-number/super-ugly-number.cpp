class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<long long,vector<long long>,greater<long long>>p;
        unordered_set<long long>s;
        p.push(1);
        long long l=0,k=0;
        while(n>1){
            k = p.top();
            for(auto &x:primes){
                l = k*x;
                p.push(l);
            }
            while(!p.empty() && p.top() == k) p.pop();
            --n;
        }
        return p.top();
    }
};