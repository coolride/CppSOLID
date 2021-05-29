#include "storage/YamlStorage.hpp"
#include "storage/ValidatedStorage.hpp"

#include <gtest/gtest.h>
#include <optional>

#include "types/Report.hpp"

struct YamlStorageTests : testing::Test {
    storage::ValidatedStorage<storage::YamlStorage> sut;

    const types::Report validReport{ 10, "VAT", 20, 2020 };
    const types::Report invalidReport{ 10 };
};

TEST_F(YamlStorageTests, whenValidData_storeReportSuccess)
{
    const std::optional<types::StorageResult> storageResult = sut.storeReport( validReport );
    ASSERT_TRUE(storageResult);
    ASSERT_EQ( storageResult, types::StorageResult::Success );
}

TEST_F(YamlStorageTests, whenFieldsAreNotValid_ValidatedStoragestoreReportReturnsFailure)
{
    const std::optional<types::StorageResult> storageResult = sut.storeReport( invalidReport );
    ASSERT_EQ( storageResult, types::StorageResult::Failure );
}
