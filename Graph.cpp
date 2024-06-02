//ID : 208336701
//mail : ofekmarom9@gmail.com

//matala 2

#include "Graph.hpp"
#include <stdexcept>
#include <algorithm>
using namespace std;
namespace ariel
{

    Graph::Graph() //constructor
    {
        adjMatrix = {};
        vertices = 0;
        edges = 0;
    }

    void Graph::loadGraph(vector<vector<int>> graph2) //function to load the graph to an object
    {
        // check if the graph is a square matrix.
        if (graph2.empty() || graph2.size() != graph2[0].size())
        {
            throw invalid_argument("Invalid graph: The graph is not a square matrix.");
        }

        adjMatrix = graph2;// load the matrix to the graph
        // count the number of vertices and edges in the graph.
        vertices = graph2.size();
        int allEdges = 0;
        for (size_t i = 0; i < vertices; i++) {
            for (size_t j = 0 ; j < vertices; j++) {
                if (adjMatrix[i][j] != 0) {
                    allEdges++;
                }
            }

        }
        edges = allEdges;
    }
    std::vector<std::vector<int>> Graph::getMatrix()//return the adjacency matrix representing the graph
    {
        return adjMatrix;
    }
    void Graph::printGraph()//funtion to print the graph
    {
        cout << "Graph with " << vertices << " vertices and " << edges << " edges." << endl;
    }
    int Graph::getVertices()//return the number of vertices in the graph
    {
        return this->vertices;
    }
    int Graph::getEdges()//return the number of edges in the graph
    {
        return this->edges;
    }




//operators of matala 2

    
    
    //שישה אופרטורים חשבוניים
    
    // addition operator to add two graphs (+)
    Graph Graph::operator+(Graph& other)
    {
        // check if the graphs have different sizes and if yes its error
        if (adjMatrix.size() != other.adjMatrix.size() || adjMatrix[0].size() != other.adjMatrix[0].size())
        {
            throw invalid_argument("the size of the first matrix must be equal to the size of the second matrix");
        }
                                           //num of rows of newGraph,  num of coloms and every element in the matrix is set to 0
        std::vector<std::vector<int>> newGraph(adjMatrix.size(), std::vector<int>(adjMatrix[0].size(), 0));//vector of vectors of int for the matrix
        // do the addition for every element in the matrixs
        for (size_t i = 0; i < adjMatrix.size(); i++)
        {
            for (size_t j = 0; j < adjMatrix[0].size(); j++)
            {
                newGraph[i][j] = adjMatrix[i][j] + other.adjMatrix[i][j];
            }
        }
        Graph ans;
        ans.loadGraph(newGraph);//load the addition graph to ans
        return ans;
    }
    

    // += operator
    Graph& Graph::operator+=(Graph& other)
    {
        // check if the graphs have different sizes and if yes its error
        if (adjMatrix.size() != other.adjMatrix.size() || adjMatrix[0].size() != other.adjMatrix[0].size())
        {
            throw invalid_argument("the size of the first matrix must be equal to the size of the second matrix");
        }

        // do the addition for every element in the matrix
        for (size_t i = 0; i < adjMatrix.size(); i++) {
            for (size_t j = 0; j < adjMatrix[0].size(); j++)
            {
                adjMatrix[i][j] += other.adjMatrix[i][j];
            }
        }
        return *this; // returns a reference to the current graph object
    }
    

    // unary plus operator to make all elements positive
    Graph& Graph::operator+()
    {
        for (size_t i = 0; i < adjMatrix.size(); i++) {
            for (size_t j = 0; j < adjMatrix[0].size(); j++)
            {
                if(adjMatrix[i][j] < 0) //if the element is negative we will make it positive 
                {
                    adjMatrix[i][j] = -adjMatrix[i][j];
                }
            }
        }
        return *this; //returns a reference to the current graph object 
    }


    // substraction operator to subtract two graphs (-)
    Graph Graph::operator-(Graph& other)
    {
        // check if the graphs have different sizes and if yes its error
        if (adjMatrix.size() != other.adjMatrix.size() || adjMatrix[0].size() != other.adjMatrix[0].size())
        {
            throw invalid_argument("the size of the first matrix must be equal to the size of the second matrix");
        }
                                         //num of rows of newGraph,  num of coloms and every element in the matrix is set to 0
        std::vector<std::vector<int>> newGraph(adjMatrix.size(), std::vector<int>(adjMatrix[0].size(), 0));
      
        // do the subtraction for every element in the matrix
        for (size_t i = 0; i < adjMatrix.size(); i++)
        {
            for (size_t j = 0; j < adjMatrix[0].size(); j++)
            {
                newGraph[i][j] = adjMatrix[i][j] - other.adjMatrix[i][j];
            }
        }
        
        Graph ans;
        ans.loadGraph(newGraph);//load the subtraction graph to ans 
        return ans;
    }


