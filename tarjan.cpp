int timer=0;
void dfs(int node,int parent,vector<int> adj[], vector<int> &vis,vector<int> &mark, vector<int> &low,vector<int> &time){
    vis[node]=1;
    low[node]=time[node]=timer;
    timer++;
    int child=0;
    for(auto it: adj[node]){
        if(it==parent){
            continue;
        }
        if(!vis[it]){
            dfs(it,node,adj,vis,mark,low,time);
            low[node]=min(low[node],low[it]);
            if(parent!=-1 && low[it]>=time[node]){
                mark[node]=1;
            }
            child++;
        }else{
            low[node]=min(low[node],time[it]);
        }
    }
    if(parent==-1 && child>1){
        mark[node]=1;
    }
}
vector<int> tarjan(int n, vector<int> adj[]){
    vector<int> mark(n,0);
    vector<int> vis(n,0);
    vector<int> low(n,0);
    vector<int> time(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,-1,adj,vis,mark,low,time);
        }
    }
    vector<int> nodes;
    for(int i=0;i<n;i++){
        if(mark[i]){
            nodes.push_back(i);
        }
    }
    return nodes;
}