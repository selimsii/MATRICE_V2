#include <iostream>
#include <string>
#include <vector>
#include "MATRICE_V2.h"
#include <any>

using namespace std;

//CHECK VECTOR BEFORE ASSIGN MATRICE
bool MATRICE_V2::MATRICE::check_vector(vector<vector<int>>matrix_object) {

	int column_check = 0; bool specifier = false;
	column_check = matrix_object[0].size();

	for (int i = 0; i < matrix_object.size(); i++) {
		if (column_check == matrix_object[i].size()) {
			specifier= true;
		}
		else {
			return false;
		}
	}
	return specifier;
}
bool MATRICE_V2::MATRICE::check_vector(vector<vector<float>>matrix_object) {

	int column_check = 0;  bool specifier = false;
	column_check = matrix_object[0].size();

	for (int i = 0; i < matrix_object.size(); i++) {
		if (column_check == matrix_object[i].size()) {
			specifier= true;
		}
		else {
			return false;
		}
	}
	return specifier;
}
bool MATRICE_V2::MATRICE::check_vector(vector<vector<long>>matrix_object) {

	int column_check = 0;  bool specifier = false;
	column_check = matrix_object[0].size();

	for (int i = 0; i < matrix_object.size(); i++) {
		if (column_check == matrix_object[i].size()) {
			specifier =true;
		}
		else {
			return false;
		}
	}
	return specifier;
}
bool MATRICE_V2::MATRICE::check_vector(vector<vector<double>>matrix_object) {

	int column_check = 0; bool specifier = false;
	column_check = matrix_object[0].size();

	for (int i = 0; i < matrix_object.size(); i++) {
		if (column_check == matrix_object[i].size()) {
			specifier= true;
		}
		else {
			return false;
		}
	}
	return specifier;
}

bool MATRICE_V2::MATRICE::check_vector(any matrix_2) {
	
	if (matrix_2.type() == typeid(vector<vector<int>>)) {
		auto typ= any_cast<vector<vector<int>>>(matrix_2);
		return check_vector(typ);
	}
	else if (matrix_2.type() == typeid(vector<vector<float>>)) {
		auto typ = any_cast<vector<vector<float>>>(matrix_2);
		return check_vector(typ);
	}
	else if (matrix_2.type() == typeid(vector<vector<double>>)) {
		auto typ = any_cast<vector<vector<double>>>(matrix_2);
		return check_vector(typ);
	}
	else if (matrix_2.type() == typeid(vector<vector<long>>)) {
		auto typ = any_cast<vector<vector<long>>>(matrix_2);
		return check_vector(typ);
	}
	else {
		cout << "Unknown type of vector";
	}
}

// OVERLOADED CONSTRUCTORS TO ASSIGN LOCAL OBJECT VARIABLES

MATRICE_V2::MATRICE::MATRICE(vector<vector<int>>matrix_object) {
	
		// CHECKING NUMBERS OF ELEMENTS INSIDE THE INNER VECTOR
	bool specifier = check_vector(matrix_object);

	switch(specifier){
	case true:type_vector = matrix_object; type = 'I'; row = matrix_object.size(); column = matrix_object[0].size(); break;
	case false:cout << "Numbers of elements must be same in each row" << endl; break;
	}

}
MATRICE_V2::MATRICE::MATRICE(vector<vector<long>>matrix_object) {

	// CHECKING NUMBERS OF ELEMENTS INSIDE THE INNER VECTOR
	bool specifier = check_vector(matrix_object);

	switch (specifier) {
	case true:type_vector = matrix_object; type = 'L'; row = matrix_object.size(); column = matrix_object[0].size(); break;
	case false:cout << "Numbers of elements must be same in each row" << endl; break;
	}


}
MATRICE_V2::MATRICE::MATRICE(vector<vector<float>>matrix_object) {

	// CHECKING NUMBERS OF ELEMENTS INSIDE THE INNER VECTOR
	bool specifier = check_vector(matrix_object);

	switch (specifier) {
	case true:type_vector = matrix_object; type = 'F'; row = matrix_object.size(); column = matrix_object[0].size(); break;
	case false:cout << "Numbers of elements must be same in each row" << endl; break;
	}

}
MATRICE_V2::MATRICE::MATRICE(vector<vector<double>>matrix_object) {

	// CHECKING NUMBERS OF ELEMENTS INSIDE THE INNER VECTOR
	bool specifier = check_vector(matrix_object);

	switch (specifier) {
	case true:type_vector = matrix_object; type = 'D'; row = matrix_object.size(); column = matrix_object[0].size(); break;
	case false:cout << "Numbers of elements must be same in each row" << endl; break;
	}

}


