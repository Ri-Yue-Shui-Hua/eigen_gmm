
#include<Eigen/Core>
#include<iostream>
#include <fstream>
#include <vector>
using namespace std;
using namespace Eigen;
void SoftMax(Eigen::MatrixXf mat, Eigen::MatrixXf& output)
{
	MatrixXf m = mat.array().exp();
	cout << "\n" << m;
	float sum = m.sum();
	cout << "\n" << sum;
	MatrixXf n = m / sum;
	cout << "\n" << n;
	cout << "\n" << n.sum() << "\n";
	output = mat.array().exp() / mat.array().exp().sum();
}


int main()
{
	MatrixXf input(1, 4);

	//input << -1, -2, -3, -4;

	vector<int> vecinput{ -1, -2, -3, -4 };
	input = Eigen::VectorXi::Map(&vecinput[0], vecinput.size()).cast<float>();

	cout << "input: \n" << input;
	Eigen::MatrixXf softmax;
	SoftMax(input, softmax);
	cout << "softmax: \n" << softmax << "\n";

	MatrixXf input1(1, 4);

	input1 << 1, 2, 3, 4;

	MatrixXf output2 = input1 * softmax;
	cout << "output2: \n" << output2;
	return 0;
}
