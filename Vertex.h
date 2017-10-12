/* 
 * File:   Vertex.h
 * Author: aaugustyniak
 *
 * Created on 16 sierpień 2014, 13:33
 */

#ifndef VERTEX_H
#define	VERTEX_H

#include "HeapPrioQueue.h"
#include<string>
#include "Edge.h"
class Vertex {
public:
    Vertex(std::string label);
    Vertex(int label);
    
    virtual ~Vertex();

    Vertex* getPrdecessorOnPath();
    void setPrdecessorOnPath(Vertex& prdecessorOnPath);
    Vertex* addDest(Vertex* dest, int cost);
    int getCostFromFeaturedVert();
    void setCostFromFeaturedVert(int costFromFeaturedVert);
    std::string getLabel();
    std::string toString();
    std::vector<Edge*> iterable();
    bool operator>(const Vertex & that);
    bool operator<(const Vertex & that);

private:
    Vertex(const Vertex& orig);
    int costFromFeaturedVert;
    std::string vertexLabel;
    HeapPrioQueue<Edge> outgoingEdges;
    Vertex* predOnPath;

};

#endif	/* VERTEX_H */