//CONSTRUCTORS OF SQUARE MATRICE SUB CLASS --> CREATED BY CONSTRUCTORS OF MATRICE CLASS
MATRICE_V2::SQUARE_MATRICE::SQUARE_MATRICE(vector<vector<int>> matrix_object):MATRICE(matrix_object){
	if (row == column) {
		size_mt = row;
	}
	else {
		cout << "The matrice must be square";
	}
}
MATRICE_V2::SQUARE_MATRICE::SQUARE_MATRICE(vector<vector<long>> matrix_object):MATRICE(matrix_object) {
	if (row == column) {
		size_mt = row;
	}
	else {
		cout << "The matrice must be square";
	}
}
MATRICE_V2::SQUARE_MATRICE::SQUARE_MATRICE(vector<vector<float>> matrix_object):MATRICE(matrix_object) {
	if (row == column) {
		size_mt = row;
	}
	else {
		cout << "The matrice must be square";
	}

}
MATRICE_V2::SQUARE_MATRICE::SQUARE_MATRICE(vector<vector<double>> matrix_object):MATRICE(matrix_object) {
	if (row == column) {
		size_mt = row;
	}
	else {
		cout << "The matrice must be square";
		
	}
}
//RANDOM FUNCTION
any MATRICE_V2::MATRICE::random(size_t num) {
	
	srand(time(NULL));
	
	//If vector type is int
	if (type == 'I') {
		vector temp(row,vector<int>(column));
		for (size_t i=0; i < row; i++) {
			for (size_t j = 0; j < column; j++) {
				temp[i][j] = any_cast<vector<vector<int>>>(type_vector)[i][j] = (rand() % (2 * num + 1)) - num;
			}
		}
		return temp;
	}
	//If vector type is float
	else if (type == 'F') {
		vector temp(row, vector<float>(column));
		for (size_t i=0; i < row; i++) {
			for (size_t j = 0; j < column; j++) {
				temp[i][j] = any_cast<vector<vector<float>>>(type_vector)[i][j] = (rand() % (2 * num + 1)) - num;
			}
		}
		return temp;
	}

	//If vector type is double
	else if (type == 'D') {
		vector temp(row, vector<double>(column));
		for (size_t i=0; i < row; i++) {
			for (size_t j = 0; j < column; j++) {
				temp[i][j] = any_cast<vector<vector<double>>>(type_vector)[i][j] = (rand() % (2 * num + 1)) - num;
			}
		}
		return temp;
	}

	//If vector type is long
	else if (type == 'L') {
		vector temp(row, vector<double>(column));
		for (size_t i=0; i < row; i++) {
			for (size_t j = 0; j < column; j++) {
				temp[i][j] = any_cast<vector<vector<long>>>(type_vector)[i][j] = (rand() % (2 * num + 1)) - num;
			}
		}
		return temp;
	}

	//IF TYPE IS UNKNOWN
	else {
		cout << "Unknown type of vector";
	}
}
any MATRICE_V2::MATRICE::transpose() {

	//If vector type is int
	if (type=='I') {

		// Accessing 2D vector by using std::any_cast
		vector<vector<int>> retrievedVec2D = any_cast<vector<vector<int>>>(type_vector);
		vector retrievedVec2D_copy(column, vector<int>(row));

		int k = 0, c = 0, y = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				retrievedVec2D_copy[j][i] = retrievedVec2D[i][j];
			}
		}
		return (retrievedVec2D_copy);
	}

	//If vector type is float
	else if (type=='F') {

		// Accessing 2D vector by using std::any_cast
		vector<vector<float>> retrievedVec2D = any_cast<vector<vector<float>>>(type_vector);
		vector retrievedVec2D_copy(column, vector<float>(row));

		int k = 0, c = 0, y = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				retrievedVec2D_copy[j][i] = retrievedVec2D[i][j];
			}
		}
		return (retrievedVec2D_copy);
	}

	//If vector type is double
	else if (type=='D') {

		// Accessing 2D vector by using std::any_cast
		vector<vector<double>> retrievedVec2D = any_cast<vector<vector<double>>>(type_vector);
		vector retrievedVec2D_copy(column, vector<double>(row));
		int k = 0, c = 0, y = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				retrievedVec2D_copy[j][i] = retrievedVec2D[i][j];
			}
		}
		return (retrievedVec2D_copy);
	}

	//If vector type is long
	else if (type=='L') {

		// Accessing 2D vector by using std::any_cast
		vector<vector<long>> retrievedVec2D = any_cast<vector<vector<long>>>(type_vector);
		vector retrievedVec2D_copy(column, vector<long>(row));

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				retrievedVec2D_copy[j][i] = retrievedVec2D[i][j];
			}
			
		}
		return (retrievedVec2D_copy);
	}

	//IF TYPE IS UNKNOWN
	else {
		cout << "Unknown type of vector";
	}
}

//SCALER MULTIPLICATION
any MATRICE_V2::MATRICE::scaler_multiplication(any scalar_value) {
	//If vector type is int
	if (type == 'I') {

		auto value = 0.00;
		
		switch (scalar_value.type().name()[0]) {
		case 'i':value = any_cast<int>(scalar_value); break;
		case 'f':value = any_cast<float>(scalar_value); break;
		case 'd':value = any_cast<double>(scalar_value); break;
		case 'l':value = any_cast<long>(scalar_value); break;
		}

		// Accessing 2D vector by using std::any_cast
		vector retrievedVec2D(row,vector<float>(column));

		int k = 0, c = 0, y = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				retrievedVec2D[i][j] = any_cast<vector<vector<int>>>(type_vector)[i][j] * value;
			}
		}
		return (retrievedVec2D);
	}

	//If vector type is float
	else if (type == 'F') {

		auto value = 0.00;
		switch (scalar_value.type().name()[0]) {
		case 'i':value = any_cast<int>(scalar_value); break;
		case 'f':value = any_cast<float>(scalar_value); break;
		case 'd':value = any_cast<double>(scalar_value); break;
		case 'l':value = any_cast<long>(scalar_value); break;
		}
	
		// Accessing 2D vector by using std::any_cast
		auto retrievedVec2D = any_cast<vector<vector<float>>>(type_vector);

		int k = 0, c = 0, y = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				retrievedVec2D[i][j] = retrievedVec2D[i][j] * value;
			}
		}
		return (retrievedVec2D);
	}

	//If vector type is double
	else if (type == 'D') {

		auto value = 0.00;
		switch (scalar_value.type().name()[0]) {
		case 'i':value = any_cast<int>(scalar_value); break;
		case 'f':value = any_cast<float>(scalar_value); break;
		case 'd':value = any_cast<double>(scalar_value); break;
		case 'l':value = any_cast<long>(scalar_value); break;
		}

		// Accessing 2D vector by using std::any_cast
		auto retrievedVec2D = any_cast<vector<vector<double>>>(type_vector);

		int k = 0, c = 0, y = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				retrievedVec2D[i][j] = retrievedVec2D[i][j] * value;
			}
		}
		return (retrievedVec2D);
	}

	//If vector type is long
	else if (type == 'L') {

		auto value = 0.00;
		switch (scalar_value.type().name()[0]) {
		case 'i':value = any_cast<int>(scalar_value); break;
		case 'f':value = any_cast<float>(scalar_value); break;
		case 'd':value = any_cast<double>(scalar_value); break;
		case 'l':value = any_cast<long>(scalar_value); break;
		}

		// Accessing 2D vector by using std::any_cast
		vector retrievedVec2D(row,vector<double>(column));

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				retrievedVec2D[i][j] = any_cast<vector<vector<long>>>(type_vector)[i][j]* value;
			}

		}
		return (retrievedVec2D);
	}

	//IF TYPE IS UNKNOWN
	else {
		cout << "Unknown type of vector";
	}
}

