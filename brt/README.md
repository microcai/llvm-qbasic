#brt - qBasic RunTime Library

libbrt is an QBASIC runtime. It contains built-in functions.

## brt_print

when basic program calls PRINT, compiler will insert call to brt_print.
the brt_print is decleared as

	extern "C" int brt_print( int print_into , int numargs , ... );

## string

when basic program uses string, it actually uses string_* functions defined in brt.
and string is basically implemented by C struct

<pre>
struct{
	char * data; // hold the data
	int  len; // real length
	int	capacity; // length alloced to data
}

or BASIC code

dim string
	data as long
	len as int
	capacity as int
end dim

</pre>

the construction function ( copy construct empty construct and construct from literal ) is called automantically as well as the deconstruct function.

## string <-> int autoconvertion

basic supports string <-> int autoconvertion. this is done by automantically insert call to this helper functions.


