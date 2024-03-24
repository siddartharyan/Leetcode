class Node{
    public:
        Node* v[26]={NULL};
        int ind;
        Node(){
            this->ind = INT_MAX;
        }
};

class Trie{
    Node* root = NULL;
    public:
        Trie(){
            this->root = new Node();
        }
        void insert(string &s,int &j,int &n,vector<int>&v){
            Node* t = root;
            int k = 0,l=0;
            for(int i=n-1;i>=0;--i){
                k = s[i]-'a';
                if(t->v[k] == NULL){
                    t->v[k] = new Node();
                }
                t=t->v[k];
                if(t->ind != INT_MAX){
                    if(v[t->ind] > v[j]){
                        t->ind = j;
                    }else if(v[t->ind] == v[j]){
                        t->ind = min(t->ind,j);
                    }
                }else{
                    t->ind = j;
                }
            }
        }

        int get(string &s){
            Node* t = root;
            int n = s.size();
            int k = 0;
            Node* p = t;
            for(int i=n-1;i>=0;--i){
                k = s[i]-'a';
                if(t == NULL) break;
                p = t;
                t=t->v[k];
            }
            return t == NULL ? p->ind:t->ind;
        }
};


class Solution {
public:
    vector<int> stringIndices(vector<string>& w, vector<string>& q) {
        vector<int>ans;
        Trie t;
        int n = w.size();
        vector<int>s;
        int v=INT_MAX,m = 0,k=0;
        for(int i=0;i<n;++i){
            k = w[i].size();
            s.push_back(k);
            if(v > s.back()){
                v = s.back();
                m = i;
            }
        }
        for(int i=0;i<n;++i){
            t.insert(w[i],i,s[i],s);
        }
        
        for(auto &x:q){
            k = t.get(x);
            if(k == INT_MAX) ans.push_back(m);
            else ans.push_back(k);
        }
        return ans;
    }
};