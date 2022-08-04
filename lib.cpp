#include "provider.hpp"
#include "tracer.hpp"

#include <iostream>
#include <memory>

class RealTracer : public Tracer {
    void name() override final {
        std::cout << "real\n";
    }
};

class RealTracerProvider : public TracerProvider {
  std::shared_ptr<Tracer>
  GetTracer(std::string_view library_name, std::string_view library_version,
            std::string_view schema_url) noexcept override final {
    return std::make_shared<RealTracer>(RealTracer{});
  }
};

void init() {
    auto provider = Provider::GetTracerProvider();
    provider->GetTracer("init")->name();
    Provider::SetTracerProvider(std::make_shared<RealTracerProvider>(RealTracerProvider{}));
    provider = Provider::GetTracerProvider();
    provider->GetTracer("init")->name();
}

class NoopTracer : public Tracer {
    void name() override final {
        std::cout << "no op\n";
    }
};

std::shared_ptr<Tracer> NoopTracerProvider::GetTracer(
    std::string_view library_name,
    std::string_view library_version,
    std::string_view schema_url) noexcept
{
    return std::make_shared<NoopTracer>(NoopTracer{});
}