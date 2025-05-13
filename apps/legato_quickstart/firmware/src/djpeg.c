/*
 * djpeg.c
 *
 * Copyright (C) 1991-1997, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains a command-line user interface for the JPEG decompressor.
 * It should work on any system with Unix- or MS-DOS-style command lines.
 *
 * Two different command line styles are permitted, depending on the
 * compile-time switch TWO_FILE_COMMANDLINE:
 *	djpeg [options]  inputfile outputfile
 *	djpeg [options]  [inputfile]
 * In the second style, output is always to standard output, which you'd
 * normally redirect to a file or pipe to some other program.  Input is
 * either from a named file or from standard input (typically redirected).
 * The second style is convenient on Unix but is unhelpful on systems that
 * don't support pipes.  Also, you MUST use the first style if your system
 * doesn't do binary I/O to stdin/stdout.
 * To simplify script writing, the "-outfile" switch is provided.  The syntax
 *	djpeg [options]  -outfile outputfile  inputfile
 * works regardless of which command line style is used.
 */

#include "cdjpeg.h"		/* Common decls for cjpeg/djpeg applications */

#include <ctype.h>		/* to declare isprint() */

#define MAX_LUMA_WIDTH   1024
#define MAX_CHROMA_WIDTH 512

static char buf0[16][MAX_LUMA_WIDTH];
static char buf1[8][MAX_CHROMA_WIDTH];
static char buf2[8][MAX_CHROMA_WIDTH];

JSAMPROW row0[16] = { buf0[0], buf0[1], buf0[2], buf0[3],
                      buf0[4], buf0[5], buf0[6], buf0[7],
                      buf0[8], buf0[9], buf0[10], buf0[11],
                      buf0[12], buf0[13], buf0[14], buf0[15]};
JSAMPROW row1[8] = { buf1[0], buf1[1], buf1[2], buf1[3],
                     buf1[4], buf1[5], buf1[6], buf1[7]};
JSAMPROW row2[8] = { buf2[0], buf2[1], buf2[2], buf2[3],
                     buf2[4], buf2[5], buf2[6], buf2[7]};
JSAMPARRAY scanarray[3] = { row0, row1, row2 };

static const char * const cdjpeg_message_table[] = {
#include "cderror.h"
  NULL
};

/*
 * The main program.
 */

