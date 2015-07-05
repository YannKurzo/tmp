
//  ==========================================================================
/// @file   matrix.cc
/// @author Yann Kurzo
/// @date   June 17, 2015, 8:32 PM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  
//  ==========================================================================

#include "matrix.h"

#include "util.h"

#include <iostream>
#include <algorithm>

using namespace std;

Matrix::Matrix(void)
{
    init("0");
}

Matrix::Matrix(const char *str)
{
    init(string(str));
}

Matrix::Matrix(const std::string& str)
{
    init(str);
}

Matrix::~Matrix(void)
{
    
}

Matrix::Matrix(Matrix const& matrix)
{
    
}

void Matrix::init(const std::string& str)
{
    n_m = vector<vector<calculType_t> >(0);
    str_m = str.substr(1, str.size()-2);
    
    unsigned int nbLines = ::count(str_m.begin(), str_m.end(), ';')+1;
    unsigned int commaFound = -1, commaBase = 0;
    
    for(unsigned int i=0;i<nbLines;++i)
    {
        commaFound = str_m.find(";", commaFound+1);
        unsigned int spaceFound = -1, base = 0;
        n_m.push_back(vector<calculType_t>(0));
        string line = str_m.substr(commaBase, commaFound-commaBase);
        commaBase = commaFound+1;
        
        for(unsigned int j=0;j<::count(line.begin(), line.end(), ' ')+1;++j)
        {
            spaceFound = line.find(" ", spaceFound+1);
            string number = line.substr(base, spaceFound-base);
            
            if(number.size() > 0)
            {
                n_m.at(i).push_back(::atoi(number.c_str()));
            }
            
            base = spaceFound+1;
        }
    }
}

Matrix& Matrix::operator=(Matrix const& matrix)
{
    if(this != &matrix)
    {
        
    }
    return *this;
}

Matrix& Matrix::operator=(double n)
{
    
    return *this;
}

Matrix& Matrix::operator+=(const Matrix& matrix)
{
    
    return *this;
}

Matrix operator+(Matrix const& matrix1, Matrix const& matrix2)
{
    Matrix result(matrix1);
    result += matrix2;
    return result;
}

Matrix& Matrix::operator-=(const Matrix& matrix)
{
    
    return *this;
}

Matrix operator-(Matrix const& matrix1, Matrix const& matrix2)
{
    Matrix result(matrix1);
    result -= matrix2;
    return result;
}

Matrix& Matrix::operator*=(const Matrix& matrix)
{
    
    return *this;
}

Matrix operator*(Matrix const& matrix1, Matrix const& matrix2)
{
    Matrix result(matrix1);
    result *= matrix2;
    return result;
}

Matrix& Matrix::operator/=(const Matrix& matrix)
{
    
    return *this;
}

Matrix operator/(Matrix const& matrix1, Matrix const& matrix2)
{
    Matrix result(matrix1);
    result /= matrix2;
    return result;
}

Matrix& Matrix::operator^=(const Matrix& matrix)
{
    
    return *this;
}

Matrix operator^(Matrix const& matrix1, Matrix const& matrix2)
{
    Matrix result(matrix1);
    result ^= matrix2;
    return result;
}

Matrix& Matrix::operator%=(const Matrix& matrix)
{
    
    return *this;
}

Matrix operator%(Matrix const& matrix1, Matrix const& matrix2)
{
    Matrix result(matrix1);
    result %= matrix2;
    return result;
}

void Matrix::display(std::ostream& flow) const
{
    flow << "[";
            
    for(unsigned int i=0;i<n_m.size();++i)
    {
        for(unsigned int j=0;j<n_m.at(i).size();++j)
        {
            flow << n_m.at(i).at(j);
            
            if(j<n_m.at(i).size()-1)
            {
                flow << " ";
            }
        }
        
        if(i<n_m.size()-1)
        {
            flow << ";";
        }
    }
            
    flow << "]";
}

std::ostream& operator<<(std::ostream& flow, Matrix const& n)
{
    n.display(flow);
    return flow;
}


