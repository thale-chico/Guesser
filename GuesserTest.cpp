/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

#include <string>

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// distance tests
TEST(GuesserTest, distance__basic_1)
{
  Guesser object("AAA");
  ASSERT_EQ( 1, object.distance("AAB") );
}
TEST(GuesserTest, distance__basic_2)
{
  Guesser object("AAA");
  ASSERT_EQ( 2, object.distance("ABB") );
}
TEST(GuesserTest, distance__basic_3)
{
  Guesser object("AAA");
  ASSERT_EQ( 3, object.distance("BBB") );
}
TEST(GuesserTest, distance__substr_1)
{
	// create strings equal to 32
	std::string base, guess; 
	for(int i = 0; i < 32; i++){
		base += 'A';
		guess += 'A';
	}

  Guesser object(base);
  ASSERT_EQ( 0, object.distance(guess) );
}
TEST(GuesserTest, distance__substr_2)
{
	// create strings greater than 32
	std::string base, guess; 
	for(int i = 0; i < 33; i++){
		base += 'A';
		guess += 'A';
	}

  Guesser object(base);
  ASSERT_EQ( 1, object.distance(guess) );
}
TEST(GuesserTest, distance__substr_3)
{
	// create strings greater than 32
	std::string base, guess; 
	for(int i = 0; i < 33; i++){
		base += 'A';
		guess += 'B';
	}

  Guesser object(base);
  ASSERT_EQ( 32, object.distance(guess) );
}

// match tests
TEST(GuesserTest, match__basic_true)
{
  Guesser object("AAA");
  ASSERT_TRUE( object.match("AAA") );
}
TEST(GuesserTest, match__basic_false)
{
  Guesser object("AAA");
  ASSERT_FALSE( object.match("BBB") );
}
TEST(GuesserTest, distance__substr_basic_true)
{
	// create strings greater than 32
	std::string base, guess; 
	for(int i = 0; i < 32; i++){
		base += 'A';
		guess += 'A';
	}

  Guesser object(base);
  ASSERT_TRUE( object.match(guess) );
}
TEST(GuesserTest, match__substr_basic_false)
{
	// create strings greater than 32
	std::string base, guess; 
	for(int i = 0; i < 32; i++){
		base += 'A';
		guess += 'B';
	}

  Guesser object(base);
  ASSERT_FALSE( object.match(guess) );
}