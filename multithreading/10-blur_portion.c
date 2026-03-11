#include "multithreading.h"

/**
 * blur_portion - Blurs a portion of an image using a Gaussian Blur
 * @portion: Pointer to the blur_portion_t structure
 */
void blur_portion(blur_portion_t const *portion)
{
	size_t x, y, k_row, k_col;
	size_t k_size, k_offset;
	float r, g, b, weight;
	int cur_x, cur_y;
	pixel_t *src_pixels, *dest_pixels;
	size_t img_w, img_h;

	if (!portion || !portion->img || !portion->img_blur || !portion->kernel)
		return;

	src_pixels = portion->img->pixels;
	dest_pixels = portion->img_blur->pixels;
	img_w = portion->img->w;
	img_h = portion->img->h;

	k_size = portion->kernel->size;
	k_offset = k_size / 2;

	for (y = portion->y; y < portion->y + portion->h; y++)
	{
		for (x = portion->x; x < portion->x + portion->w; x++)
		{
			r = 0.0;
			g = 0.0;
			b = 0.0;

			for (k_row = 0; k_row < k_size; k_row++)
			{
				for (k_col = 0; k_col < k_size; k_col++)
				{
					cur_y = (int)y + (int)k_row - (int)k_offset;
					cur_x = (int)x + (int)k_col - (int)k_offset;

					if (cur_y >= 0 && cur_y < (int)img_h &&
					    cur_x >= 0 && cur_x < (int)img_w)
					{
						weight = portion->kernel->matrix[k_row][k_col];

						r += src_pixels[cur_y * img_w + cur_x].r * weight;
						g += src_pixels[cur_y * img_w + cur_x].g * weight;
						b += src_pixels[cur_y * img_w + cur_x].b * weight;
					}
				}
			}

			dest_pixels[y * img_w + x].r = (uint8_t)r;
			dest_pixels[y * img_w + x].g = (uint8_t)g;
			dest_pixels[y * img_w + x].b = (uint8_t)b;
		}
	}
}
