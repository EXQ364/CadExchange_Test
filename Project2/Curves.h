#pragma once
#include "Interfaces.h"
#include "UtilsTypes.h"

class Circle : public IParametricCurve
{
private:
	double _r = 0;
	Point3D _center{ 0 };

public:
	Circle(Point3D c, double r = 0) : _r{ fabs(r) }, _center{ c } {};

	Circle(const Circle& circ) noexcept
	{
		_r = circ._r;
		_center = circ._center;
	}

	Circle(Circle&& circ) noexcept
	{
		_r = circ._r;
		_center = circ._center;
	}

	Circle& operator=(const Circle& circ) noexcept
	{
		if (this == &circ)
			return *this;

		_r = circ._r;
		_center = circ._center;

		return *this;
	}

	Circle& operator=(Circle&& circ) noexcept
	{
		if (this == &circ)
			return *this;

		_r = circ._r;
		_center = circ._center;

		return *this;
	}

	double setR(const double& r) noexcept
	{
		this->_r = r;
		return this->_r;
	}
	double getR() const noexcept
	{
		return this->_r;
	}

	Point3D setCenter(const Point3D& c) noexcept
	{
		this->_center = c;
		return this->_center;
	}
	Point3D getCenter() const noexcept
	{
		return this->_center;
	}

	Point3D execute(double t) const override
	{
		return Point3D(_r * cos(t) + _center._x, _r * sin(t) + _center._y);
	}

	Vec3D derivative(double t) const override
	{
		return Vec3D(-_r * sin(t), _r * cos(t));
	}

	bool operator<(const Circle& b)
	{
		return this->_r < b._r;
	}
};

class Ellipse : public IParametricCurve
{
private:
	double _rx = 0;
	double _ry = 0;
	Point3D _center{ 0 };

public:
	Ellipse(Point3D c, double rx = 0, double ry = 0) :_rx{ fabs(rx) }, _ry{ fabs(ry) }, _center{ c } {};

	Ellipse(const Ellipse& elip) noexcept
	{
		_rx = elip._rx;
		_ry = elip._ry;
		_center = elip._center;
	}

	Ellipse(Ellipse&& elip) noexcept
	{
		_rx = elip._rx;
		_ry = elip._ry;
		_center = elip._center;
	}

	Ellipse& operator=(const Ellipse& elip) noexcept
	{
		if (this == &elip)
			return *this;

		_rx = elip._rx;
		_ry = elip._ry;
		_center = elip._center;

		return *this;
	}

	Ellipse& operator=(Ellipse&& elip) noexcept
	{
		if (this == &elip)
			return *this;

		_rx = elip._rx;
		_ry = elip._ry;
		_center = elip._center;

		return *this;
	}

	double setRx(const double& r) noexcept
	{
		this->_rx = r;
		return this->_rx;
	}
	double getRx() const noexcept
	{
		return this->_rx;
	}
	double setRy(const double& r) noexcept
	{
		this->_ry = r;
		return this->_ry;
	}
	double getRy() const noexcept
	{
		return this->_ry;
	}

	Point3D setCenter(const Point3D& c) noexcept
	{
		this->_center = c;
		return this->_center;
	}
	Point3D getCenter() const noexcept
	{
		return this->_center;
	}

	Point3D execute(double t) const override
	{
		return Point3D(_rx * cos(t) + _center._x, _ry * sin(t) + _center._y);
	}

	Vec3D derivative(double t) const override
	{
		return Vec3D(-_rx * sin(t), _ry * cos(t));
	}

};

class Helix : public IParametricCurve
{
private:
	double _step = 0;
	double _r = 0;
	Point3D _center{ 0 };

public:
	Helix(Point3D c, double r = 0, double step = 0) : _r{ fabs(r) }, _step{ step }, _center{ c } {};

	Helix(const Helix& helix) noexcept
	{
		_r = helix._r;
		_step = helix._step;
		_center = helix._center;
	}

	Helix(Helix&& helix) noexcept
	{
		_r = helix._r;
		_step = helix._step;
		_center = helix._center;
	}

	Helix& operator=(const Helix& helix) noexcept
	{
		if (this == &helix)
			return *this;

		_r = helix._r;
		_step = helix._step;
		_center = helix._center;

		return *this;
	}

	Helix& operator=(Helix&& helix) noexcept
	{
		if (this == &helix)
			return *this;

		_r = helix._r;
		_step = helix._step;
		_center = helix._center;

		return *this;
	}

	double setR(const double& r) noexcept
	{
		this->_r = r;
		return this->_r;
	}
	double getR() const noexcept
	{
		return this->_r;
	}
	double setStep(const double& s) noexcept
	{
		this->_step = s;
		return this->_step;
	}
	double getStep() const noexcept
	{
		return this->_step;
	}

	Point3D setCenter(const Point3D& c) noexcept
	{
		this->_center = c;
		return this->_center;
	}
	Point3D getCenter() const noexcept
	{
		return this->_center;
	}

	Point3D execute(double t) const override
	{
		return Point3D(_r * cos(t) + _center._x, _r * sin(t) + _center._y, _step * t + _center._z);
	}

	Vec3D derivative(double t) const override
	{
		return Vec3D(-_r * sin(t), _r * cos(t), _step);
	}

};
