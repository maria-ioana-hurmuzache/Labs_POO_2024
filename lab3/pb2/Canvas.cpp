#include "Canvas.h"
#include <iostream>
#include <cmath>

using namespace std;

Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;
	this->matrix = new char* [height];
	for (int i = 0; i < height; i++)
	{
		this->matrix[i] = new char[width];
		for (int j = 0; j < width; j++)
			this->matrix[i][j] = ' ';
	}
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i <= ray / 3 + 1; i++)
		{
			this->SetPoint(x-ray-1, y+i, ch);
			this->SetPoint(x-ray-1, y-i, ch);
			this->SetPoint(x+ray+1, y+i, ch);
			this->SetPoint(x+ray+1, y-i, ch);
			this->SetPoint(x+i, y+ray+1, ch);
			this->SetPoint(x-i, y+ray+1, ch);
			this->SetPoint(x+i, y-ray-1, ch);
			this->SetPoint(x-i, y-ray-1, ch);
		}
	for (int i = 1; i <= ray / 2; i++)
	{
		this->SetPoint(x - (ray / 3 + 1 + i), y - (ray+1 - i), ch);
		this->SetPoint(x + (ray / 3 + 1 + i), y + (ray+1 - i), ch);
		this->SetPoint(x - (ray / 3 + 1 + i), y + (ray+1 - i), ch);
		this->SetPoint(x + (ray / 3 + 1 + i), y - (ray+1 - i), ch);
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	while (ray > 0)
	{
		ray--;
		this->DrawCircle(x, y, ray, ch);
	}
	this->SetPoint(x, y, ch);
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	this->DrawLine(left, top, right, top, ch);
	this->DrawLine(left, top, left, bottom, ch);
	this->DrawLine(right, top, right, bottom, ch);
	this->DrawLine(left, bottom, right, bottom, ch);
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top + 1; i < bottom; i++)
		this->DrawLine(i, left + 1, i, right - 1, ch);
}

void Canvas::SetPoint(int x, int y, char ch)
{
	if (x<this->width && y<this->height)
		this->matrix[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int pk = 2*dx - dy;
	int xk = x1, yk = y1;
	while (xk <= x2 && yk <= y2)
	{
		this->SetPoint(xk, yk, ch);
		if (pk < 0)
		{
			pk += 2*dx;
			yk ++;
		}
		else
		{
			pk += (2 * dx - 2 * dy);
			xk++;
		}
	}
}

void Canvas::Print()
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
			cout << this->matrix[i][j];
		cout << '\n';
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
			this->matrix[i][j] = ' ';
	}
}