/*
 * Copyright (c) 2021 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#ifndef ZB_ZCL_ON_OFF_ADDONS_H__
#define ZB_ZCL_ON_OFF_ADDONS_H__

#include "zboss_api.h"

/*! \addtogroup zb_zcl_on_off_addons */
/*! @{ */

/**@brief On/Off cluster attributes according to ZCL Spec 3.8.2.2. */
typedef struct
{
    zb_bool_t   on_off;
    zb_bool_t   global_scene_ctrl;
    zb_uint16_t on_time;
    zb_uint16_t off_wait_time;
} zb_zcl_on_off_attrs_ext_t;

/**@brief Macro equivalent to @ref ZB_ZCL_ON_OFF_SEND_REQ, but command is sent without APS ACK. */
#define ZB_ZCL_ON_OFF_SEND_REQ_NO_APS_ACK(                                              \
    buffer, addr, dst_addr_mode, dst_ep, ep, prof_id, dis_default_resp, command_id, cb) \
{                                                                                       \
  zb_uint8_t* ptr = ZB_ZCL_START_PACKET_REQ(buffer)                                     \
  ZB_ZCL_CONSTRUCT_SPECIFIC_COMMAND_REQ_FRAME_CONTROL(ptr, dis_default_resp)            \
  ZB_ZCL_CONSTRUCT_COMMAND_HEADER_REQ(ptr, ZB_ZCL_GET_SEQ_NUM(), command_id);           \
  ZB_ZCL_SEND_COMMAND_SHORT_WITHOUT_ACK((buffer), ptr, (zb_addr_u *)(&(addr),           \
            dst_addr_mode, dst_ep, ep, prof_id, ZB_ZCL_CLUSTER_ID_ON_OFF, cb, 0);       \
}

/** @} */

#endif /* ZB_ZCL_ON_OFF_ADDONS_H__ */
