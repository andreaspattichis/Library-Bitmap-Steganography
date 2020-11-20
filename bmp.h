#include <stdint.h>

//structure to hold all necessary image data
typedef struct{
    unsigned char *pixel_array;
    int padding;
    int pixel_array_size;
    uint32_t width;
    uint32_t height;
    uint32_t row_length;
    uint32_t bbp;
} IMAGE;

//print out pixel data to std out omitting padded bytes
extern void print_pixel_array(IMAGE *img);

//convert the pixel array in-place from blue, green, red colour space, to the red, green, blue colour space
extern void convert_to_rgb(IMAGE *img);

//this reverses the pixel array because BMP files by definition are stored upside down
extern void reverse_pixel_array(IMAGE *img);

//load bmp file image data into a struct
extern IMAGE* load_bmp(const char *file_name);

//free the memory used by the images pixel data
void free_img(unsigned char *pixel_array, IMAGE *img);

//get the colour depth for the currently loaded image as integer.
extern uint16_t get_colour_depth(IMAGE *img);