int
//main (int argc, char **argv)
djpeg (char *p_jpg, int jpg_len, char *p_y, char *p_u, char *p_v, int *p_width, int *p_height)
{
  struct jpeg_decompress_struct cinfo;
  struct jpeg_error_mgr jerr;
  int lines;
  int ret;
  int i, j;

  /* Initialize the JPEG decompression object with default error handling. */
  cinfo.err = jpeg_std_error(&jerr);
  jpeg_create_decompress(&cinfo);
  /* Add some application-specific error messages (from cderror.h) */
  jerr.addon_message_table = cdjpeg_message_table;
  jerr.first_addon_message = JMSG_FIRSTADDONCODE;
  jerr.last_addon_message = JMSG_LASTADDONCODE;

  /* Specify data source for decompression */
  jpeg_stdio_src(&cinfo, NULL, p_jpg, jpg_len);

  /* Read file header, set default decompression parameters */
  (void) jpeg_read_header(&cinfo, TRUE);

#if 0
  fprintf(stderr, "haha image_width  = %d\n\r", cinfo.image_width);
  fprintf(stderr, "haha image_height = %d\n\r", cinfo.image_height);
  fprintf(stderr, "haha output_width  = %d\n\r", cinfo.output_width);
  fprintf(stderr, "haha output_height = %d\n\r", cinfo.output_height);
  fprintf(stderr, "haha jpeg_color_space = %d\n\r", cinfo.jpeg_color_space);
  fprintf(stderr, "haha num_components = %d\n\r", cinfo.num_components);
#endif
  /* Adjust default decompression parameters by re-parsing the options */
  //cinfo.err->trace_level = 0;
  cinfo.raw_data_out = TRUE;
  cinfo.out_color_space = JCS_YCbCr;
  //cinfo.two_pass_quantize = FALSE;
  //cinfo.dither_mode = JDITHER_ORDERED;
  cinfo.dither_mode = JDITHER_NONE;
  cinfo.dct_method = JDCT_IFAST;
  cinfo.do_fancy_upsampling = FALSE;
  //cinfo.do_block_smoothing = TRUE;

  /* Start decompressor */
  (void) jpeg_start_decompress(&cinfo);

  *p_width  = cinfo.output_width;
  *p_height = cinfo.output_height;
#if 0
  fprintf(stderr, "haha output_width  = %d\n\r", cinfo.output_width);
  fprintf(stderr, "haha output_height = %d\n\r", cinfo.output_height);
  fprintf(stderr, "haha out_color_space = %d\n\r", cinfo.out_color_space);
  fprintf(stderr, "haha output_components = %d\n\r", cinfo.output_components);
  fprintf(stderr, "haha scale_num = %d\n\r", cinfo.scale_num);
  fprintf(stderr, "haha scale_denom = %d\n\r", cinfo.scale_denom);
  fprintf(stderr, "haha raw_data_out = %d\n\r", cinfo.raw_data_out);
  fprintf(stderr, "haha rec_outbuf_height = %d\n\r", cinfo.rec_outbuf_height);
  fprintf(stderr, "haha enable_1pass_quant = %d\n\r", cinfo.enable_1pass_quant);
  fprintf(stderr, "haha enable_external_quant = %d\n\r", cinfo.enable_external_quant);
  fprintf(stderr, "haha enable_2pass_quant = %d\n\r", cinfo.enable_2pass_quant);
#endif

  lines = cinfo.max_v_samp_factor * cinfo.min_DCT_scaled_size;
    //fprintf(stderr, "haha lines = %d\n\r", lines);

  /* Process data */
  while (cinfo.output_scanline < cinfo.output_height) {
    ret = jpeg_read_raw_data(&cinfo, scanarray, lines);
    if (!ret)
	return -1;

    for (i=0; i<ret; i++)
      for (j=0; j<cinfo.output_width; j++)
        *p_y++ = buf0[i][j];

    for (i=0; i<ret/2; i++)
      for (j=0; j<cinfo.output_width/2; j++) {
        *p_u++ = buf1[i][j];
        *p_v++ = buf2[i][j];
      }
    //ret = jpeg_read_scanlines(&cinfo, output_buff, 1);
    //fprintf(stderr, "haha read lines = %d\n\r", ret);
    //fprintf(stderr, "haha output_height = %d\n\r", cinfo.output_height);
    //fprintf(stderr, "haha output_scanline = %d\n\r", cinfo.output_scanline);
#if 0
    for (i=0; i<ret; i++) {
      //for (j=0; j<cinfo.output_width; j++)
      for (j=0; j<cinfo.output_width; j+=2)
        fprintf(stderr, "%02x", buf0[i][j]);
      fprintf(stderr, "\n\r");
    }
#endif
#if 0
    for (i=0; i<ret/2; i++) {
      for (j=0; j<cinfo.output_width/2; j++)
        fprintf(stderr, "%02x", buf1[i][j]);
      fprintf(stderr, "\n\r");
    }
#endif
#if 0
    for (i=0; i<ret/2; i++) {
      for (j=0; j<cinfo.output_width/2; j++)
        fprintf(stderr, "%02x", buf2[i][j]);
      fprintf(stderr, "\n\r");
    }
#endif
  }

  (void) jpeg_finish_decompress(&cinfo);
  jpeg_destroy_decompress(&cinfo);

  /* All done. */
  //exit(jerr.num_warnings ? EXIT_WARNING : EXIT_SUCCESS);
  return 0;			/* suppress no-return-value warnings */
}
