#pragma once
#include "Interfaces.h"
#include <iostream>


class Point2D;

class Point3D : public IPoint
{
public:
	double  _x = 0;
	double  _y = 0;
	double  _z = 0;

	Point3D(double  x = 0, double  y = 0, double  z = 0) : _x{ x }, _y{ y }, _z{ z } {};

	Point3D(const Point3D& point) noexcept
	{
		_x = point._x;
		_y = point._y;
		_z = point._z;
	}

	Point3D(Point3D&& point) noexcept
	{
		_x = point._x;
		_y = point._y;
		_z = point._z;
	}

	Point3D& operator=(const Point3D& point) noexcept
	{
		if (this == &point)
			return *this;
		_x = point._x;
		_y = point._y;
		_z = point._z;
		return *this;
	}

	Point3D& operator=(Point3D&& point) noexcept
	{
		if (this == &point)
			return *this;
		_x = point._x;
		_y = point._y;
		_z = point._z;
		return *this;
	}

	Point3D operator+(const Point3D& point) const
	{
		return Point3D(this->_x + point._x, this->_y + point._y, this->_z + point._z);
	}

	Point3D operator-(const Point3D& point) const
	{
		return Point3D(this->_x - point._x, this->_y - point._y, this->_z - point._z);
	}

	friend std::ostream& operator<< (std::ostream& out, const Point3D& point)
	{
		out << "[" << point._x << ";" << point._y << ";" << point._z << "]\n";
		return out;
	}

	operator Point2D() const;

	void print() const override
	{
		std::cout << "{" << this->_x << ";" << this->_y << ";" << this->_z << "}\n";
	};
};



class Point2D : public IPoint
{
public:
	double  _x = 0;
	double  _y = 0;

	Point2D(double  x = 0, double  y = 0) : _x{ x }, _y{ y } {};

	Point2D(const Point2D& point) noexcept
	{
		_x = point._x;
		_y = point._y;
	}

	Point2D(Point2D&& point) noexcept
	{
		_x = point._x;
		_y = point._y;
	}

	Point2D& operator=(const Point2D& point) noexcept
	{
		if (this == &point)
			return *this;
		_x = point._x;
		_y = point._y;
		return *this;
	}

	Point2D& operator=(Point2D&& point) noexcept
	{
		if (this == &point)
			return *this;
		_x = point._x;
		_y = point._y;
		return *this;
	}

	void print() const override
	{
		std::cout << "{" << this->_x << ";" << this->_y << "}\n";
	};

	Point2D operator+(const Point2D& point) const
	{
		return Point2D(this->_x + point._x, this->_y + point._y);
	}

	Point2D operator-(const Point2D& point) const
	{
		return Point2D(this->_x - point._x, this->_y - point._y);
	}

	friend std::ostream& operator<< (std::ostream& out, const Point2D& point)
	{
		out << "[" << point._x << ";" << point._y << "]\n";
		return out;
	}

	operator Point3D() const
	{
		return Point3D(this->_x, this->_y, 0);
	}
};




Point3D::operator Point2D() const
{
	return Point2D(this->_x, this->_y);
}


class Vec3D : IPrintable
{
public:
	double  _x = 0;
	double  _y = 0;
	double  _z = 0;

	Vec3D(double  x = 0, double  y = 0, double  z = 0) : _x{ x }, _y{ y }, _z{ z } {};

	Vec3D(const Vec3D& vec) noexcept
	{
		_x = vec._x;
		_y = vec._y;
		_z = vec._z;
	}

	Vec3D(Vec3D&& vec) noexcept
	{
		_x = vec._x;
		_y = vec._y;
		_z = vec._z;
	}

	Vec3D& operator=(const Vec3D& vec) noexcept
	{
		if (this == &vec)
			return *this;
		_x = vec._x;
		_y = vec._y;
		_z = vec._z;
		return *this;
	}

	Vec3D& operator=(Vec3D&& vec) noexcept
	{
		if (this == &vec)
			return *this;
		_x = vec._x;
		_y = vec._y;
		_z = vec._z;
		return *this;
	}

	Vec3D operator+(const Vec3D& point) const
	{
		return Vec3D(this->_x + point._x, this->_y + point._y, this->_z + point._z);
	}

	Vec3D operator-(const Vec3D& point) const
	{
		return Vec3D(this->_x - point._x, this->_y - point._y, this->_z - point._z);
	}

	friend std::ostream& operator<< (std::ostream& out, const Vec3D& vec)
	{
		out << "{" << vec._x << ";" << vec._y << ";" << vec._z << "}\n";
		return out;
	}

	void print() const override
	{
		std::cout << "{" << this->_x << ";" << this->_y << ";" << this->_z << "}\n";
	};
};
