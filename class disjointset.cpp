class disjointset 
{
    public:
        vector<int> rank,parent;
    disjointset(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        parent[i]=i;
    }
    int findupar(int node)
    {
        if(node==parent[node])
        return node;
        return parent[node]=findupar(parent[node]);
    }
    void unionbyrank(int u,int v)
    {
        int ulpu=findupar(u);
        int ulpv=findupar(v);
        if(ulpu==ulpv)
        return ;
        if(rank[ulpu]<rank[ulpv])
            parent[ulpu]=ulpv;
        else if(rank[ulpu]>rank[ulpv])
            parent[ulpv]=ulpu;
        else
        {
            parent[ulpv]=ulpu;
            rank[ulpu]++;
        }
    }
};