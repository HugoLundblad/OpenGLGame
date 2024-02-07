#include "pch.h"
#include "../Maths/Vector3.h"

TEST(Vector3_Constructor, AssignsAllComponents) {
    Vector3 v(3, 4, 5);
    EXPECT_EQ(v.x, 3);
    EXPECT_EQ(v.y, 4);
    EXPECT_EQ(v.z, 5);
}

TEST(Vector3_EqualityComparison, Returns_True_For_Equal_Vectors) {
    EXPECT_TRUE(Vector3(3, 4, 5) == Vector3(3, 4, 5));
}

// test and implement inequality comparison

TEST(Vector3_EqualityComparison, Returns_False_For_Inequal_Vectors) {
    EXPECT_FALSE(Vector3(3, 4, 5) == Vector3(2, 4, 5));
    EXPECT_FALSE(Vector3(3, 4, 5) == Vector3(3, 2, 5));
    EXPECT_FALSE(Vector3(3, 4, 5) == Vector3(3, 4, 2));
    EXPECT_FALSE(Vector3(3, 4, 5) == Vector3(2, 2, 2));
}

TEST(Vector3_InequalityComparison, Returns_False_For_Unequal_Vectors) {
    EXPECT_FALSE(Vector3(3, 4, 5) != Vector3(3, 4, 5));
}

TEST(Vector3_InequalityComparison, Returns_True_For_Unequal_Vectors) {
    EXPECT_TRUE(Vector3(3, 4, 5) != Vector3(2, 4, 5));
    EXPECT_TRUE(Vector3(3, 4, 5) != Vector3(3, 2, 5));
    EXPECT_TRUE(Vector3(3, 4, 5) != Vector3(3, 4, 2));
    EXPECT_TRUE(Vector3(3, 4, 5) != Vector3(2, 2, 2));
}

// test and implement negate operator
TEST(Vector3_Negate, InvertsPositiveValues) {
  EXPECT_EQ(-Vector3(3,4,5), Vector3(-3,-4,-5));
  EXPECT_TRUE(true);
}

TEST(Vector3_ScalarMultiplication, ScalesAllValues) {
    EXPECT_EQ(Vector3(3, 4, 5) * 2, Vector3(6, 8, 10));
    EXPECT_TRUE(true);
}

TEST(Vector3_ScalarDivision, InverseScaleValues) {
    EXPECT_EQ(Vector3(6, 8, 10) / 2, Vector3(3, 4, 5));
    EXPECT_TRUE(true);
}

TEST(Vector3_Addition, AddSumOfAllValues) {
    EXPECT_EQ(Vector3(3, 4, 5) + Vector3(1, 2, 3), Vector3(4, 6, 8));
    EXPECT_TRUE(true);
}

TEST(Vector3_Magnitude, CalculateMagnitudeOfVector) {
    EXPECT_FLOAT_EQ(Vector3(3, 4, 0).Magnitude(), 5);
}

TEST(Vector3_SquaredMagnitude, CalculateSquaredMagnitudeOfVector) {
    EXPECT_FLOAT_EQ(Vector3(3, 4, 0).SquareMagnitude(), 25);
}

TEST(Vector3_DotProduct, CalculateDotProductOfVectors) {
    EXPECT_FLOAT_EQ(Vector3::Dot(Vector3(4, 6, 3), Vector3(-1, 8, 0)), 44);
}

TEST(Vector3_CrossProduct, CalculateCrossProductOfVectors) {
    EXPECT_EQ(Vector3::Cross(Vector3(4, 6, 3), Vector3(-1, 8, 0)), Vector3(-24, -3, 38));
}