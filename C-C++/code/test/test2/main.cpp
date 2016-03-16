#include <iostream>
#include <stdlib.h>
#include<queue>
using namespace std;

/**
 * Definition for binary tree with next pointer.*/
 struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL) return ;
        deque<TreeLinkNode *> deque_node;
        deque_node.push_back(root);
        TreeLinkNode * pLeft;
        int i;
        while(!deque_node.empty()){
            TreeLinkNode *pNode=deque_node.front();
            if(pNode==pLeft){
                for(i=0;i<deque_node.size()-1;i++)
                    deque_node[i]->next=deque_node[i+1];
            }
            deque_node.pop_front();
            if(pNode->left!=NULL)  {deque_node.push_back(pNode->left);pLeft=pNode->left;}
            if(pNode->right!=NULL)  deque_node.push_back(pNode->right);
        }
    }

    void printvector(vector<TreeLinkNode*> &myvector){
        int i;
        cout << "myvector contains:";
        for (i=0; i<myvector.size(); i++)
            cout << " " << myvector[i]->val;
        cout << endl;
    }
};
int main()
{
    struct TreeLinkNode* t1=new struct TreeLinkNode(1);
    struct TreeLinkNode* t2=new struct TreeLinkNode(2);
    struct TreeLinkNode* t3=new struct TreeLinkNode(3);
    t1->left=t2;
    t1->right=t3;

    Solution* sol=new Solution();
    sol->connect(t1);

    cout<<t2->next->val<<endl;


    return 0;
}
