#include "Map.h"

Map::Map():
	_map
{ 
	{ 
		{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,1,3,0,0,0,4,4,0,4,4,4,0,0,0,0,0},
		{1,0,0,2,1,1,1,0,0,2,4,4,4,5,0,0,4,0,0,0},
		{1,0,4,4,0,0,0,0,0,4,4,0,4,4,4,4,0,0,0,0},
		{1,0,4,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0},
		{1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0},
		{1,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,0,1,0},
		{1,8,0,0,0,0,0,0,0,0,1,0,1,0,2,0,1,0,1,0},
		{1,8,8,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0},
		{1,8,8,8,0,0,0,0,0,0,1,1,1,1,1,0,1,0,1,1},
		{1,8,8,8,8,0,0,0,0,0,1,9,0,0,1,0,1,9,1,1},
		{1,8,8,8,2,0,0,0,0,0,1,1,0,0,1,0,1,1,1,1},
		{1,8,8,8,8,0,0,0,0,0,1,0,0,0,1,0,1,5,9,1}
		},
		{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,9,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,0,0,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
		{0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0}
	
		}
	} ,
	{
		{
		{1,8,8,8,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,1},
		{1,8,8,0,0,0,0,0,0,0,1,0,1,0,1,9,1,1,1,1},
		{1,8,8,8,0,0,0,0,0,0,1,0,1,0,1,1,1,0,0,0},
		{1,8,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,1,0,0},
		{1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,9,0,0},
		{1,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
		},
		{
		{0,0,1,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,7,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
		{0,1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
		{0,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
		{0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
		}
	}

}
{}
