cmake_minimum_required(VERSION 3.4.1)

project(webserver)
set(TARGET webserver)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR} SOURCES)
add_executable(${TARGET} ${SOURCES})

find_library(cgipp fastcgipp)


target_link_libraries( # 目标库
                       ${TARGET}

                       # 目标库需要链接的库
                       # log-lib 是上面 find_library 指定的变量名
		        ${cgipp})

