#include "View.h"
#include "Point2D.h"
#include "GameObject.h"

using namespace std;

bool View::GetSubscripts(int& out_x, int& out_y, Point2D location)
{
	out_x = (location.x - origin.x) / scale;
	out_y = (location.y - origin.y) / scale;
	if((location.x > size * scale) || (location.y > size * scale))
	{
		cout << "An object is outside the display" << endl;
		return 0;
	}
	else
	{
		return 1;
	}
}

View::View()
{
	size = 11;
	scale = 2;
	Point2D origin;
}

void View::Clear()
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			grid[i][j][0] = '.';
			grid[i][j][1] = ' ';
		}
	}

	return;
}

void View::Plot(GameObject* ptr)
{
	int x, y;
	if (GetSubscripts(x, y, ptr->GetLocation()))
	{
		if(grid[x][y][0] != '.')
		{
			grid[x][y][0] = '*';
			grid[x][y][1] = ' ';
		}
		else
		{
			ptr->DrawSelf(grid[x][y]);
			char temp = '0' + ptr->GetId(); //If it ain't broke...
			grid[x][y][1] = temp;
		}
	}
	return;
}

void View::Draw()
{
	for(int i = size - 1; i >= 0; i--)
	{
		if(i % 2 == 0)
		{
			int temp = 2 * i;
			if(temp > 10)
			{
				cout << temp;
			}
			else
			{
				cout << temp << " ";
			}
		}
		else if(i == 0)
		{
			cout << "0 ";
		}
		else
		{
			cout << "  ";
		}
		for(int j = 0; j < size; j++)
		{
			cout << grid[j][i][0];
			cout << grid[j][i][1];
		}
		cout << endl;
	}
	cout << "  0   4   8   12  16  20";
	cout << endl;
	return;
}