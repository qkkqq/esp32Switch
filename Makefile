#
# This is a project Makefile. It is assumed the directory this Makefile resides in is a
# project subdirectory.
#

PROJECT_NAME := esp32Switch
EXTRA_COMPONENT_DIRS += $(PROJCT_PATH)/components

include $(IDF_PATH)/make/project.mk

