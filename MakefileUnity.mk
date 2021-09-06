#This makefile makes the examples from the first few chapters with Unity test harness

#Set this to @ to keep the makefile quiet
SILENCE = @

#---- Outputs ----#
COMPONENT_NAME = BookCode_Unity

#--- Inputs ----#
UNITY_HOME = $(UNITY_HOME_DIR)
CPP_PLATFORM = Gcc

#--- Project Directories ----#
PROJECT_HOME_DIR = .
PROJECT_SRC_DIR = src
PROJECT_INCLUDE_DIR = include
PROJECT_TEST_DIR = tests
PROJECT_MOCKS_DIR = mocks


CPP_PLATFORM = Gcc
UNITY_BUILD_HOME = $(UNITY_HOME)/extras/fixture/build

UNITY_CFLAGS += -DUNITY_OUTPUT_CHAR=UnityOutputCharSpy_OutputChar
UNITY_WARNINGFLAGS = -Wall -Werror -Wswitch-default
#UNITY_WARNINGFLAGS += -Wshadow 

SRC_DIRS = \
	$(PROJECT_SRC_DIR)/LedDriver\

TEST_SRC_DIRS = \
	$(PROJECT_TEST_DIR)\
	$(PROJECT_TEST_DIR)/LedDriver\
	$(UNITY_HOME)/unity\
	$(UNITY_HOME)/src\
    $(UNITY_HOME)/extras/fixture/src\
    $(UNITY_HOME)/extras/fixture/test\

MOCKS_SRC_DIRS = \
  $(PROJECT_MOCKS_DIR)

INCLUDE_DIRS =\
  .\
  $(UNITY_HOME)/src\
  $(UNITY_HOME)/extras/fixture/src\
  $(UNITY_HOME)/extras/fixture/test\
  $(PROJECT_INCLUDE_DIR)/LedDriver\
  $(PROJECT_INCLUDE_DIR)/util\
  
include $(UNITY_BUILD_HOME)/MakefileWorker.mk

