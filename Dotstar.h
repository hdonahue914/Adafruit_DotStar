/***********************************************************************
 *
 * @file 	DotStar.h
 * @author	hdonahue
 * @date 	02/05/2021
 * @brief	DotStar library header
 * 
 **********************************************************************/
#ifndef _DOTSTAR_H_
#define _DOTSTAR_H_
#include <cstdint>

/**
 * @namespace Dotstar
 */
namespace Dotstar
{

#define COLOR_MONO  1
#define COLOR_RGB   3
// Default to RGB Color
#ifndef COLOR_COUNT
#define COLOR_COUNT COLOR_RGB
#endif //COLOR_COUNT

#define BRIGHTNESS_OFFSET 0

// The pixel brightness can be conrolled by 5 (0-31) bits preceeding the color bits
// Alternatively, a scaling value can be applied with a scale of 0-255
#ifndef BRIGHTNESS_FULL
#ifdef BRIGHTNESS_SCALE
//#define BRIGHTNESS_FULL 255
#else
#define BRIGHTNESS_FULL 31
#endif //BRIGHTNESS_SCALE
#endif //BRIGHTNESS_FULL

/**
 * @section Pixel Class and Utilities
 */

/**
 * @enum Pixel Order (scoped)
 * @brief Defines the order of the bits for each pixel color in the raw buffer
 */
enum class PixelOrder{
    RGB,
    RBG,
    GRB,
    GBR,
    BRG,
    BGR,
};

/**
 * @class Pixel
 * @brief Pixel class contains members for the individual colors, pixel buf which orders the pixels
 *          and public methods for manipulating the pixel values. 
 */
class Pixel
{
public:
    Pixel(PixelOrder order);
    ~Pixel();
    
    int SetColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t brightness);
    void SetColor(uint8_t red, uint8_t green, uint8_t blue); 
    int SetBrightness(uint8_t b);
    void GetPixelBuf(uint8_t buf[]) const;

private:

    uint8_t red_;       ///< Red value
    uint8_t green_;     ///< Green value
    uint8_t blue_;      ///< Blue value
    uint8_t brightness_; ///< Pixel brightness can either be scaled or hardware controlled
    uint8_t red_offset_;    ///< Offset of red into pixel_buf_
    uint8_t green_offset_;  ///< Offset of green into pixel_buf_
    uint8_t blue_offset_;   ///< Offset of blue into pixel_buf_
    uint8_t pixel_buf_[COLOR_COUNT+1]; ///< Byte array for each pixel and brightness 
};






} // namespace Dotstar

#endif // _DOTSTAR_H_