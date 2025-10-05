#include "framebuffer.h"

// Example implementation for a simple FrameBuffer class

FrameBuffer::FrameBuffer(int width, int height)
    : width_(width), height_(height)
{
    _pixels.resize(width_ * height_ * 3, 0); // Assuming 3 bytes per pixel (RGB)
}

void FrameBuffer::clear(uint8_t r, uint8_t g, uint8_t b)
{
    for (size_t i = 0; i < _pixels.size(); i += 3) {
        _pixels[i] = r;
        _pixels[i + 1] = g;
        _pixels[i + 2] = b;
    }
}

void FrameBuffer::setPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b)
{
    if (x < 0 || x >= width_ || y < 0 || y >= height_)
        return;
    size_t idx = (y * width_ + x) * 3;
    _pixels[idx] = r;
    _pixels[idx + 1] = g;
    _pixels[idx + 2] = b;
}

const std::vector<uint8_t>& FrameBuffer::data() const
{
    return _pixels;
}