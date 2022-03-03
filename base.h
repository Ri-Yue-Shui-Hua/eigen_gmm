#pragma once
#include<Eigen/Core>
#include<iostream>
#include <fstream>
#include <vector>
using namespace std;
using namespace Eigen;

typedef Matrix<double, Dynamic, Dynamic, RowMajor> RowMatrixXd;

class base
{
public:
	base(int n_components, float tol, float reg_covar,	int max_iter, int n_init,	string init_params,	int random_state,
		bool warm_start,	int verbose,	int verbose_interval);
	base();
	~base();
	void fit(RowMatrixXd X);
	void fit_predict(RowMatrixXd X);
	void _check_X(RowMatrixXd X, int n_components, int n_features=0, int ensure_min_samples=1);

	int check_random_state(int seed);
	void _initialize_parameters(RowMatrixXd X, int random_state);




private:


protected:
	int n_components;
	float tol;
	float reg_covar;
	int max_iter;
	int n_init;
	string init_params;
	int random_state;
	bool warm_start;
	int verbose;
	int verbose_interval;
	bool converged_;
};

