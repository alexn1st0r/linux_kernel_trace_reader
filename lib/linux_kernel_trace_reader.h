#ifndef _TRACE_READER_
#define _TRACE_READER_

#include <iostream>
#include <bitset>

struct cr0_t {
	union {
		uint64_t val;
		struct {
#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
			uint64_t reserved_MBZ 	: 32;
			uint64_t PG 		: 1;
			uint64_t CD 		: 1;
			uint64_t NW 		: 1;
			uint64_t reserved1 	: 10;
			uint64_t AM		: 1;
			uint64_t reserved2	: 1;
			uint64_t WP		: 1;
			uint64_t reserved3	: 10;
			uint64_t NE		: 1;
			uint64_t ET		: 1;
			uint64_t TS		: 1;
			uint64_t EM		: 1;
			uint64_t MP		: 1;
			uint64_t PE		: 1;
#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ 
			uint64_t PE		: 1;
			uint64_t MP		: 1;
			uint64_t EM		: 1;
			uint64_t TS		: 1;
			uint64_t ET		: 1;
			uint64_t NE		: 1;
			uint64_t reserved3	: 10;
			uint64_t WP		: 1;
			uint64_t reserved2	: 1;
			uint64_t AM		: 1;
			uint64_t reserved1 	: 10;
			uint64_t NW 		: 1;
			uint64_t CD 		: 1;
			uint64_t PG 		: 1;
			uint64_t reserved_MBZ 	: 32;
#endif
		};
	};
};

uint64_t bitshift(std::string const& value);

std::ostream& operator<<(std::ostream& os, const cr0_t &cr0);

struct trace_reader_t {
	struct cr0_t cr0;
};
#endif /* _TRACE_READER_ */
