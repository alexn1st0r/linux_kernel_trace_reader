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

struct cr2_t {
	uint64_t val;
};

struct cr3_t {
	union {
		uint64_t val;
		struct {
#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
			uint64_t reserved_MBZ 			: 12;
			uint64_t PageMapLevel4TableBaseAddress 	: 40;
			union {
				uint64_t ProcessorContextId	: 12;
				struct {
					uint64_t Reserved1	: 7;
					uint64_t PCD		: 1;
					uint64_t PWT		: 1;
					uint64_t Reserved2	: 3;
				};
			};
#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ 
			union {
				uint64_t ProcessorContextId	: 12;
				struct {
					uint64_t Reserved1	: 7;
					uint64_t PCD		: 1;
					uint64_t PWT		: 1;
					uint64_t Reserved2	: 3;
				};
			};
			uint64_t PageMapLevel4TableBaseAddress 	: 40;
			uint64_t reserved_MBZ 	: 12;
#endif
		};
	};
};

std::ostream& operator<<(std::ostream& os, const cr0_t &cr0);
std::ostream& operator<<(std::ostream& os, const cr2_t &cr2);
std::ostream& operator<<(std::ostream& os, const cr3_t &cr3);

struct trace_reader_t {
	struct cr0_t cr0;
	struct cr2_t cr2;
	struct cr3_t cr3;
};
#endif /* _TRACE_READER_ */
