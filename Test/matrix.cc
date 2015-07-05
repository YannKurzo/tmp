
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

#define THROW(str) throw runtime_error(str);

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
    // Init
    nbLines_m = matrix.nbLines_m;
    nbColumns_m = matrix.nbColumns_m;
    
    n_m = vector<vector<calculType_t> >(nbLines_m);
    
    for(unsigned int i=0;i<nbLines_m;++i)
    {
        n_m.at(i) = vector<calculType_t>(nbColumns_m);
        
        for(unsigned int j=0;j<nbColumns_m;++j)
        {
            n_m.at(i).at(j) = matrix.n_m.at(i).at(j);
        }
    }
}

void Matrix::init(const std::string& str)
{
    // Init string
    n_m = vector<vector<calculType_t> >(0);
    str_m = str.substr(1, str.size()-2);
    
    // Get number of lines
    nbLines_m = ::count(str_m.begin(), str_m.end(), ';')+1;
    
    // Variable for checking validity
    vector<unsigned int> nbNumbersPerLine = vector<unsigned int>(nbLines_m);
    
    // Init comma
    unsigned int commaFound = -1, commaBase = 0;
    
    for(unsigned int i=0;i<nbLines_m;++i)
    {
        // Get line by line
        commaFound = str_m.find(";", commaFound+1);
        string line = str_m.substr(commaBase, commaFound-commaBase);
        commaBase = commaFound+1;
        
        // Init space
        unsigned int spaceFound = -1, base = 0;
        nbColumns_m = 0;
        
        // Init first line
        n_m.push_back(vector<calculType_t>(0));
        
        for(unsigned int j=0;j<::count(line.begin(), line.end(), ' ')+1;++j)
        {
            // Get number by number
            spaceFound = line.find(" ", spaceFound+1);
            string number = line.substr(base, spaceFound-base);
            base = spaceFound+1;
            
            // Check if it is really a number
            if(number.size() > 0)
            {
                n_m.at(i).push_back(::atoi(number.c_str()));
                ++nbColumns_m;
            }
        }
        
        // Update number of numbers
        nbNumbersPerLine.at(i) = nbColumns_m;
    }
    
    // Checking matrix validity
    for(unsigned int i=0;i<nbLines_m;++i)
    {
        if(nbColumns_m != nbNumbersPerLine.at(i))
        {
            THROW("Inconsistent matrix!");
        }
    }
}

Matrix& Matrix::operator=(Matrix const& matrix)
{
    if(this != &matrix)
    {
        // Init
        nbLines_m = matrix.nbLines_m;
        nbColumns_m = matrix.nbColumns_m;

        n_m = vector<vector<calculType_t> >(nbLines_m);

        for(unsigned int i=0;i<nbLines_m;++i)
        {
            n_m.at(i) = vector<calculType_t>(nbColumns_m);

            for(unsigned int j=0;j<nbColumns_m;++j)
            {
                n_m.at(i).at(j) = matrix.n_m.at(i).at(j);
            }
        }
    }
    return *this;
}

//Matrix& Matrix::operator=(double n)
//{
//    
//    return *this;
//}

void Matrix::checkDimensions(const Matrix& matrix, matrixOperation_t op)
{
    if(op == ADD_SUB)
    {
        if(nbLines_m != matrix.nbLines_m || nbColumns_m != matrix.nbColumns_m)
        {
            THROW("Dimensions not correct!");
        }
    }
}

Matrix& Matrix::operator+=(const Matrix& matrix)
{
    checkDimensions(matrix, ADD_SUB);
    
    for(unsigned int i=0;i<nbLines_m;++i)
    {
        for(unsigned int j=0;j<nbColumns_m;++j)
        {
            n_m.at(i).at(j) += matrix.n_m.at(i).at(j);
        }
    }
    return *this;
}

Matrix& Matrix::operator+=(const calculType_t& n)
{
    for(unsigned int i=0;i<nbLines_m;++i)
    {
        for(unsigned int j=0;j<nbColumns_m;++j)
        {
            n_m.at(i).at(j) += n;
        }
    }
    return *this;
}

Matrix operator+(Matrix const& matrix1, Matrix const& matrix2)
{
    Matrix result(matrix1);
    result += matrix2;
    return result;
}

Matrix operator+(Matrix const& matrix1, const calculType_t& n)
{
    Matrix result(matrix1);
    result += n;
    return result;
}

Matrix operator+(const calculType_t& n, Matrix const& matrix2)
{
    return matrix2 + n;
}

Matrix& Matrix::operator-=(const Matrix& matrix)
{
    for(unsigned int i=0;i<nbLines_m;++i)
    {
        for(unsigned int j=0;j<nbColumns_m;++j)
        {
            n_m.at(i).at(j) -= matrix.n_m.at(i).at(j);
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const calculType_t& n)
{
    for(unsigned int i=0;i<nbLines_m;++i)
    {
        for(unsigned int j=0;j<nbColumns_m;++j)
        {
            n_m.at(i).at(j) -= n;
        }
    }
    return *this;
}

Matrix& Matrix::operator-(void)
{
    *this = 0 - *this;
    return *this;
}

Matrix operator-(Matrix const& matrix1, Matrix const& matrix2)
{
    Matrix result(matrix1);
    result -= matrix2;
    return result;
}

Matrix operator-(Matrix const& matrix1, const calculType_t& n)
{
    Matrix result(matrix1);
    result -= n;
    return result;
}

Matrix operator-(const calculType_t& n, Matrix const& matrix2)
{
    /// PROBLEM
    return matrix2 - n;
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


