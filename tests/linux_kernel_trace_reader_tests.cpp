#include <iostream>
#include <vector>
#include <algorithm>
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "lib/linux_kernel_trace_reader.h"

namespace {

class BitshiftTest : public ::testing::Test {
protected:

	BitshiftTest() {
	}

	virtual ~BitshiftTest() {
	}

	virtual void SetUp() {
	}

	virtual void TearDown() {
	}

};

TEST(BitshiftTest, TestRealValue)
{

	uint64_t val = bitshift("0000000080050033");

	ASSERT_EQ(val, 80050033);
}

TEST(BitshiftTest, TestEmptyString)
{

	uint64_t val = bitshift("");

	ASSERT_EQ(val, 0);
}

TEST(BitshiftTest, TestNotDigitString)
{

	uint64_t val = bitshift("alala");

	ASSERT_EQ(val, 0);
}

TEST(BitshiftTest, TestNegativeValue)
{

	uint64_t val = bitshift("-129292");

	ASSERT_EQ(val, 0);
}

TEST(BitshiftTest, TestTooBigString)
{

	uint64_t val = bitshift("111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");

	ASSERT_EQ(val, 0);
}


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
	cr0.val = bitshift("0000000080050033");

	ASSERT_EQ(cr0.val, 80050033);
}

TEST(CR0Test, TestCR0ReservedMBZValue)
{
	/*
	 * CR0: 80050033
	 * reserved MBZ: 	00000000000000000000000000000000
	 */
	struct cr0_t cr0;
	cr0.val = bitshift("0000000080050033");

	ASSERT_EQ(cr0.reserved_MBZ, 0);
}

TEST(CR0Test, TestCR0PagingValue)
{
	/*
	 * CR0: 80050033
	 * Paging:		0
	 */
	struct cr0_t cr0;
	cr0.val = bitshift("0000000080050033");

	ASSERT_EQ(cr0.PG, 0);
}

TEST(CR0Test, TestCR0CacheDisableValue)
{
	/*
	 * CR0: 80050033
	 * Cache disable: 	0
	 */
	struct cr0_t cr0;
	cr0.val = bitshift("0000000080050033");

	ASSERT_EQ(cr0.CD, 0);
}

TEST(CR0Test, TestCR0NotWritethroughValue)
{
	/*
	 * CR0: 80050033
	 * Not Writethrough:	0
	 */
	struct cr0_t cr0;
	cr0.val = bitshift("0000000080050033");

	ASSERT_EQ(cr0.NW, 0);
}

TEST(CR0Test, TestCR0Reserved1Value)
{
	/*
	 * CR0: 80050033
	 * Reserved: 		0010011000
	 */
	struct cr0_t cr0;
	cr0.val = bitshift("0000000080050033");

	ASSERT_EQ(cr0.reserved1, 152);
}

TEST(CR0Test, TestCR0AlighnmentMaskValue)
{
	/*
	 * CR0: 80050033
	 * Alighnment Mask: 	1
	 */
	struct cr0_t cr0;
	cr0.val = bitshift("0000000080050033");

	ASSERT_EQ(cr0.AM, 1);
}

TEST(CR0Test, TestCR0Reserved2Value)
{
	/*
	 * CR0: 80050033
	 * Reserved: 		0
	 */
	struct cr0_t cr0;
	cr0.val = bitshift("0000000080050033");

	ASSERT_EQ(cr0.reserved2, 0);
}

TEST(CR0Test, TestCR0WriteProtectValue)
{
	/*
	 * CR0: 80050033
	 * Write Protect: 	1
	 */
	struct cr0_t cr0;
	cr0.val = bitshift("0000000080050033");

	ASSERT_EQ(cr0.WP, 1);
}

TEST(CR0Test, TestCR0Reserved3Value)
{
	/*
	 * CR0: 80050033
	 * Reserved: 		0111011101
	 */
	struct cr0_t cr0;
	cr0.val = bitshift("0000000080050033");

	ASSERT_EQ(cr0.reserved3, 477);
}

TEST(CR0Test, TestCR0NumericErrorValue)
{
	/*
	 * CR0: 80050033
	 * Numeric Error: 	1
	 */
	struct cr0_t cr0;
	cr0.val = bitshift("0000000080050033");

	ASSERT_EQ(cr0.NE, 1);
}

TEST(CR0Test, TestCR0ExtentionTypeValue)
{
	/*
	 * CR0: 80050033
	 * Extention Type:	1
	 */
	struct cr0_t cr0;
	cr0.val = bitshift("0000000080050033");

	ASSERT_EQ(cr0.ET, 1);
}

TEST(CR0Test, TestCR0TaskSwitchedValue)
{
	/*
	 * CR0: 80050033
	 * Task switched: 	0
	 */
	struct cr0_t cr0;
	cr0.val = bitshift("0000000080050033");

	ASSERT_EQ(cr0.TS, 0);
}

TEST(CR0Test, TestCR0EmulationValue)
{
	/*
	 * CR0: 80050033
	 * Emulation: 		0
	 */
	struct cr0_t cr0;
	cr0.val = bitshift("0000000080050033");

	ASSERT_EQ(cr0.EM, 0);
}

TEST(CR0Test, TestCR0MonitorCoprocessorValue)
{
	/*
	 * CR0: 80050033
	 * Monitor Coprocessor:	0
	 */
	struct cr0_t cr0;
	cr0.val = bitshift("0000000080050033");

	ASSERT_EQ(cr0.MP, 0);
}

TEST(CR0Test, TestCR0ProtectionEnabledValue)
{
	/*
	 * CR0: 80050033
	 * Protection Enabled: 	1
	 */
	struct cr0_t cr0;
	cr0.val = bitshift("0000000080050033");
	ASSERT_EQ(cr0.PE, 1);
}

};

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
