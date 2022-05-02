#include <iostream>
#include <vector>
#include <algorithm>
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "lib/linux_kernel_trace_reader.h"

namespace {


class CR0Test : public ::testing::Test { 

protected:
	CR0Test() {
	}

	virtual ~CR0Test() {
	}

	virtual void SetUp() {
	}

	virtual void TearDown() {
	}
};

TEST(CR0Test, TestCR0RealValue)
{
	/*
	 * CR0: 80050033
	 * 0000000000000000000000000000000000000100110001010111011101110001
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.val, 0x80050033);
}

TEST(CR0Test, TestCR0ReservedMBZValue)
{
	/*
	 * CR0: 80050033
	 * reserved MBZ: 	00000000000000000000000000000000
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.reservedMBZ, 0);
}

TEST(CR0Test, TestCR0PagingValue)
{
	/*
	 * CR0: 80050033
	 * Paging:		0
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.PG, 1);
}

TEST(CR0Test, TestCR0CacheDisableValue)
{
	/*
	 * CR0: 80050033
	 * Cache disable: 	0
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.CD, 0);
}

TEST(CR0Test, TestCR0NotWritethroughValue)
{
	/*
	 * CR0: 80050033
	 * Not Writethrough:	0
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.NW, 0);
}

TEST(CR0Test, TestCR0Reserved1Value)
{
	/*
	 * CR0: 80050033
	 * Reserved: 		0010011000
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.reserved1, 0);
}

TEST(CR0Test, TestCR0AlighnmentMaskValue)
{
	/*
	 * CR0: 80050033
	 * Alighnment Mask: 	1
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.AM, 1);
}

TEST(CR0Test, TestCR0Reserved2Value)
{
	/*
	 * CR0: 80050033
	 * Reserved: 		0
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.reserved2, 0);
}

TEST(CR0Test, TestCR0WriteProtectValue)
{
	/*
	 * CR0: 80050033
	 * Write Protect: 	1
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.WP, 1);
}

TEST(CR0Test, TestCR0Reserved3Value)
{
	/*
	 * CR0: 80050033
	 * Reserved: 		0111011101
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.reserved3, 0);
}

TEST(CR0Test, TestCR0NumericErrorValue)
{
	/*
	 * CR0: 80050033
	 * Numeric Error: 	1
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.NE, 1);
}

TEST(CR0Test, TestCR0ExtentionTypeValue)
{
	/*
	 * CR0: 80050033
	 * Extention Type:	1
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.ET, 1);
}

TEST(CR0Test, TestCR0TaskSwitchedValue)
{
	/*
	 * CR0: 80050033
	 * Task switched: 	0
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.TS, 0);
}

TEST(CR0Test, TestCR0EmulationValue)
{
	/*
	 * CR0: 80050033
	 * Emulation: 		0
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.EM, 0);
}

TEST(CR0Test, TestCR0MonitorCoprocessorValue)
{
	/*
	 * CR0: 80050033
	 * Monitor Coprocessor:	0
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.MP, 1);
}

TEST(CR0Test, TestCR0ProtectionEnabledValue)
{
	/*
	 * CR0: 80050033
	 * Protection Enabled: 	1
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.PE, 1);
}


class CR2Test : public ::testing::Test { 

protected:
	CR2Test() {
	}

	virtual ~CR2Test() {
	}

	virtual void SetUp() {
	}

	virtual void TearDown() {
	}
};

TEST(CR2Test, TestCR2RealValue)
{
	/*
	 * CR2: 0x7ffde15c9ec9
	 * 0000000000000000011111111111110111100001010111001001111011001001
	 */
	struct cr2_t cr2;
	cr2.val = 0x00007ffde15c9ec9;

	ASSERT_EQ(cr2.val, 0x00007ffde15c9ec9);
}


class CR3Test : public ::testing::Test { 

protected:
	CR3Test() {
	}

	virtual ~CR3Test() {
	}

	virtual void SetUp() {
	}

