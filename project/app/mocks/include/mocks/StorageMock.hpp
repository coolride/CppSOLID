#include "storage/IStorage.hpp"

#include <gmock/gmock.h>

namespace storage {
class StorageMock : public IStorage {
public:
    MOCK_CONST_METHOD1(storeReport, std::optional<types::StorageResult>(const types::Report&));
};
} // namespace parsers
