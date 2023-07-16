idf_component_register(SRCS "esp32_switch_main.c" 
                    INCLUDE_DIRS "."
                    PRIV_REQUIRES nvs_flash bt)
