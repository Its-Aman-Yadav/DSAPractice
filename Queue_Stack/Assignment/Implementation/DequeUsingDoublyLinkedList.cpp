#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int value;
    node* next_key;
    node* prev_key;
    node(int input)
    {
        value=input;
        next_key=NULL;
        prev_key=NULL;
        return;
    }
};
class DeQueues
{
    node* head;
    node* tail;
    public:
    DeQueues()
    {
        head=NULL;
        tail=NULL;
    }
    void push_back(int value)
    {
       
    }
    void push_front(int value)
    {
       
    }
    void pop_front()
    {
      
    }
    void pop_back()
    {
        
    }
    int get_front(){
    	return 0;
    }
    int get_back(){
    	return 0;
    }
    void display_queue()
    {
        
    }
};
int main()
{
    DeQueues s;
    s.push_front(0);
    s.push_front(1);
    s.push_front(2);
    s.push_back(-1);
    cout<<"front: "<<get_front()<<"\n";
    cout<<"back: "<<get_back()<<"\n";
    s.display_queue();
}
