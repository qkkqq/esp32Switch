set (servo_src "src/servo.c")

idf_component_register(SRCS "${servo_src}"
                    INCLUDE_DIRS "include")
