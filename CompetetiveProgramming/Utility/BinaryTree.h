#pragma once
#include <iostream>
#include <memory>
#include <vector>

struct Node
{
    Node(int d) : data(d), left(nullptr), right(nullptr)
    {
    }

    Node(int d, std::unique_ptr<Node> &n1, std::unique_ptr<Node> &n2)
        : data(d), left(std::move(n1)), right(std::move(n2))
    {
    }

    int data;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
};

struct BinTree
{
    BinTree() = default;

    // shitty ctor 1
    BinTree(const std::vector<int> &ivec)
    {
        for (auto &ii : ivec)
        {
            insert_tree(ii);
        }
    }

    // shitty ctor 2
    BinTree(const std::vector<int> &ivec, const std::vector<int> &ivec2)
    {
        for (auto &ii : ivec)
        {
            insert_tree(ii);
        }

        for (auto &ii : ivec2)
        {
            insert_tree(ii);
        }
    }

    template <typename FwdIt> BinTree(FwdIt beg, FwdIt end)
    {
        for (auto st = beg; st != end; ++st)
        {
            insert_tree(*st);
        }
    }

    void insert_tree(int data)
    {
        auto new_node{std::make_unique<Node>(data)};
        if (!rootNode)
        {
            rootNode = std::move(new_node);
        }
        else
        {
            insert_tree(data, rootNode.get());
        }
    }

    void print_tree()
    {
        print_tree(rootNode.get());
    }

    void to_vector()
    {
        to_vector(rootNode.get());
    }

    void print_list()
    {
        for (auto st = list.begin(); st != list.end(); ++st)
        {
            std::cout << *st << ' ';
        }
    }

    std::vector<int> list;

  private:
    void insert_tree(int data, Node *leaf)
    {
        if (data < leaf->data)
        {
            if (leaf->left)
            {
                insert_tree(data, leaf->left.get());
            }
            else
            {
                leaf->left = std::make_unique<Node>(data);
                leaf->left->data;
            }
        }

        else if (data >= leaf->data)
        {
            if (leaf->right)
            {
                insert_tree(data, leaf->right.get());
            }
            else
            {
                leaf->right = std::make_unique<Node>(data);
                leaf->right->data;
            }
        }
    }

    void print_tree(Node *nodePtr)
    {
        if (nodePtr)
        {
            print_tree(nodePtr->left.get());
            std::cout << nodePtr->data << ' ';
            print_tree(nodePtr->right.get());
        }
    }

    auto to_vector(Node *nodePtr) -> std::vector<int>
    {
        if (nodePtr)
        {
            print_tree(nodePtr->left.get());
            list.push_back(nodePtr->data);
            print_tree(nodePtr->right.get());
        }

        return list;
    }

    std::unique_ptr<Node> rootNode;
};
