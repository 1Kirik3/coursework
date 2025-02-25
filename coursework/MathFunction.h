#pragma once
#include <vector>
#define PI 3.141592653589793238463
class MathFunction
{
protected:
	virtual  double f(double x) = 0;
	double from, to;
	double step=1;

	bool is_log;
	struct
	{
		double x_from, x_to;
		double y_from, y_to;
	}scale;
	bool is_calculated = false;
	CRect rect;
public:
	std::vector<POINT> points;
	COLORREF color;
public:
	void set_scale(double x_from, double x_to, double y_from, double y_to);
	void set_definition_scope(double from, double to);
	void set_step(double s);
	void set_rect(CRect r);
	void set_log(bool b);
	void set_color(COLORREF rgb);
	void set_not_calculated();
	virtual const std::vector<POINT>& get_points();
protected:
	virtual void calculate();
	POINT to_the_new_coords_system(double x, double y) const;
};

class SignalFunction : public MathFunction
{
protected:
	double a, m, f_;
public:
	std::vector<double> data;
protected:
	virtual double f(double x);
public:
	void set_a(double a);
	void set_m(double m);
	void set_f(double f);
	const std::vector<double>& get_data();
	virtual void calculate();
};
class DFTFunction : public SignalFunction
{
public:
	DFTFunction(SignalFunction* s);
protected:
	double f(double x);
	SignalFunction* signal;
public:
	void calculate();
	void set_signal(SignalFunction* s);

};