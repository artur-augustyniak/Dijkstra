/* 
 * File:   SomeGraph.h
 * Author: aaugustyniak
 *
 * Created on 20 sierpień 2014, 20:46
 */

#ifndef SOMEGRAPH_H
#define	SOMEGRAPH_H

#include "Igraph.h"

class SomeGraph : public Igraph {
public:
    SomeGraph();
    SomeGraph(const SomeGraph& orig);
    virtual ~SomeGraph();
    virtual Vertex* getFeaturedVertex();
    virtual std::vector<Vertex*> getAllVertices();
    virtual std::string textural();
private:
    Vertex* featuredVertex;
    std::vector<Vertex*> allGraphVertices;

};

#endif	/* SOMEGRAPH_H */

