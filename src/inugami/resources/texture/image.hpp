/*******************************************************************************
 * Inugami - An OpenGL framework designed for rapid game development
 * Version: 0.3.0
 * https://github.com/DBRalir/Inugami
 *
 * Copyright (c) 2012 Jeramy Harrison <dbralir@gmail.com>
 *
 * This software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from the
 * use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 *  1. The origin of this software must not be misrepresented; you must not
 *     claim that you wrote the original software. If you use this software
 *     in a product, an acknowledgment in the product documentation would be
 *     appreciated but is not required.
 *
 *  2. Altered source versions must be plainly marked as such, and must not be
 *     misrepresented as being the original software.
 *
 *  3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/

#ifndef INUGAMI_IMAGE_H
#define INUGAMI_IMAGE_H

#include "pixel.hpp"

#include <png++/png.hpp>

#include <string>
#include <vector>

namespace Inugami {

namespace Resources_detail {

/*! @brief Container for pixel data.
 *
 *  Describes an image in RGBA8 format. Designed to be converted into a Texture.
 */
class Image
{
public:
    /*! @brief A row of pixels.
     */
    using Row = Pixel*;
    using CRow = Pixel const*;

    /*! @brief Creates an Image from a PNG file.
     *
     *  Loads the given PNG file into an Image.
     *
     *  @param filename Name of PNG file to import.
     *
     *  @return Image imported from the PNG file.
     */
    static Image fromPNG(const std::string& filename);

    /*! @brief Creates an Image from random noise.
     *
     *  Creates an Image from random noise.
     *
     *  @param w Width.
     *  @param h Height.
     *
     *  @return Image created from noise.
     */
    static Image fromNoise(int w, int h);

    /*! @brief Default contructor.
     */
    Image() = default;

    /*! @brief Canvas constructor.
     *
     *  Constructs the Image such that all pixels are a default color.
     *
     *  @param w Width.
     *  @param h Height.
     */
    Image(int w, int h);

    /*! @brief Solid color constructor.
     *
     *  Constructs the Image such that all pixels are the given color.
     *
     *  @param w Width.
     *  @param h Height.
     *  @param color Pixel to fill the Image with.
     */
    Image(int w, int h, const Pixel& color);

    /*! @brief Access the pixel at the given location.
     *
     *  @param x X coordinate.
     *  @param y Y coordinate.
     *
     *  @return Reference to the Pixel.
     */
    Pixel& at(int x, int y);

    /*! @brief Access the pixel at the given location.
     *
     *  @param x X coordinate.
     *  @param y Y coordinate.
     *
     *  @return Reference to the Pixel.
     */
    const Pixel& at(int x, int y) const;

    /*! @brief Access the row at the given location.
     *
     *  @param y Y coordinate.
     *
     *  @return Row of pixels.
     */
    Row operator[](int y);

    /*! @brief Access the row at the given location.
     *
     *  @param y Y coordinate.
     *
     *  @return Row of pixels.
     */
    CRow operator[](int y) const;

    /*! @brief Changes the dimensions of the Image.
     *
     *  @note Invalidates all contained Pixel%s.
     *
     *  @param w New width.
     *  @param h New height.
     */
    void resize(int w, int h);

    int getWidth() const;

    int getHeight() const;

private:
    int width = 0;
    int height = 0;

    std::vector<Pixel> pixels;
};

} // namespace Resources_detail

using Resources_detail::Image;

} // namespace Inugami

#endif // INUGAMI_IMAGE_H
