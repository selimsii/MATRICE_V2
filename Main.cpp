#include<iostream>
#include "MATRICE_V2.h"
#include <vector>
#include <any>

int main()
{

   vector<vector<int>> myvector = { {6,-1,3,2,4},{ -6,-1,16,9,-8},{-7,-8,-6,-1,-4},{-3,-2,-11,4,-12},{-7,-1,8,3,-17} };
   MATRICE_V2::SQUARE_MATRICE mymatrice(myvector);


   //determinant value of int type vector is returned as float type inside any type, you can take the value by using any_cast
   cout<< any_cast<float>(mymatrice.determinant());
   
   

    return 0;
}