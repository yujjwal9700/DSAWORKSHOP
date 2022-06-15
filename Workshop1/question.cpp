int find_count(int a,int b)
{
    int ans=0,count;
    for(int i=a;i<=b;i++){
        count=0;
        for(int  j=1;j<=i;j++){
            if(i%j==0)
               count++;
        }
        if(count%2==1)
          ans++;
    }
    return ans;
}