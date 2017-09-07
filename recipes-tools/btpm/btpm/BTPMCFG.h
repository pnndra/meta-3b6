/*****< btpmcfg.h >************************************************************/
/*      Copyright 2010 - 2014 Stonestreet One.                                */
/*      All Rights Reserved.                                                  */
/*                                                                            */
/*      Copyright 2015 Texas Instruments Incorporated.                        */
/*      All Rights Reserved.                                                  */
/*                                                                            */
/*  BTPSCFG - Stonestreet One Bluetopia Platform Manager configuration        */
/*            directives/constants.  The information contained in this file   */
/*            controls various compile time parameters that are needed to     */
/*            build Bluetopia Platform Manager for a specific platform.       */
/*                                                                            */
/*  Author:  Damon Lange                                                      */
/*                                                                            */
/*** MODIFICATION HISTORY *****************************************************/
/*                                                                            */
/*   mm/dd/yy  F. Lastname    Description of Modification                     */
/*   --------  -----------    ------------------------------------------------*/
/*   05/23/10  D. Lange       Initial creation.                               */
/*   11/11/15  D. Horowitz    Initial creation.                               */
/******************************************************************************/
#ifndef __BTPMCFGH__
#define __BTPMCFGH__

#include "BTPSKRNL.h"           /* BTPS Kernel Prototypes/Constants.          */

   /* Debug Configuration.                                              */
#define BTPM_CONFIGURATION_DEBUG_MAXIMUM_DEBUG_DUMP_LIMIT                     0
#define BTPM_CONFIGURATION_DEBUG_DEFAULT_DEBUG_ZONES_PAGE_0          0x00000000
#define BTPM_CONFIGURATION_DEBUG_DEFAULT_DEBUG_ZONES_PAGE_1          0x00000000
#define BTPM_CONFIGURATION_DEBUG_DEFAULT_DEBUG_ZONES_PAGE_2          0x00000000
#define BTPM_CONFIGURATION_DEBUG_DEFAULT_DEBUG_ZONES_PAGE_3          0x00000000
#define BTPM_CONFIGURATION_DEBUG_DEBUG_PREFIX_FORMAT                 "[BTPM] %s:"
#define BTPM_CONFIGURATION_DEBUG_DEBUG_PREFIX_PARAMETERS             __FUNCTION__
#define BTPM_CONFIGURATION_DEBUG_DEBUG_FRAMEWORK_PRESENT                      1

   /* Internal Timer Module Configuration.                              */
#define BTPM_CONFIGURATION_TIMER_MAXIMUM_NUMBER_CONCURRENT_TIMERS           128
#define BTPM_CONFIGURATION_TIMER_TIMER_THREAD_STACK_SIZE                  32768
#define BTPM_CONFIGURATION_TIMER_MINIMUM_TIMER_RESOLUTION_MS                500

   /* Message Sub-system Configuration.                                 */
#define BTPM_CONFIGURATION_MESSAGE_EVENT_POOL_SIZE                           16

   /* Configuration Settings Store Configuration.                       */
#define BTPM_CONFIGURATION_SETTINGS_MAXIMUM_FILE_LINE_LENGTH               1024
#define BTPM_CONFIGURATION_SETTINGS_MAXIMUM_FILE_PATH_LENGTH               1024
#define BTPM_CONFIGURATION_SETTINGS_PATH_DELIMETER_STRING                   "/"
#define BTPM_CONFIGURATION_SETTINGS_PATH_DELIMETER_CHARACTER                '/'

   /* Local Device Manager Configuration.                               */
#define BTPM_CONFIGURATION_DEVICE_MANAGER_NUMBER_DISPATCH_MAILBOX_SLOTS    8192
#define BTPM_CONFIGURATION_DEVICE_MANAGER_THREAD_STACK_SIZE               65536
#define BTPM_CONFIGURATION_DEVICE_MANAGER_THREAD_SHUTDOWN_TIME_MS          2000
#define BTPM_CONFIGURATION_DEVICE_MANAGER_POWER_DOWN_TIME_MS               3000
#define BTPM_CONFIGURATION_DEVICE_MANAGER_GENERAL_MESSAGE_RESPONSE_TIME_MS 6000
#define BTPM_CONFIGURATION_DEVICE_MANAGER_POWER_MESSAGE_RESPONSE_TIME_MS   15000
#define BTPM_CONFIGURATION_DEVICE_MANAGER_DEVICE_FILE_MAXIMUM_LINE_LENGTH   512
#define BTPM_CONFIGURATION_DEVICE_MANAGER_DEVICE_FILE_DELIMETER_STRING      "|"
#define BTPM_CONFIGURATION_DEVICE_MANAGER_DEVICE_FILE_DELIMETER_CHARACTER   '|'

#define BTPM_CONFIGURATION_DEVICE_MANAGER_DEVICE_SETTINGS_SECTION_NAME "Local Device"

