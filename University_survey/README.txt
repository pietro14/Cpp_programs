
The material in this folder is the result of a simple C++ project
aimed at calculating the determinant of a square matrix 


FOLDER CONTENT:

- header folder: in this folder are saved the header file: "permutation_sign.h" for
		 calculating the sign of a permutation, and "Matrix.h" which 			 
		 is the header file for Matrix class;

- test_determinant_by_Leibinz.cpp: this main program tests the method Matrix::LU() implemented
			           in "Matrix.h", which uses the Leibniz formula for calculating the determinant

- test_determinant_by_LU.cpp: this main program tests the method Matrix::LU() implemented
			      in "Matrix.h", which uses the LU decomposition for calculating the determinant

- test_execution_time.cpp: this main program tests the execution time of method Matrix::determinant_by_Leibinz()
			   implemented in "Matrix.h"

- execution_time_data.dat: the data elaborated by "test_execution_time.cpp" are stored in this file

- fit_execution_time.C: this ROOT macro uses the data stored in "execution_time_data.dat" to confirm
			the expected factorial increasing of the execution time, when using the method
                        Matrix::determinant_by_Leibniz()
