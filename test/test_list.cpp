#include "tlist.h"

#include <gtest.h>

TEST(TList, can_create_list_with_positive_length) {
	ASSERT_NO_THROW(TList<int> l(3));
}