	virtual void TearDown() {
	}
};

TEST(CR3Test, TestCR3RealValue)
{
	/*
	 * CR3: 9458004
	 * 0000000000000000000000000000000000001001010001011000000000000100
	 */
	struct cr3_t cr3;
	cr3.val = 0x0000000009458004;

	ASSERT_EQ(cr3.val, 0x0000000009458004);
}

TEST(CR3Test, TestCR3ReservedMBZ)
{
	/*
	 * CR3: 9458004
	 * 0000000000000000000000000000000000001001010001011000000000000100
	 */
	struct cr3_t cr3;
	cr3.val = 0x0000000009458004;

	ASSERT_EQ(cr3.reservedMBZ, 0);
}

TEST(CR3Test, TestCR3PageMapLevel4TableBaseAddress)
{
	/*
	 * CR3: 9458004
	 * 0000000000000000000000000000000000001001010001011000000000000100
	 */
	struct cr3_t cr3;
	cr3.val = 0x0000000009458004;

	ASSERT_EQ(cr3.PageMapLevel4TableBaseAddress, 0x9458);
}

TEST(CR3Test, TestCR3ProcessorContextId)
{
	/*
	 * CR3: 9458004
	 * 0000000000000000000000000000000000001001010001011000000000000100
	 */
	struct cr3_t cr3;
	cr3.val = 0x0000000009458004;

	ASSERT_EQ(cr3.ProcessorContextId, 0x4);
}


class CR4Test : public ::testing::Test { 

protected:
	CR4Test() {
	}

	virtual ~CR4Test() {
	}

	virtual void SetUp() {
	}

	virtual void TearDown() {
	}
};

TEST(CR4Test, TestCR4RealValue)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.val, 0x00000000001706e0);
}

TEST(CR4Test, TestCR4ReservedMBZ)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.reservedMBZ, 0);
}

TEST(CR4Test, TestCR4ControlFlowEnforcementTechnology)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.CET, 0);
}

TEST(CR4Test, TestCR4ProtectionKeyEnable)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.PKE, 0);
}

TEST(CR4Test, TestCR4SupervisorModeAccessProtection)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.SMAP, 0);
}

TEST(CR4Test, TestCR4SupervisorModeExecutionPrevention)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.SMEP, 1);
}

TEST(CR4Test, TestCR4Reserved)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.reserved1, 0);
}

TEST(CR4Test, TestCR4XSAVEAndProcessorExtendedStatesEnableBit)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.OSXSAVE, 1);
}

TEST(CR4Test, TestCR4ProcessContextIdentifierEnable)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.PCIDE, 1);
}

TEST(CR4Test, TestCR4FSGSBASE)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.FSGSBASE, 1);
}

TEST(CR4Test, TestCR4Reserved2)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.reserved2, 0);
}

TEST(CR4Test, TestCR4UserModeInstructionPrevention)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.UMIP, 0);
}

TEST(CR4Test, TestCR4OperatingSystemUnmaskedExceptionSupport)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.OSXMMEXCPT, 1);
}

TEST(CR4Test, TestCR4OperatingSystemFXSAVEFXRSTORSupport)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.OSFXSR, 1);
}

TEST(CR4Test, TestCR4PerformanceMonitoringCounterEnable)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.PCE, 0);
}

TEST(CR4Test, TestCR4PageGlobalEnable)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.PGE, 1);
}

TEST(CR4Test, TestCR4MachineCheckEnable)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.MCE, 1);
}

TEST(CR4Test, TestCR4PhysicalAddressExtension)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.PAE, 1);
}

TEST(CR4Test, TestCR4PageSizeExtension)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.PSE, 0);
}

TEST(CR4Test, TestCR4DebuggingExtensions)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.PSE, 0);
}

TEST(CR4Test, TestCR4TimeStampDisable)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.TSD, 0);
}

TEST(CR4Test, TestCR4ProtectedModeVirtualInterrupts)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.PVI, 0);
}

TEST(CR4Test, TestCR4Virtual8086ModeExtensions)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.VME, 0);
}

};

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
