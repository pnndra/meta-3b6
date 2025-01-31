/**
 */

#ifndef __IPU_H
#define __IPU_H


#include <stdint.h>
#include <linux/types.h>
#include <linux/videodev2.h>

typedef unsigned char bool;

#define dma_addr_t int
#define u32 unsigned int
#define u8 unsigned char

/*!
 * Enumeration of IPU rotation modes
 */
typedef enum {
  /* Note the enum values correspond to BAM value */
  IPU_ROTATE_NONE           = 0,
  IPU_ROTATE_VERT_FLIP      = 1,
  IPU_ROTATE_HORIZ_FLIP     = 2,
  IPU_ROTATE_180            = 3,
  IPU_ROTATE_90_RIGHT       = 4,
  IPU_ROTATE_90_RIGHT_VFLIP = 5,
  IPU_ROTATE_90_RIGHT_HFLIP = 6,
  IPU_ROTATE_90_LEFT        = 7,
} ipu_rotate_mode_t;

/*  IPU Pixel format definitions */
/*  Four-character-code (FOURCC) */
#define fourcc(a, b, c, d)\
   (((__u32)(a)<<0)|((__u32)(b)<<8)|((__u32)(c)<<16)|((__u32)(d)<<24))

/*!
 * @name IPU Pixel Formats
 *
 * Pixel formats are defined with ASCII FOURCC code. The pixel format codes are
 * the same used by V4L2 API.
 */

/*! @{ */
/*! @name Generic or Raw Data Formats */
/*! @{ */
#define IPU_PIX_FMT_GENERIC fourcc('I', 'P', 'U', '0')  /*!< IPU Generic Data */
#define IPU_PIX_FMT_GENERIC_32 fourcc('I', 'P', 'U', '1') /*!< IPU Generic Data */
#define IPU_PIX_FMT_LVDS666 fourcc('L', 'V', 'D', '6')  /*!< IPU Generic Data */
#define IPU_PIX_FMT_LVDS888 fourcc('L', 'V', 'D', '8')  /*!< IPU Generic Data */
/*! @} */
/*! @name RGB Formats */
/*! @{ */
#define IPU_PIX_FMT_RGB332  fourcc('R', 'G', 'B', '1')  /*!<  8  RGB-3-3-2    */
#define IPU_PIX_FMT_RGB555  fourcc('R', 'G', 'B', 'O')  /*!< 16  RGB-5-5-5    */
#define IPU_PIX_FMT_RGB565  fourcc('R', 'G', 'B', 'P')  /*!< 16  RGB-5-6-5    */
#define IPU_PIX_FMT_RGB666  fourcc('R', 'G', 'B', '6')  /*!< 18  RGB-6-6-6    */
#define IPU_PIX_FMT_BGR666  fourcc('B', 'G', 'R', '6')  /*!< 18  BGR-6-6-6    */
#define IPU_PIX_FMT_BGR24   fourcc('B', 'G', 'R', '3')  /*!< 24  BGR-8-8-8    */
#define IPU_PIX_FMT_RGB24   fourcc('R', 'G', 'B', '3')  /*!< 24  RGB-8-8-8    */
#define IPU_PIX_FMT_GBR24   fourcc('G', 'B', 'R', '3')  /*!< 24  GBR-8-8-8    */
#define IPU_PIX_FMT_BGR32   fourcc('B', 'G', 'R', '4')  /*!< 32  BGR-8-8-8-8  */
#define IPU_PIX_FMT_BGRA32  fourcc('B', 'G', 'R', 'A')  /*!< 32  BGR-8-8-8-8  */
#define IPU_PIX_FMT_RGB32   fourcc('R', 'G', 'B', '4')  /*!< 32  RGB-8-8-8-8  */
#define IPU_PIX_FMT_RGBA32  fourcc('R', 'G', 'B', 'A')  /*!< 32  RGB-8-8-8-8  */
#define IPU_PIX_FMT_ABGR32  fourcc('A', 'B', 'G', 'R')  /*!< 32  ABGR-8-8-8-8 */
/*! @} */
/*! @name YUV Interleaved Formats */
/*! @{ */
#define IPU_PIX_FMT_YUYV    fourcc('Y', 'U', 'Y', 'V')  /*!< 16 YUV 4:2:2 */
#define IPU_PIX_FMT_UYVY    fourcc('U', 'Y', 'V', 'Y')  /*!< 16 YUV 4:2:2 */
#define IPU_PIX_FMT_YVYU    fourcc('Y', 'V', 'Y', 'U')  /*!< 16 YVYU 4:2:2 */
#define IPU_PIX_FMT_VYUY    fourcc('V', 'Y', 'U', 'Y')  /*!< 16 VYYU 4:2:2 */
#define IPU_PIX_FMT_Y41P    fourcc('Y', '4', '1', 'P')  /*!< 12 YUV 4:1:1 */
#define IPU_PIX_FMT_YUV444  fourcc('Y', '4', '4', '4')  /*!< 24 YUV 4:4:4 */
#define IPU_PIX_FMT_VYU444  fourcc('V', '4', '4', '4')  /*!< 24 VYU 4:4:4 */
/* two planes -- one Y, one Cb + Cr interleaved  */
#define IPU_PIX_FMT_NV12    fourcc('N', 'V', '1', '2') /* 12  Y/CbCr 4:2:0  */
/*! @} */
/*! @name YUV Planar Formats */
/*! @{ */
#define IPU_PIX_FMT_GREY    fourcc('G', 'R', 'E', 'Y')  /*!< 8  Greyscale */
#define IPU_PIX_FMT_YVU410P fourcc('Y', 'V', 'U', '9')  /*!< 9  YVU 4:1:0 */
#define IPU_PIX_FMT_YUV410P fourcc('Y', 'U', 'V', '9')  /*!< 9  YUV 4:1:0 */
#define IPU_PIX_FMT_YVU420P fourcc('Y', 'V', '1', '2')  /*!< 12 YVU 4:2:0 */
#define IPU_PIX_FMT_YUV420P fourcc('I', '4', '2', '0')  /*!< 12 YUV 4:2:0 */
#define IPU_PIX_FMT_YUV420P2 fourcc('Y', 'U', '1', '2') /*!< 12 YUV 4:2:0 */
#define IPU_PIX_FMT_YVU422P fourcc('Y', 'V', '1', '6')  /*!< 16 YVU 4:2:2 */
#define IPU_PIX_FMT_YUV422P fourcc('4', '2', '2', 'P')  /*!< 16 YUV 4:2:2 */
/*! @} */