#define BTPM_CONFIGURATION_DEVICE_MANAGER_DEFAULT_DEVICE_NAME            "WL18xx Device"
#define BTPM_CONFIGURATION_DEVICE_MANAGER_DEFAULT_CLASS_OF_DEVICE(_c)    ASSIGN_CLASS_OF_DEVICE(_c, 0x24, 0x04, 0x1C)
#define BTPM_CONFIGURATION_DEVICE_MANAGER_DEFAULT_DISCOVERABLE_MODE        TRUE
#define BTPM_CONFIGURATION_DEVICE_MANAGER_DEFAULT_CONNECTABLE_MODE         TRUE
#define BTPM_CONFIGURATION_DEVICE_MANAGER_DEFAULT_PAIRING_ALLOWED_STATE    TRUE
#define BTPM_CONFIGURATION_DEVICE_MANAGER_DEFAULT_PAIRABILITY_MODE_SSP     TRUE
#define BTPM_CONFIGURATION_DEVICE_MANAGER_CACHE_NON_PAIRED_DEVICES        FALSE
#define BTPM_CONFIGURATION_DEVICE_MANAGER_MAXIMUM_DEVICES_READ_FROM_CACHE  8192

#define BTPM_CONFIGURATION_DEVICE_MANAGER_DEFAULT_ASCII_DEBUG_FILE_NAME  "SS1BTPM_ASC.log"
#define BTPM_CONFIGURATION_DEVICE_MANAGER_DEFAULT_FTS_DEBUG_FILE_NAME    "SS1BTPM_FTS.log"

#define BTPM_CONFIGURATION_DEVICE_MANAGER_DEVICE_ID_INFORMATION_PRESENT       1
#define BTPM_CONFIGURATION_DEVICE_MANAGER_DEFAULT_DEVICE_ID_VENDOR_ID    (HCI_LMP_COMPID_MANUFACTURER_NAME_TEXAS_INSTRUMENTS)
#define BTPM_CONFIGURATION_DEVICE_MANAGER_DEFAULT_DEVICE_ID_PRODUCT_ID   0x0001
#define BTPM_CONFIGURATION_DEVICE_MANAGER_DEFAULT_DEVICE_ID_VERSION      0x0112
#define BTPM_CONFIGURATION_DEVICE_MANAGER_DEFAULT_DEVICE_ID_USB_VEND_ID   FALSE

#define BTPM_CONFIGURATION_DEVICE_MANAGER_INTERLACED_INQUIRY_SCAN             1
#define BTPM_CONFIGURATION_DEVICE_MANAGER_INTERLACED_PAGE_SCAN                1

#define BTPM_CONFIGURATION_DEVICE_MANAGER_RESET_SCAN_MODE_ON_SHUTDOWN         1
#define BTPM_CONFIGURATION_DEVICE_MANAGER_RESET_DEVICE_ON_SHUTDOWN            1

#define BTPM_CONFIGURATION_DEVICE_MANAGER_MAXIMUM_CONNECTION_REQUESTS         3
#define BTPM_CONFIGURATION_DEVICE_MANAGER_MAXIMUM_NAME_DISCOVERY_REQUESTS     2
#define BTPM_CONFIGURATION_DEVICE_MANAGER_MAXIMUM_SERVICE_DISCOVERY_REQUESTS  2

#define BTPM_CONFIGURATION_DEVICE_MANAGER_DISCOVERY_TIMEOUT_EXTENSION_MS   3000
#define BTPM_CONFIGURATION_DEVICE_MANAGER_MAXIMUM_DISCOVERY_EXTENSIONS        5
#define BTPM_CONFIGURATION_DEVICE_MANAGER_DISCOVERY_NUMBER_NAME_RETRIES       2
#define BTPM_CONFIGURATION_DEVICE_MANAGER_DISCOVERY_OUTSTANDING_REQUESTS  (BTPM_CONFIGURATION_DEVICE_MANAGER_MAXIMUM_CONNECTION_REQUESTS)
#define BTPM_CONFIGURATION_DEVICE_MANAGER_RSSI_PROPERTY_CHANGE_THRESHOLD      0

#define BTPM_CONFIGURATION_DEVICE_MANAGER_SERVICE_DISCOVERY_IDLE_TIMEOUT_MS   1500

