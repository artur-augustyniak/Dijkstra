/* 
 * File:   Edge.cpp
 * Author: aaugustyniak
 * 
 * Created on 18 sierpień 2014, 20:34
 */

#include "Edge.h"
#include <stdexcept>
Edge::Edge(Vertex* src, Vertex* dst, int c) {
    validateCost(c);
    source = src;
    destination = dst;
    cost = c;
}

Edge::Edge(int id) {
}

Edge::Edge(const Edge& orig) {
}

Edge::~Edge() {
}

Vertex* Edge::getSource() {
    return source;
}

Vertex* Edge::getDestination() {
    return destination;
}

int Edge::getCost() {
    return cost;
}

bool Edge::operator>(const Edge & that) {
    return this->cost > that.cost;
    
}

bool Edge::operator<(const Edge & that) {
    return this->cost < that.cost;
}

void Edge::validateCost(int c) {
    if(c <0){
        throw std::runtime_error("Do not use negative values for path cost.");
    }
}