any MATRICE_V2::MATRICE::multiplication(any matrix_2){
	bool specifier = check_vector(matrix_2);

	switch (type * specifier) {
	case 'I': return mm_int(matrix_2); break;
	case 'F': return mm_float(matrix_2); break;
	case 'D': return mm_double(matrix_2); break;
	case 'L': return mm_long(matrix_2); break;
	case 0:cout<< "Unknown Type or Incompatible Vector Size"; break;
	default: cout<<"Unknown Type or Incompatible Vector Size";
	}
}
any MATRICE_V2::MATRICE::mm_int(any matrix_2) {  

	auto matrix1 = any_cast<vector<vector<int>>>(type_vector);
	
	if (matrix_2.type() == typeid(vector<vector<int>>)) {

		auto matrix2 = any_cast<vector<vector<int>>>(matrix_2);
		vector matrix3(row, vector<int>(matrix2[0].size()));
		
		for (int i = 0; i < row; i++) {
			for (int k = 0; k < matrix2[0].size(); k++) {
				for (int j = 0; j < column; j++) {
					matrix3[i][k] += matrix1[i][j] * matrix2[j][k];
				}
			}
		}
		return matrix3;
	}
	else if(matrix_2.type() == typeid(vector<vector<float>>)){

		auto matrix2 = any_cast<vector<vector<float>>>(matrix_2);
		vector matrix3(row, vector<float>(matrix2[0].size()));

		for (int i = 0; i < row; i++) {
			for (int k = 0; k < matrix2[0].size(); k++) {
				for (int j = 0; j < column; j++) {
					matrix3[i][k] += matrix1[i][j] * matrix2[j][k];
				}
			}
		}
		return matrix3;
	}
	else if(matrix_2.type() == typeid(vector<vector<double>>)){

		auto matrix2 = any_cast<vector<vector<double>>>(matrix_2);
		vector matrix3(row, vector<double>(matrix2[0].size()));

		for (int i = 0; i < row; i++) {
			for (int k = 0; k < matrix2[0].size(); k++) {
				for (int j = 0; j < column; j++) {
					matrix3[i][k] += matrix1[i][j] * matrix2[j][k];
				}
			}
		}
	
		return matrix3;
	}
	else if(matrix_2.type() == typeid(vector<vector<long>>)){

		auto matrix2 = any_cast<vector<vector<long>>>(matrix_2);
		vector matrix3(row, vector<long>(matrix2[0].size()));

		for (int i = 0; i < row; i++) {
			for (int k = 0; k < matrix2[0].size(); k++) {
				for (int j = 0; j < column; j++) {
					matrix3[i][k] += matrix1[i][j] * matrix2[j][k];
				}
			}
		}
		return matrix3;
	}
	else {
		cout << "Unknown Type";
	}
}
any MATRICE_V2::MATRICE::mm_double(any matrix_2) {

	auto matrix1 = any_cast<vector<vector<double>>>(type_vector);
	auto matrix2 = any_cast<vector<vector<double>>>(matrix_2);
	
	vector matrix3(row, vector<double>(matrix2[0].size()));

	for (int i = 0; i < row; i++) {
		for (int k = 0; k < matrix2[0].size(); k++) {
			for (int j = 0; j < column; j++) {
				matrix3[i][k] += matrix1[i][j] * matrix2[j][k];
			}
		}
	}
	return matrix3;

}
any MATRICE_V2::MATRICE::mm_float(any matrix_2){

	auto matrix1 = any_cast<vector<vector<float>>>(type_vector);

	if (matrix_2.type() == typeid(vector<vector<int>>)) {

		auto matrix2 = any_cast<vector<vector<int>>>(matrix_2);
		vector matrix3(row, vector<float>(matrix2[0].size()));

		for (int i = 0; i < row; i++) {
			for (int k = 0; k < matrix2[0].size(); k++) {
				for (int j = 0; j < column; j++) {
					matrix3[i][k] += matrix1[i][j] * matrix2[j][k];
				}
			}
		}
		return matrix3;
	}
	else if (matrix_2.type() == typeid(vector<vector<float>>)) {

		auto matrix2 = any_cast<vector<vector<float>>>(matrix_2);
		vector matrix3(row, vector<float>(matrix2[0].size()));

		for (int i = 0; i < row; i++) {
			for (int k = 0; k < matrix2[0].size(); k++) {
				for (int j = 0; j < column; j++) {
					matrix3[i][k] += matrix1[i][j] * matrix2[j][k];
				}
			}
		}
		return matrix3;
	}
	else if (matrix_2.type() == typeid(vector<vector<double>>)) {

		auto matrix2 = any_cast<vector<vector<double>>>(matrix_2);
		vector matrix3(row, vector<double>(matrix2[0].size()));

		for (int i = 0; i < row; i++) {
			for (int k = 0; k < matrix2[0].size(); k++) {
				for (int j = 0; j < column; j++) {
					matrix3[i][k] += matrix1[i][j] * matrix2[j][k];
				}
			}
		}
		return matrix3;
	}
	else if (matrix_2.type() == typeid(vector<vector<long>>)) {

		auto matrix2 = any_cast<vector<vector<long>>>(matrix_2);
		vector matrix3(row, vector<float>(matrix2[0].size()));

		for (int i = 0; i < row; i++) {
			for (int k = 0; k < matrix2[0].size(); k++) {
				for (int j = 0; j < column; j++) {
					matrix3[i][k] += matrix1[i][j] * matrix2[j][k];
				}
			}
		}
		return matrix3;
	}
	else {
		cout << "Unknown Type";
	}
}
any MATRICE_V2::MATRICE::mm_long(any matrix_2){

	auto matrix1 = any_cast<vector<vector<long>>>(type_vector);

	if (matrix_2.type() == typeid(vector<vector<int>>)) {

		auto matrix2 = any_cast<vector<vector<int>>>(matrix_2);
		vector matrix3(row, vector<long>(matrix2[0].size()));

		for (int i = 0; i < row; i++) {
			for (int k = 0; k < matrix2[0].size(); k++) {
				for (int j = 0; j < column; j++) {
					matrix3[i][k] += matrix1[i][j] * matrix2[j][k];
				}
			}
		}
		return matrix3;
	}
	else if (matrix_2.type() == typeid(vector<vector<float>>)) {

		auto matrix2 = any_cast<vector<vector<float>>>(matrix_2);
		vector matrix3(row, vector<float>(matrix2[0].size()));

		for (int i = 0; i < row; i++) {
			for (int k = 0; k < matrix2[0].size(); k++) {
				for (int j = 0; j < column; j++) {
					matrix3[i][k] += matrix1[i][j] * matrix2[j][k];
				}
			}
		}
		return matrix3;
	}
	else if (matrix_2.type() == typeid(vector<vector<double>>)) {

		auto matrix2 = any_cast<vector<vector<double>>>(matrix_2);
		vector matrix3(row, vector<double>(matrix2[0].size()));

		for (int i = 0; i < row; i++) {
			for (int k = 0; k < matrix2[0].size(); k++) {
				for (int j = 0; j < column; j++) {
					matrix3[i][k] += matrix1[i][j] * matrix2[j][k];
				}
			}
		}
		return matrix3;
	}
	else if (matrix_2.type() == typeid(vector<vector<long>>)) {

		auto matrix2 = any_cast<vector<vector<long>>>(matrix_2);
		vector matrix3(row, vector<long>(matrix2[0].size()));

		for (int i = 0; i < row; i++) {
			for (int k = 0; k < matrix2[0].size(); k++) {
				for (int j = 0; j < column; j++) {
					matrix3[i][k] += matrix1[i][j] * matrix2[j][k];
				}
			}
		}
		return matrix3;
	}
	else {
		cout << "Unknown Type";
	}
}

