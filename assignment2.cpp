#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    char ch;
    int freq;
    Node *left,*right;
    Node(char c,int f){
        ch=c;
        freq=f;
        left=nullptr;
        right=nullptr;
    }
};
class compare{
    public:
    bool operator()(Node * a,Node *b){
        return a->freq>b->freq;
    }
};
void print(Node *root,string code){
    if(root==nullptr)return ;
    if(root->left==nullptr && root->right==nullptr){
        cout<<root->ch<<" : "<<code<<endl;
    }
    print(root->left,code+'0');
    print(root->right,code+'1');
}
int main(){
    priority_queue<Node *,vector<Node *>,compare>pq;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        char c;
        int f;
        cin>>c>>f;
        Node *temp=new Node(c,f);
        pq.push(temp);
    }
    while(pq.size()>1){
        Node *a=pq.top();
        pq.pop();
        Node *b=pq.top();
        pq.pop();
        Node * temp=new Node('$',a->freq+b->freq);
        pq.push(temp);
        temp->left=a;
        temp->right=b;
    }
    print(pq.top(),"");
    return 0;
}
