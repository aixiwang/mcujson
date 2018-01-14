#ifndef __MAIN_H__ 
#define __MAIN_H__

/** Entry point for example_3. */
int example_3_entry(int argc, char **argv);

int set_file_content(const char *filename, const char *content, unsigned long content_size);

int get_file_content(const char *filename, char *content, unsigned long *max_content_size);

#endif
