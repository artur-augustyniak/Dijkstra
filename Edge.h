/* 
 * File:   Edge.h
 * Author: aaugustyniak
 *
 * Created on 18 sierpień 2014, 20:34
 */

#ifndef EDGE_H
#define	EDGE_H


class Vertex;
class Edge {
public:
    Edge(Vertex* source, Vertex* dest, int cost);
    Edge(int id);
    Edge(const Edge& orig);
    virtual ~Edge();
    Vertex* getSource();
    Vertex* getDestination();
    int getCost();

    bool operator>(const Edge & that);
    bool operator<(const Edge & that);
private:
    Vertex* source;
    Vertex* destination;
    int cost;
    void validateCost(int c);

};

#endif	/* EDGE_H */

