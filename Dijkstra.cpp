/* 
 * File:   Dijkstra.cpp
 * Author: aaugustyniak
 * 
 * Created on 20 sierpień 2014, 21:31
 */

#include "Dijkstra.h"

Dijkstra::Dijkstra(Igraph& g) {
    graph = &g;
    openSet = new HeapPrioQueue<Vertex>(g.getAllVertices());
}

Dijkstra::Dijkstra(const Dijkstra& orig) {
}

Dijkstra::~Dijkstra() {
    delete openSet;
}

Igraph* Dijkstra::evaluateShortestPaths() {
    graph->getFeaturedVertex()->setCostFromFeaturedVert(0);
    while (!openSet->isEmpty()) {
        Vertex* currentVert = openSet->dequeueMin();
        std::vector<Edge*> nb = currentVert->iterable();




        for (int i = 0; i < nb.size(); i++) {

            Edge* e = nb.at(i);

            int lastCostToDest = e->getDestination()->getCostFromFeaturedVert();
            int currCostToDest = currentVert->getCostFromFeaturedVert() + e->getCost();
            if (lastCostToDest > currCostToDest) {
                e->getDestination()->setCostFromFeaturedVert(currCostToDest);
                e->getDestination()->setPrdecessorOnPath(*currentVert);
            }
        }
    }
    return graph;
}

