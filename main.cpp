#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include "graph.h"
using namespace std;

vector<pair<int,int>> read_file(string filename){
    pair<int,int> input; vector<pair<int,int>> vr;
    ifstream myfile(filename);
    while(!myfile.eof()){myfile>>input;vr.push_back(input);}
    vr.pop_back();
    return vr;}

bool searchFunction(Graphh G, int u){ //int u is the starting point of the function
    stack<int> S, temp; stack<pair<int,int> > paste; int count = 0;
    S.push(u);
    for(int i=1; i<G.size; ++i){ //the first if statement in pseudocode
        for(int j=1; j<G.size; ++j){
            if(G.a[i][j]==1){count++;}}}
    if(count==0){cout<<"Solution found"<<endl; return true;} else{count=0;}
    //finding all indexes where there is an adjacent vertex
    for(int i=0; i<G.size; ++i){if(G.a[u][i]==1){count++; temp.push(i);}}
    //for all adj verticies v of u in Graph G
    for(int i=0; i<count; ++i){
        int v = temp.top(); temp.pop();
        pair<int,int> e = {u,v};
        if(i==0){paste.push(e);}
        //"deleting" edges from the graph
        G.a[u][v]=0; G.a[v][u]=0;
        bool f = searchFunction(G, v);
        //if(f){cout<<e.first<<" "<<e.second<<endl; return true;}
        if(f){
            if(paste.top().second!=e.first){int tempo = e.first; e.first = e.second; e.second = tempo;}
            cout<<"("<<e.first<<", "<<e.second<<") -> ";
            return true;}
        //undo deleting
        else{G.a[u][v]=1; G.a[v][u]=1;}}
    S.pop();
    return false;
}

int main(int argc, char** argv){
    string filename = argv[1];
    bool temp;
    vector<pair<int,int>> p = read_file(filename);
    cout<<"\nThis is the input file "<<filename<<":"<<endl;
    for(int i=0; i<p.size(); ++i){cout<<p[i].first<<" "<<p[i].second<<endl;}
    Graph graph(p[0].first+1);
    Graphh graphh(p[0].first+1);
    for(int i=1; i<=p[0].second; ++i){graph.new_edge(p[i].first, p[i].second);}
    for(int i=1; i<=p[0].second; ++i){graphh.new_edge(p[i].first, p[i].second);}
    cout<<"This is the adjacency list of "<<filename<<endl; graph.print();
    graphh.print(); cout<<endl;
    for(int i=0; i<graphh.size; ++i){if((temp = searchFunction(graphh, i))==true){cout<<"end of solution"<<endl; graphh.draw(filename); break;} if(searchFunction(graphh, i)!=true && i==graphh.size-1){cout<<"No solution."<<endl;}}
    return 0;
}
