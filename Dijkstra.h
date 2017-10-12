/* 
 * File:   Dijkstra.h
 * Author: aaugustyniak
 *
 * Created on 20 sierpień 2014, 21:31
 */

#ifndef DIJKSTRA_H
#define	DIJKSTRA_H

#include "Igraph.h"
#include "Vertex.h"

class Dijkstra {
public:
    Dijkstra(Igraph& g);
    Dijkstra(const Dijkstra& orig);
    virtual ~Dijkstra();
    Igraph* evaluateShortestPaths();
private:
    Igraph* graph;
    HeapPrioQueue<Vertex>* openSet;

};

#endif	/* DIJKSTRA_H */

