//
// Created by malanore on 24-5-21.
//

#include "mat.h"

#include <gtest/gtest.h>

TEST(TestMat, FloatAdd) {
    EXPECT_FLOAT_EQ(FloatAdd(1.1, 2.2), 3.3);
}