//EWISE MULTIPLICATION
any MATRICE_V2::MATRICE::ewisemultiplication(any matrix_2){

	bool specifier = check_vector(matrix_2);
	
	switch (type*specifier) {
	case'I':return ewisem_int(matrix_2); break;
	case'F':return ewisem_float(matrix_2); break;
	case 'D':return ewisem_double(matrix_2); break;
	case 'L':return ewisem_long(matrix_2); break;
	default: cout<<"Unknown Type or Incorrect Type Of Vector Input"; break;
	}

}

any MATRICE_V2::MATRICE::ewisem_int(any matrix_2) {

	auto matrix1 = any_cast<vector<vector<int>>>(type_vector);


	if (matrix_2.type() == typeid(vector<vector<int>>)) {

		auto matrix2 = any_cast<vector<vector<int>>>(matrix_2);
		vector matrix3(row, vector<int>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] * matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<float>>)) {

		auto matrix2 = any_cast<vector<vector<float>>>(matrix_2);
		vector matrix3(row, vector<float>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] * matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<double>>)) {

		auto matrix2 = any_cast<vector<vector<double>>>(matrix_2);
		vector matrix3(row, vector<double>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] * matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<long>>)) {

		auto matrix2 = any_cast<vector<vector<long>>>(matrix_2);
		vector matrix3(row, vector<long>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] * matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else {
		cout << "Unknown Type";
	}
}
any MATRICE_V2::MATRICE::ewisem_float(any matrix_2) {

	auto matrix1 = any_cast<vector<vector<float>>>(type_vector);

	if (matrix_2.type() == typeid(vector<vector<int>>)) {

		auto matrix2 = any_cast<vector<vector<int>>>(matrix_2);
		vector matrix3(row, vector<float>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] * matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<float>>)) {

		auto matrix2 = any_cast<vector<vector<float>>>(matrix_2);
		vector matrix3(row, vector<float>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] * matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<double>>)) {

		auto matrix2 = any_cast<vector<vector<double>>>(matrix_2);
		vector matrix3(row, vector<double>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] * matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<long>>)) {

		auto matrix2 = any_cast<vector<vector<long>>>(matrix_2);
		vector matrix3(row, vector<float>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] * matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else {
		cout << "Unknown Type";
	}
}
any MATRICE_V2::MATRICE::ewisem_double(any matrix_2) {

	auto matrix1 = any_cast<vector<vector<double>>>(type_vector);
	auto matrix2 = any_cast<vector<vector<double>>>(matrix_2);

	vector matrix3(row, vector<double>(matrix2[0].size()));

	if (row == matrix2.size() && column == matrix2[0].size()) {
		for (int i = 0; i < row; i++) {
			for (int k = 0; k < column; k++) {
				matrix3[i][k] = matrix1[i][k] * matrix2[i][k];
			}
		}
		return matrix3;
	}
	else {
		cout << "Input must have same dimensions";
	}
}
any MATRICE_V2::MATRICE::ewisem_long(any matrix_2){
	auto matrix1 = any_cast<vector<vector<long>>>(type_vector);

	if (matrix_2.type() == typeid(vector<vector<int>>)) {

		auto matrix2 = any_cast<vector<vector<int>>>(matrix_2);
		vector matrix3(row, vector<long>(matrix2[0].size()));
		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] * matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<float>>)) {

		auto matrix2 = any_cast<vector<vector<float>>>(matrix_2);
		vector matrix3(row, vector<float>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] * matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<double>>)) {

		auto matrix2 = any_cast<vector<vector<double>>>(matrix_2);
		vector matrix3(row, vector<double>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] * matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<long>>)) {

		auto matrix2 = any_cast<vector<vector<long>>>(matrix_2);
		vector matrix3(row, vector<long>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] * matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else {
		cout << "Unknown Type";
	}
}

//////////////////////////////EWISE DIVISION///////////////////////////////////
any MATRICE_V2::MATRICE::ewisedivision(any matrix_2) {
	bool specifier = check_vector(matrix_2);

	switch (type * specifier) {
	case'I':return ewised_int(matrix_2); break;
	case'F':return ewised_float(matrix_2); break;
	case 'D':return ewised_double(matrix_2); break;
	case 'L':return ewised_long(matrix_2); break;
	default:cout << "Unknown Type or Incorrect Vector Input"; break;
	}

}

