#pragma once 

#include <optional>
#include <string>

#include "types/Report.hpp"
#include "types/Storage.hpp"

namespace storage {
class IStorage {
public:
    virtual ~IStorage() = default;
    virtual std::optional<types::StorageResult> storeReport(const types::Report&) const = 0;
};
} // namespace storage
