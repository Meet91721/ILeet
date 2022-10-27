class Solution {
public:
    long long n;
    struct Tree{
        long long val;
        long long left;
        long long right;
        Tree* lc;
        Tree* rc;
    };
    map<long long,Tree*>mp;
    long long res = 0, cnt = 0;
    long long dfs(Tree* node){
        // long long l = 0, r = 0
        if(node->lc!=NULL){
            node->left = dfs(node->lc);
        }
        if(node->rc!=NULL){
            node->right = dfs(node->rc);
        }
        return node->left+node->right+1;
    }
    void func(Tree* node){
        long long rem = max(1LL,n-node->left-node->right-1);
        long long l = max(1LL,node->left);
        long long r = max(1LL,node->right);
        long long mul = l*r*rem;
        if(mul>cnt){
            cnt=mul;
            res=1;
        }
        else if(mul == cnt){
            res++;
        }
        if(node->lc)
        func(node->lc);
        
        if(node->rc)
        func(node->rc);
    }
    
    int countHighestScoreNodes(vector<int>& parents) {
        n=parents.size();
        for(long long i = 0; i < n; i++){
            Tree* t = (struct Tree*)malloc(sizeof(struct Tree));
            t->val=i;
            t->left=0;
            t->right=0;
            t->lc=NULL;
            t->rc=NULL;
            mp[i]=t;
        }
        for(long long i = 1; i < n; i++){
            if(mp[parents[i]]->lc==NULL){
                mp[parents[i]]->lc=mp[i];
            }
            else{
                mp[parents[i]]->rc=mp[i];
            }
        }
        dfs(mp[0]);
        func(mp[0]);
        return res;
    }
};