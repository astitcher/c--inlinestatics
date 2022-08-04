#include <memory>
#include <string_view>

class Tracer;

class TracerProvider: public std::enable_shared_from_this<TracerProvider> {
public:
  virtual ~TracerProvider() = default;

  virtual std::shared_ptr<Tracer>
  GetTracer(std::string_view library_name,
            std::string_view library_version = "",
            std::string_view schema_url = "") noexcept = 0;
};
