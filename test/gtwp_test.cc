#include <gtwp/gtwp.h>

TEST(gtwp, print)
{
    GTWP_INFO("This is a information message.");
    GTWP_WARN("This is a warning message.");
    GTWP_CRIT("This is a critical or error message.");
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
