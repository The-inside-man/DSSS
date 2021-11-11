#include "../include/dsss.hpp"

using namespace std;

// Test Cases
int main(){
	// Main sequence of bits
	string original_sequence = "1001101101010010";
    string barker_bits = "110";
	
	cout << "_______________________________________________________________\n" << endl;
	
	cout << "Original Sequence \t: " << original_sequence << endl;
	
	// Encoded sequence
    string encoded_bits = encoder(original_sequence, barker_bits);
	cout << "Encoded \t\t: " << encoded_bits << endl;
	
	// Encoded sequence with 10% error
	cout << "10% Error applied \t: " << channel(encoded_bits, 10) << endl;
	
	// Decoded sequence of encoded sequence
    string decoded_bits = decoder(encoded_bits, barker_bits);
	cout << "Decoded Sequence \t: " << decoded_bits << endl;
	
	cout << "_______________________________________________________________" << endl;
}
