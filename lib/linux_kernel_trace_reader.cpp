#include "linux_kernel_trace_reader.h"


uint64_t bitshift(std::string const& value)
{
	uint64_t result = 0;
	char const* p;
	char const* q;

	if (value.empty()) {
		return 0;
	}

	if (!(value.find_first_not_of("0123456789") == std::string::npos)) {
		return 0;
	}

	if (value.size() > 64) {
		return 0;
	}

	p = value.c_str();
	q = p + value.size();

	while (p < q) {
		result = (result << 1) + (result << 3) + *(p++) - '0';
	}

	return result;
}

std::ostream& operator<<(std::ostream& os, const cr0_t &cr0)
{
	int bit;

	os << "CR0: " << cr0.val << "\n";
	for (bit = 63; bit >= 0; bit--) {
		os << ((cr0.val >> bit) & 1);
	}
	os << "\n";

	os << "reserved MBZ: 		";
	for (bit = 31; bit >= 0; bit--) {
		os << ((cr0.reserved_MBZ >> bit) & 1);
	}
	os << "\n";

	os << "Paging:			" << cr0.PG << "\n";
	os << "Cache disable: 		" << cr0.CD << "\n";
	os << "Not Writethrough:	" << cr0.NW << "\n";

	os << "Reserved: 		" ;
	for (bit = 9; bit >= 0; bit--) {
		os << ((cr0.reserved1 >> bit) & 1);
	}
	os << "\n";

	os << "Alighnment Mask: 	" << cr0.AM << "\n";
	os << "Reserved: 		" << cr0.reserved2 << "\n";
	os << "Write Protect: 		" << cr0.WP << "\n";

	os << "Reserved: 		"  ;
	for (bit = 9; bit >= 0; bit--) {
		os << ((cr0.reserved3 >> bit) & 1);
	}
	os << "\n";

	os << "Numeric Error: 		" << cr0.NE << "\n";
	os << "Extention Type:		" << cr0.ET << "\n";
	os << "Task switched: 		" << cr0.TS << "\n";
	os << "Emulation: 		" << cr0.EM << "\n";
	os << "Monitor Coprocessor: 	" << cr0.MP << "\n";
	os << "Protection Enabled: 	" << cr0.PE << "\n";

	return os;
}
