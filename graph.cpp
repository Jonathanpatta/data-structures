#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
    string name;
    int data;
    Node(string name,int data){
        this->name = name;
        this->data = data;
    }
};

class Edge{
    public:
    Node* Left;
    Node* Right;
    int value;

    Edge(Node* left,Node* right,int val){
        Left = left;
        Right = right;
        value = val;
    }
};

class Graph{

    vector<Node*> nodes;
    vector<Edge*> edges;

    public:
    bool add_node(Node* node){
        bool valid = true;
        for(auto n:nodes){
            if(n->name == node->name){
                valid=false;
            }
        }
        if(valid){
            nodes.push_back(node);
            return true;
        }
        return false;
    }

    bool add_edge(Edge* edge){
        bool lexists = false;
        bool rexists = false;
        for(auto n:nodes){
            if(edge->Left == n){
                lexists = true;
            }
            if(edge->Right == n){
                rexists = true;
            }
        }
        bool edge_exists = false;
        for(auto e:edges){
            if(e==edge){
                edge_exists = true;
            }
        }

        if(lexists && rexists && !edge_exists){
            edges.push_back(edge);
            return true;
        }
        return false;
    }
    void printNodes(){
        for(auto node:nodes){
            cout<<"node:"<<node->name<<"\n";
        }
    }

    void printEdges(){
        for(auto edge:edges){
            cout<<"edge:"<<edge->Left->name<<"->"<<edge->Right->name<<"\n";
        }
    }

};

int main(){
    
    Graph g1;
    Node* n1 = new Node("A",0);
    g1.add_node(n1);
    
    
    Node* n2 = new Node("C",0);
    g1.add_node(n2);
    
    Edge* edge = new Edge(n1,n2,0);
    g1.add_edge(edge);
    
    g1.printNodes();
    
    g1.printEdges();
}