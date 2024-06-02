//ID : 208336701
//mail : ofekmarom9@gmail.com

//matala 2
#include "Graph.hpp"
#include "Algorithms.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
using ariel::Algorithms;

int main()
{
    ariel::Graph g1;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph); // load the graph to the object.

    cout<<g1; // should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]

    // 3x3 matrix that represents a weighted connected graph.
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    ariel::Graph g2;
    g2.loadGraph(weightedGraph); // load the graph to the object.

    ariel::Graph g3 = g1 + g2; // add the two graphs together.
    cout<<g3;           // should print the matrix of the graph: [0, 2, 1], [2, 0, 3], [1, 3, 0]

    g1 *= -2;        // multiply the graph by -2.
    cout<<g1; // should print the matrix of the graph: [0, -2, 0], [-2, 0, -2], [0, -2, 0]

    g1 /= -2;
    ariel::Graph g4 = g1 * g2; // multiply the two graphs together.
    cout<<g4;           // should print the multiplication of the matrices of g1 and g2: [0, 0, 2], [1, 0, 1], [1, 0, 0]
    
    g4++;
    cout<<g4; 
    
    ++g4;
    cout<<g4; 
    
    
    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    ariel::Graph g5;
    g5.loadGraph(graph2); // load the graph to the object.
    
    
    try     //try addition between different size graphs
    {
        ariel::Graph g7 = g2 + g5;
    }
    catch (const std::invalid_argument &e)
    {
         cout << e.what() << endl; // should print "Graphs must have the same size for addition."
    }
    
   
    
    
    try     // try multiply between two graphs that cant be multiply.
    {
        ariel::Graph g6 = g5 * g1; 
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // should print "The number of columns in the first matrix must be equal to the number of rows in the second matrix."
    }
    return 0;
}


