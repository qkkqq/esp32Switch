#ifndef __BLE_H_
    #define __BLE_H_
    #include "esp_system.h"
    #include "esp_log.h"
    #include "nvs_flash.h"
    #include "esp_bt.h"
    #include "esp_gap_ble_api.h"//GAP设置头文件，广播和连接相关参数配置
    #include "esp_gatts_api.h"//GATT配置头文件，创建Service和Characteristic
    #include "esp_bt_main.h"//蓝牙栈空间的初始化头文件
    #include "esp_bt_main.h"
    #include "esp_gatt_common_api.h"

    enum
    {
        IDX_SVC,

        IDX_CHAR_SWITCH,
        IDX_CHAR_VAL_SWITCH,

        HRS_IDX_NB
    };
    
    #define GATTS_TABLE_TAG "GATTS_TABLE_DEMO"

    #define PROFILE_NUM 1
    #define PROFILE_APP_IDX 0
    #define ESP_APP_ID 0x55
    #define SAMPLE_DEVICE_NAME "switch" // 修改蓝牙名
    #define SVC_INST_ID 0


    /* The max length of characteristic value. When the GATT client performs a write or prepare write operation,
    *  the data length must be less than GATTS_DEMO_CHAR_VAL_LEN_MAX.
    */
    #define GATTS_DEMO_CHAR_VAL_LEN_MAX 500
    #define PREPARE_BUF_MAX_SIZE 1024
    #define CHAR_DECLARATION_SIZE (sizeof(uint8_t))

    #define ADV_CONFIG_FLAG (1 << 0)
    #define SCAN_RSP_CONFIG_FLAG (1 << 1)


    uint16_t heart_rate_handle_table[HRS_IDX_NB];

    typedef struct
    {
        uint8_t *prepare_buf;
        int prepare_len;
    } prepare_type_env_t;

    struct gatts_profile_inst
    {
        esp_gatts_cb_t gatts_cb;
        uint16_t gatts_if;
        uint16_t app_id;
        uint16_t conn_id;
        uint16_t service_handle;
        esp_gatt_srvc_id_t service_id;
        uint16_t char_handle;
        esp_bt_uuid_t char_uuid;
        esp_gatt_perm_t perm;
        esp_gatt_char_prop_t property;
        uint16_t descr_handle;
        esp_bt_uuid_t descr_uuid;
    };

    void Ble_Init(void);

#endif // !__BLE_H_