    // -= operator
    Graph& Graph::operator-=(Graph& other)
    {
        // check if the graphs have different sizes and if yes its error
        if (adjMatrix.size() != other.adjMatrix.size() || adjMatrix[0].size() != other.adjMatrix[0].size())
        {
            throw std::invalid_argument("the size of the first matrix must be equal to the size of the second matrix");
        }
        

        // do the subtraction for every element in the matrix
        for (size_t i = 0; i < adjMatrix.size(); i++) {
            for (size_t j = 0; j < adjMatrix[0].size(); j++)
            {
                adjMatrix[i][j] -= other.adjMatrix[i][j];
            }
        }
        
        return *this;// returns a reference to the current graph object
    }

    // unary minus operator to make all elements negative
    Graph& Graph::operator-()
    {
        for (size_t i = 0; i < adjMatrix.size(); i++) {
            for (size_t j = 0; j < adjMatrix[0].size(); j++)
            {
                //if the element is positive we will make it negative 
                if(adjMatrix[i][j] > 0)
                {
                    adjMatrix[i][j] = -adjMatrix[i][j];
                }
            }
        }
        
        return *this; //returns a reference to the current graph object 
    }
    
    
    
    
    //שישה אופרטורי השוואה
    //6 comparison operators
    
    
    // == operator to check if two graphs are equal
    bool Graph::operator==(Graph& other) 
{
    // bool to check if the graphs have the same size and the same edge weights
    bool sameSizeAndWeights = true;
    
    // check if the sizes of the matrixs are different
    if (adjMatrix.size() != other.adjMatrix.size() || adjMatrix[0].size() != other.adjMatrix[0].size()) {
        sameSizeAndWeights = false;
    } 
    else {
        // if the sizes are the same, we need to compare edge weights
        for (size_t i = 0; i < adjMatrix.size(); i++) {
            for (size_t j = 0; j < adjMatrix[0].size(); j++) {
                if (adjMatrix[i][j] != other.adjMatrix[i][j]) {
                    sameSizeAndWeights = false;
                    break; // break out of the inner loop if we find difference
                }
            }
            if (!sameSizeAndWeights) {
                break; // break out of the outer loop if we find difference
            }
        }
    }

    // check if both of the graphs are not greater than the other
    bool notGreater = (!(*this > other) && !(other > *this));
    //bool notGreater = *this <= other && *this >= other;
    
    // return true if one of the conditions is met
    return sameSizeAndWeights || notGreater;
}

    
    
    // != operator to check if two graphs are not equal
    bool Graph::operator!=(Graph& other)
    {
        return !(*this == other); //not equal is the opposite of equal
    }



    // > greater than operator to check if one graph is greater than the other
    bool Graph::operator>(Graph& other)
    {


        bool contains = true; //bool to check if the first graph contains the other graph

        // check if the size of the other graph is greater
        if (other.adjMatrix.size() > adjMatrix.size()) {
            contains = false;
        }

        if (contains) {
            // check if the first graph contains the other graph
            for (size_t i = 0; i < other.adjMatrix.size(); i++)
            {
                for (size_t j = 0; j < other.adjMatrix.size(); j++)
                {
                    //check if they have different values
                    if (adjMatrix[i][j] != other.adjMatrix[i][j])
                    {
                        contains = false;
                        break; // break out of the inner loop if we find difference
                    }
                }
                if (!contains)
                {
                    break; // break out of the outer loop if we find difference
                }
            }
        }
        //if contains and they the same size they are equals and it false
        if (contains && (adjMatrix.size() == other.adjMatrix.size()))
        {
            return false;
        }

        // if the first graph contains the other and they are not equal return true
        if (contains)
        {
            return true;
        }

        // if the first graph has more edges then the other return true
        if (this->edges > other.edges)
        {
            return true;
        }

        // if the number of edges is the same and the first graph has more vertices then the other return true
        if (this->edges == other.edges && adjMatrix.size() > other.adjMatrix.size())
        {
            return true;
        }

        // return false if none of the conditions are met
        return false;
    }




    // >= - greater than or equal operator
    bool Graph::operator>=(Graph& other)
    {
        //if the first is greater or equals to the other it will return true
        return (*this > other) || (*this == other);
    }

    // < - less than operator to check if one graph is less than the other
    bool Graph::operator<(Graph& other)
    {
        //this < other its like other > this
        return (other > *this);
    }

    // less than or equal to operator
    bool Graph::operator<=(Graph& other)
    {
        //if the first is less or equals to the other it will return true
        return (*this < other) || (*this == other);
    }




//++ and -- operators

    // ++graph
    // ++ operator to increase all elements by 1 (++graph) (first increase then return the graph)
    Graph& Graph::operator++()
    {
        for (size_t i = 0; i < adjMatrix.size(); i++)
        {
            for (size_t j = 0; j < adjMatrix[0].size(); j++)
            {
                // increase each edge weight by 1
                adjMatrix[i][j]++;
            }
        }
        // return the graph after ++
        return *this;
    }
    
    
     // graph++
     // ++ operator to increase all elements by 1 (graph++) (returns the original graph and then increase the edges of the graph)
    Graph Graph::operator++(int) //stam parameter int to distinguish it from the other ++ operator
    {
        // create a copy of the graph before incrementing
        Graph temp = *this;
        for (size_t i = 0; i < adjMatrix.size(); i++) {
            for (size_t j = 0; j < adjMatrix[0].size(); j++) {
                // increase each edge weight by 1
                adjMatrix[i][j]++;
            }
        }
        // return the copy of the graph before increasing
        return temp;
    }
    
    
    
