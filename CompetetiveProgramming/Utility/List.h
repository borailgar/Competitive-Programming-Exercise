#pragma once

#include <memory>
#include <ostream>

struct Node
{
    Node(int d) : data(d), next(nullptr)
    {
    }

    Node(int d, std::unique_ptr<Node> &n1, std::unique_ptr<Node> &n2) : data(d), next(std::move(n1))
    {
    }

    int data;
    std::unique_ptr<Node> next;
};

struct FList
{
    void push_front(int data)
    {
        auto new_node{std::make_unique<Node>(data)};
        if (!headNode)
        {
            headNode = std::move(new_node);
        }
        else
        {
            new_node->next = std::move(headNode);
            headNode = std::move(new_node);
        }
    }

    void push_back(int data)
    {
        auto new_node{std::make_unique<Node>(data)};
        if (!headNode)
        {
            headNode = std::move(new_node);
        }
        else
        {
            Node *ItNode = headNode.get();
            while (ItNode->next)
            {
                ItNode = ItNode->next.get();
            }

            if (ItNode)
            {
                ItNode->next = std::move(new_node);
            }
        }
    }

    // Push data to sorted list and keeps list sorted as well
    virtual void push_by_order(int data)
    {
        auto new_node = std::make_unique<Node>(data);

        Node *nodeIter = headNode.get();
        while (nodeIter && nodeIter->data < data && (nodeIter->next) && nodeIter->next->data > data)
        {
            nodeIter = nodeIter->next.get();
        }

        if (nodeIter)
        {
            new_node->next = std::move(nodeIter->next);
            nodeIter->next = std::move(new_node);
        }
    }

    virtual void swapPairs() = 0;

    void clean_list()
    {
        while (headNode)
        {
            headNode = std ::move(headNode->next);
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const FList &flist);

    ~FList()
    {
        clean_list();
    }

  protected:
    std::unique_ptr<Node> headNode;
};

std::ostream &operator<<(std::ostream &os, const FList &flist)
{
    Node *ItNode = flist.headNode.get();
    while (ItNode)
    {
        os << ItNode->data << ' ';
        ItNode = ItNode->next.get();
    }

    return os;
}
