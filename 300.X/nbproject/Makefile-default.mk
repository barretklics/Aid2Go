#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/300.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/300.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=newavr-main.c twi_master.c i2c_lcd.c menu.c watch.c bUtils.c button.c reoccurring.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/newavr-main.o ${OBJECTDIR}/twi_master.o ${OBJECTDIR}/i2c_lcd.o ${OBJECTDIR}/menu.o ${OBJECTDIR}/watch.o ${OBJECTDIR}/bUtils.o ${OBJECTDIR}/button.o ${OBJECTDIR}/reoccurring.o
POSSIBLE_DEPFILES=${OBJECTDIR}/newavr-main.o.d ${OBJECTDIR}/twi_master.o.d ${OBJECTDIR}/i2c_lcd.o.d ${OBJECTDIR}/menu.o.d ${OBJECTDIR}/watch.o.d ${OBJECTDIR}/bUtils.o.d ${OBJECTDIR}/button.o.d ${OBJECTDIR}/reoccurring.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/newavr-main.o ${OBJECTDIR}/twi_master.o ${OBJECTDIR}/i2c_lcd.o ${OBJECTDIR}/menu.o ${OBJECTDIR}/watch.o ${OBJECTDIR}/bUtils.o ${OBJECTDIR}/button.o ${OBJECTDIR}/reoccurring.o

# Source Files
SOURCEFILES=newavr-main.c twi_master.c i2c_lcd.c menu.c watch.c bUtils.c button.c reoccurring.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/300.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=AVR128DB28
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/newavr-main.o: newavr-main.c  .generated_files/flags/default/570a20c7d06c1650833c1b77ddb583ff5a8a7697 .generated_files/flags/default/77f3f082d413d90c61e2b1eddcd528f88b385cde
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/newavr-main.o.d 
	@${RM} ${OBJECTDIR}/newavr-main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/newavr-main.o.d" -MT "${OBJECTDIR}/newavr-main.o.d" -MT ${OBJECTDIR}/newavr-main.o -o ${OBJECTDIR}/newavr-main.o newavr-main.c 
	
${OBJECTDIR}/twi_master.o: twi_master.c  .generated_files/flags/default/1ca0be860cfb3d47e51324506dea65554eb52c73 .generated_files/flags/default/77f3f082d413d90c61e2b1eddcd528f88b385cde
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/twi_master.o.d 
	@${RM} ${OBJECTDIR}/twi_master.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/twi_master.o.d" -MT "${OBJECTDIR}/twi_master.o.d" -MT ${OBJECTDIR}/twi_master.o -o ${OBJECTDIR}/twi_master.o twi_master.c 
	
${OBJECTDIR}/i2c_lcd.o: i2c_lcd.c  .generated_files/flags/default/46a16f28415c4408835618869548537ef79d6b26 .generated_files/flags/default/77f3f082d413d90c61e2b1eddcd528f88b385cde
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/i2c_lcd.o.d 
	@${RM} ${OBJECTDIR}/i2c_lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/i2c_lcd.o.d" -MT "${OBJECTDIR}/i2c_lcd.o.d" -MT ${OBJECTDIR}/i2c_lcd.o -o ${OBJECTDIR}/i2c_lcd.o i2c_lcd.c 
	
${OBJECTDIR}/menu.o: menu.c  .generated_files/flags/default/d038a030b4ef0896d26da89513c2278d7fb53a06 .generated_files/flags/default/77f3f082d413d90c61e2b1eddcd528f88b385cde
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/menu.o.d 
	@${RM} ${OBJECTDIR}/menu.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/menu.o.d" -MT "${OBJECTDIR}/menu.o.d" -MT ${OBJECTDIR}/menu.o -o ${OBJECTDIR}/menu.o menu.c 
	
${OBJECTDIR}/watch.o: watch.c  .generated_files/flags/default/9e321f135122e97a7e49d803e1b6abc9fb5e90c9 .generated_files/flags/default/77f3f082d413d90c61e2b1eddcd528f88b385cde
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/watch.o.d 
	@${RM} ${OBJECTDIR}/watch.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/watch.o.d" -MT "${OBJECTDIR}/watch.o.d" -MT ${OBJECTDIR}/watch.o -o ${OBJECTDIR}/watch.o watch.c 
	
${OBJECTDIR}/bUtils.o: bUtils.c  .generated_files/flags/default/890b72ae11981bbcd8b832f9ae6b6c0b85e4b9e3 .generated_files/flags/default/77f3f082d413d90c61e2b1eddcd528f88b385cde
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/bUtils.o.d 
	@${RM} ${OBJECTDIR}/bUtils.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/bUtils.o.d" -MT "${OBJECTDIR}/bUtils.o.d" -MT ${OBJECTDIR}/bUtils.o -o ${OBJECTDIR}/bUtils.o bUtils.c 
	
${OBJECTDIR}/button.o: button.c  .generated_files/flags/default/a4affd89ddc10584ff910d3290507af3ebfebe92 .generated_files/flags/default/77f3f082d413d90c61e2b1eddcd528f88b385cde
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/button.o.d 
	@${RM} ${OBJECTDIR}/button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/button.o.d" -MT "${OBJECTDIR}/button.o.d" -MT ${OBJECTDIR}/button.o -o ${OBJECTDIR}/button.o button.c 
	
