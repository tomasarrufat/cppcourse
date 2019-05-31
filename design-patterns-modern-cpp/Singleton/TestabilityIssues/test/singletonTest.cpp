
#include "gtest/gtest.h"
#include "TestabilityIssues.hpp"

TEST(RecordFinderTest, SingletonTotalPopulationTest)
{
    SingletonRecordFinder rf;
    vector<string> names{ "UnitedKingdom", "France", "Germany", "Netherlands", "Spain", "Italy", "France"};
    int total = rf.totalPopulation(names);
    EXPECT_EQ(336190541,total);
}

TEST(RecordFinderTest, DependantTotalPopulationTest)
{
    DummyDatabase db;
    ConfigurableRecordFinder rf{db};
    EXPECT_EQ(6 ,rf.totalPopulation(vector<string>{"alpha", "beta", "gamma"}));
}