# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "Msgs: 2 messages, 0 services")

set(MSG_I_FLAGS "-IMsgs:/home/firly/testing ros/branch msgs/nyobain_ws/src/Msgs/msg;-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(Msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/firly/testing ros/branch msgs/nyobain_ws/src/Msgs/msg/HardwareCommand.msg" NAME_WE)
add_custom_target(_Msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "Msgs" "/home/firly/testing ros/branch msgs/nyobain_ws/src/Msgs/msg/HardwareCommand.msg" ""
)

get_filename_component(_filename "/home/firly/testing ros/branch msgs/nyobain_ws/src/Msgs/msg/keyboardinput.msg" NAME_WE)
add_custom_target(_Msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "Msgs" "/home/firly/testing ros/branch msgs/nyobain_ws/src/Msgs/msg/keyboardinput.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(Msgs
  "/home/firly/testing ros/branch msgs/nyobain_ws/src/Msgs/msg/HardwareCommand.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Msgs
)
_generate_msg_cpp(Msgs
  "/home/firly/testing ros/branch msgs/nyobain_ws/src/Msgs/msg/keyboardinput.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Msgs
)

### Generating Services

### Generating Module File
_generate_module_cpp(Msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(Msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(Msgs_generate_messages Msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/firly/testing ros/branch msgs/nyobain_ws/src/Msgs/msg/HardwareCommand.msg" NAME_WE)
add_dependencies(Msgs_generate_messages_cpp _Msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/firly/testing ros/branch msgs/nyobain_ws/src/Msgs/msg/keyboardinput.msg" NAME_WE)
add_dependencies(Msgs_generate_messages_cpp _Msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(Msgs_gencpp)
add_dependencies(Msgs_gencpp Msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS Msgs_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(Msgs
  "/home/firly/testing ros/branch msgs/nyobain_ws/src/Msgs/msg/HardwareCommand.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/Msgs
)
_generate_msg_eus(Msgs
  "/home/firly/testing ros/branch msgs/nyobain_ws/src/Msgs/msg/keyboardinput.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/Msgs
)

### Generating Services

### Generating Module File
_generate_module_eus(Msgs
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/Msgs
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(Msgs_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(Msgs_generate_messages Msgs_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/firly/testing ros/branch msgs/nyobain_ws/src/Msgs/msg/HardwareCommand.msg" NAME_WE)
add_dependencies(Msgs_generate_messages_eus _Msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/firly/testing ros/branch msgs/nyobain_ws/src/Msgs/msg/keyboardinput.msg" NAME_WE)
add_dependencies(Msgs_generate_messages_eus _Msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(Msgs_geneus)
add_dependencies(Msgs_geneus Msgs_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS Msgs_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(Msgs
  "/home/firly/testing ros/branch msgs/nyobain_ws/src/Msgs/msg/HardwareCommand.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Msgs
)
_generate_msg_lisp(Msgs
  "/home/firly/testing ros/branch msgs/nyobain_ws/src/Msgs/msg/keyboardinput.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Msgs
)

### Generating Services

### Generating Module File
_generate_module_lisp(Msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(Msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(Msgs_generate_messages Msgs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/firly/testing ros/branch msgs/nyobain_ws/src/Msgs/msg/HardwareCommand.msg" NAME_WE)
add_dependencies(Msgs_generate_messages_lisp _Msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/firly/testing ros/branch msgs/nyobain_ws/src/Msgs/msg/keyboardinput.msg" NAME_WE)
add_dependencies(Msgs_generate_messages_lisp _Msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(Msgs_genlisp)
add_dependencies(Msgs_genlisp Msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS Msgs_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(Msgs
  "/home/firly/testing ros/branch msgs/nyobain_ws/src/Msgs/msg/HardwareCommand.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/Msgs
)
_generate_msg_nodejs(Msgs
  "/home/firly/testing ros/branch msgs/nyobain_ws/src/Msgs/msg/keyboardinput.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/Msgs
)

### Generating Services

### Generating Module File
_generate_module_nodejs(Msgs
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/Msgs
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(Msgs_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(Msgs_generate_messages Msgs_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/firly/testing ros/branch msgs/nyobain_ws/src/Msgs/msg/HardwareCommand.msg" NAME_WE)
add_dependencies(Msgs_generate_messages_nodejs _Msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/firly/testing ros/branch msgs/nyobain_ws/src/Msgs/msg/keyboardinput.msg" NAME_WE)
add_dependencies(Msgs_generate_messages_nodejs _Msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(Msgs_gennodejs)
add_dependencies(Msgs_gennodejs Msgs_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS Msgs_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(Msgs
  "/home/firly/testing ros/branch msgs/nyobain_ws/src/Msgs/msg/HardwareCommand.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Msgs
)
_generate_msg_py(Msgs
  "/home/firly/testing ros/branch msgs/nyobain_ws/src/Msgs/msg/keyboardinput.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Msgs
)

### Generating Services

### Generating Module File
_generate_module_py(Msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(Msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(Msgs_generate_messages Msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/firly/testing ros/branch msgs/nyobain_ws/src/Msgs/msg/HardwareCommand.msg" NAME_WE)
add_dependencies(Msgs_generate_messages_py _Msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/firly/testing ros/branch msgs/nyobain_ws/src/Msgs/msg/keyboardinput.msg" NAME_WE)
add_dependencies(Msgs_generate_messages_py _Msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(Msgs_genpy)
add_dependencies(Msgs_genpy Msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS Msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(Msgs_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/Msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/Msgs
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(Msgs_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(Msgs_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/Msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/Msgs
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(Msgs_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(Msgs_generate_messages_py std_msgs_generate_messages_py)
endif()
