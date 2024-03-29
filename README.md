# A Simple Direct-Sequence Spread Spectrum (DSSS) Solution in C++

## Included Documents
	- /include/dsss.hpp
	- /src/dsss.cpp
	- /tests/dsssTestCases.cpp
	- README.md
	
## To compile:
	
	### Open terminal point to the directory that this file is located.
	Type the following command:
	
	`./build.sh`
	
	**Note** Tests will run automatically at build

## To run:

	### Type the following command:
	
	`./tests.redmars`

## Examples:

	The user will be presented with an original sequence of bits,
	encoded bit, encoded bits with erroneous bits due to a 10% 
	error applied, and the decoded bit sequence.
	
	The original sequence can be modified in the source code of 
	dsss.c in the main() portion of the program. It is labelled
	as 's' under "test cases". The value of error can also be 
	modified in this section as well. 
	
	For any info on how the functions work, please refer to the
	header file as all descriptions are written above each func-
	tion header.
