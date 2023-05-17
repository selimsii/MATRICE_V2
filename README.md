***********************************************************************************************************************************************************************
**Written by: Selim Can ÖVÜR**

**IDE:Visual Studio 2022**

**Operating System:Windows 10 Pro For Workstations**

**C++ Language Standard:ISO C++17 Standard (/std:c++17)**
***********************************************************************************************************************************************************************

# MATRICE LIBRARY V2:

  **The library works as follows:**
  
1) MATRICE class takes only 4 types of one input as vector inside a vector such as: vector<vector<(int)>>, vector<vector<float>>, vector< vector <long> >, vector<vector<double>>

2) SQUARE_MATRICE class inherits from the MATRICE class, and only some certain types of functions are available for MATRICE class 
(denoted as:**random(),transpose(),scaler_multiplication(),vectoral_multiplication(),elementwise_multiplication(),elementwise_division(),summation())** rest of the functions are only availabe for SQUARE_MATRICE class since these require to be an square matrice.

3) Apart from only the __"determinant()"__ function, each function returns __"any"__ type which can have the following types inside: vector<vector<int>>, vector<vector<float>>, vector<vector<long>>, vector<vector<double>>. These vectors can be assigned to new vectors in main by simply using "any_cast<vector<vector<double>>>object.function()".

4) __"determinant()"__  function also returns any type but this time the "any" type may have the following types inside since its not an vector of matrice: float, double. These values can be assigned to new vectors in main by simply using "std::any_cast<float>object.determinant()" or "std::any_cast<double>object.determinant()".

5) When you create new object with vector<vector<int>> or vector<vector<long>> the object functions may return vector<vector<float>> or vector<vector<double>> to prevent data loss due to matrice operations.
(Such as elementwise_division() or inverse_matrice())

6) Matrice size is not restricted with a finite number. Operations are available for any mxn sized vectors of matrice
  
7) MATRICE_V2 namespace is used in the library. 

  **Includes the following functions in MATRICE Class:**
 - Random Function (To fill the empty vector matrice with random values between +- input)<br>
 - Matrice Transpose <br>
 - Scaler Multiplication <br>
 - Vectoral Multiplication <br>
 - Elementwise Multiplication <br>
 - Elementwise Division <br>
 - Summation <br>
 - Subtraction <br>
 - Sub Minor Matrice (   (m-1)x(n-1) sub minor matrice of a mxn matrice  ) <br>
 - Minor Value ( Minor Value of Sub Minor Matrice ) <br>
 - Minor Matrice ( The matrice consisting of all possible minor values ) <br>
 - Determinant <br>
 - Cofactor Matrice <br>
 - Adjugate Matrice <br>
 - Inverse Matrice <br>

**The sample code that shows the result of determinant of 5x5 vector of matrice is given below**:

```
#include<iostream>
#include "MATRICE_V2.h"
#include <vector>
#include <any>

int main()
{

   vector<vector<int>> myvector = { {6,-1,3,2,4},{ -6,-1,16,9,-8},{-7,-8,-6,-1,-4},{-3,-2,-11,4,-12},{-7,-1,8,3,-17} };
   MATRICE_V2::SQUARE_MATRICE mymatrice(myvector);


   //determinant value of int type vector is returned as float type inside any type, you can take the value by using any_cast
   cout<< "The determinant value is:" << any_cast<float>(mymatrice.determinant()) << endl;
   
   

    return 0;
}
```
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
