#include "FileLogger.hpp"

#include "LogFormatter.hpp"

namespace foo {

class FileLogger::impl {
  public:
    impl(std::ostream& output)
        : output{output} {}

    ~impl() {}

    std::ostream& output;
};

FileLogger::FileLogger(std::ostream& output)
    : pimpl{std::make_unique<impl>(output)}
{
}

FileLogger::~FileLogger() {
}

void FileLogger::write(const std::string& log) {
  pimpl->output << "[" << LogFormatter::getTimeStamp() << "] " << log << '\n';
}

} // namespace foo