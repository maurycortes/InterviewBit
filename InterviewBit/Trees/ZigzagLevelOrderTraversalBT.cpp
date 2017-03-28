/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> levelNodeValues;
        if(!root) return levelNodeValues;
        
        stack<TreeNode*> *curLevel = new stack<TreeNode*>();
        stack<TreeNode*> *nextLevel = new stack<TreeNode*>();
        curLevel->push(root);
        bool left2right = true;
        
        while(!curLevel->empty())
        {
            vector<int> curLevelValues;
            while(!curLevel->empty())
            {
                TreeNode *cur = curLevel->top();
                curLevel->pop();
                curLevelValues.push_back(cur->val);
                
                if(left2right)
                {
                    if(cur->left) nextLevel->push(cur->left);
                    if(cur->right) nextLevel->push(cur->right);
                }
                else
                {
                    if(cur->right) nextLevel->push(cur->right);
                    if(cur->left) nextLevel->push(cur->left);
                }
            }
            levelNodeValues.push_back(curLevelValues);
            
            // swap curLevel and nextLevel, no need to clear since curLevel is already empty 
            stack<TreeNode*> *temp = curLevel;
            curLevel = nextLevel;
            nextLevel = temp;
            
            left2right  = !left2right;
        }
        
        return levelNodeValues;
}
