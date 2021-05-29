#pragma once

#include "storage/IStorage.hpp"

#include <type_traits>

namespace storage {
template <typename BaseStorage> class ValidatedStorage : public BaseStorage {
public:
    static_assert(std::is_base_of<IStorage, BaseStorage>::value);
    std::optional<types::StorageResult> storeReport(const types::Report&) const override;
};
} // namespace storage
