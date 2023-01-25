// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "Curves.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#define M_PI 3.1415926535897932384626433832795029L

//Flag for cout step-by-step results
//#define DEBUG

//set initialize count of curves;
#define NUM_CURVES 1000

int main()
{

	std::vector<std::unique_ptr<IParametricCurve>> curves;
	srand(time(0));

	//. Populate a container (e.g. vector or list) of objects of these types created in random manner with
	//random parameters.
	for(auto i = 0; i< NUM_CURVES; i++)
	{
		Point3D center( rand() % 150, rand() % 150, rand() % 150 );
		auto rnd = rand() % 3;

		if (rnd == 0)
		{
			double radius = rand() % 100;
			curves.emplace_back(std::make_unique<Circle>(center, radius));
			continue;
		}
		if (rnd == 1)
		{
			double radius1 = rand() % 100;
			double radius2 = rand() % 100;
			curves.emplace_back(std::make_unique<Ellipse>(center, radius1, radius2));
			continue;
		}

		if (rnd == 2)
		{
			double radius = rand() % 100;
			double step = rand() % 10;
			curves.emplace_back(std::make_unique<Helix>(center, radius, step));
			continue;
		}
	}



	//Print coordinates of points and derivatives of all curves in the container at t=PI/4.
	std::for_each(curves.begin(), curves.end(), [](std::unique_ptr<IParametricCurve>& uptr_curve)
	{
			std::cout.precision(3);
			std::cout << std::fixed << uptr_curve->execute(M_PI / 4);
			std::cout << std::fixed << uptr_curve->derivative(M_PI / 4) << "\n\n";
	});



	/*Populate a second container that would contain only circles from the first container.Make sure the
		second container shares(i.e. not clones) circles of the first one, e.g.via pointers.*/
	std::vector<Circle*> circles;
	std::for_each(curves.begin(), curves.end(), [&circles](std::unique_ptr<IParametricCurve>& uptr_curve){
		if (Circle* circ = dynamic_cast<Circle*>(uptr_curve.get())) circles.push_back(circ);
	});
#ifdef DEBUG
	std::cout << "______________________CIRCLES____________________\n";

	std::for_each(circles.begin(), circles.end(), [](const Circle* ptr_circle)
	{
			std::cout.precision(3);
			std::cout << std::fixed << ptr_circle->execute(M_PI / 4);
			std::cout << std::fixed << ptr_circle->derivative(M_PI / 4) << "\n\n";
	});
#endif //DEBUG



	/*Sort the second container in the ascending order of circles’ radii.That is, the first element has the
		smallest radius, the last - the greatest.*/
	std::sort(circles.begin(), circles.end(), [](const Circle* a, const Circle* b)
	{
			return a->getR() < b->getR();
	});
#ifdef DEBUG
	std::for_each(circles.begin(), circles.end(), [](const Circle* ptr_circle)
		{
			std::cout.precision(3);
			std::cout << std::fixed << ptr_circle->getR() << "\n";
		});
#endif //DEBUG



	/*. Compute the total sum of radii of all curves in the second container.*/
	
	//One Thread
	/*double radii_sum_onethread = 0;
	std::for_each(circles.begin(), circles.end(), [&radii_sum_onethread](const Circle* ptr_circle) {
		radii_sum_onethread +=ptr_circle->getR();
	});
	std::cout << radii_sum_onethread<<"\n";*/

	//Multithread (OpenMP)
	double radii_sum_multithread = 0;
	#pragma omp parallel for reduction(+:radii_sum_multithread)
	for (unsigned long long i = 0; i < circles.size(); i++)
	{
		radii_sum_multithread += circles[i]->getR();
	}
	std::cout << radii_sum_multithread << "\n";



	return 0;
}

