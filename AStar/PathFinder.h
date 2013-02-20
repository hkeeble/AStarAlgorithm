/*   /--------------------------------------------------------------------------------------------------------------------------------------------------\
	|																-	PATHFINDER.H	-																 |
	| Program: AStar.exe																																 |
	| Author: Henri Keeble (KEE09195812)																												 |
	| Description: Declaration for a PathFinder class that takes a map and finds the optimal route between two given points using the A* algorithm.		 |
	| Also contains declaration for PathNode class used to represent individual nodes in the path.														 |
	 \--------------------------------------------------------------------------------------------------------------------------------------------------/  */
#pragma once
#include "Map.h"
#include "List.h"

// PathNode
class PathNode
{
	public:
		friend class PathFinder;

		PathNode();
		PathNode(MapCell* mapCell, PathNode* parent, int G, Point2D target);

		int GetF() const;
		int GetG() const;
		int GetDist() const;
		PathNode* GetParent() const;
		MapCell* GetCell() const;

		void SetParent(PathNode* newParent);

	private:
		PathNode* _parent;
		MapCell* _cell;
		int _g, _mDist, _f;
};

// PathFinder
class PathFinder
{
	public:
		PathFinder();
		List<PathNode> FindPath(Point2D start, Point2D target);
	private:
		Map _currentMap;
		void SetMap(Map map);
};
