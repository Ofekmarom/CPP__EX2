//ID : 208336701
//mail : ofekmarom9@gmail.com

//matala 2

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;
using namespace ariel;


TEST_CASE("operator g1 + g2") {

    ariel::Graph graph1;
    ariel::Graph graph2;
    vector<vector<int>> adjMatrix1 ={
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    vector<vector<int>> adjMatrix2 = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    graph1.loadGraph(adjMatrix1);
    graph2.loadGraph(adjMatrix2);
    ariel::Graph result = graph1 + graph2;//addition operator

    //the result matrix should be
    vector<vector<int>> ans = { {0, 2, 1}, {2, 0, 3}, {1, 3, 0}};
    CHECK(result.getMatrix() == ans);
}

TEST_CASE("operator g1 += g2") {
    ariel::Graph graph1;
    ariel::Graph graph2;
    vector<vector<int>> adjMatrix1 ={
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    vector<vector<int>> adjMatrix2 = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    graph1.loadGraph(adjMatrix1);
    graph2.loadGraph(adjMatrix2);
    graph1 += graph2; // addition operator

    //the result matrix should be
    vector<vector<int>> ans = { {0, 2, 1}, {2, 0, 3}, {1, 3, 0}};
    CHECK(graph1.getMatrix() == ans);
}

TEST_CASE("unary plus operator +g") {
    ariel::Graph graph;
    vector<vector<int>> adjMatrix = {{-1, 2}, {3, -4}};
    graph.loadGraph(adjMatrix);
    ariel::Graph result = +graph; // Perform unary plus operation
    // all elements in the result matrix should be positive
    vector<vector<int>> expected = {{1, 2}, {3, 4}};
    CHECK(result.getMatrix() == expected);
}
TEST_CASE("operator g1 - g2") {
    ariel::Graph graph1;
    ariel::Graph graph2;
    vector<vector<int>> adjMatrix1 = {{0, 5, 0}, {1, 0, 1}, {0, 1, 0}};
    vector<vector<int>> adjMatrix2 = {{1, 0, 1}, {0, 0, 1}, {1, 1, 0}};
    graph1.loadGraph(adjMatrix1);
    graph2.loadGraph(adjMatrix2);
    ariel::Graph result = graph1 - graph2;

    //the result matrix should be
    vector<vector<int>> expected = {{-1, 5, -1}, {1, 0, 0}, {-1, 0, 0}};
    CHECK(result.getMatrix() == expected);
}

TEST_CASE("operator g1 -= g2") {
    ariel::Graph graph1;
    ariel::Graph graph2;
    vector<vector<int>> adjMatrix1 = {{0, 5, 0}, {1, 0, 1}, {0, 1, 0}};
    vector<vector<int>> adjMatrix2 = {{1, 0, 1}, {0, 0, 1}, {1, 1, 0}};
    graph1.loadGraph(adjMatrix1);
    graph2.loadGraph(adjMatrix2);

    graph1 -= graph2;
    vector<vector<int>> expected = {{-1, 5, -1}, {1, 0, 0}, {-1, 0, 0}};

    CHECK(graph1.getMatrix() == expected);
}

TEST_CASE("unary minus operator -g") {

    ariel::Graph graph;
    vector<vector<int>> adjMatrix = {{1, -2}, {-3, 4}};
    graph.loadGraph(adjMatrix);
    ariel::Graph result = -graph; //  unary minus

    vector<vector<int>> expected = {{-1, -2}, {-3, -4}};

    CHECK(result.getMatrix() == expected);
}
TEST_CASE("operator g1 == g2") {
    ariel::Graph graph1;
    ariel::Graph graph2;
    vector<vector<int>> adjMatrix = {{1, 2}, {3, 4}};
    vector<vector<int>> adjMatrix2 = {{1, 2}, {3, 4}};
    graph1.loadGraph(adjMatrix);
    graph2.loadGraph(adjMatrix2);
    // check if the two graphs are equal
    CHECK((graph1 == graph2) ==true);
    CHECK((graph1 != graph2) ==false);
}

TEST_CASE("operator g1 != g2") {

    ariel::Graph graph1;
    ariel::Graph graph2;
    vector<vector<int>> adjMatrix1 = {{1,6,2},{1,1,1} ,{1,3,4}};
    vector<vector<int>> adjMatrix2 = {{1, 0}, {0, 1}};
    graph1.loadGraph(adjMatrix1);
    graph2.loadGraph(adjMatrix2);

    // check if the two graphs are not equal
    CHECK((graph1 != graph2) == true);
    CHECK((graph1 == graph2) == false);
}


TEST_CASE("operator g1 > g2") {
    ariel::Graph graph1;
    ariel::Graph graph2;
    vector<vector<int>> adjMatrix1 = {{1, 3}, {2, 4}};
    vector<vector<int>> adjMatrix2 = {{0, 2}, {1, 3}};
    graph1.loadGraph(adjMatrix1);
    graph2.loadGraph(adjMatrix2);

    // check if graph1 is greater than graph2
    CHECK((graph1 > graph2) == true);
    CHECK((graph2 > graph1) == false);
}

TEST_CASE("operator g1 >= g2") {
    ariel::Graph graph1;
    ariel::Graph graph2;
    vector<vector<int>> adjMatrix1 = {{1, 3}, {2, 4}};
    vector<vector<int>> adjMatrix2 = {{1, 3}, {2, 4}};
    graph1.loadGraph(adjMatrix1);
    graph2.loadGraph(adjMatrix2);

    // check if graph1 is greater than or equal to graph2
    CHECK((graph1 >= graph2) == true);
    CHECK((graph2 >= graph1) == true);
}


TEST_CASE("operator g1 < g2") {
    ariel::Graph graph1;
    ariel::Graph graph2;
    vector<vector<int>> adjMatrix1 = {{0, 1}, {1, 2}};
    vector<vector<int>> adjMatrix2 = {{1, 3}, {2, 4}};
    graph1.loadGraph(adjMatrix1);
    graph2.loadGraph(adjMatrix2);

    // check if graph1 is less than graph2
    CHECK((graph1 < graph2) == true);
    CHECK((graph2 < graph1) == false);
}


TEST_CASE("operator g1 <= g2") {
    ariel::Graph graph1;
    ariel::Graph graph2;
    vector<vector<int>> adjMatrix1 = {{1, 3}, {2, 4}};
    vector<vector<int>> adjMatrix2 = {{1, 3}, {2, 4}};
    graph1.loadGraph(adjMatrix1);
    graph2.loadGraph(adjMatrix2);

    // check if graph1 is less than or equal to graph2
    CHECK((graph1 <= graph2) == true);
    CHECK((graph2 <= graph1) == true);
}

TEST_CASE("++ operator ++g") {

    ariel::Graph graph;
    vector<vector<int>> adjMatrix = {{1, 2}, {3, 4}};
    graph.loadGraph(adjMatrix);
    ++graph; // ++ operation
    vector<vector<int>> expected = {{2, 3}, {4, 5}};
    CHECK(graph.getMatrix() == expected);
}

TEST_CASE("++ operator g++") {

    ariel::Graph graph;
    vector<vector<int>> adjMatrix = {{1, 2}, {3, 4}};
    graph.loadGraph(adjMatrix);
    graph++; // ++ operation
    vector<vector<int>> expected = {{2, 3}, {4, 5}};

    CHECK(graph.getMatrix() == expected);
}
TEST_CASE("operator g * scalar") {
    ariel::Graph graph;
    vector<vector<int>> adjMatrix = {{1, 2}, {3, 4}};
    graph.loadGraph(adjMatrix);
    int scalar = 2;
    ariel::Graph result = graph * scalar;// * operator

    vector<vector<int>> expected = {{2, 4}, {6, 8}};
    CHECK(result.getMatrix() == expected);
}

TEST_CASE("operator g *= scalar") {
    ariel::Graph graph;
    vector<vector<int>> adjMatrix = {{1, 2}, {3, 4}};
    graph.loadGraph(adjMatrix);
    int scalar = 2;
    graph *= scalar; // *= operator

    vector<vector<int>> expected = {{2, 4}, {6, 8}};
    CHECK(graph.getMatrix() == expected);
}


TEST_CASE("operator g / scalar") {
    ariel::Graph graph;
    vector<vector<int>> adjMatrix = {{2, 4}, {6, 8}};
    graph.loadGraph(adjMatrix);
    int scalar = 2;
    ariel::Graph result = graph / scalar; // / operator

    vector<vector<int>> expected = {{1, 2}, {3, 4}};
    CHECK(result.getMatrix() == expected);
}

TEST_CASE("operator g /= scalar") {
    ariel::Graph graph;
    vector<vector<int>> adjMatrix = {{2, 4}, {6, 8}};
    graph.loadGraph(adjMatrix);
    int scalar = 2;
    graph /= scalar; // /= operator

    vector<vector<int>> expected = {{1, 2}, {3, 4}};
    CHECK(graph.getMatrix() == expected);
}

TEST_CASE("matrix multiplication operator g1 * g2") {
    ariel::Graph graph1;
    ariel::Graph graph2;
    vector<vector<int>> adjMatrix1 = {{1, 2}, {3, 4}};
    vector<vector<int>> adjMatrix2 = {{0, 1}, {1, 0}};
    graph1.loadGraph(adjMatrix1);
    graph2.loadGraph(adjMatrix2);
    ariel::Graph result = graph1 * graph2; // graphs multiplication

    vector<vector<int>> expected = {{2, 1}, {4, 3}};
    CHECK(result.getMatrix() == expected);
}



TEST_CASE("output Operator << from the demo") {
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph);
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
}

TEST_CASE("-- Operator --graph") {

    ariel::Graph graph;
    vector<vector<int>> adjMatrix = {{1, 2}, {3, 4}};
    graph.loadGraph(adjMatrix);
    --graph;

    vector<vector<int>> expected = {{0, 1}, {2, 3}};
    CHECK(graph.getMatrix() == expected);
}

TEST_CASE("-- Operator graph--") {
    ariel::Graph graph;
    vector<vector<int>> adjMatrix = {{1, 2}, {3, 4}};
    graph.loadGraph(adjMatrix);
    ariel::Graph result = graph--;

    vector<vector<int>> expectedGraph = {{0, 1}, {2, 3}};
    CHECK(graph.getMatrix() == expectedGraph);

    // check that original graph (result of the graph--) is unchanged
    CHECK(result.getMatrix() == adjMatrix);
}

TEST_CASE("== operator g1 == g2") {

    ariel::Graph graph1;
    ariel::Graph graph2;
    vector<vector<int>> adjMatrix = {{1, 2}, {3, 4}};
    graph1.loadGraph(adjMatrix);
    graph2.loadGraph(adjMatrix);
    //check if the graph equals to itself
    CHECK(graph1 == graph2);
}

TEST_CASE("!= operator g1 != g2") {

    ariel::Graph graph1;
    ariel::Graph graph2;
    vector<vector<int>> adjMatrix1 = {{1, 2}, {3, 4}};
    vector<vector<int>> adjMatrix2 = {{1,4,3}, {2,5,4},{1,5,7}};
    graph1.loadGraph(adjMatrix1);
    graph2.loadGraph(adjMatrix2);

    // check that the two graphs are not equal
    CHECK((graph1 != graph2)== true);
    //check that the same graph equals to himself
    CHECK((graph1 == graph1)== true);
    CHECK((graph1 != graph1)== false);
}


