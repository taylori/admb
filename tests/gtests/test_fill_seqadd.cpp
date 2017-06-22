#include <gtest/gtest.h>
#include <fvar.hpp>

extern "C"
{
  void test_ad_exit(const int exit_code);
}

class test_fill_seqadd: public ::testing::Test {};

TEST_F(test_fill_seqadd, dvector)
{
  dvector vec(1, 4);

  vec.fill_seqadd(1.5, 0.5);

  ASSERT_DOUBLE_EQ(1.5, vec(1));
  ASSERT_DOUBLE_EQ(2.0, vec(2));
  ASSERT_DOUBLE_EQ(2.5, vec(3));
  ASSERT_DOUBLE_EQ(3.0, vec(4));
}
TEST_F(test_fill_seqadd, dvectornegativeoffset)
{
  dvector vec(1, 4);

  vec.fill_seqadd(1.5, -0.5);

  ASSERT_DOUBLE_EQ(1.5, vec(1));
  ASSERT_DOUBLE_EQ(1.0, vec(2));
  ASSERT_DOUBLE_EQ(0.5, vec(3));
  ASSERT_DOUBLE_EQ(0.0, vec(4));
}
TEST_F(test_fill_seqadd, ivector)
{
  ivector vec(1, 4);

  vec.fill_seqadd(5, 2);

  ASSERT_DOUBLE_EQ(5, vec(1));
  ASSERT_DOUBLE_EQ(7, vec(2));
  ASSERT_DOUBLE_EQ(9, vec(3));
  ASSERT_DOUBLE_EQ(11, vec(4));
}
TEST_F(test_fill_seqadd, ivectornegativeoffset)
{
  ivector vec(1, 4);

  vec.fill_seqadd(5, -5);

  ASSERT_DOUBLE_EQ(5, vec(1));
  ASSERT_DOUBLE_EQ(0, vec(2));
  ASSERT_DOUBLE_EQ(-5, vec(3));
  ASSERT_DOUBLE_EQ(-10, vec(4));
}
TEST_F(test_fill_seqadd, lvector)
{
  lvector vec(1, 4);

  vec.fill_seqadd(5, 2);

  ASSERT_DOUBLE_EQ(5, vec(1));
  ASSERT_DOUBLE_EQ(7, vec(2));
  ASSERT_DOUBLE_EQ(9, vec(3));
  ASSERT_DOUBLE_EQ(11, vec(4));
}
TEST_F(test_fill_seqadd, lvectornegativeoffset)
{
  lvector vec(1, 4);

  vec.fill_seqadd(5, -5);

  ASSERT_DOUBLE_EQ(5, vec(1));
  ASSERT_DOUBLE_EQ(0, vec(2));
  ASSERT_DOUBLE_EQ(-5, vec(3));
  ASSERT_DOUBLE_EQ(-10, vec(4));
}
TEST_F(test_fill_seqadd, dmatrixi)
{
  dmatrix mat(1, 4, 1, 3);
  mat.initialize();
  mat.rowfill_seqadd(2, 1.5, 0.5);
  ASSERT_DOUBLE_EQ(0, mat(1, 1));
  ASSERT_DOUBLE_EQ(0, mat(1, 2));
  ASSERT_DOUBLE_EQ(0, mat(1, 3));
  ASSERT_DOUBLE_EQ(1.5, mat(2, 1));
  ASSERT_DOUBLE_EQ(2.0, mat(2, 2));
  ASSERT_DOUBLE_EQ(2.5, mat(2, 3));
  ASSERT_DOUBLE_EQ(0, mat(3, 1));
  ASSERT_DOUBLE_EQ(0, mat(3, 2));
  ASSERT_DOUBLE_EQ(0, mat(3, 3));
  ASSERT_DOUBLE_EQ(0, mat(4, 1));
  ASSERT_DOUBLE_EQ(0, mat(4, 2));
  ASSERT_DOUBLE_EQ(0, mat(4, 3));

  dvect vec(1, 3);
  vec(1) = 3;
  vec(2) = 2;
  vec(3) = 1;
  mat.rowfill(3, vec);
/*
  ASSERT_DOUBLE_EQ(0, mat(1, 1));
  ASSERT_DOUBLE_EQ(0, mat(1, 2));
  ASSERT_DOUBLE_EQ(0, mat(1, 3));
  ASSERT_DOUBLE_EQ(1.5, mat(2, 1));
  ASSERT_DOUBLE_EQ(2.0, mat(2, 2));
  ASSERT_DOUBLE_EQ(2.5, mat(2, 3));
  ASSERT_DOUBLE_EQ(0, mat(3, 1));
  ASSERT_DOUBLE_EQ(0, mat(3, 2));
  ASSERT_DOUBLE_EQ(0, mat(3, 3));
  ASSERT_DOUBLE_EQ(0, mat(4, 1));
  ASSERT_DOUBLE_EQ(0, mat(4, 2));
  ASSERT_DOUBLE_EQ(0, mat(4, 3));
*/
}
