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

TEST(CR0Test, RealValue)
{
	/*
	 * CR0: 80050033
	 * 0000000000000000000000000000000000000100110001010111011101110001
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.val, 0x80050033);
}

TEST(CR0Test, ReservedMBZValue)
{
	/*
	 * CR0: 80050033
	 * reserved MBZ: 	00000000000000000000000000000000
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.reservedMBZ, 0);
}

TEST(CR0Test, PagingValue)
{
	/*
	 * CR0: 80050033
	 * Paging:		0
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.PG, 1);
}

TEST(CR0Test, CacheDisableValue)
{
	/*
	 * CR0: 80050033
	 * Cache disable: 	0
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.CD, 0);
}

TEST(CR0Test, NotWritethroughValue)
{
	/*
	 * CR0: 80050033
	 * Not Writethrough:	0
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.NW, 0);
}

TEST(CR0Test, Reserved1Value)
{
	/*
	 * CR0: 80050033
	 * Reserved: 		0010011000
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.reserved1, 0);
}

TEST(CR0Test, AlighnmentMaskValue)
{
	/*
	 * CR0: 80050033
	 * Alighnment Mask: 	1
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.AM, 1);
}

TEST(CR0Test, Reserved2Value)
{
	/*
	 * CR0: 80050033
	 * Reserved: 		0
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.reserved2, 0);
}

TEST(CR0Test, WriteProtectValue)
{
	/*
	 * CR0: 80050033
	 * Write Protect: 	1
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.WP, 1);
}

TEST(CR0Test, Reserved3Value)
{
	/*
	 * CR0: 80050033
	 * Reserved: 		0111011101
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.reserved3, 0);
}

TEST(CR0Test, NumericErrorValue)
{
	/*
	 * CR0: 80050033
	 * Numeric Error: 	1
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.NE, 1);
}

TEST(CR0Test, ExtentionTypeValue)
{
	/*
	 * CR0: 80050033
	 * Extention Type:	1
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.ET, 1);
}

TEST(CR0Test, TaskSwitchedValue)
{
	/*
	 * CR0: 80050033
	 * Task switched: 	0
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.TS, 0);
}

TEST(CR0Test, EmulationValue)
{
	/*
	 * CR0: 80050033
	 * Emulation: 		0
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.EM, 0);
}

TEST(CR0Test, MonitorCoprocessorValue)
{
	/*
	 * CR0: 80050033
	 * Monitor Coprocessor:	0
	 */
	struct cr0_t cr0;
	cr0.val = 0x0000000080050033;

	ASSERT_EQ(cr0.MP, 1);
}

TEST(CR0Test, ProtectionEnabledValue)
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

TEST(CR2Test, RealValue)
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

TEST(CR3Test, RealValue)
{
	/*
	 * CR3: 9458004
	 * 0000000000000000000000000000000000001001010001011000000000000100
	 */
	struct cr3_t cr3;
	cr3.val = 0x0000000009458004;

	ASSERT_EQ(cr3.val, 0x0000000009458004);
}

TEST(CR3Test, ReservedMBZ)
{
	/*
	 * CR3: 9458004
	 * 0000000000000000000000000000000000001001010001011000000000000100
	 */
	struct cr3_t cr3;
	cr3.val = 0x0000000009458004;

	ASSERT_EQ(cr3.reservedMBZ, 0);
}

TEST(CR3Test, PageMapLevel4TableBaseAddress)
{
	/*
	 * CR3: 9458004
	 * 0000000000000000000000000000000000001001010001011000000000000100
	 */
	struct cr3_t cr3;
	cr3.val = 0x0000000009458004;

	ASSERT_EQ(cr3.PageMapLevel4TableBaseAddress, 0x9458);
}

TEST(CR3Test, ProcessorContextId)
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

TEST(CR4Test, RealValue)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.val, 0x00000000001706e0);
}

TEST(CR4Test, ReservedMBZ)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.reservedMBZ, 0);
}

TEST(CR4Test, ControlFlowEnforcementTechnology)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.CET, 0);
}

TEST(CR4Test, ProtectionKeyEnable)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.PKE, 0);
}

TEST(CR4Test, SupervisorModeAccessProtection)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.SMAP, 0);
}

TEST(CR4Test, SupervisorModeExecutionPrevention)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.SMEP, 1);
}

TEST(CR4Test, Reserved)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.reserved1, 0);
}

TEST(CR4Test, XSAVEAndProcessorExtendedStatesEnableBit)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.OSXSAVE, 1);
}

TEST(CR4Test, ProcessContextIdentifierEnable)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.PCIDE, 1);
}

TEST(CR4Test, FSGSBASE)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.FSGSBASE, 1);
}

