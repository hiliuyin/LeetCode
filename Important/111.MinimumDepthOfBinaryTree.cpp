/*Question:
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Tags: Tree Depth-first Search, Breadth-first Search
Similar Problems: Binary Tree Level Order Traversal , Maximum Depth of Binary Tree
*/

/*思路：
方法一：
层次遍历二叉树，找到第一个叶子节点就停止查找。 为了统计层数（也就是到叶子节点的路径长度，用nullptr指针作为分隔每一层的节点。
*/

//Code:
//Code 1:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        std::deque<TreeNode*> treeDeq;
        treeDeq.push_back(root);
        treeDeq.push_back(nullptr);
        
        int depthVal = 0;
        while(!treeDeq.empty())
        {
            TreeNode* pCur = treeDeq.front();
            treeDeq.pop_front();
            if(pCur == nullptr)
            {
                ++depthVal;
                treeDeq.push_back(nullptr);
                continue;
            }
            if(pCur->left == nullptr && pCur->right == nullptr)
            {
                ++depthVal;
                return depthVal;
            }
            if(pCur->left != nullptr)
                treeDeq.push_back(pCur->left);
            if(pCur->right != nullptr)
                treeDeq.push_back(pCur->right);
        }
        
        return depthVal;
    }
};
