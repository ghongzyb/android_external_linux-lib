/*
 * Copyright 2004-2012 Freescale Semiconductor, Inc. All Rights Reserved.
 *
 */

/*
 * The code contained herein is licensed under the GNU Lesser General
 * Public License.  You may obtain a copy of the GNU Lesser General
 * Public License Version 2.1 or later at the following locations:
 *
 * http://www.opensource.org/licenses/lgpl-license.html
 * http://www.gnu.org/copyleft/lgpl.html
 */

/*!
 * @file vpu_debug.h
 *
 * @brief VPU debug definition
 *
 * @ingroup VPU
 */

#ifndef __VPU_DEBUG_H
#define __VPU_DEBUG_H

#ifdef BUILD_FOR_ANDROID
#define LOG_TAG "vpu-lib"
#include <utils/Log.h>
#endif

extern int vpu_lib_dbg_level;

#ifdef BUILD_FOR_ANDROID
#define dprintf(level, fmt, arg...)     if (vpu_lib_dbg_level >= level) \
        LOGD(fmt, ## arg)
#else
#define dprintf(level, fmt, arg...)     if (vpu_lib_dbg_level >= level) \
        printf("[DEBUG]\t%s:%d " fmt, __FILE__, __LINE__, ## arg)
#endif

#ifdef BUILD_FOR_ANDROID
#ifndef ALOGE
#define ALOGE LOGE
#endif
#ifndef ALOGW
#define ALOGW LOGW
#endif
#ifndef ALOGI
#define ALOGI LOGI
#endif
#define err_msg		ALOGE
#define info_msg	ALOGI
#define warn_msg	ALOGW
#else
#define err_msg(fmt, arg...) do { if (vpu_lib_dbg_level >= 1)		\
	printf("[ERR]\t%s:%d " fmt,  __FILE__, __LINE__, ## arg); else \
	printf("[ERR]\t" fmt, ## arg);	\
	} while (0)
#define info_msg(fmt, arg...) do { if (vpu_lib_dbg_level >= 1)		\
	printf("[INFO]\t%s:%d " fmt,  __FILE__, __LINE__, ## arg); else \
	printf("[INFO]\t" fmt, ## arg);	\
	} while (0)
#define warn_msg(fmt, arg...) do { if (vpu_lib_dbg_level >= 1)		\
	printf("[WARN]\t%s:%d " fmt,  __FILE__, __LINE__, ## arg); else \
	printf("[WARN]\t" fmt, ## arg);	\
	} while (0)
#endif

#define ENTER_FUNC() dprintf(4, "enter %s()\n", __func__)
#define EXIT_FUNC() dprintf(4, "exit %s()\n", __func__)

#endif
