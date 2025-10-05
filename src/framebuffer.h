// Simple 1080p framebuffer (RGBA stored in 0xRRGGBBAA)
#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <cstdint>
#include <vector>
#include <string>

class Framebuffer {
public:
    static constexpr int WIDTH = 1920;
    static constexpr int HEIGHT = 1080;

    Framebuffer(int width = WIDTH, int height = HEIGHT)
        : _width(width), _height(height), _pixels(width * height, 0){};

    void clear(uint32_t rgba);
    void set_pixel(int x, int y, uint32_t rgba);
    uint32_t get_pixel(int x, int y) const;

    // Fill a deterministic test pattern (useful to verify the framebuffer)
    void fill_test_pattern();

    // Write the framebuffer to a PPM (P6) file (RGB, 8-bit per channel)
    bool write_ppm(const std::string &path) const;

    int width() const { return _width; }
    int height() const { return _height; }
    
private:
    std::vector<uint32_t> _pixels;
    int _width;
    int _height;
};

#endif // FRAMEBUFFER_H
