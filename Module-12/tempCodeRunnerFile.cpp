   for (int i = 0; i < n; i++)
    {
        for (int child : adj[i])
        {
            mat[i][child] = 1;
        }
    }