
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
        
    public:
        /// @brief  Default constructor
        Matrix(void);
        
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
        Matrix& operator=(double n);
        
        /// @brief  += operator
        Matrix& operator+=(const Matrix& matrix);
        
        /// @brief  -= operator
        Matrix& operator-=(const Matrix& matrix);
        
        /// @brief  *= operator
        Matrix& operator*=(const Matrix& matrix);
        
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
};

/// @brief  += operator
Matrix operator+(Matrix const& matrix1, Matrix const& matrix2);

/// @brief  -= operator
Matrix operator-(Matrix const& matrix1, Matrix const& matrix2);

/// @brief  *= operator
Matrix operator*(Matrix const& matrix1, Matrix const& matrix2);

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

