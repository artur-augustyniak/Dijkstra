/* 
 * File:   Igraph.h
 * Author: aaugustyniak
 *
 * Created on 20 sierpień 2014, 20:45
 */

#ifndef IGRAPH_H
#define	IGRAPH_H
#include <vector>
#include "Vertex.h"

class Igraph {
public:
    virtual Vertex* getFeaturedVertex() = 0;
    virtual std::vector<Vertex*> getAllVertices() = 0;
    virtual std::string textural() = 0;
};

#endif	/* IGRAPH_H */