any MATRICE_V2::MATRICE::ewised_int(any matrix_2) {

	auto matrix1 = any_cast<vector<vector<int>>>(type_vector);


	if (matrix_2.type() == typeid(vector<vector<int>>)) {

		auto matrix2 = any_cast<vector<vector<int>>>(matrix_2);
		vector matrix3(row, vector<int>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] / matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<float>>)) {

		auto matrix2 = any_cast<vector<vector<float>>>(matrix_2);
		vector matrix3(row, vector<float>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] / matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<double>>)) {

		auto matrix2 = any_cast<vector<vector<double>>>(matrix_2);
		vector matrix3(row, vector<double>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] / matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<long>>)) {

		auto matrix2 = any_cast<vector<vector<long>>>(matrix_2);
		vector matrix3(row, vector<long>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] / matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else {
		cout << "Unknown Type";
	}
}
any MATRICE_V2::MATRICE::ewised_float(any matrix_2) {

	auto matrix1 = any_cast<vector<vector<float>>>(type_vector);

	if (matrix_2.type() == typeid(vector<vector<int>>)) {

		auto matrix2 = any_cast<vector<vector<int>>>(matrix_2);
		vector matrix3(row, vector<float>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] / matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<float>>)) {

		auto matrix2 = any_cast<vector<vector<float>>>(matrix_2);
		vector matrix3(row, vector<float>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] / matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<double>>)) {

		auto matrix2 = any_cast<vector<vector<double>>>(matrix_2);
		vector matrix3(row, vector<double>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] / matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<long>>)) {

		auto matrix2 = any_cast<vector<vector<long>>>(matrix_2);
		vector matrix3(row, vector<float>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] / matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else {
		cout << "Unknown Type";
	}
}
any MATRICE_V2::MATRICE::ewised_double(any matrix_2) {

	auto matrix1 = any_cast<vector<vector<double>>>(type_vector);
	auto matrix2 = any_cast<vector<vector<double>>>(matrix_2);

	vector matrix3(row, vector<double>(matrix2[0].size()));

	if (row == matrix2.size() && column == matrix2[0].size()) {
		for (int i = 0; i < row; i++) {
			for (int k = 0; k < column; k++) {
				matrix3[i][k] = matrix1[i][k] / matrix2[i][k];
			}
		}
		return matrix3;
	}
	else {
		cout << "Input must have same dimensions";
	}
}
any MATRICE_V2::MATRICE::ewised_long(any matrix_2) {
	auto matrix1 = any_cast<vector<vector<long>>>(type_vector);

	if (matrix_2.type() == typeid(vector<vector<int>>)) {

		auto matrix2 = any_cast<vector<vector<int>>>(matrix_2);
		vector matrix3(row, vector<long>(matrix2[0].size()));
		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] / matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<float>>)) {

		auto matrix2 = any_cast<vector<vector<float>>>(matrix_2);
		vector matrix3(row, vector<float>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] / matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<double>>)) {

		auto matrix2 = any_cast<vector<vector<double>>>(matrix_2);
		vector matrix3(row, vector<double>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] / matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<long>>)) {

		auto matrix2 = any_cast<vector<vector<long>>>(matrix_2);
		vector matrix3(row, vector<long>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] / matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else {
		cout << "Unknown Type";
	}
}
//////////////////////////////SUMMATION///////////////////////////////////
any MATRICE_V2::MATRICE::summation(any matrix_2) {
	bool specifier = check_vector(matrix_2);

	switch (type * specifier) {
	case'I':return sum_int(matrix_2); break;
	case'F':return sum_float(matrix_2); break;
	case 'D':return sum_double(matrix_2); break;
	case 'L':return sum_long(matrix_2); break;
	default:cout << "Unknown Type or Incorrect Vector Input"; break;
	}

}

any MATRICE_V2::MATRICE::sum_int(any matrix_2) {

	auto matrix1 = any_cast<vector<vector<int>>>(type_vector);


	if (matrix_2.type() == typeid(vector<vector<int>>)) {

		auto matrix2 = any_cast<vector<vector<int>>>(matrix_2);
		vector matrix3(row, vector<int>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] + matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<float>>)) {

		auto matrix2 = any_cast<vector<vector<float>>>(matrix_2);
		vector matrix3(row, vector<float>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] + matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<double>>)) {

		auto matrix2 = any_cast<vector<vector<double>>>(matrix_2);
		vector matrix3(row, vector<double>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] + matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<long>>)) {

		auto matrix2 = any_cast<vector<vector<long>>>(matrix_2);
		vector matrix3(row, vector<long>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] + matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else {
		cout << "Unknown Type";
	}
}
any MATRICE_V2::MATRICE::sum_float(any matrix_2) {

	auto matrix1 = any_cast<vector<vector<float>>>(type_vector);

	if (matrix_2.type() == typeid(vector<vector<int>>)) {

		auto matrix2 = any_cast<vector<vector<int>>>(matrix_2);
		vector matrix3(row, vector<float>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] + matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<float>>)) {

		auto matrix2 = any_cast<vector<vector<float>>>(matrix_2);
		vector matrix3(row, vector<float>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] + matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<double>>)) {

		auto matrix2 = any_cast<vector<vector<double>>>(matrix_2);
		vector matrix3(row, vector<double>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] + matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<long>>)) {

		auto matrix2 = any_cast<vector<vector<long>>>(matrix_2);
		vector matrix3(row, vector<float>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] + matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else {
		cout << "Unknown Type";
	}
}
any MATRICE_V2::MATRICE::sum_double(any matrix_2) {

	auto matrix1 = any_cast<vector<vector<double>>>(type_vector);
	auto matrix2 = any_cast<vector<vector<double>>>(matrix_2);

	vector matrix3(row, vector<double>(matrix2[0].size()));

	if (row == matrix2.size() && column == matrix2[0].size()) {
		for (int i = 0; i < row; i++) {
			for (int k = 0; k < column; k++) {
				matrix3[i][k] = matrix1[i][k] + matrix2[i][k];
			}
		}
		return matrix3;
	}
	else {
		cout << "Input must have same dimensions";
	}
}
any MATRICE_V2::MATRICE::sum_long(any matrix_2) {
	auto matrix1 = any_cast<vector<vector<long>>>(type_vector);

	if (matrix_2.type() == typeid(vector<vector<int>>)) {

		auto matrix2 = any_cast<vector<vector<int>>>(matrix_2);
		vector matrix3(row, vector<long>(matrix2[0].size()));
		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] + matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<float>>)) {

		auto matrix2 = any_cast<vector<vector<float>>>(matrix_2);
		vector matrix3(row, vector<float>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] + matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<double>>)) {

		auto matrix2 = any_cast<vector<vector<double>>>(matrix_2);
		vector matrix3(row, vector<double>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] + matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<long>>)) {

		auto matrix2 = any_cast<vector<vector<long>>>(matrix_2);
		vector matrix3(row, vector<long>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] + matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else {
		cout << "Unknown Type";
	}
}
//////////////////////////////SUBTRACTION///////////////////////////////////
any MATRICE_V2::MATRICE::subtraction(any matrix_2) {
	bool specifier = check_vector(matrix_2);

	switch (type * specifier) {
	case'I':return sub_int(matrix_2); break;
	case'F':return sub_float(matrix_2); break;
	case 'D':return sub_double(matrix_2); break;
	case 'L':return sub_long(matrix_2); break;
	default:cout<<"Unknown Type or Incorrect Vector Input"; break;
	}

}

