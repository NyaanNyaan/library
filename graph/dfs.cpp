auto dfs = [&](auto rec,int cur,int par = -1) -> void{
    
  each(dst , g[cur]){
    if(dst == par) continue;
    rec(rec , dst , cur);
  }

};
dfs(dfs , 0);