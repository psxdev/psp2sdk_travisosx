/**
 * \file
 * \brief Header file which defines control related variables and functions
 *
 * Copyright (C) 2015 PSP2SDK Project
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef _PSP2_CTRL_H_
#define _PSP2_CTRL_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum {
	SCE_CTRL_ERROR_INVALID_ARG	= 0x80340001,
	SCE_CTRL_ERROR_PRIV_REQUIRED	= 0x80340002,
	SCE_CTRL_ERROR_FATAL		= 0x803400FF
};

/** Enumeration for the digital controller buttons. */
enum {
	/** Select button. */
	PSP2_CTRL_SELECT	= 0x000001,
	/** Start button. */
	PSP2_CTRL_START		= 0x000008,
	/** Up D-Pad button. */
	PSP2_CTRL_UP		= 0x000010,
	/** Right D-Pad button. */
	PSP2_CTRL_RIGHT		= 0x000020,
	/** Down D-Pad button. */
	PSP2_CTRL_DOWN		= 0x000040,
	/** Left D-Pad button. */
	PSP2_CTRL_LEFT		= 0x000080,
	/** Left trigger. */
	PSP2_CTRL_LTRIGGER	= 0x000100,
	/** Right trigger. */
	PSP2_CTRL_RTRIGGER	= 0x000200,
	/** Triangle button. */
	PSP2_CTRL_TRIANGLE	= 0x001000,
	/** Circle button. */
	PSP2_CTRL_CIRCLE	= 0x002000,
	/** Cross button. */
	PSP2_CTRL_CROSS		= 0x004000,
	/** Square button. */
	PSP2_CTRL_SQUARE	= 0x008000,
	/** Any input intercepted. */
	PSP2_CTRL_ANY		= 0x010000
};

/** Controller mode. */
enum {
	/** Digitial buttons only. */
	PSP2_CTRL_MODE_DIGITAL = 0,
	/** Digital buttons + Analog support. */
	PSP2_CTRL_MODE_ANALOG,
	/** Same as ::PSP2_CTRL_MODE_ANALOG, but with larger range for analog sticks. */
	PSP2_CTRL_MODE_ANALOG_WIDE
};

/** Returned controller data */
typedef struct SceCtrlData {
	/** The current read frame. */
	uint64_t	timeStamp;
	/** Bit mask containing zero or more of ::CtrlButtons. */
	unsigned int 	buttons;
	/** Left analogue stick, X axis. */
	unsigned char 	lx;
	/** Left analogue stick, Y axis. */
	unsigned char 	ly;
	/** Right analogue stick, X axis. */
	unsigned char 	rx;
	/** Right analogue stick, Y axis. */
	unsigned char 	ry;
	/** Reserved. */
	uint8_t 	reserved[16];
} SceCtrlData;

/** Structure to pass as argument to ::sceCtrlSetRapidFire */
typedef struct SceCtrlRapidFireRule {
	unsigned int Mask;
	unsigned int Trigger;
	unsigned int Target;
	unsigned int Delay;
	unsigned int Make;
	unsigned int Break;
} SceCtrlRapidFireRule;

/**
 * Set the controller mode.
 *
 * @param[in] mode - One of ::CtrlMode.
 *
 * @return The previous mode, <0 on error.
 */
int sceCtrlSetSamplingMode(int mode);

/**
 * Get the current controller mode.
 *
 * @param[out] pMode - Return value, see ::CtrlMode.
 *
 * @return The current mode, <0 on error.
 */
int sceCtrlGetSamplingMode(int *pMode);

/**
 * Get the controller state information (polling, positive logic).
 *
 * @param[in] port - use 0.
 * @param[out] *pad_data - see ::SceCtrlData.
 * @param[in] count - Buffers count.
 *
 * @return Buffers count, between 1 and 'count'. <0 on error.
 */
int sceCtrlPeekBufferPositive(int port, SceCtrlData *pad_data, int count);

/**
 * Get the controller state information (polling, negative logic).
 *
 * @param[in] port - use 0.
 * @param[out] *pad_data - see ::SceCtrlData.
 * @param[in] count - Buffers count.
 *
 * @return Buffers count, between 1 and 'count'. <0 on error.
 */
int sceCtrlPeekBufferNegative(int port, SceCtrlData *pad_data, int count);

/**
 * Get the controller state information (blocking, positive logic).
 *
 * @param[in] port - use 0.
 * @param[out] *pad_data - see ::SceCtrlData.
 * @param[in] count - Buffers count.
 *
 * @return Buffers count, between 1 and 'count'. <0 on error.
 */
int sceCtrlReadBufferPositive(int port, SceCtrlData *pad_data, int count);

/**
 * Get the controller state information (blocking, negative logic).
 *
 * @param[in] port - use 0.
 * @param[out] *pad_data - see ::SceCtrlData.
 * @param[in] count - Buffers count.
 *
 * @return Buffers count, between 1 and 'count'. <0 on error.
 */
int sceCtrlReadBufferNegative(int port, SceCtrlData *pad_data, int count);

/**
 * Set rules for button rapid fire
 *
 * @param[in] port - use 0.
 * @param[in] idx - rule index between 0-15
 * @param[in] pRule - structure ::SceCtrlRapidFireRule.
 *
 * @return 0, <0 on error.
 */
int sceCtrlSetRapidFire(int port, int idx, const SceCtrlRapidFireRule* pRule);

/**
 * Clear rules for button rapid fire
 *
 * @param[in] port - use 0.
 * @param[in] idx - rule index between 0-15
 *
 * @return 0, <0 on error.
 */
int sceCtrlClearRapidFire(int port, int idx);

#ifdef __cplusplus
}
#endif

#endif /* _PSP2CTRL_H_ */
