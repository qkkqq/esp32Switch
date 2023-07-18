

idf_component_register(SRCS "esp32_switch_main.c" "src/servo.c" "src/ble.c"
                    INCLUDE_DIRS "." "include"
                    PRIV_REQUIRES nvs_flash bt)
