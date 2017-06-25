//
//  max_clique_p.cpp
//  WS_C
//
//  Created by Lucas Pellizon on 6/24/17.
//  Copyright © 2017 Lucas Pellizon. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
#include <limits.h>
#include <list>

using namespace std;
int **adj,m,*s;
int clique(int s[],int l)
{
    int i,j,deg[l],mini = 0;
    while(1)
    {
        int minn=l+5,maxx=0;
        memset(deg,0,sizeof(deg));
        for(i=0;i<l;i++)
        {
            for(j=0;j<l;j++)
            {
                if(adj[s[i]][s[j]] && i!=j)
                {
                    deg[i]++;
                    //             cout<<"i="<<s[i]<<" j="<<s[j]<<endl;
                }
            }
            
        }
        /*    cout<<"deg==>"<<endl;
         for(i=0;i<l;i++)
         cout<<deg[i]<<" ";
         cout<<endl;
         */    for(i=0;i<l;i++)
         {
             if(deg[i]<minn)
                 minn=deg[i],mini=i;
             if(deg[i]>maxx)
                 maxx=deg[i];
         }
        //    cout<<"min="<<minn<<" max="<<maxx<<endl;
        //   system("pause");
        if(minn==maxx)
            return l;
        else
        {
            l--;
            for(i=1;i<mini;i++)
                s[i]=s[i];
            for(;i<=l;i++)
                s[i]=s[i+1];
        }
    }
}
int main()
{
    int m,i,j,maxx=0;
    int v, e;
    int x, y;
    scanf("%d", &v);//Número de vértices
    scanf("%d", &m); //Número de arestas
    
    s = (int*) malloc(m*sizeof(int));
    adj = (int**) malloc(m*sizeof(int*));
    for (i=0;i<m;i++){
        adj[i] = (int*) malloc(m*sizeof(int));

    }

    
    for(int i=0;i<m;i++){
        cin>>x;
        cin>>y;
//        grauvertice[x]++;
//        grau_vertice[y]++;
        adj[x][y] = adj[y][x] = 1; //Matriz de adjacência
    }
//    cin>>m;
//    for(i=0;i<m;i++)
//    {
//        for(j=0;j<m;j++)
//            cin>>adj[i][j];
//    }
    /*  for(i=0;i<m;i++)
     {
     for(j=0;j<m;j++)
     cout<<adj[i][j]<<" ";
     cout<<endl;
     }
     */
    for(i=0;i<m;i++)
     {
         int s[867]={i},len=1;
         //    cout<<"i===>"<<i+1<<endl;
         for(j=0;j<m;j++)
             if(adj[i][j])
                 s[len++]=j;//,cout<<j+1<<" ";
         //  cout<<"len="<<len<<endl;
         maxx=max(maxx,clique(s,len));
     }
    cout<<"clique maximo: " << maxx << "\n";
    return 0;
}