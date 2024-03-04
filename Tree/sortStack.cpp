#include<bits/stdc++.h>


using namespace std;

void insertSort(stack<int>&s,int element){
    
    if(s.empty()||element>s.top()){
        
       s.push(element);
       return ;
    }
    
    int temp = s.top();
    s.pop();
    insertSort(s,element);
    s.push(temp);
    
    return ;
    }
    


void sortStack(stack<int>&s){
    
    
    if(s.empty()){
        return ;
    }  
    
    int temp = s.top();
    s.pop();
    sortStack(s);
    
    insertSort(s,temp);
}


int main(){
 stack<int>s ;    
    s.push(5);
    s.push(0);
    s.push(1);
    s.push(3);
    s.push(2);
    s.push(4);
    
    
 sortStack(s);  
 
 stack<int>s2;
 
 
 while(!s.empty()){
     int temp = s.top();
     
     s2.push(temp);
     
     s.pop();
 }
    
    while(!s2.empty()){
        cout<<s2.top()<<" ";
        s2.pop();
    }
    return 0;
}







/*  ******************************************************* */
