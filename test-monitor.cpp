#include "./monitor.h"

#include "gtest/gtest.h"

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
  ASSERT_FALSE(vitalsOk(99, 102, 70));
  ASSERT_TRUE(vitalsOk(98.1, 70, 98));
  ASSERT_FALSE(vitalsOk(94.9, 70, 98));
  ASSERT_FALSE(vitalsOk(99, 70, 98));
  ASSERT_FALSE(vitalsOk(99, 102, 89));
}
