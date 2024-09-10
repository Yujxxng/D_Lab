#pragma once

#include <vector>
struct deck;

// TODO:
// Objective: Reorder a Deck so that it is equal to target vector
// Constrains: I can only access the 2 first elements of obj
// Constrains: O(n^2)
// 
//
void Scry2Sort(const std::vector<int>& target, deck& obj);

// DO NOT MODIFY
void PrintVec(const std::vector<int>& v);
