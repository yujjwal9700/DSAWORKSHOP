#include<bits/stdc++.h>
using namespace std;
class CustomArray{
    int *arr;
    int sz,cap;
    void resize()
    {
        if(cap==0)
           cap=1;
        else
           cap*=2;
        int *new_arr=new int[cap];
        for(int i=0;i<sz;i++)
           new_arr[i]=arr[i];
        int *temp=arr;
        arr=new_arr;
        delete temp;
    }
    public:
    CustomArray(){
        sz=cap=0;
        arr=NULL;
    }
    CustomArray(int n,int val)
    {
        sz=0;
        cap=n;
        arr=new int[cap];
        for(int i=0;i<cap;i++)
           this->push_back(val);
    }
    CustomArray(initializer_list<int>temp)
    {
          sz=0;
          cap=temp.size();
          arr=new int[cap];
          for(int i:temp)
              this->push_back(i);
            
    }
    void push_back(int val)
    {
        if(sz==cap){
            this->resize();
        }
        this->arr[sz]=val;
        sz++;
        
    }
    void pop_back()
    {
        if(sz==0)
        {
            throw __throw_range_error;
        }
        else
           sz--;
    }
    int at(int idx){
        if(idx>=sz)
             __throw_out_of_range("Given index is out of range");
        return this->arr[idx];
    }
    int& operator[](int idx){
         if(idx>=sz)
             __throw_out_of_range("Given index is out of range");
        return this->arr[idx];
    }
    void insert(int idx,int val)
    {
        if(idx>=sz)
           __throw_out_of_range("Given index is out of range");
        if(cap==sz)
            this->resize();
        for(int i=sz;i>=idx;i--)
              arr[i]=arr[i-1];
        arr[idx]=val;
        sz++;
    }
    int find(int val){
        for(int i=0;i<sz;i++){
            if(arr[i]==val)
               return i;
        }
        return -1;
    }
    void print(){
        for(int i=0;i<sz;i++)
           cout<<this->at(i)<<" ";
        cout<<endl;
    }
};
int main(){
    CustomArray *obj=new CustomArray();
    obj->push_back(10);
    obj->push_back(20);
    obj->push_back(30);
    obj->print();
    obj->pop_back();
    obj->print();
    //cout<<(*obj)[2]<<endl;
    obj->insert(1,12);
    obj->print();
}