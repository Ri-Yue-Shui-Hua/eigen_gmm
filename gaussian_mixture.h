#pragma once
#include "base.h"

class GaussianMixture:public base
{
public:
	GaussianMixture();
	virtual ~GaussianMixture();

	virtual RowMatrixXd _estimate_log_prob(RowMatrixXd X);
	RowMatrixXd _estimate_log_gaussian_prob(RowMatrixXd X, RowMatrixXd means, RowMatrixXd precisions_chol, string covariance_type);
	RowMatrixXd _compute_log_det_cholesky(RowMatrixXd matrix_chol, string covariance_type, int n_features);
	void _estimate_gaussian_parameters(RowMatrixXd X, RowMatrixXd resp, float reg_covar, string covariance_type, 
		RowMatrixXd &weights, RowMatrixXd &means, RowMatrixXd &covariances);

	RowMatrixXd _estimate_gaussian_covariances_full(RowMatrixXd resp, RowMatrixXd X, RowMatrixXd nk, RowMatrixXd means, float reg_covar);

	RowMatrixXd _compute_precision_cholesky(RowMatrixXd covariances, string covariance_type);



	virtual void _initialize(RowMatrixXd X, RowMatrixXd resp);

	virtual RowMatrixXd _estimate_log_weights();
	virtual void _check_parameters(RowMatrixXd X);
	virtual void _m_step(RowMatrixXd X, RowMatrixXd& log_resp);
	virtual double _compute_lower_bound(RowMatrixXd log_resp, double log_prob_norm);
	virtual Parameters _get_parameters();
	virtual void _set_parameters(Parameters params);

private:
	


private:
	RowMatrixXd weights_;
	RowMatrixXd means_;
	RowMatrixXd covariances_;
	RowMatrixXd precisions_cholesky_;
	RowMatrixXd precisions_;
	string covariance_type;
	
};
