#include "utmatrix.h" 

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
	ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
	ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
	TVector<int> v(10);

	ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v(3, 2);
	v[0] = 1; v[1] = 2, v[2] = 3;
	TVector<int> v1(v);

	EXPECT_EQ(true, v == v1);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v(3, 2);
	v[0] = 1; v[1] = 2, v[2] = 3;
	TVector<int> v1(v);
	v1[0] = 2; v1[1] = 3, v1[2] = 4;

	EXPECT_EQ(false, v == v1);
}

TEST(TVector, can_get_size)
{
	TVector<int> v(4);

	EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
	TVector<int> v(4, 2);

	EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
	TVector<int> v(4);
	v[0] = 4;

	EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	ADD_FAILURE();
	//ASSERT_ANY_THROW(TVector<int> v[-5] = { 1 });
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	ADD_FAILURE();
	//ASSERT_ANY_THROW(TVector<int> v[MAX_VECTOR_SIZE + 1]);
}

TEST(TVector, can_assign_vector_to_itself)
{
	ADD_FAILURE();
	//
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v(3, 2), v1(3, 2);
	v[0] = 1; v[1] = 2, v[2] = 3;
	v1 = v;

	EXPECT_EQ(true, v1 == v);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v(2, 2), v1(5, 2);

	for (int i = 0; i < 2; i ++)
	{
		v[i] = 1;
	}
	v1 = v;

	EXPECT_EQ(2, v1.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v(2, 2), v1(5, 2);

	for (int i = 0; i < 2; i++)
	{
		v[i] = 1;
	}
	v1 = v;

	EXPECT_NE(0, v1[0]);
	EXPECT_NE(0, v1[1]);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v(3, 2), v1(3, 2);

	for (int i = 0; i < 3; i++)
		v[i] = 1;
	v1 = v;

	EXPECT_EQ(v, v1);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v(3, 2);

	for (int i = 0; i < 3; i++)
		v[i] = 1;
	v = v;

	EXPECT_EQ(v, v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v(5, 2), v1(2, 2);

	for (int i = 0; i < 5; i++)
		v[i] = 1;
	for (int i = 0; i < 2; i++)
		v1[i] = 1;

	EXPECT_NE(v, v1);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v(3, 2), v1(3, 2);

	for (int i = 0; i < 3; i++)
	{
		v[i] = 1;
		v1[i] = 0;
	}
	v1 = v1 + 1;

	EXPECT_EQ(v, v1);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v(3, 2), v1(3, 2);

	for (int i = 0; i < 3; i++)
	{
		v[i] = 1;
		v1[i] = 0;
	}
	v = v - 1;

	EXPECT_EQ(v, v1);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v(3, 2), v1(3, 2);

	for (int i = 0; i < 3; i++)
	{
		v[i] = 3;
		v1[i] = 1;
	}
	v1 = v1 * 3;

	EXPECT_EQ(v, v1);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v(3, 2), v1(3, 2), v2(3, 2);

	for (int i = 0; i < 3; i++)
	{
		v[i] = 2;
		v1[i] = 1;
		v2[i] = 3;
	}
	v1 = v1 + v;

	EXPECT_EQ(v2, v1);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v(5, 2), v1(2, 2), v2(5, 2);

	for (int i = 0; i < 2; i++)
		v[i] = 2;

	for (int i = 2; i < 5; i++)
		v[i] = 3;

	for (int i = 0; i < 5; i++)
		v2[i] = 3;

	for (int i = 0; i < 2; i++)
		v1[i] = 1;

	v = v + v1;

	EXPECT_EQ(v2, v);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v(3, 2), v1(3, 2), v2(3, 2);

	for (int i = 0; i < 3; i++)
	{
		v[i] = 1;
		v1[i] = 4;
		v2[i] = 3;
	}
	v1 = v1 - v;

	EXPECT_EQ(v2, v1);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v(5, 2), v1(2, 2), v2(5, 2);

	for (int i = 0; i < 2; i++)
		v[i] = 4;

	for (int i = 2; i < 5; i++)
		v[i] = 3;

	for (int i = 0; i < 5; i++)
		v2[i] = 3;

	for (int i = 0; i < 2; i++)
		v1[i] = 1;

	v = v - v1;

	EXPECT_EQ(v2, v);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> v(3, 2), v1(3, 2);
	
	for (int i = 0; i < 3; i++)
	{
		v[i] = i + 1;
		v1[i] = i + 2;
	}

	EXPECT_EQ(20, v1 * v);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	ADD_FAILURE();
}

