#include "tlist.h"

#include <gtest.h>

TEST(TList, can_create_list) {
	ASSERT_NO_THROW(TList<int> l);
}
TEST(TList, can_create_list_with_positive_length) {
	ASSERT_NO_THROW(TList<int> l(5));
}
TEST(TList, cant_create_list_with_negative_length) {
	ASSERT_ANY_THROW(TList<int> l(-2));
}
TEST(TList, create_list_with_zero_length) {
	ASSERT_NO_THROW(TList<int> l(0));
}
TEST(TList, copy_list) {
	const int size = 5;
	TList<int> l1(size);

	ASSERT_NO_THROW(TList<int> l2(l1));
}
TEST(TList, copy_list_itself) {
	const int size = 5;
	TList<int> l1(size);

	ASSERT_NO_THROW(TList<int> l1(l1));
}
TEST(TList, copy_list_has_equal_size) {
	const int size = 5;
	TList<int> l1(size);
	TList<int> l2(l1);
	ASSERT_EQ(size, l2.size());
}
TEST(TList, can_get_element_with_positive_index) {
	const int size = 3;
	TList<int> l1(size);
	for (int i = 0; i < size; i++) {
		l1[i] = i;
	}
	ASSERT_EQ(l1[2], 2);
}
TEST(TList, cant_get_element_with_negative_index) {
	const int size = 3;
	TList<int> l1(size);
	ASSERT_ANY_THROW(l1[-1]);
}
TEST(TList, cant_get_element_with_index_more_than_list_size) {
	const int size = 3;
	TList<int> l1(size);
	ASSERT_ANY_THROW(l1[15]);
}
TEST(TList, can_insert_element) {
	TList<int> lst(5, 1);
	lst.insert(10, lst.find(1));
	ASSERT_EQ(lst[1], 10);
}
TEST(TList, can_erase_element) {
	TList<int> lst(5, 1);
	lst.erase(lst.find(1));
	ASSERT_NO_THROW(lst.erase(lst.find(1)));
}
TEST(TList, can_find_elenent_in_list) {
	TList<int> lst(5, 1);
	ASSERT_NE(lst.find(1), nullptr);
}
TEST(TList, cant_find_elenent_in_list) {
	TList<int> lst(5, 1);
	ASSERT_EQ(lst.find(10), nullptr);
}
TEST(TList, can_get_size) {
	TList<int> lst(5, 1);
	ASSERT_EQ(lst.size(), 5);
}

// Task 4

TEST(TList, task4_odd) {
	TList<int> lst(5);
	lst[0] = 0;
	lst[1] = 1;
	lst[2] = 2;
	lst[3] = 3;
	lst[4] = 4;
	int* list = lst.midle_element();
	int n = list[0];
	ASSERT_EQ(list[0], 1);
}
TEST(TList, task4_even) {
	TList<int> lst(4);
	lst[0] = 0;
	lst[1] = 1;
	lst[2] = 2;
	lst[3] = 3;
	int* list = lst.midle_element();
	ASSERT_EQ(list[0], 1);
	ASSERT_EQ(list[1], 2);
}