TEST(CR4Test, Reserved2)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.reserved2, 0);
}

TEST(CR4Test, UserModeInstructionPrevention)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.UMIP, 0);
}

TEST(CR4Test, OperatingSystemUnmaskedExceptionSupport)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.OSXMMEXCPT, 1);
}

TEST(CR4Test, OperatingSystemFXSAVEFXRSTORSupport)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.OSFXSR, 1);
}

TEST(CR4Test, PerformanceMonitoringCounterEnable)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.PCE, 0);
}

TEST(CR4Test, PageGlobalEnable)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.PGE, 1);
}

TEST(CR4Test, MachineCheckEnable)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.MCE, 1);
}

TEST(CR4Test, PhysicalAddressExtension)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.PAE, 1);
}

TEST(CR4Test, PageSizeExtension)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.PSE, 0);
}

TEST(CR4Test, DebuggingExtensions)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.PSE, 0);
}

TEST(CR4Test, TimeStampDisable)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.TSD, 0);
}

TEST(CR4Test, ProtectedModeVirtualInterrupts)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.PVI, 0);
}

TEST(CR4Test, Virtual8086ModeExtensions)
{
	/*
	 * CR4: 00000000001706e0
	 * 0000000000000000000000000000000000000000000101110000011011100000
	 */
	struct cr4_t cr4;
	cr4.val = 0x00000000001706e0;

	ASSERT_EQ(cr4.VME, 0);
}


class RFLAGSTest : public ::testing::Test { 

protected:
	RFLAGSTest() {
	}

	virtual ~RFLAGSTest() {
	}

	virtual void SetUp() {
	}

	virtual void TearDown() {
	}
};

TEST(RFLAGSTest, RealValue)
{
	/*
	 * RFLAGS: 00000000001706e0
	 * 0000000000000000000000000000000000000000000000010000001001000110
	 */
	struct rflags_t rflags;
	rflags.val = 0x00010246;

	ASSERT_EQ(rflags.val, 0x00010246);
}

TEST(RFLAGSTest, ReservedRAZ)
{
	/*
	 * RFLAGS: 00000000001706e0
	 * 0000000000000000000000000000000000000000000000010000001001000110
	 */
	struct rflags_t rflags;
	rflags.val = 0x00010246;

	ASSERT_EQ(rflags.reservedRAZ, 0);
}

TEST(RFLAGSTest, ProcessorFeatureIdentificationBit)
{
	/*
	 * RFLAGS: 00000000001706e0
	 * 0000000000000000000000000000000000000000000000010000001001000110
	 */
	struct rflags_t rflags;
	rflags.val = 0x00010246;

	ASSERT_EQ(rflags.ID, 0);
}

TEST(RFLAGSTest, VirtualInterruptPending)
{
	/*
	 * RFLAGS: 00000000001706e0
	 * 0000000000000000000000000000000000000000000000010000001001000110
	 */
	struct rflags_t rflags;
	rflags.val = 0x00010246;

	ASSERT_EQ(rflags.VIP, 0);
}

TEST(RFLAGSTest, VirtualInterruptBit)
{
	/*
	 * RFLAGS: 00000000001706e0
	 * 0000000000000000000000000000000000000000000000010000001001000110
	 */
	struct rflags_t rflags;
	rflags.val = 0x00010246;

	ASSERT_EQ(rflags.VIF, 0);
}

TEST(RFLAGSTest, AlignmentCheckBit)
{
	/*
	 * RFLAGS: 00000000001706e0
	 * 0000000000000000000000000000000000000000000000010000001001000110
	 */
	struct rflags_t rflags;
	rflags.val = 0x00010246;

	ASSERT_EQ(rflags.AC, 0);
}

TEST(RFLAGSTest, Virtual8086ModeBit)
{
	/*
	 * RFLAGS: 00000000001706e0
	 * 0000000000000000000000000000000000000000000000010000001001000110
	 */
	struct rflags_t rflags;
	rflags.val = 0x00010246;

	ASSERT_EQ(rflags.VM, 0);
}

TEST(RFLAGSTest, ResumeFlagBit)
{
	/*
	 * RFLAGS: 00000000001706e0
	 * 0000000000000000000000000000000000000000000000010000001001000110
	 */
	struct rflags_t rflags;
	rflags.val = 0x00010246;

	ASSERT_EQ(rflags.RF, 1);
}

TEST(RFLAGSTest, Reserved1Bit)
{
	/*
	 * RFLAGS: 00000000001706e0
	 * 0000000000000000000000000000000000000000000000010000001001000110
	 */
	struct rflags_t rflags;
	rflags.val = 0x00010246;

	ASSERT_EQ(rflags.reserved1, 0);
}

