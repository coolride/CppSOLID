#pragma once

#include <iosfwd>

namespace types {
enum class ReportFormat { Json, Xml, Yaml };
} // namespace types

std::istream& operator>>(std::istream&, types::ReportFormat&);
std::ostream& operator<<(std::ostream&, types::ReportFormat);