    // --graph
    // -- operator to decrease all elements by 1 (--graph) (first decrease then return the graph)
    Graph& Graph::operator--()
    {
        for (size_t i = 0; i < adjMatrix.size(); i++)
        {
            for (size_t j = 0; j < adjMatrix[0].size(); j++)
            {
                // decrease each edge weight by 1
                adjMatrix[i][j]--;
            }
        }
        // return the graph after --
        return *this;
    }
    
    
    
    // graph--
    // -- operator to decrease all elements by 1 (graph--) (returns the original graph and then decrease the edges of the graph)
    Graph Graph::operator--(int)
    {
        // create a copy of the graph before decreasing
        Graph temp = *this;
        for (size_t i = 0; i < adjMatrix.size(); i++)
        {
            for (size_t j = 0; j < adjMatrix[0].size(); j++)
            {
                // decrease each edge weight by 1
                adjMatrix[i][j]--;
            }
        }
        // return the copy of the graph before decreasing
        return temp;
    }
    

    //multiply and divide operators
    
    
    // * - multiply the graph by scalar
    Graph Graph::operator*(int scalar) {
        Graph ans = *this; // create a copy of the current graph
        for (size_t i = 0; i < ans.adjMatrix.size(); ++i) {
            for (size_t j = 0; j < ans.adjMatrix[0].size(); ++j) {
                // multiply each edge weight by the scalar
                ans.adjMatrix[i][j] *= scalar;
            }
        }
        return ans; // return the graph that we get by this multiplication
    }
    
    
    // *= - multiply the graph by a scalar and change the current graph
    Graph& Graph::operator*=(int scalar) {
        for (size_t i = 0; i < adjMatrix.size(); ++i) {
            for (size_t j = 0; j < adjMatrix[0].size(); ++j) {
                // multiply each edge weight by the scalar
                adjMatrix[i][j] *= scalar;
            }
        }
        // return the graph after the multiplication
        return *this;
    }
    
    
    
    //  / - divide the graph by scalar
    Graph Graph::operator/(int scalar) {
        Graph ans = *this; // create a copy of the current graph
        for (size_t i = 0; i < ans.adjMatrix.size(); ++i) {
            for (size_t j = 0; j < ans.adjMatrix[0].size(); ++j) {
                // divide each edge weight by the scalar
                ans.adjMatrix[i][j] /= scalar;
            }
        }
        return ans; // return the graph we get by this division
    }


    //  /= - divide the graph by a scalar and change the current graph
    Graph& Graph::operator/=(int scalar) {
        for (size_t i = 0; i < adjMatrix.size(); ++i) {
            for (size_t j = 0; j < adjMatrix[0].size(); ++j) {
                // divide each edge weight by the scalar
                adjMatrix[i][j] /= scalar;
            }
        }
        // return the graph after the division
        return *this;
    }
    
    

    // * - multiplication operator to multiply two graphs 
    Graph Graph::operator*(Graph& other)
    {
        // check if the graphs have differnet sizes
        if (adjMatrix.size() != other.adjMatrix.size())
        {
            throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
        }
                                     //num of rows of newGraph,  num of coloms and every element in the matrix is set to 0
        std::vector<std::vector<int>> newGraph(adjMatrix.size(), std::vector<int>(adjMatrix[0].size(), 0));

        for (size_t i = 0; i < adjMatrix.size(); i++)
        {
            for (size_t j = 0; j < adjMatrix.size(); j++)
            {
                for (size_t k = 0; k < adjMatrix.size(); k++)
                {
                         //do the multiplication for every element in the matrix
                        newGraph[i][j] += adjMatrix[i][k] * other.adjMatrix[k][j];
                }
            }
        }
        
        Graph ans;
        ans.loadGraph(newGraph);//load the matrix we got from the multiplication to the answer graph
        return ans;
    }



    // operator to print the graph
    std::ostream& operator<<(std::ostream& output,Graph& graph) {
        // iterate over each row of the matrix
        for (size_t i = 0; i < graph.adjMatrix.size(); i++) {
            if (i > 0) {
                output << ", "; // add "," between rows of the matrix
            }
            output << "["; // add "[" in the start of each row
            // iterate over each column of the current row
            for (size_t j = 0; j < graph.adjMatrix[i].size(); j++) {
                if (j > 0) {
                    output << ", "; // add "," between elements
                }
                output << graph.adjMatrix[i][j]; // print the current element
            }
            output << "]"; // add "]" in the end of the current row
        }
        output << "\n"; // go a line down after the print of the matrix
        return output; // return the output stream
    }

}
