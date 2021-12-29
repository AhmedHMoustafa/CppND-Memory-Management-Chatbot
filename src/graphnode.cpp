#include "graphedge.h"
#include "graphnode.h"
#include <memory>

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    //delete _chatBot; [Task 0] remove it to remove bug

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge) // [Task 4] update to accomodate for unique pointer instead of raw
{
    _childEdges.push_back(std::move(edge)); 
}


//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot) // [Task 5] updated to reflect chatbot instance
{
    _chatBot = std::move(chatbot); 
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot)); // [Task 5] use move semantics
    //_chatBot = nullptr; // invalidate pointer at source // [Task 5] removed since _chatBot is no longer a pointer
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get(); // [Task 4] updated to accomodate for _childEdges being unique_ptr

    ////
    //// EOF STUDENT CODE
}