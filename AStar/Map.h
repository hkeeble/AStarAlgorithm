/*   /--------------------------------------------------------------------------------------------------------------------------------------------------\
	|																-	MAP.H	-																		 |
	| Program: AStar.exe																																 |
	| Author: Henri Keeble (KEE09195812)																												 |
	| Description: This file contains both the declaration for a map class, along with it's invididual cells and a struct to store a two-dimensional	 |
	| location.																																			 |
	 \--------------------------------------------------------------------------------------------------------------------------------------------------/  */
#pragma once

#include <iostream>
#include <string>

// Point 2D Declaration
struct Point2D
{
	int x;
	int y;
	Point2D(int X, int Y);
	Point2D();
	static Point2D Zero();
	int Dist(Point2D point) const;
};

// MapCell Declaration
class MapCell 
{
	public:
		friend class Map;
		Point2D GetPosition();
		void Display();
	private:
		MapCell();
		bool _passable;
		bool _playerStart;
		bool _target;
		Point2D _position;
		inline void SetPosition(Point2D newPosition);
};

// Map Declaration
class Map
{
	public:
		Map();
		Map(std::string fileName, int width, int height);
		void Display();
		Point2D GetPlayerStart() const;
		Point2D GetTarget() const;
	private:
		MapCell* _cells;
		int _width;
		int _height;
		Point2D _playerStart;
		Point2D _target;

		std::string ReadMap(std::string fileName, int width, int height);
		void SetPlayerStart(float x, float y);
		void SetTarget(float x, float y);
};