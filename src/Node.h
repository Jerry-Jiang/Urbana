#pragma once
 #include <boost/graph/adjacency_list.hpp>
#include "Output.h"
#include "State.h"

class Node;
typedef boost::adjacency_list<boost::vecS,boost::vecS,boost::undirectedS, Node*> Graph; //todo: change to undirected.
typedef boost::graph_traits<Graph>::vertex_descriptor Vertex_t;

class Node{
    Vertex_t vertex;
    Output* output;
    State* state;
    int nodeNumber;
    bool dbFlag;
    bool graphFlag; //indicates whether this node has been stored in the graph, eq. the vertex is not null.
    
    
    //Masks:                We use mask to avoid repeating the same interations in order to prune the graph
    int* stateMask;         //The first mask is the stateMask. stateMask[i] indicates whether or not the bit i has already been flipped.
                            //Therefore we never flip a variable i where stateMask[i]==1
    int* outputMask;        //The second mask is the outputMask. Every output is connected to a limited number of variables (defined in int** clause).
                            //For outputMask[i]==1 iff forall j in clause[i]. stateMask[j]==1
                            //When the outputMask[i] is one, there is no reason to pick that node anymore.
                            //Think: when outputMask[i] is one + output[i]=0: is this node unsatisfiable??
    int nodeMask;           //Indicates whether or not this node is unsatisfiable. If the nodeMask is one, we cannot reach a satisfiable solution
                            //within one bit-flip of this node. Therefore we exclude this node from searching for nearest node.
                            //
    
    
public:
    Node(State*, Output*);
    int getNodeNumber();
    void setNodeNumber(int);
    
    State* getState();
    Output* getOutput();
    bool isSatisfiable();
    bool getDBFlag();
    void setDBFlag(bool);
    void setVertex(Vertex_t);
    Vertex_t getVertex();
    bool getGraphFlag();
    void setGraphFlag(bool);
};