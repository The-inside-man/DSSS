#include "../include/dsss.hpp"

using namespace std;

// Test Cases
int main(){
	// Main sequence of bits
	string s = "1001101101010010";
	
	cout << "_______________________________________________________________\n" << endl;
	
	cout << "Original Sequence \t: " << s << endl;
	
	// Encoded sequence
	cout << "Encoded \t\t: " << encoder(s, "110") << endl;
	
	// Encoded sequence with 10% error
	cout << "10% Error applied \t: " << channel(encoder(s, "110"), 10) << endl;
	
	// Decoded sequence of encoded sequence
	cout << "Decoded Sequence \t: " << decoder(encoder(s, "110"), "110") << endl;
	
	cout << "_______________________________________________________________" << endl;
}
