#pragma once

#include <string>
#include <vector>

/**
 * @brief Regular Expression Matching
 * @link https://leetcode.com/problems/regular-expression-matching/
 * 
 */


enum NFA
{
	Split = 256,
	Match = 257
};

struct StateNode
{
	StateNode(const int data) 
		: ch(data), next_node0(nullptr), next_node1(nullptr) {}

	StateNode(const int data, StateNode* n0, StateNode* n1)
		: ch(data), next_node0(n0), next_node1(n1) {}

	int ch;
	StateNode* next_node0;
	StateNode* next_node1;
	int last_list{};
};

using StateList_t = std::vector<StateNode*>;

struct NState
{
	StateNode* start;
	StateList_t ptr_list;
};

static StateList_t create_list(StateNode** output_ptr) 
{
	std::cout << "in create_list" << output_ptr << std::endl;
	StateList_t l{ *output_ptr };
	return l;
}

static StateList_t append_list(StateList_t& list, StateList_t& list2)
{

}

static void patch(StateList_t& l, StateNode* s)
{

}



