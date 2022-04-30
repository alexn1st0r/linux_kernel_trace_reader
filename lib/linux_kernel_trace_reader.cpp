#include "linux_kernel_trace_reader.h"


std::ostream& operator<<(std::ostream& os, const cr0_t &cr0)
{
	int bit;

	os << "CR0—Provides operating-mode controls and some processor-feature controls.\n";
	os << "CR0: " << std::hex << cr0.val << "\n";
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


std::ostream& operator<<(std::ostream& os, const cr2_t &cr2)
{
	int bit;

	os << 	"CR2—This register is used by the page-translation mechanism.\n"
		"It is loaded by the processor with the page-fault virtual address\n"
		"when a page-fault exception occurs.\n";
	os << "Page-Fault Virtual address: " << "0x" << std::hex << cr2.val << "\n";
	for (bit = 63; bit >= 0; bit--) {
		os << ((cr2.val >> bit) & 1);
	}
	os << "\n";

	return os;
}


std::ostream& operator<<(std::ostream& os, const cr3_t &cr3)
{
	int bit;

	os << "CR3—This register is also used by the page-translation mechanism.\n";
	os << "It contains the base address ofthe highest-level page-translation table,\n";
	os << "and also contains cache controls for the specified table..\n";
	os << "CR3: " << std::hex << cr3.val << "\n";

	for (bit = 63; bit >= 0; bit--) {
		os << ((cr3.val >> bit) & 1);
	}
	os << "\n";

	os << "reserved MBZ: 		";
	for (bit = 11; bit >= 0; bit--) {
		os << ((cr3.reserved_MBZ >> bit) & 1);
	}
	os << "\n";

	os << "Page-Map Level-4 Table Base Address:\n";
	for (bit = 39; bit >= 0; bit--) {
		os << ((cr3.PageMapLevel4TableBaseAddress >> bit) & 1);
	}
	os << "\n";

	os << "Processor Context Identifier:\n";
	for (bit = 11; bit >= 0; bit--) {
		os << ((cr3.ProcessorContextId >> bit) & 1);
	}
	os << "\n";

	os << "Reserved:	";
	for (bit = 6; bit >= 0; bit--) {
		os << ((cr3.Reserved1 >> bit) & 1);
	}
	os << "\n";

	os << "Page-Level Cache Disable: 		" << cr3.PCD << "\n";
	os << "Page-Level Writethrough: 		" << cr3.PWT << "\n";

	os << "Reserved:	";
	for (bit = 2; bit >= 0; bit--) {
		os << ((cr3.Reserved2 >> bit) & 1);
	}
	os << "\n";

	return os;
}
