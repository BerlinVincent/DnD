#include <gtest/gtest.h>
#include "../DungeonsAndDragons/Framework/game_engine/Game.hpp"

class AttributeTests : public ::testing::Test {
protected:
    Attribute *attribute;

    virtual void SetUp() override {
        attribute = new Attribute("STR", 10);
    }

    virtual void TearDown() override {
        delete attribute;
    }
};

TEST_F(AttributeTests, Constructor) {
    string name = "STR";
    int score = 10;
    int attr_mod = 0;

    EXPECT_EQ(name, attribute->getName());
    EXPECT_EQ(score, attribute->getScore());
    EXPECT_EQ(attr_mod, attribute->getMod());
}

auto main(int argc, char **argv) -> int {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}