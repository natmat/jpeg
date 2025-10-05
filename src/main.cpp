#include "../src/framebuffer.h"
#include <iostream>

int main() {
  // Entry point of the program
  std::cout << "Hello, JPEG!" << std::endl;

  Framebuffer fb;
  fb.fill_test_pattern();
  const std::string out = "framebuffer_1080p.ppm";
  if (!fb.write_ppm(out)) {
    std::cerr << "Failed to write " << out << "\n";
    return 1;
  }
  std::cout << "Wrote " << out << " (" << Framebuffer::WIDTH << "x"
            << Framebuffer::HEIGHT << ")\n";
  return 0;
}
