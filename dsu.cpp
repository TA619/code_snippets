class dsu{
    vector<int> parent, size;

public: 
    dsu(int n){
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int ulp(int x){
        if(parent[x] == x) return x;
        return parent[x] = ulp(parent[x]);
    }

    void join(int u, int v){
        int pu = ulp(u);
        int pv = ulp(v);

        if(pu == pv) return;
        
        if(size[pu] > size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        } else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};
