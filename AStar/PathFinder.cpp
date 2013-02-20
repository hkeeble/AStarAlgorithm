/*   /--------------------------------------------------------------------------------------------------------------------------------------------------\
	|																-	PATHFINDER.CPP	-																 |
	| Program: AStar.exe																																 |
	| Author: Henri Keeble (KEE09195812)																												 |
	| Description: Definitions for functions in the PathFinder class functions. Also contains definitions for PathNode class functions. Declarations	 |
	| are in PATHFINDER.H																																 |
	 \--------------------------------------------------------------------------------------------------------------------------------------------------/  */
#include "PathFinder.h"

/*   /--------------------------------------------------------------------------------------------------------------------------------------------------\
	|																-	PATHFINDER FUNCTIONS	-														 |
	 \--------------------------------------------------------------------------------------------------------------------------------------------------/  */
// Default Constructor
PathFinder::PathFinder()
{
	_currentMap = Map();
}

// Set Map Function
void PathFinder::SetMap(Map newMap)
{
	_currentMap = newMap;
}

List<PathNode> PathFinder::FindPath(Point2D start, Point2D target)
{
	// PATHFINDING ALGORITHM GOES HERE

	// RETURN LIST OF NODES SHOWING OPTIMAL PATH
	return List<PathNode>();
}

/*   /--------------------------------------------------------------------------------------------------------------------------------------------------\
	|																-	PATHNODE FUNCTIONS	-															 |
	 \--------------------------------------------------------------------------------------------------------------------------------------------------/  */
// Default Constructor
PathNode::PathNode()
{
	_parent = NULL;
	_cell = NULL;
	_g = 0;
	_mDist = 0;
	_f = 0;
}

// Constructor
PathNode::PathNode(MapCell* mapCell, PathNode* parent, int G, Point2D target)
{
	_g = G + parent->GetG();
	_cell = mapCell;
	_parent = parent;
	_mDist = (mapCell->GetPosition().Dist(target));
	_f = _g + _mDist;
}

// Get F Cost Function
inline int PathNode::GetF() const
{
	return _f;
}

// Get G Cost Function
inline int PathNode::GetG() const
{
	return _g;
}

// Get Manhattan Distance Function
inline int PathNode::GetDist() const
{
	return _mDist;
}

// Get Parent Function
inline PathNode* PathNode::GetParent() const
{
	return _parent;
}

// Get MapCell Function
inline MapCell* PathNode::GetCell() const
{
	return _cell;
}