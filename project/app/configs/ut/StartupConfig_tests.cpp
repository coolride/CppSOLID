#include "configs/StartupConfig.hpp"

#include <gtest/gtest.h>
#include <string>

#include "types/ReportFormat.hpp"
#include "types/Storage.hpp"

char arg0[] = "Program name";
char arg1[] = "--port";
char arg2[] = "8000";
char arg3[] = "--format";
char arg4[] = "xml";
char arg5[] = "--storage";
char arg6[] = "xml";

TEST(StartupConfigTests, validOptions_returnsStartupConfig)
{
    char* argv[] = { &arg0[0], &arg1[0], &arg2[0], &arg3[0], &arg4[0], &arg5[0], &arg6[0], NULL };
    const auto config = optionsToStartupConfig(7, argv);
    ASSERT_TRUE(config);
    ASSERT_EQ(config->port, 8000);
    ASSERT_EQ(config->reportFormat, types::ReportFormat::Xml);
    ASSERT_EQ(config->storageFormat, types::StorageFormat::Xml);
}

TEST(StartupConfigTests, helpOption_returnsEmptyStartupConfig)
{
    char help[] = "--help";
    char* argv[] = { &arg0[0], &help[0], NULL };
    const auto config = optionsToStartupConfig(2, argv);
    ASSERT_FALSE(config);
}

TEST(StartupConfigTests, defaultOptions_returnsValidStartupConfig)
{
    char* argv[] = { &arg0[0], NULL };
    const auto config = optionsToStartupConfig(1, argv);
    ASSERT_TRUE(config);
    ASSERT_EQ(config->port, 8080);
    ASSERT_EQ(config->reportFormat, types::ReportFormat::Json);
    ASSERT_EQ(config->storageFormat, types::StorageFormat::Json);
}
