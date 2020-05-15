#include "biblioteka.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

//only for testing

bool IfPassed (double averange)
{
    if (averange>=5)
        return true;
    else return false;
}
bool IfFailed (double averange)
{
    if (averange<5)
        return true;
    else return false;
}

double FinalResult (double averange, int exam)
{
    return 0.4*averange+0.6*exam;
}

 TEST_CASE("Final Mark") {

	REQUIRE(FinalResult(5.1, 7) == 6.24);
	REQUIRE(FinalResult(4.1, 10) == 7.64);
	REQUIRE(FinalResult(9.2, 4) == 6.08);
	REQUIRE(FinalResult(8.5, 9) == 8.8);
	REQUIRE(FinalResult(8.5, 3) == 5.2);

}

TEST_CASE("If student Passed test") {

	REQUIRE(IfPassed(9) == true);
	REQUIRE(IfPassed(4) == false);
	REQUIRE(IfPassed(10) == true);
	REQUIRE(IfPassed(7) == true);
	REQUIRE(IfPassed(5) == true);

}
TEST_CASE("If student Failed test") {

	REQUIRE(IfFailed(7) == false);
    REQUIRE(IfFailed(5) == false);
	REQUIRE(IfFailed(4) == true);
	REQUIRE(IfFailed(1) == true);
	REQUIRE(IfFailed(3) == true);

}
