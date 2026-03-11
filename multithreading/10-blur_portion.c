#include "multithreading.h"

/**
 * blur_portion - Blurs a portion of an image using a Gaussian Blur
 * @portion: Pointer to the blur_portion_t structure
 */
void blur_portion(blur_portion_t const *portion)
{
    size_t i, j, k_row, k_col;
    size_t k_size, k_offset;
    float r, g, b, weight;
    pixel_t *src_pixels, *dest_pixels;

    /* Proper validation: Check for NULL and return immediately */
    if (!portion || !portion->img || !portion->img_blur || !portion->kernel)
        return;

    src_pixels = portion->img->pixels;
    dest_pixels = portion->img_blur->pixels;
    k_size = portion->kernel->size;
    k_offset = k_size / 2;

    for (j = portion->y; j < portion->y + portion->h; j++)
    {
        for (i = portion->x; i < portion->x + portion->w; i++)
        {
            r = g = b = 0.0;
            for (k_row = 0; k_row < k_size; k_row++)
            {
                for (k_col = 0; k_col < k_size; k_col++)
                {
                    size_t cur_y = j + k_row - k_offset;
                    size_t cur_x = i + k_col - k_offset;

                    if (cur_y < portion->img->h && cur_x < portion->img->w)
                    {
                        weight = portion->kernel->matrix[k_row][k_col];
                        pixel_t p = src_pixels[cur_y * portion->img->w + cur_x];
                        r += p.r * weight;
                        g += p.g * weight;
                        b += p.b * weight;
                    }
                }
            }
            dest_pixels[j * portion->img->w + i] = (pixel_t){(uint8_t)r, (uint8_t)g, (uint8_t)b};
        }
    }
}
