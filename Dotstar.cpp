/***********************************************************************
 *
 * @file 	DotStar.cpp
 * @author	hdonahue
 * @date 	02/05/2021
 * @brief	Dotstar library
 * 
 **********************************************************************/
#include <cstdint>
#include "Dotstar.h"

namespace Dotstar
{
  

  /**
   * @fn Pixel::Pixel
   * @brief Construct a new Pixel:: Pixel object
   * 
   * @param order PixelOrder enum defining the order of the pixels in the buffer
   */
  Pixel::Pixel(PixelOrder order) :
    red_(0), green_(0), blue_(0), brightness_(0), red_offset_(0), green_offset_(0), blue_offset_(0)
  {
    switch (order)
    {
      case PixelOrder::RGB:
        red_offset_ = 1;
        green_offset_ = 2;
        blue_offset_ = 3;
        break;

      case PixelOrder::RBG:
        red_offset_ = 1;
        green_offset_ = 3;
        blue_offset_ = 2;
        break;

      case PixelOrder::GRB:
        red_offset_ = 2;
        green_offset_ = 1;
        blue_offset_ = 3;
        break;

      case PixelOrder::GBR:
        red_offset_ = 3;
        green_offset_ = 1;
        blue_offset_ = 2;
        break;

      case PixelOrder::BRG:
        red_offset_ = 2;
        green_offset_ = 3;
        blue_offset_ = 1;
        break;

      case PixelOrder::BGR:
        red_offset_ = 3;
        green_offset_ = 2;
        blue_offset_ = 1;
        break;

      default:
        break;
    }
  }



  /**
   * @fn SetColor
   * @brief Set the color and brightness of the pixel
   * 
   * @param red 
   * @param green 
   * @param blue 
   * @param brightness 
   */
  int Pixel::SetColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t brightness)
  {
    if(brightness > BRIGHTNESS_FULL) //TODO: consider exception here instead of err code
      return -1;
    
    red_ = red;
    green_ = green;
    blue_ = blue;
    brightness_ = brightness;
    pixel_buf_[red_offset_] = red;
    pixel_buf_[green_offset_] = green;
    pixel_buf_[blue_offset_] = blue;
    pixel_buf_[BRIGHTNESS_OFFSET] = 0xE0 + brightness;
    return 0;
  }

  void Pixel::SetColor(uint8_t red, uint8_t green, uint8_t blue)
  {
    red_ = red;
    green_ = green;
    blue_ = blue;
    pixel_buf_[red_offset_] = red;
    pixel_buf_[green_offset_] = green;
    pixel_buf_[blue_offset_] = blue;
  }

  int Pixel::SetBrightness(uint8_t b)
  {
    if(b > BRIGHTNESS_FULL) // consider exception here
      return -1;

    brightness_ = b;
    pixel_buf_[BRIGHTNESS_OFFSET] = b;
    return 0;
  }

  void Pixel::GetPixelBuf(uint8_t buf[]) const
  {
    for(int i=0; i<COLOR_COUNT+1; i++)
    {
      buf[i] = pixel_buf_[i];
    }
  }



} // namespace Dotstar