/* IPU device */
typedef enum {
  RGB_CS,
  YUV_CS,
  NULL_CS
} cs_t;

struct ipu_pos {
  u32 x;
  u32 y;
};

struct ipu_crop {
  struct ipu_pos pos;
  u32 w;
  u32 h;
};

struct ipu_deinterlace {
  bool  enable;
  u8  motion; /*see ipu_motion_sel*/
#define IPU_DEINTERLACE_FIELD_TOP 0
#define IPU_DEINTERLACE_FIELD_BOTTOM  1
  u8  field_fmt;
};

struct ipu_input {
  u32 width;
  u32 height;
  u32 format;
  struct ipu_crop crop;
  dma_addr_t paddr;

  struct ipu_deinterlace deinterlace;
  dma_addr_t paddr_n; /*valid when deinterlace enable*/
};

struct ipu_alpha {
#define IPU_ALPHA_MODE_GLOBAL 0
#define IPU_ALPHA_MODE_LOCAL  1
  u8 mode;
  u8 gvalue; /* 0~255 */
  dma_addr_t loc_alp_paddr;
};

struct ipu_colorkey {
  bool enable;
  u32 value; /* RGB 24bit */
};

struct ipu_overlay {
  u32 width;
  u32 height;
  u32 format;
  struct ipu_crop crop;
  struct ipu_alpha alpha;
  struct ipu_colorkey colorkey;
  dma_addr_t paddr;
};

struct ipu_output {
  u32 width;
  u32 height;
  u32 format;
  u8  rotate;
  struct ipu_crop crop;
  dma_addr_t paddr;
};

struct ipu_task {
  struct ipu_input input;
  struct ipu_output output;

  bool overlay_en;
  struct ipu_overlay overlay;

#define IPU_TASK_PRIORITY_NORMAL 0
#define IPU_TASK_PRIORITY_HIGH  1
  u8  priority;

#define IPU_TASK_ID_ANY 0
#define IPU_TASK_ID_VF  1
#define IPU_TASK_ID_PP  2
#define IPU_TASK_ID_MAX 3
  u8  task_id;

  int timeout;
};

/* IOCTL commands */
#define IPU_CHECK_TASK    _IOWR('I', 0x1, struct ipu_task)
#define IPU_QUEUE_TASK    _IOW('I', 0x2, struct ipu_task)
#define IPU_ALLOC         _IOWR('I', 0x3, int)
#define IPU_FREE          _IOW('I', 0x4, int)

typedef struct {
  int             fd;
  struct ipu_task task;
  int             isize;
  void           *inbuf;
}sIpuHnd, *psIpuHnd;


psIpuHnd ipuOpen(char* device, int bpp);
int ipuClose(psIpuHnd pHnd);
int ipuRotate(psIpuHnd pHnd, uint32_t paddr, int x, int y, int w, int h, int rot);

#endif /* __IPU_H */
