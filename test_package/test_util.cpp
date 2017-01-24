#include <iostream>

#include <gtest/gtest.h>
#include "util/stringfmt.h"

// standard formatting tests
TEST(StringFormat, Basic) {
	std::string str = stringfmt("This is a test");
	EXPECT_EQ(strcmp(str.c_str(), "This is a test"), 0);
}

TEST(StringFormat, Integer) {
	std::string str = stringfmt("%d", 42);
	EXPECT_EQ(strcmp(str.c_str(), "42"), 0);
}