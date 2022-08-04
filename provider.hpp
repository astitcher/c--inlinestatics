#include <memory>
#include <string_view>

#include "tracerprovider.hpp"

class __attribute__((visibility("default"))) NoopTracerProvider : public TracerProvider {
  std::shared_ptr<Tracer>
  GetTracer(std::string_view library_name, std::string_view library_version,
            std::string_view schema_url) noexcept override final;
};

class Provider {
public:
  static std::shared_ptr<TracerProvider> GetTracerProvider() noexcept {
    return GetProvider();
  }

  static void SetTracerProvider(std::shared_ptr<TracerProvider> tp) noexcept {
    GetProvider() = tp;
  }

private:
  static std::shared_ptr<TracerProvider> provider;
  static std::shared_ptr<TracerProvider> &GetProvider() noexcept {
    return provider;
  }
};

__attribute__((visibility("default"))) std::shared_ptr<TracerProvider> Provider::provider=std::make_shared<NoopTracerProvider>();
__attribute__((visibility("default"))) void init();
