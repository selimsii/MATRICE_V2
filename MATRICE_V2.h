#pragma once
#include <iostream>
#include <vector>
#include <any>
#include <string>
#include <time.h>

using namespace std;

namespace MATRICE_V2 {
	
	class MATRICE {
	
	protected:
		char type='U';  //MATRICE TYPE INT,LONG,FLOAT,DOUBLE U stands for unknown, default value
		size_t row, column;
		any type_vector;
		

		//CHECK VECTOR BEFORE ASSIGN MATRICE
		bool check_vector(vector<vector<int>>matrix_object);
		bool check_vector(vector<vector<float>>matrix_object);
		bool check_vector(vector<vector<double>>matrix_object);
		bool check_vector(vector<vector<long>>matrix_object);
		bool check_vector(any);
		
	public:				//PUBLIC CONSTRUCTORS
		MATRICE(vector<vector<int>> matrix_object);
		MATRICE(vector<vector<long>> matrix_object);
		MATRICE(vector<vector<float>> matrix_object);
		MATRICE(vector<vector<double>> matrix_object);
	
		//RANDOM CREATOR
		any random(size_t);

		//TRANSPOSE
		any transpose();
	
		//SCALER MULTIPLICATION
		any scaler_multiplication(any);

		//MULTIPLICATION
		any multiplication(any);

		//ELEMENTWISE MULTIPLICATION
		any ewisemultiplication(any);

		//ELEMENTWISE DIVISION
		any ewisedivision(any);

		//SUMMATION
		any summation(any);

		//SUBTRACTION
		any subtraction(any);

	protected:
		any mm_int(any);
		any mm_double(any);
		any mm_float(any);
		any mm_long(any);

		any ewisem_int(any);
		any ewisem_float(any);
		any ewisem_double(any);
		any ewisem_long(any);

		any ewised_int(any);
		any ewised_float(any);
		any ewised_double(any);
		any ewised_long(any);

		any sum_int(any);
		any sum_float(any);
		any sum_double(any);
		any sum_long(any);

		any sub_int(any);
		any sub_float(any);
		any sub_double(any);
		any sub_long(any);
		
	};
	
	class SQUARE_MATRICE : public MATRICE {

	public:
		SQUARE_MATRICE(vector<vector<int>> matrix_object);
		SQUARE_MATRICE(vector<vector<long>> matrix_object);
		SQUARE_MATRICE(vector<vector<float>> matrix_object);
		SQUARE_MATRICE(vector<vector<double>> matrix_object);

		size_t size_mt=0;
		
		//DETERMINANT
		any determinant();

		//SUB MINOR MATRICE
		any sub_minor_matrice(size_t, size_t);

		//Minor Value
		any minor_value(size_t, size_t);

		//MINOR MATRICE
		any minor_matrice();

		//Cofactor Matrice
		any cofactor_matrice();

		//Adjugate Matrice
		any adjugate_matrice();

		//Inverse Matrice
		any inverse_matrice();

	protected:
		float determinant(vector<vector<float>>);
		float determinant(vector<vector<int>>);
		double determinant(vector<vector<double>>);
		double determinant(vector<vector<long>>);

		vector<vector<float>> sub_minor_matrice(vector<vector<float>>,unsigned short,unsigned short);
		vector<vector<int>>sub_minor_matrice(vector<vector<int>>, unsigned short, unsigned short);
		vector<vector<double>>sub_minor_matrice(vector<vector<double>>, unsigned short, unsigned short);
		vector<vector<long>>sub_minor_matrice(vector<vector<long>>, unsigned short, unsigned short);

	};
}

