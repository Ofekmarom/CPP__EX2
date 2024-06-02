//ID : 208336701
//mail : ofekmarom9@gmail.com

//matala 2

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
using namespace std;
namespace ariel {
    class Graph {
    private:
        vector<vector<int>> adjMatrix; // the adjacency matrix representing the graph
        int vertices; // the number of vertices in the graph
        int edges; // the number of edges in the graph

    public:
        Graph();

        //load the graph
        void loadGraph(vector<vector<int>> graph2);

        //print the graph
        void printGraph();

        //return the adjacency matrix representing the graph
        std::vector<std::vector<int>> getMatrix();

        //return the number of vertices in the graph
        int getVertices();

        //return the number of edges in the graph
        int getEdges();


    //שישה אופרטורים חשבוניים

        Graph operator+(Graph &other);//addition operator to add two graphs (+)

        Graph &operator+=(Graph &other);//+= operator
        
        Graph &operator+(); // unary plus (make all elements positive)

        Graph operator-(Graph &other);// - operator

        Graph &operator-=(Graph &other);// -= operator

        Graph &operator-(); // unary minus (make all elements negative)


    //שישה אופרטורי השוואה
        // comparison operators
        
        bool operator==(Graph &other);// == operator

        bool operator!=(Graph &other);// != operator

        bool operator>(Graph &other);// > operator

        bool operator>=(Graph &other);// >= operator

        bool operator<(Graph &other);// < operator

        bool operator<=(Graph &other);// <= operator


        // ++ and -- operators
        Graph &operator++(); // ++graph
        Graph operator++(int);//graph++
        Graph &operator--(); // --graph
        Graph operator--(int);//graph--


        // scalar multiplication and division operators
        Graph operator*(int scalar);
        Graph& operator*=(int scalar);
        Graph operator/(int scalar);
        Graph& operator/=(int scalar);


        // graphs multiplication operator
        Graph operator*(Graph &other);


        // friend function for output operator
        // friend give access to the private and protected members of the class
        friend std::ostream& operator<<(std::ostream& output,Graph& graph);

    };
}
#endif
