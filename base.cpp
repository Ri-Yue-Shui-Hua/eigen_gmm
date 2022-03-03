#include "base.h"
#include <random>



base::base(int n_components, float tol, float reg_covar, int max_iter, int n_init, string init_params, int random_state, bool warm_start, int verbose, int verbose_interval)
{
    this->n_components = n_components;
    this->tol = tol;
    this->reg_covar = reg_covar;
    this->max_iter = max_iter;
    this->n_init = n_init;
    this->init_params = init_params;
    this->random_state = random_state;
    this->warm_start = warm_start;
    this->verbose = verbose;
    this->verbose_interval = verbose_interval;
}

base::base()
{

}

/*
*       Estimate model parameters with the EM algorithm.

        The method fits the model ``n_init`` times and sets the parameters with
        which the model has the largest likelihood or lower bound. Within each
        trial, the method iterates between E-step and M-step for ``max_iter``
        times until the change of likelihood or lower bound is less than
        ``tol``, otherwise, a ``ConvergenceWarning`` is raised.
        If ``warm_start`` is ``True``, then ``n_init`` is ignored and a single
        initialization is performed upon the first call. Upon consecutive
        calls, training starts where it left off.

        Parameters
        ----------
        X : array-like of shape (n_samples, n_features)
            List of n_features-dimensional data points. Each row
            corresponds to a single data point.

        Returns
        -------
        self
        
*/
void base::fit(RowMatrixXd X)
{



}

/*
*       Estimate model parameters using X and predict the labels for X.

        The method fits the model n_init times and sets the parameters with
        which the model has the largest likelihood or lower bound. Within each
        trial, the method iterates between E-step and M-step for `max_iter`
        times until the change of likelihood or lower bound is less than
        `tol`, otherwise, a :class:`~sklearn.exceptions.ConvergenceWarning` is
        raised. After fitting, it predicts the most probable label for the
        input data points.

        .. versionadded:: 0.20

        Parameters
        ----------
        X : array-like of shape (n_samples, n_features)
            List of n_features-dimensional data points. Each row
            corresponds to a single data point.

        Returns
        -------
        labels : array, shape (n_samples,)
            Component labels.
        
*/

void base::fit_predict(RowMatrixXd X)
{
    _check_X(X, n_components, 0, 2);
    //_check_n_features(X, reset=True)
    // _check_initial_parameters(X)
    // if we enable warm_start, we will have a unique initialisation
    bool do_init = !warm_start;
    int n_init = do_init ? this->n_init : 1;
    float max_lower_bound = -Infinity;
    this->converged_ = false;
    int random_state = check_random_state(this->random_state);
    int n_samples = X.rows();
    for (int init = 0; init < n_init; init++)
    {
        //_print_verbose_msg_init_beg(init)

        if(do_init)
        {

        }


    }

}

/*
*  Check the input data X.

    Parameters
    ----------
    X : array-like of shape (n_samples, n_features)

    n_components : int

    Returns
    -------
    X : array, shape (n_samples, n_features)
    
*/

void base::_check_X(RowMatrixXd X, int n_components, int n_features, int ensure_min_samples)
{
    if (X.rows() < n_components)
    {
        cout << " Expected n_samples >= n_components" << "but got n_components = "<< n_components <<" n_samples = " << X.rows() << endl;
        return;
    }

    if (n_features != 0 && X.cols() != n_features)
    {
        cout << "Expected the input data X have "<< n_features << " features" << " but got "<< X.cols() << " features" << endl;
        return;
    }

}


/*
* Turn seed into a np.random.RandomState instance

    Parameters
    ----------
    seed : None, int or instance of RandomState
        If seed is None, return the RandomState singleton used by np.random.
        If seed is an int, return a new RandomState instance seeded with seed.
        If seed is already a RandomState instance, return it.
        Otherwise raise ValueError.    
* 
*/

int base::check_random_state(int seed)
{
    if (typeid(seed) == typeid(int))
    {
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<> distrib(-2000, 2000);
        int value = distrib(gen);
        return value;
    }

}

/*
* Initialize the model parameters.

        Parameters
        ----------
        X : array-like of shape  (n_samples, n_features)

        random_state : RandomState
            A random number generator instance that controls the random seed
            used for the method chosen to initialize the parameters.
        
*/

void base::_initialize_parameters(RowMatrixXd X, int random_state)
{
    int n_samples = X.rows();
    if (this->init_params == "kmeans")
    {
        RowMatrixXd resp = RowMatrixXd::Zero(n_samples, this->n_components);

    }

}