any MATRICE_V2::MATRICE::sub_int(any matrix_2) {

	auto matrix1 = any_cast<vector<vector<int>>>(type_vector);


	if (matrix_2.type() == typeid(vector<vector<int>>)) {

		auto matrix2 = any_cast<vector<vector<int>>>(matrix_2);
		vector matrix3(row, vector<int>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] - matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<float>>)) {

		auto matrix2 = any_cast<vector<vector<float>>>(matrix_2);
		vector matrix3(row, vector<float>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] - matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<double>>)) {

		auto matrix2 = any_cast<vector<vector<double>>>(matrix_2);
		vector matrix3(row, vector<double>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] - matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<long>>)) {

		auto matrix2 = any_cast<vector<vector<long>>>(matrix_2);
		vector matrix3(row, vector<long>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] - matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else {
		cout << "Unknown Type";
	}
}
any MATRICE_V2::MATRICE::sub_float(any matrix_2) {

	auto matrix1 = any_cast<vector<vector<float>>>(type_vector);

	if (matrix_2.type() == typeid(vector<vector<int>>)) {

		auto matrix2 = any_cast<vector<vector<int>>>(matrix_2);
		vector matrix3(row, vector<float>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] - matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<float>>)) {

		auto matrix2 = any_cast<vector<vector<float>>>(matrix_2);
		vector matrix3(row, vector<float>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] - matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<double>>)) {

		auto matrix2 = any_cast<vector<vector<double>>>(matrix_2);
		vector matrix3(row, vector<double>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] - matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<long>>)) {

		auto matrix2 = any_cast<vector<vector<long>>>(matrix_2);
		vector matrix3(row, vector<float>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] - matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else {
		cout << "Unknown Type";
	}
}
any MATRICE_V2::MATRICE::sub_double(any matrix_2) {

	auto matrix1 = any_cast<vector<vector<double>>>(type_vector);
	auto matrix2 = any_cast<vector<vector<double>>>(matrix_2);

	vector matrix3(row, vector<double>(matrix2[0].size()));

	if (row == matrix2.size() && column == matrix2[0].size()) {
		for (int i = 0; i < row; i++) {
			for (int k = 0; k < column; k++) {
				matrix3[i][k] = matrix1[i][k] - matrix2[i][k];
			}
		}
		return matrix3;
	}
	else {
		cout << "Input must have same dimensions";
	}
}
any MATRICE_V2::MATRICE::sub_long(any matrix_2) {
	auto matrix1 = any_cast<vector<vector<long>>>(type_vector);

	if (matrix_2.type() == typeid(vector<vector<int>>)) {

		auto matrix2 = any_cast<vector<vector<int>>>(matrix_2);
		vector matrix3(row, vector<long>(matrix2[0].size()));
		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] - matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<float>>)) {

		auto matrix2 = any_cast<vector<vector<float>>>(matrix_2);
		vector matrix3(row, vector<float>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] - matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<double>>)) {

		auto matrix2 = any_cast<vector<vector<double>>>(matrix_2);
		vector matrix3(row, vector<double>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] - matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else if (matrix_2.type() == typeid(vector<vector<long>>)) {

		auto matrix2 = any_cast<vector<vector<long>>>(matrix_2);
		vector matrix3(row, vector<long>(matrix2[0].size()));

		if (row == matrix2.size() && column == matrix2[0].size()) {
			for (int i = 0; i < row; i++) {
				for (int k = 0; k < column; k++) {
					matrix3[i][k] = matrix1[i][k] - matrix2[i][k];
				}
			}
			return matrix3;
		}
		else {
			cout << "Input must have same dimensions";
		}
	}
	else {
		cout << "Unknown Type";
	}
}
any MATRICE_V2::SQUARE_MATRICE::sub_minor_matrice(size_t row_index, size_t column_index) {
	if (typeid(vector<vector<int>>) == type_vector.type()) {
		return sub_minor_matrice(any_cast<vector<vector<int>>>(type_vector),row_index,column_index);
	}
	else if (typeid(vector<vector<float>>) == type_vector.type()) {
		return sub_minor_matrice(any_cast<vector<vector<float>>>(type_vector), row_index, column_index);
	}
	else if (typeid(vector<vector<double>>) == type_vector.type()) {
		return sub_minor_matrice(any_cast<vector<vector<double>>>(type_vector), row_index, column_index);
	}
	else if (typeid(vector<vector<long>>) == type_vector.type()) {
		return sub_minor_matrice(any_cast<vector<vector<long>>>(type_vector), row_index, column_index);
	}
	else { cout << "Unknown type of square matrice"; }
}
vector<vector<float>> MATRICE_V2::SQUARE_MATRICE::sub_minor_matrice(vector<vector<float>> matrix, unsigned short row_index, unsigned short column_index) {

	unsigned short x=0, y=0;
	vector my_sub_minor_matrice(size_mt - 1, vector<float>(size_mt - 1));

	for (int i = 0; i < size_mt; i++) {
		if (i != row_index - 1) {
			for (int j = 0; j < size_mt; j++) {
				if (j != column_index - 1) { my_sub_minor_matrice[x][y] = matrix[i][j]; y++; }
				else { }
			}
			x++,y=0;
		}
		else {}
	}
	return my_sub_minor_matrice;
}
vector<vector<int>>MATRICE_V2::SQUARE_MATRICE::sub_minor_matrice(vector<vector<int>> matrix, unsigned short row_index, unsigned short column_index) {
	
	unsigned short x = 0, y = 0;
	vector my_sub_minor_matrice(size_mt - 1, vector<int>(size_mt - 1));

	for (int i = 0; i < size_mt; i++) {
		if (i != row_index - 1) {
			for (int j = 0; j < size_mt; j++) {
				if (j != column_index - 1) { my_sub_minor_matrice[x][y] = matrix[i][j]; y++; }
				else {}
			}
			x++, y = 0;
		}
		else {}
	}
	return my_sub_minor_matrice;
}
vector<vector<double>>MATRICE_V2::SQUARE_MATRICE::sub_minor_matrice(vector<vector<double>> matrix, unsigned short row_index, unsigned short column_index) {

	unsigned short x = 0, y = 0;
	vector my_sub_minor_matrice(size_mt - 1, vector<double>(size_mt - 1));

	for (int i = 0; i < size_mt; i++) {
		if (i != row_index - 1) {
			for (int j = 0; j < size_mt; j++) {
				if (j != column_index - 1) { my_sub_minor_matrice[x][y] = matrix[i][j]; y++; }
				else {}
			}
			x++, y = 0;
		}
		else {}
	}
	return my_sub_minor_matrice;
}
vector<vector<long>>MATRICE_V2::SQUARE_MATRICE::sub_minor_matrice(vector<vector<long>> matrix, unsigned short row_index, unsigned short column_index) {

	unsigned short x = 0, y = 0;
	vector my_sub_minor_matrice (size_mt-1, vector<long>(size_mt-1));

	for (int i = 0; i < size_mt; i++) {
		if (i != row_index - 1) {
			for (int j = 0; j < size_mt; j++) {
				if (j != column_index - 1) { my_sub_minor_matrice[x][y] = matrix[i][j]; y++; }
				else {}
			}
			x++, y = 0;
		}
		else {}
	}
	return my_sub_minor_matrice;
}



