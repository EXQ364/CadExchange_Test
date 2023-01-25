#pragma once

class Point3D;
class Vec3D;

class IPrintable
{
public:
	virtual void print() const = 0;
};

class IPoint : IPrintable
{
public:
	virtual void print() const override {};
};

class IParametricCurve
{
public:
	virtual Point3D execute(double t) const = 0;
	virtual Vec3D derivative(double t) const = 0;
};

