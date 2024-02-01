#include "pch.h"
#include "../ConsoleApplication1/myClass.h"
#include "../ConsoleApplication1/myClass.cpp"
#include <vector>
#include <memory>
using namespace std;

class sameconf :public testing::Test {
protected:
	void SetUp() override {
		list.push_back(1);
		list.push_back(2);
	}

	void TearDown() override {
		//list.clear();
	}

	vector<int>list;
};

TEST(TestmyClass, test1) {
	unique_ptr<myClass>a = make_unique<myClass>("hiiiiiiiiii");
  //ASSERT_EQ(strcmp(a->getval(),"hiiiiiiiiii"),0) << "is not valid";
	EXPECT_NEAR(10, 13, 2) << "more than 2";
  EXPECT_STRCASEEQ(a->getval(), "Hiiiiiiiiii") << "is not valid 1";
  EXPECT_STREQ(a->getval(), "Hiiiiiiiiii") << "is not valid 2";
}

TEST(TestmyClass, test2) {
	ASSERT_EQ(10+20, 30) << "is not valid 2";
}

TEST_F(sameconf, test3) {
	ASSERT_EQ(list.size(), 2) << "is not valid 3";
}

TEST_F(sameconf, test4) {
	ASSERT_EQ(list.size(), 2) << "is not valid 4";
}