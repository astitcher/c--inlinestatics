#include "provider.hpp"
#include "tracer.hpp"

int main() {
    Provider::GetTracerProvider()->GetTracer("initial")->name();
    init();
    Provider::GetTracerProvider()->GetTracer("final")->name();
}