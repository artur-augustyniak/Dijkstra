/* 
 * File:   Vertex.cpp
 * Author: aaugustyniak
 * 
 * Created on 16 sierpień 2014, 13:34
 */

#include "Vertex.h"
#include <sstream>
#include <string>

Vertex::Vertex(std::string label) {
    vertexLabel = label;
    costFromFeaturedVert = 100000000;
}

Vertex::Vertex(int label) {
    std::ostringstream strnify;
    strnify << label;
    vertexLabel = strnify.str();
//    vertexLabel = std::to_string(label);
//    costFromFeaturedVert = 100000000;
}



Vertex::~Vertex() {
    for (int i = 0; i < outgoingEdges.iterable().size(); i++) {
        delete outgoingEdges.iterable().at(i);
    }

}

Vertex* Vertex::getPrdecessorOnPath() {
    return predOnPath;
}

void Vertex::setPrdecessorOnPath(Vertex& pred) {
    predOnPath = &pred;
}

Vertex* Vertex::addDest(Vertex* dest, int cost) {
    
    Edge* e = new Edge(this, dest, cost);
    outgoingEdges.enqueue(e);
    return this;
}

int Vertex::getCostFromFeaturedVert() {
    return costFromFeaturedVert;
}

void Vertex::setCostFromFeaturedVert(int costFromFVert) {
    costFromFeaturedVert = costFromFVert;
}

std::string Vertex::getLabel() {
    return vertexLabel;
}

std::string Vertex::toString() {

    std::string label = (vertexLabel.size()) ? vertexLabel : "No Label";
    std::string predLabel = (predOnPath) ? predOnPath->getLabel() : "X";
    std::ostringstream stringStream;
    stringStream << "Vertex " << label << " : Pred "
            << predLabel << " : Least cost form source "
            << costFromFeaturedVert << std::endl;
    std::string ret = stringStream.str();
    return ret;
}

bool Vertex::operator>(const Vertex & that) {
    return this->costFromFeaturedVert > that.costFromFeaturedVert;
}

bool Vertex::operator<(const Vertex & that) {
    return this->costFromFeaturedVert < that.costFromFeaturedVert;
}

std::vector<Edge*> Vertex::iterable() {
    return outgoingEdges.iterable();
}