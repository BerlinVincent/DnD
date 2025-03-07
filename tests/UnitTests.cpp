#include <gtest/gtest.h>
#include "../DungeonsAndDragons/Framework/game_engine/Game.hpp"

class AttributeTests : public ::testing::Test {
protected:
    string name = "Test";
    int score = 10;
    int attr_mod = 0;
    Attribute *attribute;

    virtual void SetUp() override {
        attribute = new Attribute(name, score);
    }
    virtual void TearDown() override {
        delete attribute;
    }
};

TEST_F(AttributeTests, Constructor) {
    string badName = "Tets";
    int badScore = 100;
    int badAttr_mod = 100;
    Attribute tempAttribute(name, score);

    EXPECT_EQ(name, tempAttribute.getName());
    EXPECT_EQ(score, tempAttribute.getScore());
    EXPECT_EQ(attr_mod, tempAttribute.getMod());

    EXPECT_NE(badName, tempAttribute.getName());
    EXPECT_NE(badScore, tempAttribute.getScore());
    EXPECT_NE(badAttr_mod, tempAttribute.getMod());
}

TEST_F(AttributeTests, ScoreImprove) {
    int max_score = 30;
    int over_max = 31;

    for(int i = 0; i <= 21; i++) {
        attribute->scoreImprove();
    }

    EXPECT_EQ(max_score, attribute->getScore());
    EXPECT_NE(over_max, attribute->getScore());
}

TEST_F(AttributeTests, ScoreDiminish) {
    int min_score = 1;
    int under_min = 0;

    for(int i = score; i > 0; i--) {
        attribute->scoreDiminish();
    }

    EXPECT_EQ(min_score, attribute->getScore());
    EXPECT_NE(under_min, attribute->getScore());
}

TEST_F(AttributeTests, RecalcModAndCalculateModifier) {
    int min_score = 1;
    while(attribute->getScore() > min_score) attribute->scoreDiminish();
    
    for(int i = min_score; i < 31; i++) {
        EXPECT_EQ((i - 10) / 2, attribute->getMod());
        attribute->scoreImprove();
    }
}

class SkillTests : public ::testing::Test {
protected:
    string name = "Test";
    bool proficiency = false;
    Skill *skill;
    Attribute *parent_attribute;

    virtual void SetUp() {
        parent_attribute = new Attribute("PAttr", 10);
        skill = new Skill(name, *parent_attribute, proficiency);
    }
    virtual void TearDown() {
        delete skill;
        delete parent_attribute;
    }
};

TEST_F(SkillTests, Constructor) {
    int skill_mod_noProf = 0;

    EXPECT_EQ(name, skill->getName());
    EXPECT_EQ(parent_attribute, &skill->getPAttr());
    EXPECT_EQ(skill_mod_noProf, skill->getMod());
    EXPECT_FALSE(skill->hasProf());

    Skill temp_skill = Skill(name, *parent_attribute, !proficiency);
    int skill_mod_prof = 2;

    EXPECT_EQ(skill_mod_prof, temp_skill.getMod());
    EXPECT_TRUE(temp_skill.hasProf());
}

TEST_F(SkillTests, RecalcMod) {
    int start_mod = 0;

    EXPECT_EQ(start_mod, skill->getMod());

    parent_attribute->scoreImprove();
    parent_attribute->scoreImprove();

    EXPECT_EQ(start_mod + 1, skill->getMod());
}

class EntityTests : public ::testing::Test {
protected:
    I_map<string> *descriptors;
    I_map<int> *statistics;
    vector<Attribute> *attributes;
    Entity *entity;

    virtual void SetUp() {
        descriptors = new I_map<string>;
        descriptors->set("name", "Test");
        descriptors->set("description", "A test entity");

        statistics = new I_map<int>;
        statistics->set("max_hp", 20);
        statistics->set("armor_class", 5);
        statistics->set("initiative", 10);
        statistics->set("speed", 10);

        attributes = new vector<Attribute>;
        Attribute str = Attribute("STR", 10);
        Attribute dex = Attribute("DEX", 10);
        attributes->push_back(str);
        attributes->push_back(dex);

        entity = new Entity(*descriptors, *statistics, *attributes);
    }

    virtual void TearDown() {
        delete descriptors;
        delete statistics;
        delete entity;
    }
};

TEST_F(EntityTests, Constructor) {
    Entity temp_entity = Entity(*descriptors, *statistics, *attributes);

    string name = "Test";
    int max_hp = 20;
    int current_hp = 20;
    int temp_hp = 0;

    EXPECT_EQ(name, temp_entity.entity_description.get("name"));
    EXPECT_EQ(max_hp, temp_entity.entity_statistics.get("max_hp"));
    EXPECT_EQ(current_hp, temp_entity.entity_statistics.get("current_hp"));
    EXPECT_EQ(temp_hp, temp_entity.entity_statistics.get("temp_hp"));
}

TEST_F(EntityTests, CoypConstructor) {
    Entity temp_entity = Entity(*entity);

    string name = "Test";
    int max_hp = 20;
    int current_hp = 20;
    int temp_hp = 0;

    EXPECT_EQ(name, temp_entity.entity_description.get("name"));
    EXPECT_EQ(max_hp, temp_entity.entity_statistics.get("max_hp"));
    EXPECT_EQ(current_hp, temp_entity.entity_statistics.get("current_hp"));
    EXPECT_EQ(temp_hp, temp_entity.entity_statistics.get("temp_hp"));
}

auto main(int argc, char **argv) -> int {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}