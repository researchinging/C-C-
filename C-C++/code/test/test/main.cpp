#include <iostream>
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

        TreeLinkNode *label=new TreeLinkNode(0);
        queue<TreeLinkNode*> queue_node;
        vector<TreeLinkNode*> same_layer;
        int layer_count=0;
        queue_node.push(root);queue_node.push(label);
        while(!queue_node.empty()){


            TreeLinkNode *tmp=queue_node.front();

            queue_node.pop();
            cout<<tmp->val<<endl;
            if(tmp==label){
                cout << "Hello world!" << endl;
                queue_node.push(label);
                for(int i=0;i<layer_count;i++){
                    (same_layer[i])->next=same_layer[i+1];
                }
                same_layer.erase(same_layer.begin(),same_layer.end());
                layer_count=0;
            }
            else{
                cout<<"begin ifnot"<<endl;
                same_layer.push_back(tmp);
                if(tmp->left!=NULL) queue_node.push(tmp->left);
                if(tmp->right!=NULL) queue_node.push(tmp->right);

                cout<<"end ifnot"<<endl;
            }
        }
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

    //cout<<t2->next->val<<endl;


    return 0;
}
