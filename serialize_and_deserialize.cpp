//297: Serialize and Deserialize Binary tree
//topics: Tree traversals
    string serialize(TreeNode* root){
        if(!root){
            return ",#";
        }
        string s = "";
        queue<TreeNode*>q;
        s += ',';
        s += to_string(root->val);
        s += ',';
        q.push(root);
        while(!q.empty()){
            TreeNode* x = q.front();
            q.pop();
            
            if(x->left){
                s += to_string(x->left->val);
                s += ',';
                q.push(x->left);
            }else{
                s += "#,";
            }
            
            if(x->right){
                s += to_string(x->right->val);
                s += ',';
                q.push(x->right); 
            }else{
                s += "#,";
            }
        }
        return s;
    }

    int func(int& i, string str){
        int n = str.length();
        i++;
        bool is_neg = false;
        if(str[i] == '#'){
            i++;
            return INT_MAX;
        }
        
        if(str[i] == '-'){
            is_neg = true;
            i++;
        }
        
        int num = 0;
        while(i < n && str[i] != ','){
            num = (num*10) + (str[i]-'0');
            i++;
        }
        
        if(is_neg){
            num *= -1;
        }
        
        return num;
    }
    
    TreeNode* deserialize(string data) {
        int i = 0;
        int num = func(i, data);
        if(num == INT_MAX){
            return NULL;
        }
        TreeNode* root = new TreeNode(num);
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* x = q.front();
            q.pop();
            int num1 = func(i, data);
            if(num1 == INT_MAX){
                x->left = NULL;
            }else{
                x->left = new TreeNode(num1);
                q.push(x->left);
            }
            
            int num2 = func(i, data);
            if(num2 == INT_MAX){
                x->right = NULL;
            }else{
                x->right = new TreeNode(num2);
                q.push(x->right);
            }
        }
        return root;
    }