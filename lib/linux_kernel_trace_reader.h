#ifndef _TRACE_READER_
#define _TRACE_READER_

#include <iostream>
#include <bitset>

struct cr0_t {
	union {
		uint64_t val;
		struct {
#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
			uint64_t reservedMBZ 	: 32;
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
			uint64_t reservedMBZ 	: 32;
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
			uint64_t reservedMBZ 			: 12;
			uint64_t PageMapLevel4TableBaseAddress 	: 40;
			uint64_t ProcessorContextId		: 12;
#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ 
			uint64_t ProcessorContextId		: 12;
			uint64_t PageMapLevel4TableBaseAddress 	: 40;
			uint64_t reservedMBZ 			: 12;
#endif
		};
	};
};


struct cr4_t {
	union {
		uint64_t val;
		struct {
#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
			uint64_t reservedMBZ 	: 40;
			uint64_t CET 		: 1;
			uint64_t PKE 		: 1;
			uint64_t SMAP 		: 1;
			uint64_t SMEP 		: 1;
			uint64_t reserved1 	: 1;
			uint64_t OSXSAVE 	: 1;
			uint64_t PCIDE 		: 1;
			uint64_t FSGSBASE	: 1;
			uint64_t reserved2 	: 4;
			uint64_t UMIP 		: 1;
			uint64_t OSXMMEXCPT	: 1;
			uint64_t OSFXSR		: 1;
			uint64_t PCE		: 1;
			uint64_t PGE		: 1;
			uint64_t MCE		: 1;
			uint64_t PAE		: 1;
			uint64_t PSE		: 1;
			uint64_t DE		: 1;
			uint64_t TSD		: 1;
			uint64_t PVI		: 1;
			uint64_t VME		: 1;
#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ 
			uint64_t VME		: 1;
			uint64_t PVI		: 1;
			uint64_t TSD		: 1;
			uint64_t DE		: 1;
			uint64_t PSE		: 1;
			uint64_t PAE		: 1;
			uint64_t MCE		: 1;
			uint64_t PGE		: 1;
			uint64_t PCE		: 1;
			uint64_t OSFXSR		: 1;
			uint64_t OSXMMEXCPT	: 1;
			uint64_t UMIP 		: 1;
			uint64_t reserved2 	: 4;
			uint64_t FSGSBASE	: 1;
			uint64_t PCIDE 		: 1;
			uint64_t OSXSAVE 	: 1;
			uint64_t reserved1 	: 1;
			uint64_t SMEP 		: 1;
			uint64_t SMAP 		: 1;
			uint64_t PKE 		: 1;
			uint64_t CET 		: 1;
			uint64_t reservedMBZ 	: 40;
#endif
		};
	};
};

struct rflags_t {
	union {
		uint64_t val;
		struct {
#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
			uint64_t reservedRAZ 	: 42;
			uint64_t ID 		: 1;
			uint64_t VIP 		: 1;
			uint64_t VIF 		: 1;
			uint64_t AC 		: 1;
			uint64_t VM 		: 1;
			uint64_t RF 		: 1;
			uint64_t reserved1 	: 1;
			uint64_t NT 		: 1;
			uint64_t IOPL 		: 2;
			uint64_t OF 		: 1;
			uint64_t DF 		: 1;
			uint64_t IF 		: 1;
			uint64_t TF 		: 1;
			uint64_t SF 		: 1;
			uint64_t ZF 		: 1;
			uint64_t reserved2 	: 1;
			uint64_t AF 		: 1;
			uint64_t reserved3 	: 1;
			uint64_t PF 		: 1;
			uint64_t reserved4 	: 1;
			uint64_t CF 		: 1;
#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ 
			uint64_t CF 		: 1;
			uint64_t reserved4 	: 1;
			uint64_t PF 		: 1;
			uint64_t reserved3 	: 1;
			uint64_t AF 		: 1;
			uint64_t reserved2 	: 1;
			uint64_t ZF 		: 1;
			uint64_t SF 		: 1;
			uint64_t TF 		: 1;
			uint64_t IF 		: 1;
			uint64_t DF 		: 1;
			uint64_t OF 		: 1;
			uint64_t IOPL 		: 2;
			uint64_t NT 		: 1;
			uint64_t reserved1 	: 1;
			uint64_t RF 		: 1;
			uint64_t VM 		: 1;
			uint64_t AC 		: 1;
			uint64_t VIF 		: 1;
			uint64_t VIP 		: 1;
			uint64_t ID 		: 1;
			uint64_t reservedRAZ 	: 42;
#endif
		};
	};
};


std::ostream& operator<<(std::ostream& os, const cr0_t &cr0);
std::ostream& operator<<(std::ostream& os, const cr2_t &cr2);
std::ostream& operator<<(std::ostream& os, const cr3_t &cr3);
std::ostream& operator<<(std::ostream& os, const cr4_t &cr4);
std::ostream& operator<<(std::ostream& os, const rflags_t &rflags);

struct trace_reader_t {
	struct cr0_t cr0;
	struct cr2_t cr2;
	struct cr3_t cr3;
	struct cr4_t cr4;
	struct rflags_t rflags;
};
#endif /* _TRACE_READER_ */
