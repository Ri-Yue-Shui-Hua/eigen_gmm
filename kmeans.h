#pragma once
#include <string>
using namespace std;
#include<Eigen/Core>
using namespace Eigen;

typedef Matrix<double, Dynamic, Dynamic, RowMajor> RowMatrixXd;
class KMeans
{
public:
	KMeans(int n_clusters=8, string init = "k-means++", int n_init=10, int max_iter=300, double tol = 1e-4, string precompute_distances="deprecated",
	int verbose=0, int random_state=0, bool copy_x=true, string n_jobs="deprecated", string algorithm="auto");
	KMeans();
	~KMeans();

	void fit(RowMatrixXd X);

private:
	void _check_params(RowMatrixXd X);

private:
	int n_clusters;
	string init;
	int max_iter;
	double tol;
	string precompute_distances;
	int n_init;
	int verbose;
	int random_state;
	bool copy_x;
	string n_jobs;
	string algorithms;
	int _n_threads;
	int _n_init;
	double _tol;


};
