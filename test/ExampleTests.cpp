#include "../Example.hpp"
#include <gtest/gtest.h>

struct ExampleTests
    : public ::testing::Test
{
    int* x;
    int GetX(){
        return *x;
    }
    virtual void SetUp() override{     
        fprintf(stderr, "Hello Neu!\n");
        x= new int(25);
    }

    virtual void TearDown() override{        
        delete x;
    }

};


TEST_F(ExampleTests, MAC){
    int x=42;
    int y=16;
    int sum =100;
    int oldSum = sum;
    int expectedNewSum = oldSum + GetX() * y;

    EXPECT_EQ(
        expectedNewSum,
        MAC(x, y, sum)
    );
    EXPECT_EQ(
        expectedNewSum,
        sum
    );
}

TEST_F(ExampleTests, Square){
    int x=5;
    int expectedSquare =GetX() * GetX();
    EXPECT_EQ(
        expectedSquare,
        Square(x)
    );

}