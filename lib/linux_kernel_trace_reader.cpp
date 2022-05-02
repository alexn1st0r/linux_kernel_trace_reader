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
		os << ((cr0.reservedMBZ >> bit) & 1);
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
		os << ((cr3.reservedMBZ >> bit) & 1);
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

	return os;
}


std::ostream& operator<<(std::ostream& os, const cr4_t &cr4)
{
	int bit;

	os << "This register contains additional controls for various operating-mode features.\n";
	for (bit = 63; bit >= 0; bit--) {
		os << ((cr4.val >> bit) & 1);
	}
	os << "\n";

	os << "reserved MBZ: 		";
	for (bit = 39; bit >= 0; bit--) {
		os << ((cr4.reservedMBZ >> bit) & 1);
	}
	os << "\n";

	os << "CET: 		" << cr4.CET 	<< "\n";
	os << "PKE: 		" << cr4.PKE 	<< "\n";
	os << "SMAP: 		" << cr4.SMAP 	<< "\n";
	os << "SMEP: 		" << cr4.SMEP 	<< "\n";
	os << "reserved1: 	" << cr4.reserved1 << "\n";
	os << "OSXSAVE: 	" << cr4.OSXSAVE << "\n";
	os << "PCIDE: 		" << cr4.PCIDE 	<< "\n";
	os << "FSGSBASE: 	" << cr4.FSGSBASE << "\n";
	os << "reserved2: 	" << cr4.reserved2 << "\n";
	os << "UMIP: 		" << cr4.UMIP 	<< "\n";
	os << "OSXMMEXCPT: 	" << cr4.OSXMMEXCPT << "\n";
	os << "OSFXSR: 		" << cr4.OSFXSR << "\n";
	os << "PCE: 		" << cr4.PCE 	<< "\n";
	os << "PGE: 		" << cr4.PGE 	<< "\n";
	os << "MCE: 		" << cr4.MCE 	<< "\n";
	os << "PAE: 		" << cr4.PAE 	<< "\n";
	os << "PSE: 		" << cr4.PSE 	<< "\n";
	os << "DE: 		" << cr4.DE 	<< "\n";
	os << "TSD: 		" << cr4.TSD 	<< "\n";
	os << "PVI: 		" << cr4.PVI 	<< "\n";
	os << "VME: 		" << cr4.VME 	<< "\n";

	return os;
}
