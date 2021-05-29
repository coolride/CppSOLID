#include "storage/JsonStorage.hpp"
#include "storage/ValidatedStorage.hpp"

#include <gtest/gtest.h>
#include <optional>

#include "types/Report.hpp"

struct JsonStorageTests : testing::Test {
    storage::ValidatedStorage<storage::JsonStorage> sut;

    const types::Report validReport{ 10, "VAT", 20, 2020 };
    const types::Report invalidReport{ 10 };
};

TEST_F(JsonStorageTests, whenValidData_storeReportSuccess)
{
    const std::optional<types::StorageResult> storageResult = sut.storeReport( validReport );
    ASSERT_TRUE(storageResult);
    ASSERT_EQ( storageResult, types::StorageResult::Success );
}

TEST_F(JsonStorageTests, whenFieldsAreNotValid_ValidatedStoragestoreReportReturnsFailure)
{
    const std::optional<types::StorageResult> storageResult = sut.storeReport( invalidReport );
    ASSERT_EQ( storageResult, types::StorageResult::Failure );
}
