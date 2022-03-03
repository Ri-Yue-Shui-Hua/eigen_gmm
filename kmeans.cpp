#include "kmeans.h"
#include <thread>
#include <iostream>

KMeans::KMeans(int n_clusters, string init, int n_init, int max_iter, double tol, string precompute_distances, int verbose, int random_state, bool copy_x, string n_jobs, string algorithm)
{
	this->n_clusters = n_clusters;
	this->init = init;
	this->max_iter = max_iter;
	this->tol = tol;
	this->precompute_distances = precompute_distances;
	this->n_init = n_init;
	this->verbose = verbose;
	this->random_state = random_state;
	this->copy_x = copy_x;
	this->n_jobs = n_jobs;
	this->algorithms = algorithms;
}

KMeans::KMeans()
{
}

KMeans::~KMeans()
{
}

/*
*  Compute k-means clustering.

        Parameters
        ----------
        X : {array-like, sparse matrix} of shape (n_samples, n_features)
            Training instances to cluster. It must be noted that the data
            will be converted to C ordering, which will cause a memory
            copy if the given data is not C-contiguous.
            If a sparse matrix is passed, a copy will be made if it's not in
            CSR format.

        y : Ignored
            Not used, present here for API consistency by convention.

        sample_weight : array-like of shape (n_samples,), default=None
            The weights for each observation in X. If None, all observations
            are assigned equal weight.

            .. versionadded:: 0.20

        Returns
        -------
        self
            Fitted estimator.
        """
*/
void KMeans::fit(RowMatrixXd X)
{
   /* X = self._validate_data(X, accept_sparse = 'csr',
        dtype = [np.float64, np.float32],
        order = 'C', copy = self.copy_x,
        accept_large_sparse = False)*/





}


void KMeans::_check_params(RowMatrixXd X)
{

   this->_n_threads = thread::hardware_concurrency();

   if(n_init <= 0)
   {
       std::cout << "n_init should be > 0, got " << n_init << "instead. " << std::endl;
       return;
   }
   this->_n_init = this->n_init;
   if (max_iter <= 0)
   {
       std::cout << "max_iter should be > 0, got " << max_iter << "instead. " << std::endl;
       return;
   }
   if (X.rows() < n_clusters)
   {
       std::cout << "n_samples= " << X.rows() << "should be >=" << "n_clusters=" << n_clusters << std::endl;
       return;
   }

}
