#include <MyLib.hpp>
#include <array>


std::string bit_string( char const * p, unsigned nBytes ) {
	
	static std::array<char const*,16> const nibbles = {
		"0000", "0001", "0010", "0011",
		"0100", "0101", "0110", "0111",
		"1000", "1001", "1010", "1011",
		"1100", "1101", "1110", "1111",
	};

	std::string bin; bin.reserve( nBytes * 8 );
	p += nBytes;
	do {
		char ch = *--p;
		bin += nibbles[ high_nibble(ch) ];
		bin += nibbles[ low_nibble(ch) ];
	} while( --nBytes );
	return bin;
}



unsigned bit_count( char const * p, unsigned nBytes ) {
	unsigned cBits = 0;
	do {
		register char ch = *p++;		// register tag unnecessary today
		while( ch ) {
			ch = ch & (ch - 1);
			++cBits;
		}
	} while ( --nBytes );
	return cBits;
}


unsigned bit_count( unsigned var ) {
	unsigned cBits = 0;
	while( var ) {
		var = var & (var - 1);
		++cBits;
	}
	return cBits;
}