any MATRICE_V2::SQUARE_MATRICE::determinant() {
	if(typeid(vector<vector<int>>)==type_vector.type()){
		return determinant(any_cast<vector<vector<int>>>(type_vector));
	}
	else if(typeid(vector<vector<float>>) == type_vector.type()){
		return determinant(any_cast<vector<vector<float>>>(type_vector));
	}
	else if(typeid(vector<vector<double>>) == type_vector.type()){
		return determinant(any_cast<vector<vector<double>>>(type_vector));
	}
	else if(typeid(vector<vector<long>>) == type_vector.type()){
		return determinant(any_cast<vector<vector<long>>>(type_vector));
	}
	else { cout << "Unknown type of square matrice"; }
}
float MATRICE_V2::SQUARE_MATRICE::determinant(vector<vector<float>> matrix){
	float value = 0;
	if (size_mt == 1) {
		return matrix[0][0];
	}
	else if (size_mt == 2) {
		return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
	}
	else {
		for (int i = 0; i < size_mt; i++) {
			auto my_sub_matrice = sub_minor_matrice(1,i+1);
			SQUARE_MATRICE my_volatile_matrice(any_cast<vector<vector<float>>>(my_sub_matrice));
			if (i % 2 == 0) { value+=matrix[0][i] * any_cast<float>(my_volatile_matrice.determinant()); }
			else {value-= matrix[0][i] * any_cast<float>(my_volatile_matrice.determinant());}
		}
	}
	return value;
}
float MATRICE_V2::SQUARE_MATRICE::determinant(vector<vector<int>> matrix){
	float value = 0;
	if (size_mt == 1) {
		return matrix[0][0];
	}
	else if (size_mt == 2) {
		return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
	}
	else {
		for (int i = 0; i < size_mt; i++) {
			auto my_sub_matrice = sub_minor_matrice(1, i + 1);
			SQUARE_MATRICE my_volatile_matrice(any_cast<vector<vector<int>>>(my_sub_matrice));
			if (i % 2 == 0) { value += matrix[0][i] * any_cast<float>(my_volatile_matrice.determinant()); }
			else { value -= matrix[0][i] * any_cast<float>(my_volatile_matrice.determinant()); }
		}
	}
	return value;
}
double MATRICE_V2::SQUARE_MATRICE::determinant(vector<vector<double>> matrix){
	double value = 0;
	if (size_mt == 1) {
		return matrix[0][0];
	}
	else if (size_mt == 2) {
		return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
	}
	else {
		for (int i = 0; i < size_mt; i++) {
			auto my_sub_matrice = sub_minor_matrice(1, i + 1);
			SQUARE_MATRICE my_volatile_matrice(any_cast<vector<vector<double>>>(my_sub_matrice));
			if (i % 2 == 0) { value += matrix[0][i] * any_cast<double>(my_volatile_matrice.determinant()); }
			else { value -= matrix[0][i] * any_cast<double>(my_volatile_matrice.determinant()); }
		}
	}
	return value;
}
double MATRICE_V2::SQUARE_MATRICE::determinant(vector<vector<long>> matrix){
	double value = 0;
	if (size_mt == 1) {
		return matrix[0][0];
	}
	else if (size_mt == 2) {
		return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
	}
	else {
		for (int i = 0; i < size_mt; i++) {
			auto my_sub_matrice = sub_minor_matrice(1,i+1);
			SQUARE_MATRICE my_volatile_matrice(any_cast<vector<vector<long>>>(my_sub_matrice));
			if (i % 2 == 0) { value+=matrix[0][i] * any_cast<double>(my_volatile_matrice.determinant()); }
			else {value-= matrix[0][i] * any_cast<double>(my_volatile_matrice.determinant());}
		}
	}
	return value;
}

