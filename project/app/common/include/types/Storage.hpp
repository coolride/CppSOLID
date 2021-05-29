#pragma once 

#include <iosfwd>

namespace types {
enum class StorageFormat { Json, Xml, Yaml };

enum class StorageResult { Success, Failure };
} // namespace types

std::istream& operator>>(std::istream&, types::StorageFormat&);
std::ostream& operator<<(std::ostream&, types::StorageFormat);
