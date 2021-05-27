#include "parsers/YamlParser.hpp"

#include <gtest/gtest.h>
#include <optional>
#include <string>

#include "types/Report.hpp"

struct YamlParserTests : testing::Test {
    parsers::YamlParser sut;
};

TEST_F(YamlParserTests, whenValidData_parseReportReturnsReport)
{
    const std::string yamlReport =
    "report:\n"
    "  payer: 2\n"
    "  tax: VAT\n"
    "  amount: 10\n"
    "  year: 2020\n"
    ;
    const std::optional<types::Report> parsedReport = sut.parseReport(yamlReport);
    const types::Report expectedReport{ 2, "VAT", 10, 2020 };
    ASSERT_TRUE(parsedReport);
    ASSERT_EQ(*parsedReport, expectedReport);
}

TEST_F(YamlParserTests, whenEmptyReport_parseReportReturnsNull)
{
    const std::string yamlReport = "";
    ASSERT_EQ(sut.parseReport(yamlReport), std::nullopt);
}

