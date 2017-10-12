/* 
 * File:   main.cpp
 * Author: artur
 *
 * Created on 28 kwiecień 2012, 15:48
 */


#include <iostream>
#include "SomeGraph.h"
#include "Dijkstra.h"

using namespace std;

int main(int argc, char** argv) {
    SomeGraph G;
    Dijkstra alg(G);
    alg.evaluateShortestPaths();
    cout << alg.evaluateShortestPaths()->textural() << endl;
    return 0;
}

