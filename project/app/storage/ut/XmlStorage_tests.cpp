#include "storage/XmlStorage.hpp"
#include "storage/ValidatedStorage.hpp"

#include <gtest/gtest.h>
#include <optional>

#include "types/Report.hpp"

struct XmlStorageTests : testing::Test {
    storage::ValidatedStorage<storage::XmlStorage> sut;

    const types::Report validReport{ 10, "VAT", 20, 2020 };
    const types::Report invalidReport{ 10 };
};

TEST_F(XmlStorageTests, whenValidData_storeReportSuccess)
{
    const std::optional<types::StorageResult> storageResult = sut.storeReport( validReport );
    ASSERT_TRUE(storageResult);
    ASSERT_EQ( storageResult, types::StorageResult::Success );
}

TEST_F(XmlStorageTests, whenFieldsAreNotValid_ValidatedStoragestoreReportReturnsFailure)
{
    const std::optional<types::StorageResult> storageResult = sut.storeReport( invalidReport );
    ASSERT_EQ( storageResult, types::StorageResult::Failure );
}
