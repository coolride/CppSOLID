#include "storage/StorageFactory.hpp"
#include "storage/ValidatedStorage.hpp"

#include "storage/JsonStorage.hpp"
#include "storage/XmlStorage.hpp"
#include "storage/YamlStorage.hpp"

namespace storage {
StorageFactory::StorageFactory(const types::StorageFormat format)
    : storageFormat{ format }
{
}

std::unique_ptr<IStorage> StorageFactory::createStorage() const
{
    switch (storageFormat) {
    case types::StorageFormat::Json:
        return std::make_unique<storage::ValidatedStorage<JsonStorage>>();
    case types::StorageFormat::Xml:
        return std::make_unique<storage::ValidatedStorage<XmlStorage>>();
    case types::StorageFormat::Yaml:
        return std::make_unique<storage::ValidatedStorage<YamlStorage>>();
    }

    return nullptr;
}
} // namespace storage