#define BTPM_CONFIGURATION_DEVICE_MANAGER_SUPPORT_LOW_ENERGY                  1
#define BTPM_CONFIGURATION_DEVICE_MANAGER_SUPPORT_ANT                         0
#define BTPM_CONFIGURATION_DEVICE_MANAGER_SUPPORT_LOCAL_RANDOM_ADDRESSING     1
#define BTPM_CONFIGURATION_DEVICE_MANAGER_DEFAULT_RANDOM_ADDRESS_USE_COUNT    0
#define BTPM_CONFIGURATION_DEVICE_MANAGER_DEFAULT_DEVICE_APPEARANCE           0x0000
#define BTPM_CONFIGURATION_DEVICE_MANAGER_DEFAULT_MINIMUM_CONNECTION_INTERVAL 20
#define BTPM_CONFIGURATION_DEVICE_MANAGER_DEFAULT_MAXIMUM_CONNECTION_INTERVAL 40
#define BTPM_CONFIGURATION_DEVICE_MANAGER_DEFAULT_SLAVE_LATENCY               0
#define BTPM_CONFIGURATION_DEVICE_MANAGER_DEFAULT_SUPERVISION_TIMEOUT         5000
#define BTPM_CONFIGURATION_DEVICE_MANAGER_DEFAULT_SCAN_INTERVAL               60
#define BTPM_CONFIGURATION_DEVICE_MANAGER_DEFAULT_SCAN_WINDOW                 20
#define BTPM_CONFIGURATION_DEVICE_MANAGER_DEFAULT_ADVERTISING_INTV_MIN        100
#define BTPM_CONFIGURATION_DEVICE_MANAGER_DEFAULT_ADVERTISING_INTV_MAX        200
#define BTPM_CONFIGURATION_DEVICE_MANAGER_DEFAULT_CONNECTION_TIMEOUT_MS       40000
#define BTPM_CONFIGURATION_DEVICE_MANAGER_USE_PREFERRED_CONNECTION_PARAMETERS TRUE
#define BTPM_CONFIGURATION_DEVICE_MANAGER_FORCE_MIN_PREFERRED_CONN_INTERVAL   FALSE

#define BTPM_CONFIGURATION_DEVICE_MANAGER_DEFAULT_MIN_ALLOWABLE_MIN_CONNECTION_INTERVAL 10
#define BTPM_CONFIGURATION_DEVICE_MANAGER_DEFAULT_MIN_ALLOWABLE_MAX_CONNECTION_INTERVAL 20

   /* Serial Port Manager Configuration.                                */
#define BTPM_CONFIGURATION_SERIAL_PORT_MANAGER_PORT_CLOSE_DELAY_TIME_MS      50
#define BTPM_CONFIGURATION_SERIAL_PORT_MANAGER_PORT_CLOSE_DELAY_RETRIES      20

#define BTPM_CONFIGURATION_SERIAL_PORT_MANAGER_PORT_OPEN_DELAY_TIME_MS      100
#define BTPM_CONFIGURATION_SERIAL_PORT_MANAGER_PORT_OPEN_DELAY_RETRIES       10

#define BTPM_CONFIGURATION_SERIAL_PORT_MANAGER_DEFAULT_CONFIGURATION_FLAGS    0

#define BTPM_CONFIGURATION_SERIAL_PORT_MANAGER_SUPPORT_MFI                 ISPP_SUPPORT
#define BTPM_CONFIGURATION_SERIAL_PORT_MANAGER_MFI_AUTHENTICATION_DELAY_MS 2000



   /* Generic Attribute Profile Manager Configuration.                  */
#define BTPM_CONFIGURATION_GENERIC_ATTRIBUTE_MANAGER_SUPPORTED                       TRUE
#define BTPM_CONFIGURATION_GENERIC_ATTRIBUTE_MANAGER_GATT_QUEUE_DEPTH                4
#define BTPM_CONFIGURATION_GENERIC_ATTRIBUTE_MANAGER_GATT_QUEUE_THRESHOLD            0
#define BTPM_CONFIGURATION_GENERIC_ATTRIBUTE_MANAGER_PERSISTENT_SERVICE_START_HANDLE 0x0200
#define BTPM_CONFIGURATION_GENERIC_ATTRIBUTE_MANAGER_PERSISTENT_SERVICE_END_HANDLE   0x3FFF
#define BTPM_CONFIGURATION_GENERIC_ATTRIBUTE_MANAGER_DYNAMIC_SERVICE_START_HANDLE    0x4000
#define BTPM_CONFIGURATION_GENERIC_ATTRIBUTE_MANAGER_DYNAMIC_SERVICE_END_HANDLE      0xFFFF

   /* Main Module Configuration.                                        */
#define BTPM_CONFIGURATION_MAIN_NUMBER_DISPATCH_MAILBOX_SLOTS              4096
#define BTPM_CONFIGURATION_MAIN_THREAD_STACK_SIZE                         65536
#define BTPM_CONFIGURATION_MAIN_THREAD_SHUTDOWN_TIME_MS                    2000

#define BTPM_CONFIGURATION_MAIN_CONFIGURATION_FILE_NAME                "BTPMCFG.btc"
#define BTPM_CONFIGURATION_MAIN_REMOTE_DEVICE_FILE_NAME                "BTPMDEV.btd"

   /* LE Profile Configuration.                                         */
#define BTPM_CONFIGURATION_LOW_ENERGY_CONFIGURATION_FILE_NAME          "BTPMLECFG.btc"

   /* Linux specific Configuration Information.                         */
#define BTPM_LINUX_IPC_DEVICE_PATH                                     "/tmp/SS1BTPMS"

#endif
