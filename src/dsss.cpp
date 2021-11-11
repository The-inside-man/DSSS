//////////////////////////////////////////
//	Name:			Jacob Brown			//
//	Title:			DSSS				//
//	Updated:		26 February 2016	//
//////////////////////////////////////////

// Included headers
#include "../include/dsss.hpp"

// Namespace being used
using namespace std; 

/*	encoder takes in an input sequence of data
	bits and a Barker code and returns an output
	of the corresponding DSSS sequence bits */
string encoder(string seq, string bcode){
	// New sequence that will be returned
	string new_seq = "";
	
	// We iterate through the sequence of data bits
	for(unsigned int i = 0; i < seq.length(); i ++){
		
		/*	We need to iterate through the barker code
			xoring it with each bit of the sequence. */
		for(unsigned int j = 0; j < bcode.length(); j ++){
			
			// We add the new bits to the new sequence
			new_seq += x_or(seq[i], bcode[j]);
		}
	}
	
	// We then return the new sequence 
	return new_seq;
}

/*	channel takes an input sequence of data
	bits and a bit error rate which in turn 
	returns a sequence of erroneous data bits */
string channel(string seq, int err){
	// New sequence that will be returned
	string new_seq = "";
	
	// Seed the random number generator
	srand(time(0));

	// Determine number of bits to change
	int num_bits_to_chng = seq.length() * err / 100;
	
	// Array to store indexes of positions to change
	vector<int> positions;
	
	// generate our positions vector
	for(unsigned int i = 0; i < num_bits_to_chng; i ++){
		
		// Choose a position to place it in sequence
		int pos = rand() % seq.length();
		
		// Determine if we have already altered this bit with erroneous data
		while(find(positions.begin(), positions.end(), pos) != positions.end()){
			// if we have found it we need to pick a new position to change
			pos = rand() % seq.length();
		}
		
		// Add the position to the array
		positions.push_back(pos);
	}
	
	for(unsigned int i = 0; i < seq.length(); i ++){
		/* 	check to see if the position in the sequence is 
			one we chose to modify */
		if(find(positions.begin(), positions.end(), i) != positions.end()){
			/* 	To guarantee error we simply flip the
				bits from either 1 or a 0 */
			if(seq[i] == '1'){
				new_seq += "0";
			}else{
				new_seq += "1";
			}
		}else{
			new_seq += seq[i];
		}
		
	}
	
	// Return the new sequence of bits
	return new_seq;
}

/*	decoder take an input sequence of data
	bits and a Barker code and returns the
	decoded sequence of data bits. */
string decoder(string seq, string bcode){
	// New sequence that will be returned
	string new_seq = "";
	
	// Counter to keep track of Barker Code bits
	int ctr = 0;
	
	// Sum int to keep track of totals for barker codes
	int tot = 0;
	
	// We start by iterating through the entire sequence of bits
	for(unsigned int i = 0; i < seq.length(); i ++){
		
		/*	Next we need to look at every group of three bits
			and compare those to the Barker code provided to
			decode the bits. */
		if(seq[i] == bcode[ctr]){
			// If they sequence bit matches Barker bit we add to total
			tot ++;
		}else{
			// Otherwise we subtract from total
			tot --;
		}
		
		// Move to next Barker bit
		ctr ++;
		
		// Once all Barker bits are examined we check totals and re-initialize
		if(ctr == bcode.length()){
			ctr = 0;
			if(tot == bcode.length()){
				new_seq += "0";
			}else if(tot == -bcode.length()){
				new_seq += "1";
			}
			tot = 0;	
		}
	}
	
	return new_seq;
}

/* 	X_OR function to act as a helper function */
string x_or(char x, char y){
	if(x == y){
		return "0";
	} else{
		return "1";
	}
}
