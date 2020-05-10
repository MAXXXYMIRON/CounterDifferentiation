#include<iostream>
#include<vector>

using namespace std;

struct Point
{
public:
	double x;
	double y;
	Point(double _x = 0, double _y = 0)
	{
		x = _x;
		y = _y;
	}
};

double Ln1(double x, vector<Point> &Points)
{
	long double y = 0,
		mul1 = 1,
		mul2 = 1,
		sum = 0;

	unsigned n = Points.size();

	for (unsigned k = 0; k < n; k++)
	{
		mul1 = 1;
		for (unsigned j = 0; j < n; j++)
		{
			if (k == j) continue;
			mul1 *= (Points[k].x - Points[j].x);
		}

		sum = 0;
		for (unsigned m = 0; m < n; m++)
		{
			if (k == m) continue;

			mul2 = 1;
			for (unsigned i = 0; i < n; i++)
			{
				if (i == m || i == k) continue;
				mul2 *= (x - Points[i].x);
			}
			sum += mul2;
		}

		y += (Points[k].y * (sum / mul1));
	}

	return y;
}

int main()
{
	vector<Point> Points =
	{ 
		Point(-6, -2.16798),
		Point(4, -0.23461),
		Point(14, 1.63103),
		Point(24, 3.42584),
		Point(34, 5.14642),
		Point(44, 6.78910),
		Point(54, 8.34990),
		Point(64, 9.82440)
	};

	double x1 = 4, 
		x2 = 17;

	cout << Ln1(x1, Points) << endl;
	cout << Ln1(x2, Points) << endl;

	system("pause");
	return 0;
}