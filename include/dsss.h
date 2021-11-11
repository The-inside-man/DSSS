//////////////////////////////////////////////////////////
//	Name:			Jacob Brown		//
//	Title:			DSSS			//
//	Updated:		26 February 2016	//
//////////////////////////////////////////////////////////


// Included Libraries
#include <iostream>			// Used for in out stream
#include <algorithm>		// Used for find method
#include <vector>			// Used for vector
#include <ctime>			// Used for time

// Functions

/*	encoder takes in an input sequence of data
	bits and a Barker code and returns an output
	of the corresponding DSSS sequence bits */
std::string encoder(std::string,std::string);

/*	channel takes an input sequence of data
	bits and a bit error rate which in turn 
	returns a sequence of erroneous data bits */
std::string channel(std::string,int err);

/*	decoder take an input sequence of data
	bits and a Barker code and returns the
	decoded sequence of data bits. */
std::string decoder(std::string,std::string);

/* 	X_OR function to act as a helper function */
std::string x_or(char,char);
