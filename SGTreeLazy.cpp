class SGTTree{
    vector<int>seg;
    vector<int>lazy;
public:
    SGTTree(int n){
        seg.resize(4*n);
        lazy.resize(4*n);
    }

    void build(int ind,int low,int high,vector<int> arr){
        if(low==high){
            seg[ind]=arr[ind];
            return;
        }
        int mid=low+(high-low)/2;
        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }

    void update(int ind,int low,int high,int l,int r, int val){
        // update previous values and lazy propagate downwards
        if(lazy[ind]!=0){
            seg[ind] += (high-low+1)*lazy[ind];
            if(low!=high){
                lazy[2*ind+1]+=lazy[ind];
                lazy[2*ind+2]+=lazy[ind];
            }
            lazy[ind]=0;
        }

        // no overlap
        // l r low high || low high l r
        if(r<low || l>high){
            return;
        }

        // complete overlap
        // l low high r
        if(low>=l && high<=r){
            seg[ind] += (high-low+1)*val;
            if(low!=high){
                lazy[2*ind+1] += val;
                lazy[2*ind+2] += val;
            }
            return;
        }

        // partial overlap
        int mid=low+(high-low)/2;
        update(2*ind+1,low,mid,l,r,val);
        update(2*ind+2,mid+1,high,l,r,val);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }

    int query(int ind,int low, int high, int l, int r){
        if(lazy[ind]!=0){
            seg[ind] += (high-low+1)*lazy[ind];
            if(low!=high){
                lazy[2*ind+1]+=lazy[ind];
                lazy[2*ind+2]+=lazy[ind];
            }
            lazy[ind]=0;
        }

        if(r<low || l>high){
            return 0;
        }

        if(low>=l && high<=r){
            return seg[ind];
        }

        int mid=low+(high-low)/2;
        int left=query(2*ind+1,low,mid,l,r);
        int right=query(2*ind+2,mid+1,high,l,r);
        return left+right;
    }
};