TEST(RFLAGSTest, NestedTaskBit)
{
	/*
	 * RFLAGS: 00000000001706e0
	 * 0000000000000000000000000000000000000000000000010000001001000110
	 */
	struct rflags_t rflags;
	rflags.val = 0x00010246;

	ASSERT_EQ(rflags.NT, 0);
}

TEST(RFLAGSTest, InputOutputPrivilegeLevelFieldField)
{
	/*
	 * RFLAGS: 00000000001706e0
	 * 0000000000000000000000000000000000000000000000010000001001000110
	 */
	struct rflags_t rflags;
	rflags.val = 0x00010246;

	ASSERT_EQ(rflags.IOPL, 0);
}

TEST(RFLAGSTest, OverflowFlag)
{
	/*
	 * RFLAGS: 00000000001706e0
	 * 0000000000000000000000000000000000000000000000010000001001000110
	 */
	struct rflags_t rflags;
	rflags.val = 0x00010246;

	ASSERT_EQ(rflags.OF, 0);
}

TEST(RFLAGSTest, DirectionFlag)
{
	/*
	 * RFLAGS: 00000000001706e0
	 * 0000000000000000000000000000000000000000000000010000001001000110
	 */
	struct rflags_t rflags;
	rflags.val = 0x00010246;

	ASSERT_EQ(rflags.DF, 0);
}

TEST(RFLAGSTest, InterruptFlag)
{
	/*
	 * RFLAGS: 00000000001706e0
	 * 0000000000000000000000000000000000000000000000010000001001000110
	 */
	struct rflags_t rflags;
	rflags.val = 0x00010246;

	ASSERT_EQ(rflags.IF, 1);
}

TEST(RFLAGSTest, TrapFlag)
{
	/*
	 * RFLAGS: 00000000001706e0
	 * 0000000000000000000000000000000000000000000000010000001001000110
	 */
	struct rflags_t rflags;
	rflags.val = 0x00010246;

	ASSERT_EQ(rflags.TF, 0);
}

TEST(RFLAGSTest, SignFlag)
{
	/*
	 * RFLAGS: 00000000001706e0
	 * 0000000000000000000000000000000000000000000000010000001001000110
	 */
	struct rflags_t rflags;
	rflags.val = 0x00010246;

	ASSERT_EQ(rflags.SF, 0);
}

TEST(RFLAGSTest, ZeroFlag)
{
	/*
	 * RFLAGS: 00000000001706e0
	 * 0000000000000000000000000000000000000000000000010000001001000110
	 */
	struct rflags_t rflags;
	rflags.val = 0x00010246;

	ASSERT_EQ(rflags.ZF, 1);
}

TEST(RFLAGSTest, Reserved2Bit)
{
	/*
	 * RFLAGS: 00000000001706e0
	 * 0000000000000000000000000000000000000000000000010000001001000110
	 */
	struct rflags_t rflags;
	rflags.val = 0x00010246;

	ASSERT_EQ(rflags.reserved2, 0);
}

TEST(RFLAGSTest, AuxiliaryFlag)
{
	/*
	 * RFLAGS: 00000000001706e0
	 * 0000000000000000000000000000000000000000000000010000001001000110
	 */
	struct rflags_t rflags;
	rflags.val = 0x00010246;

	ASSERT_EQ(rflags.AF, 0);
}

TEST(RFLAGSTest, Reserved3Bit)
{
	/*
	 * RFLAGS: 00000000001706e0
	 * 0000000000000000000000000000000000000000000000010000001001000110
	 */
	struct rflags_t rflags;
	rflags.val = 0x00010246;

	ASSERT_EQ(rflags.reserved3, 0);
}

TEST(RFLAGSTest, ParityFlag)
{
	/*
	 * RFLAGS: 00000000001706e0
	 * 0000000000000000000000000000000000000000000000010000001001000110
	 */
	struct rflags_t rflags;
	rflags.val = 0x00010246;

	ASSERT_EQ(rflags.PF, 1);
}

TEST(RFLAGSTest, Reserved4Bit)
{
	/*
	 * RFLAGS: 00000000001706e0
	 * 0000000000000000000000000000000000000000000000010000001001000110
	 */
	struct rflags_t rflags;
	rflags.val = 0x00010246;

	ASSERT_EQ(rflags.reserved4, 1);
}

TEST(RFLAGSTest, CarryFlag)
{
	/*
	 * RFLAGS: 00000000001706e0
	 * 0000000000000000000000000000000000000000000000010000001001000110
	 */
	struct rflags_t rflags;
	rflags.val = 0x00010246;

	ASSERT_EQ(rflags.CF, 0);
}


};

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
