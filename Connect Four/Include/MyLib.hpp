#if !defined( GUARD_MY_LIB )
#define GUARD_MY_LIB

#if defined(_DEBUG) && !defined(_DLL)
#pragma comment (lib, "MyLib-mt-s-gd.lib")
#elif defined(_DEBUG) && defined(_DLL)
#pragma comment (lib, "MyLib-mt-gd.lib")
#elif !defined(_DEBUG) && !defined(_DLL)
#pragma comment (lib, "MyLib-mt-s.lib")
#elif !defined(_DEBUG) && defined(_DLL)
#pragma comment (lib, "MyLib-mt.lib")
#endif

#include <string>

std::string bit_string( char const * p, unsigned nBytes );

template <typename T_> inline std::string bit_string( T_ const & var ) {
	return bit_string( reinterpret_cast<char const*>( &var ), sizeof(var) );
}

template <typename BYTE_> inline BYTE_ low_nibble( BYTE_ const byte ) {
	return byte  &  0x0f;
}

template <typename BYTE_> inline BYTE_ high_nibble( BYTE_ const byte ) {
	return byte >> 4 & 0x0f;
}


unsigned bit_count( char const * p, unsigned nBytes );
unsigned bit_count( unsigned );
template <typename T_> inline unsigned bit_count( T_ const & var ) {
	if( sizeof(var) == 4 )
		return bit_count( *reinterpret_cast<unsigned const*>( &var ) );
	return bit_count( reinterpret_cast<char const*>( &var ), sizeof(var) );
}




#endif