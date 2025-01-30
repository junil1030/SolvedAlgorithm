#include "aStarNode.h"

const int C_ASTARNODE::way[8][2] =
{
	{-1, -1}, {-1, 0}, {-1, 1},
	{ 0, -1},          { 0, 1},
	{ 1, -1}, { 1, 0}, { 1, 1}
};

const int C_ASTARNODE::length[8] =
{
	{14}, {10}, {14},
	{10},       {10},
	{14}, {10}, {14}
};