
//  ==========================================================================
/// @file   matrix.h
/// @author Yann Kurzo
/// @date   June 17, 2015, 8:32 PM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  
//  ==========================================================================

#ifndef MATRIX_H
#define	MATRIX_H

#include "mpfrInterface.h"

#include <string>
#include <vector>

/// @brief  
class Matrix
{
    private:
        /// Used for calculation
        std::vector<std::vector<calculType_t> > n_m;
        
        std::string str_m;
        
        unsigned int nbColumns_m;
        
        unsigned int nbLines_m;
        
        typedef enum
        {
            ADD_SUB,
            MUL_DIV
        }matrixOperation_t;
        
    public:
        /// @brief  Default constructor
        Matrix(void);
        
        /// @brief  Constructor with dimensions
        Matrix(unsigned int nbLines, unsigned int nbColumns);
        
        /// @brief  Constructor from a string
        Matrix(const char *str);
        
        /// @brief  Constructor from a string
        Matrix(const std::string& str);
        
        /// @brief  Copy constructor
        Matrix(Matrix const& matrix);
        
        /// @brief  Destructor
        ~Matrix(void);
        
        /// @brief  Assignment operator
        Matrix& operator=(Matrix const& matrix);

        /// @brief  Assignment operator
        // Matrix& operator=(const calculType_t& n);
        
        /// @brief  += operator
        Matrix& operator+=(const Matrix& matrix);
        Matrix& operator+=(const calculType_t& n);
        
        /// @brief  -= operator
        Matrix& operator-=(const Matrix& matrix);
        Matrix& operator-=(const calculType_t& n);

        /// @brief  - operator (unary)
        Matrix& operator-(void);
        
        /// @brief  *= operator
        Matrix& operator*=(const Matrix& matrix);
        Matrix& operator*=(const calculType_t& n);
        
        /// @brief  /= operator
        Matrix& operator/=(const Matrix& matrix);
        
        /// @brief  ^= operator
        Matrix& operator^=(const Matrix& matrix);
        
        /// @brief  %= operator
        Matrix& operator%=(const Matrix& matrix);
        
        /// @brief  Used to display the number on standard output
        void display(std::ostream& flow) const;
        
    private:
        /// @brief  Initialize from a string
        /// @param  str String
        void init(const std::string& str);
        
        void checkDimensions(const Matrix& matrix, matrixOperation_t op);
};

/// @brief  += operator
Matrix operator+(Matrix const& matrix1, Matrix const& matrix2);
Matrix operator+(Matrix const& matrix1, const calculType_t& n);
Matrix operator+(const calculType_t& n, Matrix const& matrix2);

/// @brief  -= operator
Matrix operator-(Matrix const& matrix1, Matrix const& matrix2);
Matrix operator-(Matrix const& matrix1, const calculType_t& n);
Matrix operator-(const calculType_t& n, Matrix const& matrix2);

/// @brief  *= operator
Matrix operator*(Matrix const& matrix1, Matrix const& matrix2);
Matrix operator*(Matrix const& matrix1, const calculType_t& n);
Matrix operator*(const calculType_t& n, Matrix const& matrix2);

/// @brief  /= operator
Matrix operator/(Matrix const& matrix1, Matrix const& matrix2);

/// @brief  ^= operator
Matrix operator^(Matrix const& matrix1, Matrix const& matrix2);

/// @brief  %= operator
Matrix operator%(Matrix const& matrix1, Matrix const& matrix2);

/// @cond STANDARD_OUTPUT
std::ostream& operator<<(std::ostream& flow, Matrix const& n);
/// @endcond STANDARD_OUTPUT

#endif	/* MATRIX_H */

