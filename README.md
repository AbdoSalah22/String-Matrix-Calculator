![String_Matrix_Calculator](https://github.com/AbdoSalah22/String-Matrix-Calculator/assets/94136052/29ea3852-df28-4519-b7d9-caac7cf76813)

## Description
This project takes a string input that represents a matrix and transforms it into a 2D array and perform operations on it. Project was done initially in **C++98** that has a lot of code limitaions.

The matrix calculator that supports all necessary operations that can be done on Matrices.

## Operations
Operations that will be supported are:
- Addition
- Subtraction
- Multiplication
- Multipling Matrix by Scalar
- Transpose
- Determinant
- Inverse

## Input Format
The matrix should be entered by the user in the following format: [1 2 5, -1 8 14.2, 7.01 -18 99.3] which is the format equivalent to a 3x3 matrix as shown:

![1639947907-1f048f9fe3-Capture](https://github.com/AbdoSalah22/String-Matrix-Calculator/assets/94136052/7609ef7f-7857-42ef-b6b3-a6cd6f360c2f)

User can choose between the different operations as follows:

### Addition and Subtraction
In case of Addition: user uses '+' symbol between the two matrices as follows:

![1639948080-fcc9fd6f1f-Picture1](https://github.com/AbdoSalah22/String-Matrix-Calculator/assets/94136052/ab0e3415-7a76-46ee-8503-cea9854a49bb)

In case of subtraction: user uses ' - ' symbol between the two matrices.

### Multiplication
In case of multiplication of a matrix by a scalar, the user can begin with either the matrix or the scalar (as he wishes), with the multiplication operator between them.

![1639948435-50275d9258-Picture3](https://github.com/AbdoSalah22/String-Matrix-Calculator/assets/94136052/2b44992d-2194-46a4-895e-97db81efd914)

![1639948444-2b4b64837c-Picture4](https://github.com/AbdoSalah22/String-Matrix-Calculator/assets/94136052/be480a9b-4ffd-4f94-af23-588f6ccf9b72)

In case of multiplication of a matrix by another matrix, the input is done as similar to the addition and subtraction step.

### Transpose
In case of Transpose: user types one matrix only then enters capital ‘T’ letter as shown:

![1639950263-0d42a9d72b-Picture7](https://github.com/AbdoSalah22/String-Matrix-Calculator/assets/94136052/a38ae29d-528e-4651-9a21-460d5598ffaf)

### Determinant
In case of Determinant: user types one matrix only then enters capital ‘D’ letter, and the ouput should be shown as a number.

### Inverse
In case of Inverse: user types one matrix only then enters capital ‘I’ letter as in the case of transpose.

### Constrains
User will input string as shown previously.

Example for a 3x4 matrix, it should be witten as follows [-0.1 2 5, -1 8 14.2, 7.01 -18 99.3, 15.0 -99.24 18]

User will input the matrix of size nxm; where: `0<n<100 and 0<m<100`

The matrix will have numbers constrained by the following: each value v inside the matrix lies in the range of `-9999.999<v<9999.999`

### Notes
If the user enters a matrix in an incorrect format (other than the stated input format) your program must detect that and output the word "ERROR!" For Example:

![1639949082-8c2b40606c-Picture5](https://github.com/AbdoSalah22/String-Matrix-Calculator/assets/94136052/d9ded296-28b3-481e-9323-068630a39e07)

Your program should validate the mathematical conditions to do the different operations, for example: In addition and subtraction, both matrices should have the same dimensions. If not, your program should output an "ERROR!" message. Also, in case of multiplication for example, your program should check that the dimesions are compatible with each other and that the multiplication can take place correctly. If not, your program should output an "ERROR!" message. For Example:

![1639949316-91fc682d36-Picture6](https://github.com/AbdoSalah22/String-Matrix-Calculator/assets/94136052/366964cf-fe89-41ad-9ebb-879c20db3894)

### Output Format
The output should be a matrix of the result printed on a new line as shown previously.

Also, the error message should be in the following format: "ERROR!" on a new line as shown in the examples above.

NOTE: In the case of decimal point output, you should set the precision of the output to 2 decimal point places.


