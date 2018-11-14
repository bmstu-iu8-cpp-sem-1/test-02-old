// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>

#include <header.hpp>

#include <list>
#include <map>
#include <string>
#include <vector>

TEST(TestM2, DigitCount) {
  EXPECT_EQ(digit_count("1,2wqe3q45 6q7890"), 10);
  EXPECT_EQ(digit_count("qwe"), 0);
  EXPECT_EQ(digit_count("1234567890"), 10);
  EXPECT_EQ(digit_count(""), 0);
  EXPECT_EQ(digit_count("{}:>?<,./';[]"), 0);
}

TEST(TestM2, Zip) {
  auto m1 = zip({"a", "b", "c"}, {0, 1, 2});
  std::map<std::string, int> r1 = {{"a", 0}, {"b", 1}, {"c", 2}};
  EXPECT_EQ(m1, r1);

  auto m2 = zip({"a", "b", "c"}, {1, 2});
  std::map<std::string, int> r2{};
  EXPECT_EQ(m2, r2);

  auto m3 = zip({"a", "c"}, {0, 1, 2});
  std::map<std::string, int> r3{};
  EXPECT_EQ(m3, r3);

  auto m4 = zip({"a", "b", "c", "a"}, {5, 1, 2, 0});
  std::map<std::string, int> r4 = {{"a", 0}, {"b", 1}, {"c", 2}};
  EXPECT_EQ(m4, r4);
}

TEST(TestM2, Unzip) {
  auto v1 = unzip({{"a", 1}, {"b", 2}, {"c", 3}});
  std::vector<std::string> r1 = {"a", "b", "b", "c", "c", "c"};
  EXPECT_EQ(v1, r1);

  auto v2 = unzip({{"a", 0}, {"b", 0}, {"c", 0}});
  std::vector<std::string> r2 = {};
  EXPECT_EQ(v2, r2);

  auto v3 = unzip({{"a", 1}, {"b", 0}, {"c", 3}});
  std::vector<std::string> r3 = {"a", "c", "c", "c"};
  EXPECT_EQ(v3, r3);

  auto v4 = unzip({{"a", 4}, {"b", 1}, {"c", 2}});
  std::vector<std::string> r4 = {"a", "a", "a", "a", "b", "c", "c"};
  EXPECT_EQ(v4, r4);

  auto v5 = unzip({});
  std::vector<std::string> r5 = {};
  EXPECT_EQ(v5, r5);
}

TEST(TestM2, Clear) {
  std::list<int> v1 = {1, 1, 2, 3, 4, 5};
  std::list<int> r1 = {2, 3, 4, 5};
  clear(v1);
  EXPECT_EQ(v1, r1);

  std::list<int> v2 = {1, 2, 3, 4, 5};
  std::list<int> r2 = {1, 2, 3, 4, 5};
  clear(v2);
  EXPECT_EQ(v2, r2);

  std::list<int> v3 = {1, 1, 2, 2, 2};
  std::list<int> r3 = {};
  clear(v3);
  EXPECT_EQ(v3, r3);

  std::list<int> v4 = {1, 1, 1, 1, 1};
  std::list<int> r4 = {};
  clear(v4);
  EXPECT_EQ(v4, r4);

  std::list<int> v5 = {1, 2, 1, 2, 1};
  std::list<int> r5 = {};
  clear(v5);
  EXPECT_EQ(v5, r5);

  std::list<int> v6 = {1, 2, 5, 2, 1};
  std::list<int> r6 = {5};
  clear(v6);
  EXPECT_EQ(v6, r6);

  std::list<int> v7 = {};
  std::list<int> r7 = {};
  clear(v7);
  EXPECT_EQ(v7, r7);
}

TEST(TestM2, CustomSort) {
  std::vector<std::string> v1 = {"a", "123", "a1", "12"};
  std::vector<std::string> r1 = {"a", "a1", "12", "123"};
  custom_sort(v1);
  EXPECT_EQ(v1, r1);

  std::vector<std::string> v2 = {"a", "1", "a", "1"};
  std::vector<std::string> r2 = {"a", "a", "1", "1"};
  custom_sort(v2);
  EXPECT_EQ(v2, r2);

  std::vector<std::string> v3 = {};
  std::vector<std::string> r3 = {};
  custom_sort(v3);
  EXPECT_EQ(v3, r3);

  std::vector<std::string> v4 = {"b12", "c1", "a123"};
  std::vector<std::string> r4 = {"c1", "b12", "a123"};
  custom_sort(v4);
  EXPECT_EQ(v4, r4);
}