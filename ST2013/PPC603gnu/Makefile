# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = PPC603gnu
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := C:/Users/Pete/Documents/GitHub/2013UA
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/ST2013



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = ppc
CPU = PPC603
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 

IDE_DEFINES = 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif


#Project Targets
PROJECT_TARGETS = RobotCode2013/$(MODE_DIR)/RobotCode2013.out \
	 RobotCode2013_partialImage/$(MODE_DIR)/RobotCode2013_partialImage.o


#Rules

# RobotCode2013
ifeq ($(DEBUG_MODE),1)
RobotCode2013/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
RobotCode2013/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
RobotCode2013/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
RobotCode2013/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
RobotCode2013/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
RobotCode2013/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
RobotCode2013/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
RobotCode2013/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
RobotCode2013/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
RobotCode2013/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
RobotCode2013/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
RobotCode2013/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
RobotCode2013/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
RobotCode2013/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
RobotCode2013/$(MODE_DIR)/% : IDE_DEFINES = 
RobotCode2013/$(MODE_DIR)/% : PROJECT_TYPE = DKM
RobotCode2013/$(MODE_DIR)/% : DEFINES = 
RobotCode2013/$(MODE_DIR)/% : EXPAND_DBG = 0
RobotCode2013/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
RobotCode2013/$(MODE_DIR)/% : CPU = PPC603
RobotCode2013/$(MODE_DIR)/% : TOOL_FAMILY = gnu
RobotCode2013/$(MODE_DIR)/% : TOOL = gnu
RobotCode2013/$(MODE_DIR)/% : TOOL_PATH = 
RobotCode2013/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
RobotCode2013/$(MODE_DIR)/% : LIBPATH = 
RobotCode2013/$(MODE_DIR)/% : LIBS = 
RobotCode2013/$(MODE_DIR)/% : OBJ_DIR := RobotCode2013/$(MODE_DIR)

OBJECTS_RobotCode2013 = RobotCode2013_partialImage/$(MODE_DIR)/RobotCode2013_partialImage.o

RobotCode2013/$(MODE_DIR)/RobotCode2013.out : $(OBJECTS_RobotCode2013)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmppc $(OBJECTS_RobotCode2013) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_RobotCode2013) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

RobotCode2013/$(MODE_DIR)/RobotCode2013_compile_file : $(FILE) ;

_clean :: RobotCode2013/$(MODE_DIR)/RobotCode2013_clean

RobotCode2013/$(MODE_DIR)/RobotCode2013_clean : 
	$(TRACE_FLAG)if [ -d "RobotCode2013" ]; then cd "RobotCode2013"; rm -rf $(MODE_DIR); fi


# RobotCode2013_partialImage
ifeq ($(DEBUG_MODE),1)
RobotCode2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
RobotCode2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
RobotCode2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
RobotCode2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
RobotCode2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
RobotCode2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
RobotCode2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
RobotCode2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
RobotCode2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
RobotCode2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
RobotCode2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
RobotCode2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
RobotCode2013_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
RobotCode2013_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
RobotCode2013_partialImage/$(MODE_DIR)/% : IDE_DEFINES = 
RobotCode2013_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
RobotCode2013_partialImage/$(MODE_DIR)/% : DEFINES = 
RobotCode2013_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
RobotCode2013_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
RobotCode2013_partialImage/$(MODE_DIR)/% : CPU = PPC603
RobotCode2013_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = gnu
RobotCode2013_partialImage/$(MODE_DIR)/% : TOOL = gnu
RobotCode2013_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
RobotCode2013_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
RobotCode2013_partialImage/$(MODE_DIR)/% : LIBPATH = 
RobotCode2013_partialImage/$(MODE_DIR)/% : LIBS = 
RobotCode2013_partialImage/$(MODE_DIR)/% : OBJ_DIR := RobotCode2013_partialImage/$(MODE_DIR)

RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/Autonomous.o : $(PRJ_ROOT_DIR)/Autonomous.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/Robot.o : $(PRJ_ROOT_DIR)/Robot.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/Teleop.o : $(PRJ_ROOT_DIR)/Teleop.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/alec/AutoParser.o : $(PRJ_ROOT_DIR)/alec/AutoParser.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/alec/ConstParser.o : $(PRJ_ROOT_DIR)/alec/ConstParser.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/alec/DoubleNoid.o : $(PRJ_ROOT_DIR)/alec/DoubleNoid.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/alec/GenericController.o : $(PRJ_ROOT_DIR)/alec/GenericController.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/alec/PID.o : $(PRJ_ROOT_DIR)/alec/PID.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/alec/RoboSock.o : $(PRJ_ROOT_DIR)/alec/RoboSock.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/alec/Threading.o : $(PRJ_ROOT_DIR)/alec/Threading.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/alec/stderr.o : $(PRJ_ROOT_DIR)/alec/stderr.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/alec/ugly.o : $(PRJ_ROOT_DIR)/alec/ugly.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_RobotCode2013_partialImage = RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/Autonomous.o \
	 RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/Robot.o \
	 RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/Teleop.o \
	 RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/alec/AutoParser.o \
	 RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/alec/ConstParser.o \
	 RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/alec/DoubleNoid.o \
	 RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/alec/GenericController.o \
	 RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/alec/PID.o \
	 RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/alec/RoboSock.o \
	 RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/alec/Threading.o \
	 RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/alec/stderr.o \
	 RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/alec/ugly.o

RobotCode2013_partialImage/$(MODE_DIR)/RobotCode2013_partialImage.o : $(OBJECTS_RobotCode2013_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X  -o "$@" $(OBJECTS_RobotCode2013_partialImage) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS)  && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

RobotCode2013_partialImage/$(MODE_DIR)/RobotCode2013_partialImage_compile_file : $(FILE) ;

_clean :: RobotCode2013_partialImage/$(MODE_DIR)/RobotCode2013_partialImage_clean

RobotCode2013_partialImage/$(MODE_DIR)/RobotCode2013_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "RobotCode2013_partialImage" ]; then cd "RobotCode2013_partialImage"; rm -rf $(MODE_DIR); fi

force : 

DEP_FILES := RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/Autonomous.d RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/Robot.d RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/Teleop.d \
	 RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/alec/AutoParser.d RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/alec/ConstParser.d RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/alec/DoubleNoid.d \
	 RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/alec/GenericController.d RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/alec/PID.d RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/alec/RoboSock.d \
	 RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/alec/Threading.d RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/alec/stderr.d RobotCode2013_partialImage/$(MODE_DIR)/Objects/ST2013/alec/ugly.d
-include $(DEP_FILES)



-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

main_all : external_build $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
