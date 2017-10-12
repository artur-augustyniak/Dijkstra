/* 
 * File:   SomeGraph.cpp
 * Author: aaugustyniak
 * 
 * Created on 20 sierpień 2014, 20:46
 */

#include "SomeGraph.h"
#include <sstream>
#include <string>

SomeGraph::SomeGraph() {

    Vertex* v1 = new Vertex(1);
    Vertex* v2 = new Vertex(2);
    Vertex* v3 = new Vertex(3);
    Vertex* v4 = new Vertex(4);
    Vertex* v5 = new Vertex(5);
    Vertex* v6 = new Vertex(6);

    v1->addDest(v4, 3)->addDest(v2, 3);
    v2->addDest(v3, 2);
    v3->addDest(v6, 1);
    v4->addDest(v5, 1);
    v5->addDest(v3, 1)->addDest(v6, 2);
    v6->addDest(v4, 3);

    allGraphVertices.push_back(v1);
    allGraphVertices.push_back(v2);
    allGraphVertices.push_back(v3);
    allGraphVertices.push_back(v4);
    allGraphVertices.push_back(v5);
    allGraphVertices.push_back(v6);
    featuredVertex = v1;
}

SomeGraph::SomeGraph(const SomeGraph& orig) {
}

SomeGraph::~SomeGraph() {

    for (int i = 0; i < allGraphVertices.size(); i++) {
        delete allGraphVertices.at(i);
    }
}

Vertex* SomeGraph::getFeaturedVertex() {
    return featuredVertex;
}

std::vector<Vertex*> SomeGraph::getAllVertices() {
    return allGraphVertices;
}

std::string SomeGraph::textural() {

    std::stringstream ss;
    for (int i = 0; i < allGraphVertices.size(); i++) {
        ss << allGraphVertices.at(i)->toString();
    }
    return ss.str();


}