${OBJECTDIR}/reoccurring.o: reoccurring.c  .generated_files/flags/default/f61584f2f239dc1e82a59a7851f83bf1ca2db74 .generated_files/flags/default/77f3f082d413d90c61e2b1eddcd528f88b385cde
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/reoccurring.o.d 
	@${RM} ${OBJECTDIR}/reoccurring.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/reoccurring.o.d" -MT "${OBJECTDIR}/reoccurring.o.d" -MT ${OBJECTDIR}/reoccurring.o -o ${OBJECTDIR}/reoccurring.o reoccurring.c 
	
else
${OBJECTDIR}/newavr-main.o: newavr-main.c  .generated_files/flags/default/76f41ef1f3a765b0e8203bb839bf8586b47e18a2 .generated_files/flags/default/77f3f082d413d90c61e2b1eddcd528f88b385cde
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/newavr-main.o.d 
	@${RM} ${OBJECTDIR}/newavr-main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/newavr-main.o.d" -MT "${OBJECTDIR}/newavr-main.o.d" -MT ${OBJECTDIR}/newavr-main.o -o ${OBJECTDIR}/newavr-main.o newavr-main.c 
	
${OBJECTDIR}/twi_master.o: twi_master.c  .generated_files/flags/default/c2d7f93bd1f648f5f2fafb7df29b549f94aa84bc .generated_files/flags/default/77f3f082d413d90c61e2b1eddcd528f88b385cde
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/twi_master.o.d 
	@${RM} ${OBJECTDIR}/twi_master.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/twi_master.o.d" -MT "${OBJECTDIR}/twi_master.o.d" -MT ${OBJECTDIR}/twi_master.o -o ${OBJECTDIR}/twi_master.o twi_master.c 
	
${OBJECTDIR}/i2c_lcd.o: i2c_lcd.c  .generated_files/flags/default/259b81318860e3aa168795b116ad6bdf0ea5420a .generated_files/flags/default/77f3f082d413d90c61e2b1eddcd528f88b385cde
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/i2c_lcd.o.d 
	@${RM} ${OBJECTDIR}/i2c_lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/i2c_lcd.o.d" -MT "${OBJECTDIR}/i2c_lcd.o.d" -MT ${OBJECTDIR}/i2c_lcd.o -o ${OBJECTDIR}/i2c_lcd.o i2c_lcd.c 
	
${OBJECTDIR}/menu.o: menu.c  .generated_files/flags/default/bb646c0ca1e16622c11745679a5072bf04528e2d .generated_files/flags/default/77f3f082d413d90c61e2b1eddcd528f88b385cde
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/menu.o.d 
	@${RM} ${OBJECTDIR}/menu.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/menu.o.d" -MT "${OBJECTDIR}/menu.o.d" -MT ${OBJECTDIR}/menu.o -o ${OBJECTDIR}/menu.o menu.c 
	
${OBJECTDIR}/watch.o: watch.c  .generated_files/flags/default/7e7d87f3ed2d651ad9841e67f46e02b76fc05291 .generated_files/flags/default/77f3f082d413d90c61e2b1eddcd528f88b385cde
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/watch.o.d 
	@${RM} ${OBJECTDIR}/watch.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/watch.o.d" -MT "${OBJECTDIR}/watch.o.d" -MT ${OBJECTDIR}/watch.o -o ${OBJECTDIR}/watch.o watch.c 
	
${OBJECTDIR}/bUtils.o: bUtils.c  .generated_files/flags/default/82fbc27fec5658cd1152a043b8f9fd944c9c62b2 .generated_files/flags/default/77f3f082d413d90c61e2b1eddcd528f88b385cde
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/bUtils.o.d 
	@${RM} ${OBJECTDIR}/bUtils.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/bUtils.o.d" -MT "${OBJECTDIR}/bUtils.o.d" -MT ${OBJECTDIR}/bUtils.o -o ${OBJECTDIR}/bUtils.o bUtils.c 
	
${OBJECTDIR}/button.o: button.c  .generated_files/flags/default/fd5be292cd91b0cbbafc54a69a57c57fc44a9609 .generated_files/flags/default/77f3f082d413d90c61e2b1eddcd528f88b385cde
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/button.o.d 
	@${RM} ${OBJECTDIR}/button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/button.o.d" -MT "${OBJECTDIR}/button.o.d" -MT ${OBJECTDIR}/button.o -o ${OBJECTDIR}/button.o button.c 
	
${OBJECTDIR}/reoccurring.o: reoccurring.c  .generated_files/flags/default/c6bb110d01063054723f9ee73f2a435fdbc43927 .generated_files/flags/default/77f3f082d413d90c61e2b1eddcd528f88b385cde
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/reoccurring.o.d 
	@${RM} ${OBJECTDIR}/reoccurring.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/reoccurring.o.d" -MT "${OBJECTDIR}/reoccurring.o.d" -MT ${OBJECTDIR}/reoccurring.o -o ${OBJECTDIR}/reoccurring.o reoccurring.c 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/300.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/300.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"   -gdwarf-2 -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -gdwarf-3     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/300.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o ${DISTDIR}/300.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group  -Wl,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1
	@${RM} ${DISTDIR}/300.X.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/300.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/300.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -gdwarf-3     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/300.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o ${DISTDIR}/300.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}\\avr-objcopy -O ihex "${DISTDIR}/300.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "${DISTDIR}/300.X.${IMAGE_TYPE}.hex"
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
