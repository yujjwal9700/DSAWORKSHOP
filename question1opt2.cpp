#include<bits/stdc++.h>
using namespace std;
vector<int>numbers;
vector<bool>prime;
int range=100000;
void sieve(){
    prime.resize(range,true);
    for(int i=2;i<=sqrt(range);i++)
    {
        if(prime[i]){
            for(int j=i*2;j<=range;j*=i)
               prime[i]=false;
        
           
    }
    }
}
void odd_div()
{
    numbers.resize(range,0);
    for(int i=1;i<=sqrt(range);i++)
        {
        int count=0;
        for(int j=1;j<=i;j++)
        {
            if(i%j==0)
            {
                count++;
                if(i/j!=j)
                   count++;
            }
        }
        if(count==3)
            numbers[i*i]=1;
        }
           
    for(int i=2;i<=range;i++)
       numbers[i]+=numbers[i-1];
    
}
int solve(int a,int b)
{
    return numbers[b]-numbers[a-1];
}
int main(){
    odd_div();
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int a,b; 
        cin>>a>>b;
        cout<<solve(a,b)<<endl;
    }
}