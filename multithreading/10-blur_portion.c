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
	size_t cur_y, cur_x;

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
					/* Calculate and check for top/left overflow before assigning to size_t */
					cur_y = j + k_row - k_offset;
					cur_x = i + k_col - k_offset;

					/* Strict boundary check for all 4 sides */
					if (cur_y < portion->img->h && cur_x < portion->img->w)
					{
						weight = portion->kernel->matrix[k_row][k_col];
						r += src_pixels[cur_y * portion->img->w + cur_x].r * weight;
						g += src_pixels[cur_y * portion->img->w + cur_x].g * weight;
						b += src_pixels[cur_y * portion->img->w + cur_x].b * weight;
					}
				}
			}
			dest_pixels[j * portion->img->w + i].r = (uint8_t)r;
			dest_pixels[j * portion->img->w + i].g = (uint8_t)g;
			dest_pixels[j * portion->img->w + i].b = (uint8_t)b;
		}
	}
}
