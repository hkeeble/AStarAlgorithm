/*   /--------------------------------------------------------------------------------------------------------------------------------------------------\
	|																-	MAP.CPP	-																		 |
	| Program: AStar.exe																																 |
	| Author: Henri Keeble (KEE09195812)																												 |
	| Description: This file contains function definitions for the Map and MapCell classes declared in MAP.H											 |
	 \--------------------------------------------------------------------------------------------------------------------------------------------------/  */
#include <fstream>;
#include "Map.h";

using namespace std;

/*   /--------------------------------------------------------------------------------------------------------------------------------------------------\
	|																-	MAP FUNCTIONS	-															 |
	 \--------------------------------------------------------------------------------------------------------------------------------------------------/  */
// Default Constructor
Map::Map()
{
	_cells = NULL;
	_width = 0;
	_height = 0;
	_playerStart = Point2D::Zero();
	_target = Point2D::Zero();
}

// Constructor
Map::Map(string fileName, int width, int height)
{
	_width = width;
	_height = height;

	_cells = new MapCell[width*height];

	string mapData = ReadMap(fileName, width, height);

	for(int y = 0; y < _height; y++)
		for(int x = 0; x < _width; x++)
		{
				int currentCell = y*_width+x;

				if(mapData[currentCell] == '0' || mapData[currentCell] == 'P' || mapData[currentCell] == 'X')
				{
					_cells[currentCell]._passable = true; // If Empty, Player or Target, cell is passable
					if(mapData[currentCell] == 'P') // Set Player or Target position
					{
						_cells[currentCell]._playerStart = true;
						SetPlayerStart(x, y);
					}
					if (mapData[currentCell] == 'X')
					{
						_cells[currentCell]._target = true;
						SetTarget(x, y);
					}
				}
				else if(mapData[currentCell] == '1') // Set walls as impassable
					_cells[currentCell]._passable = false;

				_cells[currentCell].SetPosition(Point2D(x, y));
			}
}

// Get/Set Accessors
void Map::SetPlayerStart(float x, float y)
{
	_playerStart.x = x;
	_playerStart.y = y;
}
		
void Map::SetTarget(float x, float y)
{
	_target.x = x;
	_target.y = y;
}

Point2D Map::GetPlayerStart() const
{
	return _playerStart;
}

Point2D Map::GetTarget() const
{
	return _target;
}

// Read Map
string Map::ReadMap(string fileName, int width, int height)
{
	ifstream stream;
	stream.open(fileName);
	
	string output = "";
	string currentLine = "";
	char next;

	if(stream.is_open())
		for(int y = 0; y < height; y++)
		{
			std::getline(stream, currentLine);
			output.append(currentLine);
			currentLine.clear();
		}

		stream.close();

	return output;
}

// Display Map
void Map::Display()
{
	for(int y = 0; y < _height; y++)
	{
		for(int x = 0; x < _width; x++)
		{
			_cells[y*_width+x].Display();
		}
		std::cout << "\n";
	}
}

/*   /--------------------------------------------------------------------------------------------------------------------------------------------------\
	|																-	MAPCELL FUNCTIONS	-															 |
	 \--------------------------------------------------------------------------------------------------------------------------------------------------/  */
// Constructor
MapCell::MapCell()
{
	_passable = true;
	_playerStart = false;
	_target = false;
	_position = Point2D::Zero();
}

// Display Function
void MapCell::Display()
{
	if(!_playerStart && !_target)
		std::cout << (_passable ? '%' : '#');
	if(_playerStart == true)
		std::cout << 'P';
	if(_target == true)
		std::cout << 'X';
}

// Set Position
inline void MapCell::SetPosition(Point2D newPosition)
{
	_position = newPosition;
}

// Get Position
Point2D MapCell::GetPosition()
{
	return _position;
}
/*   /--------------------------------------------------------------------------------------------------------------------------------------------------\
	|																-	POINT2D FUNCTIONS	-															 |
	 \--------------------------------------------------------------------------------------------------------------------------------------------------/  */
// Default Constructor
Point2D::Point2D()
{
	(*this) = Point2D::Zero();
}

// Constructor
Point2D::Point2D(int X, int Y)
{
	x = X;
	y = Y;
}

// Zero Function
Point2D Point2D::Zero()
{
	return Point2D(0, 0);
}

// Distance Function
int Point2D::Dist(Point2D point) const
{
	return (x-point.x) + (y-point.y);
}