#pragma once

#include "storage/IStorage.hpp"

namespace types {
struct Report;
} // namespace types

namespace storage {
class JsonStorage: public IStorage {
public:
    std::optional<types::StorageResult> storeReport( const types::Report& report) const override;
};
} // namespace storage