any MATRICE_V2::SQUARE_MATRICE::minor_value(size_t index_row, size_t index_column) {
	if (type == 'I') {
		auto sub_matrice = any_cast<vector<vector<int>>>(sub_minor_matrice(index_row, index_column)); 
		SQUARE_MATRICE int_type(sub_matrice); 
		return(int_type.determinant());
	}
	else if (type == 'L') {
		auto sub_matrice = any_cast<vector<vector<long>>>(sub_minor_matrice(index_row, index_column)); 
		SQUARE_MATRICE long_type(sub_matrice); 
		return(long_type.determinant());
	}
	else if (type == 'F') {
		auto sub_matrice = any_cast<vector<vector<float>>>(sub_minor_matrice(index_row, index_column)); 
		SQUARE_MATRICE float_type(sub_matrice); 
		return(float_type.determinant());
	}
	else if (type == 'D') {
		auto sub_matrice = any_cast<vector<vector<double>>>(sub_minor_matrice(index_row, index_column)); 
		SQUARE_MATRICE double_type(sub_matrice); 
		return(double_type.determinant());
	}
	else {
		cout << "Unknown Type";
	}
	
}
any MATRICE_V2::SQUARE_MATRICE::minor_matrice() {
	if (type == 'I') {
		vector sub_matrice(size_mt, vector<float>(size_mt));
		for (int i = 0; i < size_mt; i++) {
			for (int j = 0; j < size_mt; j++) {
				sub_matrice[i][j]=any_cast<float>(minor_value(i+1,j+1));
			}
		}
		return sub_matrice;
	}
	else if (type == 'L') {
		vector sub_matrice(size_mt, vector<double>(size_mt));
		for (int i = 0; i < size_mt; i++) {
			for (int j = 0; j < size_mt; j++) {
				sub_matrice[i][j] = any_cast<double>(minor_value(i+1, j+1));
			}
		}
		return sub_matrice;
	}
	else if (type == 'F') {
		vector sub_matrice(size_mt, vector<float>(size_mt));
		for (int i = 0; i < size_mt; i++) {
			for (int j = 0; j < size_mt; j++) {
				sub_matrice[i][j] = any_cast<float>(minor_value(i+1, j+1));
			}
		}
		return sub_matrice;
	}
	else if (type == 'D') {
		vector sub_matrice(size_mt, vector<double>(size_mt));
		for (int i = 0; i < size_mt; i++) {
			for (int j = 0; j < size_mt; j++) {
				sub_matrice[i][j] = any_cast<double>(minor_value(i+1, j+1));
			}
		}
		return sub_matrice;
	}
	else {
		cout << "Unknown Type";
	}
}

any MATRICE_V2::SQUARE_MATRICE::cofactor_matrice() {
	if (type == 'I') {
		vector cof_matrice(size_mt, vector<float>(size_mt));
		for (int i = 0; i < size_mt; i++) {
			for (int j = 0; j < size_mt; j++) {
				if ((i + j) % 2 == 0) { cof_matrice[i][j] = any_cast<float>(minor_value(i + 1, j + 1)); }
				else { cof_matrice[i][j] = -1 * any_cast<float>(minor_value(i + 1, j + 1)); }
			}
		}
		return cof_matrice;
	}
	else if (type == 'L') {
		vector cof_matrice(size_mt, vector<double>(size_mt));
		for (int i = 0; i < size_mt; i++) {
			for (int j = 0; j < size_mt; j++) {
				if ((i + j) % 2 == 0) { cof_matrice[i][j] = any_cast<double>(minor_value(i + 1, j + 1)); }
				else { cof_matrice[i][j] = -1 * any_cast<double>(minor_value(i + 1, j + 1)); }
			}
		}
		return cof_matrice;
	}
	else if (type == 'F') {
		vector cof_matrice(size_mt, vector<float>(size_mt));
		for (int i = 0; i < size_mt; i++) {
			for (int j = 0; j < size_mt; j++) {
				if ((i + j) % 2 == 0) {cof_matrice[i][j] = any_cast<float>(minor_value(i + 1, j + 1));}
				else {cof_matrice[i][j] = -1 * any_cast<float>(minor_value(i + 1, j + 1));}
			}
		}
		return cof_matrice;
	}
	else if (type == 'D') {
		vector cof_matrice(size_mt, vector<double>(size_mt));
		for (int i = 0; i < size_mt; i++) {
			for (int j = 0; j < size_mt; j++) {
				if ((i + j) % 2 == 0) {cof_matrice[i][j] = any_cast<double>(minor_value(i + 1, j + 1));}
				else {cof_matrice[i][j] = -1* any_cast<double>(minor_value(i + 1, j + 1));}
			}
		}
		return cof_matrice;
	}
	else {
		cout << "Unknown Type";
	}
}

any MATRICE_V2::SQUARE_MATRICE::adjugate_matrice() {
	if (type == 'I') {
		SQUARE_MATRICE my_volatile(any_cast<vector<vector<float>>>(cofactor_matrice()));
		return my_volatile.transpose();
	}
	else if (type == 'L') {
		SQUARE_MATRICE my_volatile(any_cast<vector<vector<double>>>(cofactor_matrice()));
		return my_volatile.transpose();
	}
	else if (type == 'F') {
		SQUARE_MATRICE my_volatile(any_cast<vector<vector<float>>>(cofactor_matrice()));
		return my_volatile.transpose();
	}
	else if (type == 'D') {
		SQUARE_MATRICE my_volatile(any_cast<vector<vector<double>>>(cofactor_matrice()));
		return my_volatile.transpose();
	}
	else {
		cout << "Unknown Type";
	}
}
any MATRICE_V2::SQUARE_MATRICE::inverse_matrice() {
	if (type == 'I') {
		auto value = 1/(any_cast<float>(determinant()));
		SQUARE_MATRICE my_volatile(any_cast<vector<vector<float>>>(adjugate_matrice()));
		return my_volatile.scaler_multiplication(value);
	}
	else if (type == 'L') {
		auto value = 1/(any_cast<double>(determinant()));
		SQUARE_MATRICE my_volatile(any_cast<vector<vector<double>>>(adjugate_matrice()));
		return my_volatile.scaler_multiplication(value);
	}
	else if (type == 'F') {
		auto value = 1/(any_cast<float>(determinant()));
		SQUARE_MATRICE my_volatile(any_cast<vector<vector<float>>>(adjugate_matrice()));
		return my_volatile.scaler_multiplication(value);
	}
	else if (type == 'D') {
		auto value =1/(any_cast<double>(determinant()));
		SQUARE_MATRICE my_volatile(any_cast<vector<vector<double>>>(adjugate_matrice()));
		return my_volatile.scaler_multiplication(value);
	}
	else {
		cout << "Unknown Type";
	}
}