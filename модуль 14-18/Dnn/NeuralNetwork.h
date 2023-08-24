#include<iostream>
#include<immintrin.h>
#include<fstream>
#include<time.h>
#include<chrono>
using namespace std;


class NeuralNetwork {
public:
	int m_layersN;
	int* m_architecture;
	string* m_activationFunctions;
	long long neuronsNum = 0;
	long long weightsNum = 0;
	float* m_neuronsValues;	//values of neurons
	float* m_errors;
	float* m_weights; // weights of neurons

	NeuralNetwork() = default;

	NeuralNetwork(int layersNumber, int* architecture, string* activationFunctions) {
		m_layersN = layersNumber;
		m_architecture = new int[layersNumber];
		m_activationFunctions = new string[layersNumber];

		for (int i = 0; i < layersNumber; i++) {
			std::cout << layersNumber << ": " << i << "  " << architecture[i] << std::endl;
			m_architecture[i] = architecture[i];
			m_activationFunctions[i] = activationFunctions[i];

			std::cout << layersNumber << ": " << i << std::endl;

			neuronsNum += m_architecture[i];

			if (i > 0)
			{
				weightsNum += m_architecture[i] * m_architecture[i - 1];
			}
		}

		m_weights = new float[weightsNum];
		m_neuronsValues = new float[neuronsNum];
		m_errors = new float[neuronsNum];
	}

	void GeneralMatrixMultiplication(int M, int N, int K, const float* A, const float* B, float* C)
	{
		for (int i = 0; i < M; ++i)
		{
			float* c = C + i * N;

			for (int j = 0; j < N; ++j)
			{
				c[j] = 0;
			}

			for (int k = 0; k < K; ++k)
			{
				const float* b = B + k * N;
				float a = A[i * K + k];

				for (int j = 0; j < N; ++j)
				{
					c[j] += a * b[j];
				}
			}
		}
	}
	void gemmSum(int M, int N, int K, const float* A, const float* B, float* C)
	{
		for (int i = 0; i < M; ++i)
		{
			float* c = C + i * N;

			for (int k = 0; k < K; ++k)
			{
				const float* b = B + k * N;
				float a = A[i * K + k];

				for (int j = 0; j < N; ++j)
				{
					c[j] += a * b[j];
				}

			}
		}
	}

	void New()
	{
		long long counter = 0;

		for (int i = 0; i < m_layersN - 1; i++)
		{
			for (int j = 0; j < m_architecture[i] * m_architecture[i + 1]; j++)
			{
				m_weights[counter] = (double(rand() % 101) / 100.0) / m_architecture[i + 1];
				counter++;
			}
		}
	}

	void Activate(int valuesC, int layer) {
		if (m_activationFunctions[layer] == "sigmoid") {
			for (int i = valuesC; i < valuesC + m_architecture[layer]; i++) {
				m_neuronsValues[i] = (1 / (1 + pow(2.71828, -m_neuronsValues[i])));
			}

		}
		if (m_activationFunctions[layer] == "relu") {
			for (int i = valuesC; i < valuesC + m_architecture[layer]; i++) {
				if (m_neuronsValues[i] < 0) m_neuronsValues[i] *= 0.01;
			}
		}
		if (m_activationFunctions[layer] == "softmax") {
			float zn = 0.0;
			for (int i = 0; i < m_architecture[layer]; i++) {
				zn += pow((2.71), m_neuronsValues[valuesC + i]);
			}
			for (int i = 0; i < m_architecture[layer]; i++) {
				m_neuronsValues[valuesC + i] = pow(2.71, m_neuronsValues[valuesC + i]) / zn;
			}
		}
	}

	void pro(float* value, int ecounter, int layer) {
		if (m_activationFunctions[layer] == "sigmoid")
		{
			for (int i = 0; i < m_architecture[layer]; i++)
			{
				m_neuronsValues[ecounter + i] = m_neuronsValues[ecounter + i] * (1.0 - m_neuronsValues[ecounter + i]);
				value[i] *= m_neuronsValues[ecounter + i];
			}
		}

		if (m_activationFunctions[layer] == "relu")
		{
			for (int i = 0; i < m_architecture[layer]; i++)
			{
				if (m_neuronsValues[i + ecounter] < 0) m_neuronsValues[i] = 0.01;
				else m_neuronsValues[i + ecounter] = 1.0;
				value[i] *= m_neuronsValues[ecounter + i];
			}
		}

		if (m_activationFunctions[layer] == "softmax")
		{
			for (int i = 0; i < m_architecture[layer]; i++)
			{
				value[i] *= m_neuronsValues[ecounter + i] * (1.0 - m_neuronsValues[ecounter + i]);
			}
		}
	}

	void ForwardFeed(float* input_data) {
		for (int i = 0; i < m_architecture[0]; i++) {
			m_neuronsValues[i] = input_data[i];
		}

		long long valuesC = 0;
		long long weightsC = 0;
		for (int i = 0; i < m_layersN - 1; i++) {
			float* a = m_neuronsValues + valuesC;
			float* b = m_weights + weightsC;
			float* c = m_neuronsValues + valuesC + m_architecture[i];
			GeneralMatrixMultiplication(1, m_architecture[i + 1], m_architecture[i], a, b, c);


			//for (int j = valuesC; j < valuesC + arch[i + 1]; j++) {
			valuesC += m_architecture[i];
			Activate(valuesC, i + 1);

			weightsC += m_architecture[i] * m_architecture[i + 1];

		}

	}

	void GetPrediction(float* result) {
		long long h = neuronsNum - m_architecture[m_layersN - 1];
		float sum = 0;
		for (int i = 0; i < m_architecture[m_layersN - 1]; i++) {
			result[i] = m_neuronsValues[h + i];
			sum += result[i];
			//cout << "Result[" << i << "]: " << result[i] << endl;
		}
	}

	void BackPropogation(float* rightResults, float lr) {
		//calculating errors

		int h = neuronsNum - m_architecture[m_layersN - 1];

		for (int i = 0; i < m_architecture[m_layersN - 1]; i++)
		{
			m_errors[i + h] = rightResults[i] - m_neuronsValues[i + h];
		}

		long long wcounter = weightsNum;
		long long ecounter = neuronsNum;
		long long counter = neuronsNum - m_architecture[m_layersN - 1];

		for (int i = m_layersN - 1; i > 0; i--) {
			ecounter -= m_architecture[i];
			wcounter -= m_architecture[i] * m_architecture[i - 1];
			counter -= m_architecture[i - 1];
			float* a = m_errors + ecounter;
			float* b = m_weights + wcounter;
			float* c = m_errors + counter;
			GeneralMatrixMultiplication(1, m_architecture[i - 1], m_architecture[i], a, b, c);

		}

		//renew matrix weights:
		long long vcounter = neuronsNum - m_architecture[m_layersN - 1];
		wcounter = weightsNum;
		ecounter = neuronsNum;

		for (int i = m_layersN - 1; i > 0; i--)
		{
			ecounter -= m_architecture[i];
			vcounter -= m_architecture[i - 1];
			wcounter -= m_architecture[i] * m_architecture[i - 1];

			float* layer = new float[m_architecture[i]];

			for (int j = 0; j < m_architecture[i]; j++)
			{
				layer[j] = m_errors[ecounter + j] /*pro(values[ecounter + j], i)*/ * lr;
			}

			pro(layer, ecounter, i);
			float* a = m_neuronsValues + vcounter;
			float* c = m_weights + wcounter;

			gemmSum(m_architecture[i - 1], m_architecture[i], 1, a, layer, c);

			delete[] layer;
		}

	}

};

